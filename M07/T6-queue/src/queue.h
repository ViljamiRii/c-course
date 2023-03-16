#ifndef AALTO_C_QUEUE_H
#define AALTO_C_QUEUE_H

struct studentqueue {
    char *name;
    struct studentqueue *next;
};

int enqueue(struct studentqueue *q, const char *name);

int dequeue(struct studentqueue *q, char *buffer, unsigned int size);

#endif
