#include "../include/queue.h"
#include <stdio.h>
#include <stdlib.h>

Queue* createQueue()
{
    Queue* q=(Queue*)malloc(sizeof(Queue));
    q->front=NULL;
    q->rear=NULL;
    return q;
}

Node* createNode(Voter* val)
{
    Node* n=(Node*)malloc(sizeof(Node));
    n->data=val;
    n->next=NULL;
}

void enqueue(Queue* q,Voter* val)
{
    if(q->front==NULL)
    {
        q->front=createNode(val);
        q->rear=q->front;
    }
    else
    {
        Node* temp=createNode(val);
        q->rear->next=temp;
        q->rear=q->rear->next;
    }
}

Node* dequeue(Queue* q)
{
    Node* temp=q->front;
    q->front=q->front->next;
    free(temp);
}

bool isEmpty(Queue* q)
{
    if(q->front==q->rear)
    {
        return true;
    }
    return false;
}
