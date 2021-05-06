#ifndef ____node_c____
#define ____node_c____

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <malloc.h>
#include "node.h"

bool node_comparator(node *a, node *b)
{
    // // User puts in the node comparator here
    // return a->value < b->value; // A sample comparator

    //DFS INorder, Seen time pe
    //BFS Level order ,
}

void input_node(node *a)
{
    // inputs the information of one node. Use this in a loop to input all the nodes.
    scanf("%d %d %d", &(a->state_number), &(a->value), &(a->parent));
}

void findParentAndInsert(node *Root, node *temp)
{
    ////***Recursive use is depreciated and shall likely be removed in a later update.
    // Find the FIRST node in children array which is Empty
    int i;
    for (i = 0; i < 10000; i++)
    {
        if (Root->children[i] == NULL)
            break;
    }

    //scan Root and insert into Children array at 'i' if the Root state number is the parent value
    if (Root->state_number == temp->parent)
    {

        Root->children[i] = temp;
    }
    else
    {
        //Scan Children in the same way, 
        
        for (int j = 0; j <=i; j++)
        {
            findParentAndInsert(Root->children[j],temp);
        }
    }
    Root->depth++;
}


#endif