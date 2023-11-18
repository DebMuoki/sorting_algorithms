#include "sort.h"

/**
 * insertion_sort_list - Sort doubly linked list of integers in ascending order
 * using the Insertion sort algorithm.
 *
 * @list: A pointer to the doubly linked list
 *
 * Description: sorts the given doubly linked list in ascending order
 * using the Insertion Sort algorithm.
 */
void insertion_sort_list(listint_t **list)
{
	/* Initialize variables */
	listint_t *current = (*list)->next;
	listint_t *prev;
	listint_t *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (current != NULL)
	{
		prev = current->prev;
		temp = current;

		/* Move the nodes backward until the correct position is found */
		while (prev != NULL && temp->n < prev->n)
		{
			/* Swap nodes */
			if (temp->next != NULL)
				temp->next->prev = prev;

			prev->next = temp->next;
			temp->prev = prev->prev;
			temp->next = prev;

			if (prev->prev != NULL)
				prev->prev->next = temp;
			else
				*list = temp;

			prev->prev = temp;

			/* Print the list after each swap */
			print_list(*list);
			prev = temp->prev;
		}

		current = current->next;
	}
}

