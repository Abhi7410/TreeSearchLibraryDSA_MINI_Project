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


typedef struct pHeap
{
   int size;
   int capacity;
   PtrNode* Arr;  
}pHeap;
typedef struct pHeap* PtrHeap;

int IsEmpty(PtrHeap P);
void ProclateUp(PtrNode *Arr,int position,char* string);
void ProclateDown(PtrNode* Arr,int position,int size,char* string);
int DeleteTop(PtrHeap Pq,char* string);
void HeapInsert(PtrHeap Pq,PtrNode new,char* string);
PtrHeap Initialise_Heap(int capacity);
PtrNode assign_node(int d,int b,int c);
void insertNode(PtrNode * ParentArr,PtrNode new, int n);
void Initialise_Tree(int n, PtrNode* ParentArr);
void print_Tree( PtrNode* ParentArr,int n);
// bool DFScomparator(Node* a,Node* b);
void heapify(PtrNode Arr[], int i,int size);
// bool BFScomparator(Node* a,Node* b);
bool comparator(Node* a,Node* b,char *string);
void Print(PtrHeap P);

