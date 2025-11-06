#ifndef CANDIDATE_TREE_H
#define CANDIDATE_TREE_H

typedef struct Candidate {
    int candidateID;
    char name[50];
    char party[50];
    int voteCount;
    struct Candidate* left;
    struct Candidate* right;
} Candidate;

Candidate* insertCandidate(Candidate* root, int id, const char* name, const char* party);
Candidate* searchCandidate(Candidate* root, int id);
void displayCandidatesInOrder(Candidate* root);
void incrementVoteCount(Candidate* root, int id);
void freeCandidateTree(Candidate* root);

#endif
