#include "../include/voter.h"
#include "../include/queue.h"
#include <stdio.h>
#include <stdlib.h>

void registerVoter(int id,const char* name,const char* gender,int age)
{
    Voter* newNode=(Voter*)malloc(sizeof(Voter));
    newNode->age=age;
    newNode->voterID=id;
    newNode->hasVoted=0;
    newNode->name=(char*)malloc(strlen(name)+1);
    strcpy(newNode->name,name);
    newNode->gender=(char*)malloc(strlen(gender)+1);
    strcpy(newNode->gender,gender);
    enqueue(&voterQueue,newNode);
}