# Searching-A-Sorted-Table

Selection of Design Techniques:

The design techniques used here for the solving of this problem are quite straightforward.
1. We have to form a 2D array which represents a table with a 10x10 dimension size.
2. This represents the 100 cards arranged in a tabular fashion.
3. The next step is to formulate a sequence of 100 random numbers to be fitted into this 2D array, with the constraint, “n ≠0”.
4. The next step involves sorting this table row wise and column wise. This means we have to arrange each row and each column in ascending order.
5. Once we do this, we have to assign a random location to be searched by randomizing variables to get random index values.
6. A search algorithm is implemented and must find the value assigned to the random memory location. This step must be timed, and the number of iterations required to find the value must be counted. 
7. We need to design this search algorithm in such a way that the number of steps does not exceed 20.
8. After displaying all this information on the output screen, our program is now complete

Approach 1:

The first design technique used was to sort the 2D array of 100 randomized numbers and then perform a binary search operation on the sorted 2D array. This method’s computation time was noted and the number of steps to find the desired card was also measured.
The binary search process compares the target value to the middle element of the array. If they are not equal, the half in which the target cannot lie is eliminated and the search continues on the remaining half, again taking the middle element to compare to the target value, and repeating this until the target value is found.
In other words, searching for an element must follow the given steps:

Let ‘k’ be the element we’re trying to search for in the table and ‘c’ be the current element we’re processing in the array.

Step 1: Let the top right element be ‘c’.

Step 2: Looping statements (These statements occur recursively as a sequence of sub algoritms):

if c = k, then return position of c, since we found k in the given matrix.	

if c > k then move left to check all the elements smaller than c.

if c < k then move below to check elements greater than c.

Step 3: Repeat steps i to iii until you either find the value or return a false condition.
 If the search ends with the remaining half being empty, the target is not in the array.
 

The sorting algorithms used here is the standard sort function defined in the Standard Template Library or STL.
This sort algorithm sorts any given values from a range of addresses, which uses the following algorithm:

    for (int i = 0 ; i <n; i++)
    sort (mat[i], mat[i] + n);
    //Sorts all given rows from [startaddress, endaddress)
The sorting procedure involves a rudimentary matrix operation, which is the transposal of a matrix. 
The algorithm employed for transposal is defined as below:
 

    for (int i = 0; i<n; i++)
                      {
         for (int j = i + 1; i <n; i++)
                       {
           int temp = mat[i][j];
            mat[i][j] = mat[j][i];
           mat[j][i] = temp;
                        }
                       }
To sort a matrix, we need to arrange the elements in ascending order, both row and column wise.
For this, we employ 3 major steps to carry out the sorting procedure:
1.	Sort each row of the matrix.
2.	Transpose the Matrix
3.	Again, sort each row of the Matrix
4.	Again, transpose the matrix.
After the completion of this step, we use the binary search method (as discussed above) to find the card.


Approach 2: 

As there are 2 rudimentary functions to be performed in this program, the only 2 functions that can be changed are the sorting method or the searching method.

The second design technique involves changing the searching method of the 2D array of the card lattice.

Instead of using a binary search technique which has a linear time complexity method, we switched to use a divide and conquer mechanism, which employs the following steps:

1.	Find the middle element present in the matrix.
2.	If the middle element is same as key return back the position.
3.	If middle element is lesser than key then,

         i.	Search submatrix on lower side of middle element.

        ii.	Search submatrix on right hand side of middle element

4. If middle element is greater than key then, 

        i.	 search vertical submatrix on left side of middle element.

        ii.	 search submatrix on right hand side.		

If middle element is lesser than key then,

    i.	Search submatrix on lower side of middle element.

    ii.	Search submatrix on right hand side of middle element

If middle element is greater than key then, 
  
    i.	Search vertical submatrix on left side of middle element.

    ii.	Search submatrix on right hand side.		
 
Limitations and further enhancements:

Searching in a sorted matrix is a difficult task, as one has to keep into mind the rows and columns already covered and the remaining rows and columns to be searched. This requires a good approach, and most optimal solution is dependent on several factors, some of which are outside of our ability to control.
Randomizing and assigning clock values also requires the use of multiple functions that are not always 100% accurate due to the header file limitations as they are quite old and some functions are not applicable as they have been designed for older systems.

This method of searching and sorting across a table can be applied to a table size of any length. The way of solving any such problem can have multiple of ways of evaluating the same result. This table could be of 400 or 10000 elements, and the logic would remain exactly the same.
We could allow for a better method of searching, or a faster one. The same can be said for the sorting process too, as there are better methods of sorting rather than transposing and sorting each row.


References:


[1] Binary Search, https://en.wikipedia.org/wiki/Binary_search_algorithm

[2] Search element in a sorted matrix, https://www.geeksforgeeks.org/search-element-sorted-matrix/

[3] Row wise sorting in 2D array, https://www.geeksforgeeks.org/row-wise-sorting-2d-array/

[4] Introduction to the design and analysis of algorithms, by Anany Levitin, 3rd Edition, Pearson
Education, 2011.

[5] Design and analysis of algorithm, by A.M Padma Reddy

[6] Sorting a matrix, https://www.faceprep.in/c/sorting-a-matrix/

