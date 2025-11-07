#ifndef QUEUE_H
#define QUEUE_
#include "../include/voter.h"
typedef struct Node 
{
    Voter* data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue();
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int isEmpty(Queue* q);
void freeQueue(Queue* q);

#endif