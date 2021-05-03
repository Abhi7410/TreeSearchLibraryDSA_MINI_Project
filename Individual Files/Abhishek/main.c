#include "treesl.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main()
{
    int num_nodes;
    scanf("%d",&num_nodes);
   
  
    printf("ENTER THE DATA \n");
   PtrNode* ParentArr = (PtrNode*)malloc(num_nodes*(sizeof(PtrNode)));

   for ( int i = 0; i < num_nodes; i++)
   {
     ParentArr[i] = NULL;
   }
   
   PtrNode head = Initialise_Tree(num_nodes,ParentArr);


  

   print_Tree(ParentArr,num_nodes); 


}
