#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {1, 2, 3, 11, 4, 5, 6, 7, 8, 9, 10};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("starting...\n");
    bubble_sort(array, n);
    printf("finished...\n");
    print_array(array, n);
    return (0);
}
