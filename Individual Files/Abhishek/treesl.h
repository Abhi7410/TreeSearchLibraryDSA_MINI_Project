#ifndef __treesearchlibrary__
#define __treesearchlibrary__
#include<stdbool.h>
typedef struct node
{
    int state_number;
    int value;
    int parent;

    // You (as a developer) can add any extra information here [Will not be touched by user]
    int depth, seen_time, num_children;
    struct node* children[10000];
} Node;

typedef struct node* PtrNode;
void input_node(Node* a);
void insertNode(PtrNode * ParentArr,PtrNode new, int n);
PtrNode* Initialise_Tree( int n);


///Vivek -> please check the code written by me, I have moved it to Main Frogram Files.
///Input and output taken care of




#endif
