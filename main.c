#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "candidate.h"
#include "voter.h"
#include "queue.h"

void clearscreen();

int main()
{
    int choice;
    Queue *voterQueue=createQueue();
    TreeNode* candidateTree=NULL;
    do
    {
        clearscreen();
        printf("----------------------------------------------\n");
        printf("|Online Voting System for Panchayat Elections|\n");
        printf("----------------------------------------------\n");
        printf("|       Press 1 to add new voter             |\n");
        printf("|       Press 2 to add new candidate         |\n");
        printf("|       Press 3 to start voting              |\n");
        printf("|       Press 4 to display results           |\n");
        printf("|       Press 5 to exit                      |\n");
        printf("----------------------------------------------\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter Voter name: ");
                char name[50];
                scanf("%s", name);
                printf("Enter Voter ID: ");
                int voterID;
                scanf("%d", &voterID);
                printf("Enter Voter Age: ");
                int age;
                scanf("%d", &age);
                printf("Enter Voter Gender: ");
                char gender[10];
                scanf("%s", gender);
                Voter* newVoter = createVoter(voterID, name, gender, age);
                enqueue(voterQueue, newVoter);
                break;
            case 2:
                printf("Enter Candidate name: ");  
                char cname[50];
                scanf("%s", cname);
                printf("Enter Candidate ID: ");
                int candidateID;
                scanf("%d", &candidateID);
                printf("Enter Candidate Party: ");
                char party[50];
                scanf("%s", party);
                Candidate* newCandidate = createCandidate(candidateID, cname, party);
                candidateTree=insert(candidateTree, newCandidate);
                break;
            case 3:
                printf("Voting started...\n");
                Node* temp=voterQueue->front;
                while(temp!=NULL)
                {
                    printf("Voter ID: %d, Name: %s, please cast your vote.\n",
                           temp->data->voterID,
                           temp->data->name);
                    int voteID;
                    printf("Enter Candidate ID to vote for: ");
                    scanf("%d", &voteID);
                    TreeNode* candidateNode = search(candidateTree, voteID);
                    if(candidateNode!=NULL)
                    {
                        candidateNode->data->voteCount++;
                        temp->data->hasVoted=1;
                        printf("Vote casted successfully for %s.\n", candidateNode->data->name);
                    }
                    else
                    {
                        printf("Invalid Candidate ID. Vote not counted.\n");
                    }
                    temp=temp->next;
                }
                break;
            case 4:
                printf("Election Results:\n");
                TreeNode* winner=displayCandidates(NULL, candidateTree);
                if(winner!=NULL)
                {
                    printf("Winner is %s from %s with %d votes.\n",
                           winner->data->name,
                           winner->data->party,
                           winner->data->voteCount);
                }
                else
                {
                    printf("No candidates available.\n");
                }
                printf("Press Enter to continue...");
                getchar();
                getchar();
                break;
            case 5:
                continue;
                break;
            default:
                printf("Invalid Choice\n");
        }
    } while (choice!=5);
    freeQueue(voterQueue);
    freeTree(candidateTree);
    return 0;
}

void clearscreen()
{
    for(int i=0;i<100;i++)
    {
        putchar('\n');
    }
}
