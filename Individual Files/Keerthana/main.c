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

    int a;
    int Depth = 0;
    for (int i = 0; i < N; i++)
    {
        if (root[i].parent != (-1))
        {
            a = (Root[(Root[i].parent - 1)].children);
            (Root[(Root[i].parent - 1)].children)++;
            Root[(Root[i].parent - 1)].children[a] = &Root[i];
            nodePtr ROOT = &Root[i];
            while (ROOT->parent != (-1))
            {
                Depth = Depth + 1;
                int D = ((ROOT->parent) - 1);
                ROOT = &(Root[D]);
            }
            root[i].Depth = Depth;
        }
    }
    return 0;
}
