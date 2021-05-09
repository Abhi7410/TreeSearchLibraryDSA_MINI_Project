#include "treesl.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//It is a bool function take two node pointers and one string , in this we just return on the basis of string
//the returning bools are on the basis of seentimes of node and values of nodes, for BFS and DFS we are using seentimes
// and for greedy search we use value of node for comparator
bool comparator(Node *a, Node *b, char *string)
{
    if (strcmp(string,"BFS") == 0)
    {
        return (b->seen_time > a->seen_time);
    }
    if (strcmp(string,"DFS") == 0)
    {
        return (a->seen_time > b->seen_time);
    }
    if (strcmp(string,"GREEDY") == 0)
    {
        return (a->value > b->value);
    }
   
}

void swap(PtrNode *a, PtrNode *b)
{
    PtrNode temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

//In this function we allocate a node , assigning three values d,b,c as state number , value and parent number respectively
//intially we make seentime for every node to be zero and then it returns the node

PtrNode assign_node(int d, int b, int c)
{
    PtrNode patakha = (PtrNode)malloc(sizeof(Node));
    patakha->state_number = d;
    patakha->value = b;
    patakha->parent = c;
    patakha->seen_time = 0;
    return patakha;
}



//It takes a pointer to the array of pointer nodes and n as arugument, it is none other than assigning the nodes after taking the inputs
// as we take inputs and assign the nodes these values with the help of previous function and then we use insertNode function which finds the
// the prent of the node by comparing state no, and parent and we return void
void Initialise_Tree(int n, PtrNode *ParentArr)
{
//     PtrNode head = NULL;
    PtrNode new_bomb;
    for (int i = 0; i < n; i++)
    {
        int sn, val, parent;
        scanf("%d %d %d", &sn, &val, &parent);
        new_bomb = assign_node(sn, val, parent);
        insertNode(ParentArr, new_bomb, n);

    }
    return;
}


//This is the main function FOR  a making a tree it takes a parentarr that is array of pointers and number of nodes to be inserted and new node that is going to be inserted
//So basically it will take the node and compare on the basis of its parent , intially if the parent is -1 then it becomes the head node , and further when a node comes
// we compare its parent with the existing node's statenumber if it is present then it goes in the children array of that state number , and further the node is added
//in the parentarr table as we find a NULL space/
void insertNode(PtrNode *ParentArr, PtrNode new, int n)
{
    int Depth;
    if (new->parent == -1)
    {
        ParentArr[0] = new;   //frst node to be the head one
        return;
    }
    int temp = 0;
    while (ParentArr[temp] != NULL && temp < n - 1 && ParentArr[temp]->state_number != new->parent)
    {
        temp++;             //check for the parent and Null spce in the parentArr 
    }

    if (ParentArr[temp]->state_number == new->parent)
    {
        int i = 0;                                           //if we fount parent and state no. to be same then we traverse the children array as we wound NULL pointer
                                                              //we place the node there , increase the children array of that parent. and modiffies the depth
        while (ParentArr[temp]->children[i] != NULL)          
        {
            i++;
        }
        ParentArr[temp]->children[i] = new;
        ParentArr[temp]->num_children++;
        Depth = ParentArr[temp]->depth;
        new->depth = Depth + 1;

        while (ParentArr[temp] != NULL)               //if we found the valid parent than we insert in the children array and as we go we will add the node in the parentArr too
        {
            temp++;
        }
        ParentArr[temp] = new;
    }
}

//basicaly it prints the tree , the sample is given below for the fiven test case
// 1 5 -1   (3)
//  ------ >  (2 3 1 )  (4 1 1 )  (7 20 1 )  
// 2 3 1    (2)
//  ------->        (3 10 2 )  (6 21 2 )  
// 3 10 2    (0)
//---------->
// 4 1 1    (1)
// ----------> (5 6 4 )  
// 5 6 4    (2)
// ---------> (8 11 5 )  (9 2 5 )  
// 6 21 2    (0)
//--------->
// 7 20 1    (1)
// ---------->  (10 4 7 )  
// 8 11 5    (0)
//----------->
// 9 2 5    (0)
//---------->
// 10 4 7    (0)
//--------->
void print_Tree(PtrNode *ParentArr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d %d %d    (%d)\n", ParentArr[i]->state_number, ParentArr[i]->value, ParentArr[i]->parent, ParentArr[i]->num_children);
        int j = 0;
        while (ParentArr[i]->children[j] != NULL)
        {
            printf("(%d %d %d )  ", ParentArr[i]->children[j]->state_number, ParentArr[i]->children[j]->value, ParentArr[i]->children[j]->parent);
            j++;
        }
        printf("\n");
    }
}
//Heap initialisation or priority queue takes capacity as input where capacity is the maximim size allocated
// intialises it with size == 0, capacity to be the argumented capacity
//we allocate array and will free this to remove the memory leak in the main program
// it return the pointer to heap


PtrHeap Initialise_Heap(int capacity)
{
    PtrHeap Pq = (PtrHeap)malloc(sizeof(pHeap));
    Pq->size = 0;
    Pq->capacity = capacity;
    Pq->Arr = (PtrNode *)malloc(capacity * sizeof(PtrNode));
    return Pq;
}
void HeapInsert(PtrHeap Pq, PtrNode new,char* string)   //argument as priority queue, new node to insert, string to select the comparator
{
    Pq->Arr[Pq->size] = new;                        //assigns in the array at the last of the table             
    ProclateUp(Pq->Arr, Pq->size,string);           //as we insert in the heap the structure of heap changes to non-heap so we apply proclate heap to make it heap again
    Pq->size++;                                     //we incrase the size of the heap
}
void ProclateUp(PtrNode *Arr, int position,char* string)
{
    int parent = (position - 1) / 2;
    if (position != 0)
    {
        if (comparator(Arr[position], Arr[parent],string))  //using the comparator on the position and parent and swap if it is 1
        {
            PtrNode temp = Arr[position];
            Arr[position] = Arr[parent];
            Arr[parent] = temp;

            ProclateUp(Arr, parent,string);       //and here we apply recursion to go down one by one along the child in heap(binary heap)
        }
    }
}
int DeleteTop(PtrHeap Pq,char* string)         //On the basis of comparator the top element becomes the desired one
{                                               //suppose for BFS we are considering lowest seentime, the element in the heap with the lowest seentime
    int value = Pq->Arr[0]->state_number;       // will come the top and we pop it from the heap and decreases the size by one
                                                //After poping out the top element , the heap again has to recover the heap structure so we use recursion
    Pq->Arr[0] = Pq->Arr[Pq->size - 1];         //based proclate down function to make it heap again
    Pq->size--;                                 //it returns the value which is the state no. of the node
    ProclateDown(Pq->Arr, 0, Pq->size,string);  //the value returned will be printed in the global array and will be used to find the children too
    return value;
}
void ProclateDown(PtrNode *Arr, int position, int size,char* string)
{
    int lchild = 2 * position + 1;                            //after popping out the top element we manage the below heap to make it valid heap structure
    int rchild = lchild + 1;                                  // following basic methods of heap comparing with left and right and all
    int small = -1;
    if (lchild < size)
    {
        small = lchild;
    }
    if (rchild < size && comparator(Arr[rchild], Arr[lchild],string))
    {
        small = rchild;
    }
    if (small != -1 && comparator(Arr[small], Arr[position],string))
    {
        PtrNode temp = Arr[position];
        Arr[position] = Arr[small];
        Arr[small] = temp;
        ProclateDown(Arr, small,size,string);
    }
}
int IsEmpty(PtrHeap P)
{
    if (P->size == 0)
    {
        return 0;              //just check the priority queue is empty or not
    }
    else
    {
        return 1;
    }
}

void Print(PtrHeap P)                       //just for traversal check not going to be used in the interface
{
    for (int i = 0; i < P->size; i++)
    {
        printf("%d (%d) ", P->Arr[i]->state_number, P->Arr[i]->depth);
    }
    printf("\n");
}
    
