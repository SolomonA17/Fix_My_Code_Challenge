#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_dnodeint_end - Adds a new node at the end of a doubly linked list
 *
 * @head: A pointer to the address of the first element of the list
 * @n: The integer value to store in the new node
 *
 * Return: A pointer to the newly added node, or NULL on failure
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
    dlistint_t *newNode, *lastNode;

    newNode = malloc(sizeof(dlistint_t));
    if (newNode == NULL)
    {
        return (NULL); // Memory allocation failed
    }

    newNode->n = n;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        newNode->prev = NULL;
        return (newNode);
    }

    lastNode = *head;
    while (lastNode->next != NULL)
    {
        lastNode = lastNode->next;
    }

    lastNode->next = newNode;
    newNode->prev = lastNode;

    return (newNode);
}

