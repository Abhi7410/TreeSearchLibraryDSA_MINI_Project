#include "treesl.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
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
PtrNode assign_node(int d, int b, int c)
{
    PtrNode patakha = (PtrNode)malloc(sizeof(Node));
    patakha->state_number = d;
    patakha->value = b;
    patakha->parent = c;
    patakha->seen_time = 0;
    return patakha;
}

void Initialise_Tree(int n, PtrNode *ParentArr)
{
    PtrNode head = NULL;
    PtrNode new_bomb;
    for (int i = 0; i < n; i++)
    {
        int sn, val, parent;
        scanf("%d %d %d", &sn, &val, &parent);
        new_bomb = assign_node(sn, val, parent);
        insertNode(ParentArr, new_bomb, n);

        if (i == 0)
        {
            head = new_bomb;
        }
    }
    return;
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

PtrHeap Initialise_Heap(int capacity)
{
    PtrHeap Pq = (PtrHeap)malloc(sizeof(pHeap));
    Pq->size = 0;
    Pq->capacity = capacity;
    Pq->Arr = (PtrNode *)malloc(capacity * sizeof(PtrNode));
    return Pq;
}
void HeapInsert(PtrHeap Pq, PtrNode new,char* string)
{
    Pq->Arr[Pq->size] = new;
    ProclateUp(Pq->Arr, Pq->size,string);
    Pq->size++;
}
void ProclateUp(PtrNode *Arr, int position,char* string)
{
    int parent = (position - 1) / 2;
    if (position != 0)
    {
        if (comparator(Arr[position], Arr[parent],string))
        {
            PtrNode temp = Arr[position];
            Arr[position] = Arr[parent];
            Arr[parent] = temp;

            ProclateUp(Arr, parent,string);
        }
    }
}
int DeleteTop(PtrHeap Pq,char* string)
{
    int value = Pq->Arr[0]->state_number;
    Pq->Arr[0] = Pq->Arr[Pq->size - 1];
    Pq->size--;
    ProclateDown(Pq->Arr, 0, Pq->size,string);
    return value;
}
void ProclateDown(PtrNode *Arr, int position, int size,char* string)
{
    int lchild = 2 * position + 1;
    int rchild = lchild + 1;
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
        return 0;
    }
    else
    {
        return 1;
    }
}

void Print(PtrHeap P)
{
    for (int i = 0; i < P->size; i++)
    {
        printf("%d (%d) ", P->Arr[i]->state_number, P->Arr[i]->depth);
    }
    printf("\n");
}
    
