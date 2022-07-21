#include <stdlib.h>
#include "sort.h"

/**
 * swaplist - swaps list with previous
 * @add: address of swapping
 * @head: incase we need to become the head
 *
 * Return: no shit
 */

void swaplist(listint_t *add, listint_t **head)
{
	listint_t *node = add;
	listint_t *temprev = node->prev;
	listint_t *tempnext = node->next;

	if (temprev->prev == NULL)
	{
		node->prev->next = node->next;
		if (node->next != NULL)
			node->next->prev = node->prev;
		node->prev->prev = node;
		node->next = node->prev;
		node->prev = NULL;
		*head = node;

	}
	else
	{
		temprev->prev->next = node;
		node->prev = temprev->prev;
		node->next = temprev;
		temprev->next = tempnext;
		temprev->prev = node;
		if (tempnext != NULL)
			tempnext->prev = temprev;
	}
}

/**
 * insertion_sort_list - sorts linked list by insertion method
 * @list: head addrress of list
 *
 * Return: no shit
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *wemove = NULL;
	listint_t *swapadd = NULL;
	int swap = 0;

	if (list == NULL)
		return;

	wemove = *list;
	while (wemove->next != NULL)
	{
		if (wemove->n > wemove->next->n)
		{
			swaplist(wemove->next, list);
			print_list(*list);
			swap = 1;
			swapadd = wemove->prev;
		}
		if (swap == 0)
			wemove = wemove->next;
		while (swap == 1)
		{
			if (swapadd->prev == NULL)
				break;
			if (swapadd->n < swapadd->prev->n)
			{
				swaplist(swapadd, list);
				print_list(*list);
			}
			else
			{
				swap = 0;
			}
		}
	}
}
