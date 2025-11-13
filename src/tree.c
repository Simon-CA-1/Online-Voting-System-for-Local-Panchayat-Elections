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

void insert(TreeNode* root, Candidate* data)
{
    if(root==NULL)
    {
        root=createNode(data);
        return;
    }
    else
    {
        TreeNode* prev=root;
        while(root!=NULL)
        {
            prev=root;
            if(data->candidateID<root->data->candidateID)
            {
                root=root->left;
            }
            else
            {
                root=root->right;
            }
        }
        if(data->candidateID < prev->data->candidateID)
        {
            prev->left=createNode(data);
        }
        else
        {
            prev->right=createNode(data);
        }
    }
}