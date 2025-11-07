#ifndef TREE_H
#define TREE_H
#include "./candidate.h"
typedef struct TreeNode 
{
    Candidate* data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(Candidate* data);
void insert(TreeNode* root, Candidate* data);
TreeNode* search(TreeNode* root, int candidateID);
#endif