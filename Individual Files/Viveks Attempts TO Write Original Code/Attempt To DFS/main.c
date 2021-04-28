#ifndef ____main_c____
#define ____main_c____

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <malloc.h>
#include "node.h"

int main()
{

    //Taking Input
    long int N,i,value;
    scanf("%ld", N);

    node Root;
    Root.depth=0;
    Root.height=0;
    input_node(&Root);
    Root.seen_time=1;

    for (long int i = 1; i < N; i++)
    {
        node temp;

        //Allocate memory
        //temp.children = (node*)malloc(10000*sizeof(node));
        ///////////////////////// Vivek -> Idk how to do this

        input_node(&temp);

        findParentAndInsert(&Root, &temp);
    }

    puts("Input value to search for.");
    scanf("%ld",&value);
    //Confirming Input - Printing tree once

    printf("%d\n", Root.value);
    //TreePrintLOT(&Root);

    //Processing Input - Searching

    node * AnswerNode= DFS(&Root,value);

    if(AnswerNode==NULL)
    {
        printf("The node wasn't found, unfortunately. please Try again");
    }
    else
    {
        printf("' %ld ' was found at position (state number) %d in the tree at depth = %d and height = %d with parent = %d state",value,AnswerNode->state_number,AnswerNode->depth,AnswerNode->height,AnswerNode->parent);
    }

    return 0;
}

node *DFS(node *Root, long int val)
{
    if (Root == NULL)
    {
        return NULL;
    }
    else
    {

        if (val == Root->value)
        {
            return Root;
        }
        else
        {
            int i = 0;
            node* rValue=NULL;
            while (i < 10000)
            {
                if (Root->children[i] == NULL || rValue != NULL)
                {
                    break;
                }
                else
                {
                    rValue=DFS(Root,val);
                }
            }
            return rValue;

        }
    }
}
// void TreePrintLOT(node * Root)
// {

//     int i=0;
//     while(Root->children[i]!=NULL)
//     {
//         printf("%d\t",Root->children[i]->value);
//         i++;
//     }
//     printf("")
//     i=0;
//     while(Root->children[i]!=NULL)
//     {
//         TreePrintLOT(Root->children[i]);
//         i++;
//     }
//}

#endif