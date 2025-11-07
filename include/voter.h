#ifndef VOTER_H
#define VOTER_H
#include "../include/queue.h"
typedef struct {
    int voterID;
    char *name;
    char *gender;
    int age;
    int hasVoted;
} Voter;
void registerVoter(int id, const char* name, const char* gender, int age,Queue *voterQueue);
void displayVoters(Queue *voterQueue);

#endif