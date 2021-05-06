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
PtrNode assign_node(int d,int b,int c);
void insertNode(PtrNode * ParentArr,PtrNode new, int n);
PtrNode Initialise_Tree(int n, PtrNode* ParentArr);
void print_Tree( PtrNode* ParentArr,int n);






#endif
