#include "treesl.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool node_comparator(Node *a, Node *b)
{
    // User puts in the node comparator here
    return (a->value < b->value); // A sample comparator
}

void input_node(Node* a)
{
    scanf("%d %d %d",&(a->state_number),&(a->value),&(a->parent));
}



void insertNode(PtrNode * ParentArr,PtrNode new, int n)
{
    int Depth;
    if (new->parent == -1)
    {
       ParentArr[0] = new;
       return;
    }
    int temp = 0;
    while (ParentArr[temp]!=NULL && temp<n-1 && ParentArr[temp]->state_number!= new->parent)
    {
      temp++;
    }
    if (ParentArr[temp]->state_number == new->parent)
    {
        int i = 0;
        while (ParentArr[temp]->children[i]!=NULL)
        {
            i++;
        }
        ParentArr[temp]->children[i] = new;
        ParentArr[temp]->num_children++;
        Depth = ParentArr[temp]->depth;
        new->depth = Depth +1;

        while (ParentArr[temp]!=NULL)
        {
            temp++;
        }
        ParentArr[temp] = new;
    }
    if (ParentArr[temp]==NULL)
    {
       printf("Parent not found\n");
    }
    
}
