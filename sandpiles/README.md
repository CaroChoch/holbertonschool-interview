# Project Sandpiles

## Description
The "Sandpiles" project involves implementing a function that calculates the sum of two sandpiles. A sandpile is considered stable when none of its cells contains more than 3 grains. The function takes two input grids of size 3x3, representing two stable sandpiles. After the addition, the first grid must be stable, and its state should be displayed before each toppling round, only if it is unstable.

## Resources
- [Sandpiles - Numberphile](https://intranet.hbtn.io/rltoken/6Ft_wbSkMejwmfJQQjISlw)



## Prerequisites
- All files must be compiled on Ubuntu 14.04 LTS.
- Programs and functions must be compiled with gcc 4.8.4 using the specified options.
- Files must end with a new line.
- Code must follow the Betty style.
- No use of global variables.
- No more than 5 functions per file.
- Prototypes of all functions must be included in the header file `sandpiles.h`.
- Header files must be include guarded.

## Installation and Configuration
1. Clone the repository.
2. Compile the files with the command `gcc -Wall -Wextra -Werror -pedantic *.c -o sandpiles`.
3. Run the program with `./sandpiles`.

## Usage

```c
#include <stdlib.h>
#include <stdio.h>
#include "sandpiles.h"

int main(void)
{
    int grid1[3][3] = {
        {3, 3, 3},
        {3, 3, 3},
        {3, 3, 3}
    };
    int grid2[3][3] = {
        {1, 3, 1},
        {3, 3, 3},
        {1, 3, 1}
    };

    print_grid_sum(grid1, grid2);

    sandpiles_sum(grid1, grid2);

    printf("=\n");
    print_grid(grid1);

    return (EXIT_SUCCESS);
}
```

## Main Features
- Calculation of the sum of two sandpiles.
- Display of the state of the first grid before each toppling round if it is unstable.
- Adherence to Betty style standards.
- No dynamic memory allocation.


## Task List

### 0.Sandpiles sum

Write a function that computes the sum of two sandpiles

- Prototype: `void sandpiles_sum(int grid1[3][3], int grid2[3][3]);`
- You can assume that both `grid1` and `grid2` are individually **stable**
- A sandpile is considered **stable** when none of its cells contains more than 3 grains
- When your function is done, `grid1` must be **stable**
- `grid1` must be printed before each toppling round, only if it is unstable (See example)
- You’re not allowed to allocate memory dynamically
