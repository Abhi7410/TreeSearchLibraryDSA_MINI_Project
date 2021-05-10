Just for the project

Frst we have to implement the graph in which we will make a array of pointers which are pointing to the boxes .
now every boxing numbering from 1 to n they all point to children array which has maximum capacity of 10000 (whatever)
initially all have seen times == 0
so basically the given sample is such
1----->2,4,7
2----->3,6
3----->
4----->5
5----->8,9
6------>
7------>10
 we will make an array to show the traversal
 frst put 1 in that array and now make heap(so called priority queue/ don't panic by this name )
 heap will be formed by 2,4,7 and we will assign seen time to these three ==1
    
    2
   4  7
   now all have same seen times so 2 will be popped out and inserted in the traversal array which becomes 1,2
   now it looks like
   4
  7
  now as we pop 2 we will insert 2's children in the prioroty queue which are 3,6 and assign seen times to be 2
  4
 7 3 
6
now here comes the role of bool comparator which is
for BFS    return (a->seentime < b->seentime) 
for DFS    return (a->seentime > b->seentime)
for greedy search (a->value > b->value)

so now i m taking example for DFS
so 3 and 6 has 2 as seen time so we will heapify and the swaps that we will aplly on the basis of bool comparator , so in this
case heaps becomes
   3
 6   4
7
now we pop 3 and assign 3 seen time to its children , fortunately 3 does not have children array becomes 1,2,3
now 6 pops  array is 1 , 2 , 3 , 6
4, 7 remains in the heap and both have same seen time 1 now 4 will be popped and goes to traversal array 1,2,3,6,4
children of 4 is 5 so seen time will be 3
now 
 7            5 (after heapify)
5    --->    7
 5 will be popped and goes to 1,2,3,6,4,5
 8,9 will be given seen time as 4
    7                  8
   8 9 ---->          9  7
as we go the array becomes
1,2,3,6,4,5,8,9,7,10 this array is the DFS traversal of the tree 

same we can do for both others

 for analysis part
 
 max depth
 avg depth 
 branching factor
 
 
 
 
