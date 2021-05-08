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
{                              //priority queue for the implentation 
   int size;                    //size of the heap indicates the no. of elements in the heap
   int capacity;               //capacity is the maximum space for the heap table
   PtrNode* Arr;               //double pointer where PtrNode is pointer to node and pointing to array
}pHeap;
typedef struct pHeap* PtrHeap;

int IsEmpty(PtrHeap P);  //to check whether the heap is empty or not
void ProclateUp(PtrNode *Arr,int position,char* string);             // used in insertion in heap to make it a heap structute on the basis of comparator
void ProclateDown(PtrNode* Arr,int position,int size,char* string);  //used in deletion of top element
int DeleteTop(PtrHeap Pq,char* string);                              //deletion of the top element
void HeapInsert(PtrHeap Pq,PtrNode new,char* string);               //insertion in the heap contains proclate up function
PtrHeap Initialise_Heap(int capacity);                               
PtrNode assign_node(int d,int b,int c);                             //assigns three values
void insertNode(PtrNode * ParentArr,PtrNode new, int n);            //insertion of node in the table of pointers 
void Initialise_Tree(int n, PtrNode* ParentArr);                     //insitalise the tree else given in the .c file
void print_Tree( PtrNode* ParentArr,int n);
// bool DFScomparator(Node* a,Node* b);

// bool BFScomparator(Node* a,Node* b);
bool comparator(Node* a,Node* b,char *string);                     //three bool comparators DFS,BFSa and greedy
void Print(PtrHeap P);

typedef struct global_array               //global array contains 5 datas -->value is the visited state number,,,,,maxdepth --->is the depth of that node in the tree
                                          //sumdepth is the sum of all the depth od the node till that time , we wil use this to find average depth
{                                         //as we are not clear with the terminolgy of branching factor in our code brancing is only the no, of children nodes of that
                                            //that parent element
                                           //not sure for the visited children just thinking on how to do this as we visit the node we check how many children we have visited 
    int max_depth;                         //and choosing the max of them 
    float sumdepth;
    int branching_factor;
    int visited_children;
    int value;
}global_array;





#endif
