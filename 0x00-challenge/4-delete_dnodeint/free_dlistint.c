#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * free_dlistint - Frees a doubly linked list
 *
 * @head: A pointer to the first element of the doubly linked list
 */
void free_dlistint(dlistint_t *head)
{
    dlistint_t *currentNode;

    while (head != NULL)
    {
        currentNode = head;
        head = head->next;
        free(currentNode);
    }
}

