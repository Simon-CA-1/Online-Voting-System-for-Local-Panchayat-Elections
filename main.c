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
        printf("|       Press 5 to see age demographics      |\n");
        printf("|       Press 6 to exit                      |\n");
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
                if(age<18)
                {
                    printf("Voter must be at least 18 years old to register.\n");
                    printf("Press Enter to continue...");
                    getchar();
                    getchar();
                    break;
                }
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
                printf("Age Demographics:\n");

                int total18_25 = 0, voted18_25 = 0;
                int total25_40 = 0, voted25_40 = 0;
                int total40plus = 0, voted40plus = 0;

                Node* curr = voterQueue->front;

                while(curr != NULL)
                {
                    int age = curr->data->age;
                    int voted = curr->data->hasVoted;

                    if(age >= 18 && age <= 25)
                    {
                        total18_25++;
                        if(voted) voted18_25++;
                    }
                    else if(age > 25 && age <= 40)
                    {
                        total25_40++;
                        if(voted) voted25_40++;
                    }
                    else if(age > 40)
                    {
                        total40plus++;
                        if(voted) voted40plus++;
                    }

                    curr = curr->next;
                }

                printf("\n18 - 25:\n");
                printf("Total voters: %d\n", total18_25);
                if(total18_25 > 0)
                    printf("Voted: %d (%.2f%%)\n",
                           voted18_25,
                           (voted18_25 * 100.0) / total18_25);
                else
                    printf("No voters in this group.\n");

                printf("\n25 - 40:\n");
                printf("Total voters: %d\n", total25_40);
                if(total25_40 > 0)
                    printf("Voted: %d (%.2f%%)\n",
                           voted25_40,
                           (voted25_40 * 100.0) / total25_40);
                else
                    printf("No voters in this group.\n");

                printf("\nAbove 40:\n");
                printf("Total voters: %d\n", total40plus);
                if(total40plus > 0)
                    printf("Voted: %d (%.2f%%)\n",
                           voted40plus,
                           (voted40plus * 100.0) / total40plus);
                else
                    printf("No voters in this group.\n");

                printf("\nPress Enter to continue...");
                getchar();
                getchar();
                break;
            case 6:
                continue;
                break;
            default:
                printf("Invalid Choice\n");
        }
    } while (choice!=6);
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
