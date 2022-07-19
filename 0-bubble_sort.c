#include <stdlib.h>
#include "sort.h"

/**
 * swaparr - swaps array
 * @add: address of present array
 *
 * Return: no shit
 */
void swaparr(int *add)
{
        int temp = *add;
        *add = add[-1];
        add[-1] = temp;
}


/**
 * bubble_sort - sorts in ascending order by swaping element in each tranverse
 * @array: address of array to be sorted
 * @size: size of array
 *
 * Return: nothing
 */

void bubble_sort(int *array, size_t size)
{
	size_t newsize = size;
	size_t i;
	size_t n = size;

	while(newsize > 1)
	{
		for(i = 0; i < size; i++)
		{
			if(array[i] < array[i - 1])
			{
				swaparr(array + i);
				newsize = i;
				print_array(array, n);
			}
		}
		size = newsize;
	}
}
