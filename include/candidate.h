#ifndef CANDIDATE_TREE_H
#define CANDIDATE_TREE_H
#include "./tree.h"
typedef struct Candidate {
    int candidateID;
    char name[50];
    char party[50];
    int voteCount;
} Candidate;

Candidate* createCandidate(int id, const char* name, const char* party);
void displayCandidates(TreeNode* root);

#endif
