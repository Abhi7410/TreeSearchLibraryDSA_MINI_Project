#include "treesl.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool node_comparator(Node *a, Node *b)
{
    // User puts in the node comparator here
    return (a->value < b->value); // A sample comparator
}

PtrNode assign_node(int d,int b,int c)
{
    PtrNode patakha = (PtrNode)malloc(sizeof(Node));
    patakha->state_number = d;
    patakha->value = b;
    patakha->parent = c;
    patakha->seen_time = 0;
    return patakha;
}


PtrNode Initialise_Tree(int n, PtrNode* ParentArr)
{
  PtrNode head = NULL;
  PtrNode new_bomb;
  for (int i = 0; i < n; i++)
  {
     int sn,val,parent;
     scanf("%d %d %d",&sn,&val,&parent);
     new_bomb = assign_node(sn,val,parent);
     insertNode(ParentArr,new_bomb,n);

     if (i==0)
     {
        head = new_bomb;
     }
  } 
 return head;
}

void insertNode(PtrNode *ParentArr, PtrNode new, int n)
{
    int Depth;
    if (new->parent == -1)
    {
        ParentArr[0] = new;
        return;
    }
    int temp = 0;
    while (ParentArr[temp] != NULL && temp < n - 1 && ParentArr[temp]->state_number != new->parent)
    {
        temp++;
    }
    if (ParentArr[temp]->state_number == new->parent)
    {
        int i = 0;
        while (ParentArr[temp]->children[i] != NULL)
        {
            i++;
        }
        ParentArr[temp]->children[i] = new;
        ParentArr[temp]->num_children++;
        Depth = ParentArr[temp]->depth;
        new->depth = Depth + 1;

        while (ParentArr[temp] != NULL)
        {
            temp++;
        }
        ParentArr[temp] = new;
    }
 
}
void print_Tree(PtrNode *ParentArr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d %d %d    \n", ParentArr[i]->state_number, ParentArr[i]->value, ParentArr[i]->parent);
        int j = 0;
        while (ParentArr[i]->children[j] != NULL)
        {
            printf("(%d %d %d )  ", ParentArr[i]->children[j]->state_number, ParentArr[i]->children[j]->value, ParentArr[i]->children[j]->parent);
            j++;
        }
        printf("\n");
    }
}
    
