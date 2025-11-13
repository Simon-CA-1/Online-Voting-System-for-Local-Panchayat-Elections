#include "../include/tree.h"
#include <stdio.h>
#include <stdlib.h>

TreeNode* createNode(Candidate* data) 
{
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (!newNode) 
    {
        printf("Memory allocation failed\n");
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

