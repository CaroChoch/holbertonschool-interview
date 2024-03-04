#!/usr/bin/python3
"""
Method that determines if a given data set represents a valid UTF-8 encoding
"""


def validUTF8(data):
    """
    Determines if a given data set represents a valid UTF-8 encoding.

    Arguments:
        data (list[int]): The data set represented by a list of integers,
                          where each integer represents 1 byte of data.

    Returns:
        bool: True if data is a valid UTF-8 encoding, else False.
    """
    # Initialize the number of bytes to follow for the current character
    bytes_to_follow = 0
    
    # Masks for checking leading bits of bytes
    mask1 = 1 << 7  # 10000000
    mask2 = 1 << 6  # 01000000

    # If data is empty or None, it's considered valid UTF-8
    if not data or len(data) == 0:
        return True

    # Iterates through each byte in the data
    for byte in data:
        mask = 1 << 7
        if bytes_to_follow == 0:
            # Counts the number of bytes in the current character
            while mask & byte:
                bytes_to_follow += 1
                mask = mask >> 1

            # If no bytes are counted, it's an ASCII character
            if bytes_to_follow == 0:
                continue
            # Checks if the number of bytes is within the valid range
            if bytes_to_follow == 1 or bytes_to_follow > 4:
                return False
        else:
            # For multi-byte characters, check if the leading bits are correct
            if not (byte & mask1 and not (byte & mask2)):
                return False
        # Reduce remaining character bytes
        bytes_to_follow -= 1

    # Checks if all bytes are consumed for characters
    return bytes_to_follow == 0
