# IIITH_DSA_T2_Y1_2021_ProjectRepo_Team36_MiniProject1


<h1><b>ReadMe File. </b></h1>


We add data for the Program here. <br>






<h1>LOG-></h1>

XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

<h2>Entry 1 ->   --> Entry by Vivek Mathur</h2>

<b>Actions Taken</b>

<i>(in Individual folder)</i><br>
Added Basic files, Restructured into Standard Form, Added a main.c and A Way to input into Tree.<br>
Added the find Parent and insert function, It is currently recursive, thinking of ways to make it iterative.<br>
<br>
<br>
Planning to add a print function for to test the Input function.

<b>Documentation :__</b>


The Data Structure that WE are Using initally --> As of 26/04/12<br>
______________________________________________________________________________________________________________________________________

                                       Data (Graph) Strcuture
                                        
                                        Tree - General, 
                                        
______________________________________________________________________________________________________________________________________

                                        node Root;
______________________________________________________________________________________________________________________________________                                        
                                        
                                        
                                        --------
                                       |  Node  | <---- Root Node
                                        --------
                                            |
                                            |
            ________________________________|____________________________    .........___________.............. 10000 terms
           |                                   |                                          |
           |                                   |                                          |
         
         Pointer                            Pointer                                     Pointer
      Root->children[0]                 Root->children[1]                           Root->children[i]
           
           
        --------                            --------  
       |  Node  | <----Child Node [0]      |  Node  | <----Child Node [1]     .......... NULL   .......... 
        --------                            --------
        
            |                                  |
            |                                  |
            |                                  |
           ...                                ...
           
           
______________________________________________________________________________________________________________________________________           
        
   
   There are other Stubs associated with each root : Namely :-<br>

    
    
    int depth, seen_time, number_of_children;
    
    int state_number;     //  "NAME" of a node<br>
    int value;            //    Data of graph, Used by comparator<br>
    int parent;           //    Holds the name of the "Parent"<br>
    
    // We shall remove the 'i' in the main .c and node.h soon.
    
XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX    
        
        
