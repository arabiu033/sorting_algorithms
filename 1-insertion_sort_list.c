#include "sort.h"

/**
 * insertion_sort_list - implementing insertion sort algorithm on a linked list
 * @list: the linked list to sort
 * Return: void - nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next;

	current = *list;
	next = current->next;
	while(current && next)
	{
		if (current->n > next->n)
		{
			printf("insert \n");
			switcher(next);
			print_list(*list);
			look_back(next, list);
			next = current->next;
			continue;
		}

		current = current->next;
		next = current->next;
	}
}

/**
 * look_back - check for sorts through reverse
 * @current: node to start from
 * Return: nothing
 */
void look_back(listint_t *current, listint_t **list)
{
	listint_t *prev;

	prev = current->prev;
	while (current && prev && prev->prev->n > current->n)
	{
		printf("look back\n");
		switcher(current);
		print_list(*list);
		prev = current->prev;
	}
}

/**
 * switcher - switches node
 * @node: the node to switch
 * Return: void - nothing
 */
void switcher(listint_t *node)
{
	listint_t *A, *D, *B, *C;

	if (!node || !node->prev)
		return;

	A = node->prev->prev;
	D = node->next;
	C = node;
	B = node->prev;

	if (A)
		A->next = C;
	if (D)
		D->prev = B;
	B->next = D;
	B->prev = C;
	C->next = B;
	C->prev = A;
}
