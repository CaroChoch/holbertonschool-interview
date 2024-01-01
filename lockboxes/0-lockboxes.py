#!/usr/bin/python3
""" Method that determines if all the boxes can be opened """


def canUnlockAll(boxes):
    """
    Method that determines if all the boxes can be opened
    Argument :
        boxes: list of lists
    Returns: True if all boxes can be opened, False otherwise
    """
    # If the list of boxes is empty, return False
    if len(boxes) == 0:
        return False

    # Initialize the list of keys with key 0
    keys = [0]

    # For each key in the list of keys
    for key in keys:
        # For each box in the list of boxes at the index of the key
        for box in boxes[key]:
            # If the box is not already in the list of keys and the index of
            # the box is less than the length of the list of boxes
            if box not in keys and box < len(boxes):
                # Add the box to the list of keys
                keys.append(box)

    # If the length of the list of keys is equal to the length of the list of
    # boxes, return True
    if len(keys) == len(boxes):
        return True

    # Otherwise, return False
    return False
