#include "treesl.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
int main()
{
  int num_nodes;
  scanf("%d", &num_nodes);       //NO. OF TEST RUNS OR NODES GOING TO BE INSERTED OR NODES FOR CHECK

  // printf("ENTER THE DATA \n");
  PtrNode *ParentArr = (PtrNode *)malloc(num_nodes * (sizeof(PtrNode))); /  //ALLOCATING MEMORY TO PARENTARR (ARRAY OF POINTERS)

  for (int i = 0; i < num_nodes; i++)
  {
    ParentArr[i] = NULL;          //INTIALISING EVERY NODE POINTING TO THE ARRAY BY NULL
  }
  Initialise_Tree(num_nodes, ParentArr);   //INTIALISING THE TREE TAKING THE INPUT AND INSERTING THEM TO MAKE THE TREE NODE BY NODE
  // print_Tree(ParentArr,num_nodes);
  PtrHeap P;
  P = Initialise_Heap(num_nodes);    //INITALIING HEAP AND GIVING IT AS A POINTER TO THE P

  char search_method[10];             //TAKINNG AS INPYT THE STRING TO CHECK THE TRAVERSAL
  scanf("%s", search_method);

  global_array array[num_nodes + 1];  //INTIALISING THE GLOBAL ARRAY FOR STORING THE DIFFERENT PARAMTERES

  //array[j].num_children

  int seentime = 0;
  ParentArr[0]->seen_time = seentime;
  seentime++;

  HeapInsert(P, ParentArr[0], search_method);
  // float sumdepth[num_nodes];
  for (int i = 0; i <= num_nodes; i++)
  {
    array[i].sumdepth = 0;
  }

  int j = 1;

  while (IsEmpty(P) != 0)
  {

    int value = DeleteTop(P, search_method);
    array[j].value = value;
    array[j].max_depth = ParentArr[value - 1]->depth;
    array[j].sumdepth = array[j - 1].sumdepth + ParentArr[value - 1]->depth;
    array[j].branching_factor = ParentArr[value - 1]->num_children;
  
    j++;
    int i = 0;
    while (i < ParentArr[value - 1]->num_children)
    {
      PtrNode new = ParentArr[value - 1]->children[i];
      new->seen_time = seentime;
      HeapInsert(P, new, search_method);
      seentime++;
      i++;
    }
    //  Print(P);
  }


  free(P->Arr);        // FREE THE MEMORU ALLOCATED TO THE HEAP ARRAY 
  free(P);             //FREE THE MEMORY ALLOCATED TO THE  HEAP ITSELF
  free(ParentArr);     //FREE THE MEMORY ALLOCATED TO THE PARENT ARRAY
  


  for (int i = 1; i < num_nodes; i++)                //chosing the maximum depth one by one 
  {
    int max = array[i].max_depth;
    if (array[i].max_depth > array[i+1].max_depth  )
    {
      array[i+1].max_depth = array[i].max_depth;
    }
    
  }
  
   printf("ITERATION\t");
    printf("VISIT-STATE\t");
    printf("\t\tBRANCHING-FACT\t");
     printf("\tMAX-DEPTH\t");
      printf("\tAVG-DEPTH\n");
 
  for (int i = 1; i <= num_nodes; i++)
  {
    printf("%d\t\t\t ",i);
    printf("%d\t\t\t",array[i].value);
    printf("%d \t\t\t",array[i].branching_factor);
     printf("%d\t\t\t",array[i].max_depth);
      printf("%g\n",(array[i].sumdepth)/i);
 
  }
  printf("\n");
}
