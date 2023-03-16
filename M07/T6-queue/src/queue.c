#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "queue.h"

int enqueue(struct studentqueue *q, const char *name)
{
    struct studentqueue *new_student = malloc(sizeof(struct studentqueue));

    new_student->name = malloc(strlen(name) + 1);
    strcpy(new_student->name, name);

    new_student->next = NULL;

    struct studentqueue *tail = q;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    tail->next = new_student;

    return 1;
}

int dequeue(struct studentqueue *q, char *buffer, unsigned int size)
{
    if (q->next == NULL) {
        return 0;
    }

    struct studentqueue *head = q->next;
    strncpy(buffer, head->name, size - 1);
    buffer[size - 1] = '\0';

    q->next = head->next;
    free(head->name);
    free(head);

    return 1;
}