#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Deletes a node at a specific index from a doubly linked list
 *
 * @head: A pointer to the first element of the doubly linked list
 * @index: The index of the node to be deleted
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *saved_head;
    dlistint_t *tmp;
    unsigned int position;

    if (*head == NULL)
    {
        return (-1); // List is empty, deletion not possible
    }

    saved_head = *head;
    position = 0;

    while (position < index && *head != NULL)
    {
        *head = (*head)->next;
        position++;
    }

    if (position != index)
    {
        *head = saved_head;
        return (-1); // Index out of bounds, deletion not possible
    }

    if (0 == index)
    {
        tmp = (*head)->next;
        free(*head);
        *head = tmp;
        if (tmp != NULL)
        {
            tmp->prev = NULL;
        }
    }
    else
    {
        (*head)->prev->next = (*head)->next;
        free(*head);
        if ((*head)->next != NULL)
        {
            (*head)->next->prev = (*head)->prev;
        }
        *head = saved_head;
    }

    return (1); // Node successfully deleted
}

