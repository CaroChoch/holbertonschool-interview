# Making Change

## Description
This repository contains Python scripts that implement algorithms to determine the fewest number of coins needed to meet a given total amount using a pile of coins with different denominations.

## Requirements
- All scripts are written and tested on Ubuntu 14.04 LTS using Python 3.4.3.
- Scripts should adhere to PEP 8 style guidelines (version 1.7.x).
- Each script file should begin with `#!/usr/bin/python3`.
- Scripts must be executable.
- The repository must include a `README.md` file that provides an overview of the project.

## Functionality
The main function implemented is `makeChange(coins, total)`, which calculates:
- The minimum number of coins required to meet the `total` amount.
- Returns `0` if `total` is 0 or less.
- Returns `-1` if the total cannot be met with the given coins.

## Files
- `0-making_change.py`: Python script containing the `makeChange` function.
- `0-main.py`: Main script for testing the `makeChange` function with sample inputs.

## Usage
To test the scripts:
```bash
./0-main.py
```
This will execute 0-main.py and print the results of the makeChange function with predefined test cases.

