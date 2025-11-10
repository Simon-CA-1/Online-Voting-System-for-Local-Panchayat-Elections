#include "../include/voter.h"
#include "../include/queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Voter* createNode(int id, const char* name, const char* gender, int age)
{
    Voter* newNode=(Voter*)malloc(sizeof(Voter));
    newNode->age=age;
    newNode->voterID=id;
    newNode->hasVoted=0;
    newNode->name=(char*)malloc(strlen(name)+1);
    strcpy(newNode->name,name);
    newNode->gender=(char*)malloc(strlen(gender)+1);
    strcpy(newNode->gender,gender);
    return newNode;
}
void registerVoter(int id,const char* name,const char* gender,int age,Queue *voterQueue)
{
    Voter* newNode=createNode(id,name,gender,age);
    enqueue(voterQueue,newNode);
}

void displayVoters(Queue *voterQueue)
{
    if(isEmpty(voterQueue))
    {
        printf("No voters registered yet.\n");
        return;
    }
    Node* temp=voterQueue->front;
    printf("Registered Voters:\n");
    while(temp!=NULL)
    {
        printf("Voter ID: %d, Name: %s, Gender: %s, Age: %d\n",
               temp->data->voterID,
               temp->data->name,
               temp->data->gender,
               temp->data->age);
        temp=temp->next;
    }
}