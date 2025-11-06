#ifndef VOTER_H
#define VOTER_H

typedef struct {
    int voterID;
    char *name;
    char *gender;
    int age;
    int hasVoted;
} Voter;
void registerVoter(int id, const char* name, const char* gender, int age);
void displayVoters();

#endif