#ifndef CANDIDATE_TREE_H
#define CANDIDATE_TREE_H

typedef struct TreeNode TreeNode;

typedef struct Candidate {
    int candidateID;
    char name[50];
    char party[50];
    int voteCount;
} Candidate;

Candidate* createCandidate(int id,const char* name,const char* party);
void registerCandidate(int id,const char* name,const char* party,TreeNode* candidateTree);
TreeNode* displayCandidates(TreeNode* max,TreeNode* root);
#endif
