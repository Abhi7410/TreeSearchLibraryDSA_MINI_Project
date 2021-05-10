# IIITH_DSA_T2_Y1_2021_ProjectRepo_Team36_MiniProject1


<h1><b>ReadMe File. </b></h1>


<br>

We add data for the Program here. <br>








//amey's part

We start off in the main function by declaring a var num_nodes, for number of nodes. We ask for input from the user and initialise num_nodes with that value.

We then declare a var ParentArr of type struct PtrNode,which is an array of num_nodes cells . We allocate it sufficient memory so we can store the values.

Using a for loop,we first initialise it to NULL for all cells of the array.

We now use the Initialise_Tree function to initialise the tree,making nodes one after another based on the input.

We declare a var P of type struct PtrHeap and we initialise it using the Initialise_Heap function. We then give it as a pointer to P.

We then declare a var search_method of type char,which we take as input string to check the traversal.

We declare and initialise a global array for storing various parameters.

We declare an int seentime and initialise it to 0. We will use this to determine the number of times a node is traversed. We assign the value of int seentime to the pointer of the seen_time of struct ParentArr[0]. We then increment it.

We use HeapInsert function which inserts new nodes to the heap and then balancing the heap after each entry. 

Next,a for loop is used to initialise sumdepth of array for all elements.

We declare and initialise an int j = 1.

Using a while loop, with condition of function IsEmpty(P) not being 0. We do a bunch of assigning operations for array[j] and increment j.
The loop doesnt end there.

Within the loop , we declare and initialise an int i = 0.
We use a second while loop with the condition of int i being less than ParentArr[value - 1]->num_children. We /////////////Help here///////

The aforementioned outer and inner loops end.

As good programmers, we deallocate the memory allocated to Heap array,the Heap itself and to the parent array using the free() function.













<h1>Work Allocation</h1>
<br><br>
<table>
  <tr>
    <th>Serial No</th>
    <th>Team Member</th>
    <th>Work Allocated</th>  
    <th>Github Profile</th>
  </tr>
  <tr>
    <td>1</td>
    <td>Vivek Mathur</td>
    <td>Depth First Search(Comparator and Algo), A* search (Algo), Code merging, <br> Data Analysis lead and writer</td>
    <td> <a href="https://github.com/Grimoors">LINK</a></td>
  </tr>
  <tr>
    <td>2</td>
    <td>Karthick Ashwath</td>
    <td>Documentation</td>
    <td> <a href="https://github.com/KarthickAshwath">LINK</a></td>
  </tr>
  <tr>
    <td>3</td>
    <td>Abhishek Sharma</td>
    <td>Greedy Search Algorithm, Breadth First Search Algorithm, Code merging</td>
    <td> <a href="https://github.com/Abhi7410">LINK</a></td>
  </tr>
  <tr>
    <td>4</td>
    <td>Amey Kunte</td>
    <td>Documentation</td>
    <td> <a href="https://github.com/ameykun">LINK</a></td>
    
  </tr>
  <tr>
    <td>5</td>
    <td>Keerthana K.</td>
    <td>Greedy Search (Algorithm) , Iterative deepening depth-first search (Algorithm) </td>
    <td> <a href="https://github.com/keerthana747">LINK</a></td>
  </tr>

</table>
<br><br>

<h1>Timeline</h1>


<h1>Documentation</h1>


<h1>LOG-></h1>

XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

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
    
XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX 
        
        
