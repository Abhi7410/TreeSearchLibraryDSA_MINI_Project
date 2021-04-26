#ifndef ____main_c____
#define ____main_c____

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <malloc.h>
#include "node.h"


int main()
{
    long int N;
    scanf("%ld", N);

    node Root;
    input_node(&Root);

    for (long int i = 1; i < N; i++)
    {
        node temp;

        //Allocate memory
        temp.children = malloc();
        ///////////////////////// Vivek -> Idk how to do this


        input_node(&temp);

        findParentAndInsert(&Root, &temp);
    }

    return 0;
}








#define ____main_c____