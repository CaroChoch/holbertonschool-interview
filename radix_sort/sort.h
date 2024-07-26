#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void print_array(const int *array, size_t size);
void radix_sort(int *array, size_t size);
void count_sort(int *array, size_t size, int exp, int *output);
int get_max(int *array, size_t size);


#endif /* SORT_H */
