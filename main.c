#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include "include/tree.h"
#include "include/candidate.h"
#include "include/voter.h"
#include "include/queue.h"

void clearscreen()
{
    for(int i=0;i<100;i++)
    {
        printf("\n");
    }
}
int main()
{
    printf("----------------------------------\n");
    printf("Online Voting System for Panchayat Elections\n");
    printf("----------------------------------\n");
    int choice;
    do
    {
        clearscreen();
        printf("Press 1 for adding new voter\n");
        printf("Press 2 for adding new candidate\n");
        printf("Press 3 to start voting\n");
        printf("Press 4 to display results\n");
        printf("Press 5 to exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                continue;
                break;
            case 2:
                continue;
                break;
            case 3:
                continue;
                break;
            default:
                printf("Invalid Choice\n");
        }
    } while (choice!=5);
    
    return 0;
}