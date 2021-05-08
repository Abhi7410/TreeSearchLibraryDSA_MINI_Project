#include "treesl.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
int main()
{
  int num_nodes;
  scanf("%d", &num_nodes);

  printf("ENTER THE DATA \n");
  PtrNode *ParentArr = (PtrNode *)malloc(num_nodes * (sizeof(PtrNode))); // for taking the inputs

  for (int i = 0; i < num_nodes; i++)
  {
    ParentArr[i] = NULL;
  }
  Initialise_Tree(num_nodes, ParentArr);

  PtrHeap P;
  P = Initialise_Heap(num_nodes);

  char search_method[10];
  scanf("%s", search_method);

  global_array array[num_nodes + 1];

  //array[j].num_children

  int seentime = 0;
  ParentArr[0]->seen_time = seentime;
  seentime++;

  HeapInsert(P, ParentArr[0], search_method);
  float sumdepth[num_nodes];
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
    // sumdepth[j] = sumdepth[j-1] + ParentArr[value-1]->depth;

    // printf("done %d",);    //gives me state number
    // printf(" %d      %d       %g\n", value,ParentArr[value-1]->depth,sumdepth[j]/j);
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
  for (int i = 1; i <= num_nodes; i++)
  {
    printf("%d           %d             %d             %d               %g \n", i, array[i].value, array[i].max_depth, array[i].branching_factor, (array[i].sumdepth) / i);
  }
}
