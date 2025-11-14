#include "candidate.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Candidate* createCandidate(int id,const char* name,const char* party)
{
    Candidate* c=malloc(sizeof(Candidate));
    if(!c)return NULL;
    c->candidateID=id;
    strncpy(c->name,name,sizeof(c->name)-1);
    c->name[sizeof(c->name)-1]='\0';
    strncpy(c->party,party,sizeof(c->party)-1);
    c->party[sizeof(c->party)-1]='\0';
    c->voteCount=0;
    return c;
}

void registerCandidate(int id,const char* name,const char* party,TreeNode* candidateTree)
{
    Candidate* newCandidate=createCandidate(id,name,party);
    insert(candidateTree,newCandidate);
}

TreeNode* displayCandidates(TreeNode* max,TreeNode* root)
{
    if(root==NULL) return max;
    if(max==NULL) max=root;
    max=displayCandidates(max,root->left);
    if(root->data->voteCount>max->data->voteCount) max=root;
    printf("ID: %d, Name: %s, Party: %s, Votes: %d\n",
           root->data->candidateID,
           root->data->name,
           root->data->party,
           root->data->voteCount);
    max=displayCandidates(max,root->right);
    return max;
}

