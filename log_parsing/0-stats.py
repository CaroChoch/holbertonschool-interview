#!/usr/bin/python3
"""
Script that reads stdin line by line and computes metrics
"""
import sys


if __name__ == '__main__':
    def print_metrics(status_code_counts, total_file_size):
        """
        Print the accumulated metrics.
        """
        print('File size: {}'.format(total_file_size))
        for code, count in sorted(status_code_counts.items()):
            if count > 0:
                print('{}: {}'.format(code, count))

    # Dictionary to store counts of different HTTP status codes
    status_code_counts = {
        '200': 0,
        '301': 0,
        '400': 0,
        '401': 0,
        '403': 0,
        '404': 0,
        '405': 0,
        '500': 0
    }
    total_file_size = 0  # Variable to store total size of files processed
    lines_processed = 0  # Counter for number of lines processed

    try:
        # Loop through each line from standard input (stdin)
        for line in sys.stdin:
            lines_processed += 1
            data = line.split()

            # Check if line contains enough elements to extract status and size
            if len(data) >= 2:
                try:
                    status_code = data[-2]
                    size = int(data[-1])
                    total_file_size += size  # Add size to total_file_size
                    # Check if status code is in status_code_counts
                    if status_code in status_code_counts:
                        status_code_counts[status_code] += 1
                except (ValueError, IndexError):
                    # Skip lines with invalid formats
                    continue

            # Print metrics every 10 lines processed
            if lines_processed % 10 == 0:
                print_metrics(status_code_counts, total_file_size)

        # Print final metrics after EOF
        print_metrics(status_code_counts, total_file_size)

    except KeyboardInterrupt:
        # Print metrics on KeyboardInterrupt (Ctrl+C)
        print_metrics(status_code_counts, total_file_size)
        raise
