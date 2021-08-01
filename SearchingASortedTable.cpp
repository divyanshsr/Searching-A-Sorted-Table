/*
		Searching a Sorted Table
One hundred different numbers are written on 100 cards, one number per
card.
The cards are arranged in 10 rows and 10 columns, in increasing
order in each row (left to right) and each column (top down).
All the cards are turned faced down so that you cannot see the numbers written on
them.
Can you devise an algorithm to determine whether a given number
is written on one of the cards by turning up less than 20 cards?
*/
#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include<windows.h>
#include<time.h>
using namespace std;
#define MAX_SIZE 10
void search(int mat[MAX_SIZE][MAX_SIZE], int fromRow, int toRow,  
                    int fromCol, int toCol, int key) 
    { 
        int i = 5; 
        int j = 5; 
        if (mat[i][j] == key) 
        cout<<"Found "<< key << " at "<< i << 
                            " " << j<<endl; 
        else
        {  
            if (i != toRow || j != fromCol) 
            search(mat, fromRow, i, j, toCol, key); 
            if (fromRow == toRow && fromCol + 1 == toCol) 
            if (mat[fromRow][toCol] == key) 
                cout<<"Found "<< key<< " at "<< 
                            fromRow << " " << toCol<<endl; 
            if (mat[i][j] < key) 
            { 
                if (i + 1 <= toRow) 
                search(mat, i + 1, toRow, fromCol, toCol, key); 
            } 
              else
            { 
                if (j - 1 >= fromCol) 
                search(mat, fromRow, toRow, fromCol, j - 1, key); 
            } 
        } 
    } 
void sortByRow(int mat[MAX_SIZE][MAX_SIZE], int n)
{
	for (int i = 0; i < n; i++)

 		sort(mat[i], mat[i] + n);
}

 void transpose(int mat[MAX_SIZE][MAX_SIZE], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)

 			swap(mat[i][j], mat[j][i]);
}

  void sortMatRowAndColWise(int mat[MAX_SIZE][MAX_SIZE], int n)
{
 	sortByRow(mat, n);

 	transpose(mat, n);

 	sortByRow(mat, n);

 	transpose(mat, n);
}

 void printMat(int mat[MAX_SIZE][MAX_SIZE], int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << mat[i][j] << " ";
		cout << endl;
	}
}
int printRandoms(int lower, int upper,
							int count)
{
	int i;
	for (i = 0; i < count; i++) {
		int num = (rand() %
		(upper - lower + 1)) + lower;
		return num;
	}
}
  
int steps=0;
 int main()
{
	int mat[MAX_SIZE][MAX_SIZE];
	int r1,c1,key;
	clock_t t1,t2;
    for (int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {
            mat[i][j]=rand()%(10000) + 1;
        }
    }
	int n = 10;
	cout<<"\t\t\t\tSearching a Sorted Table\n One hundred different numbers are written on 100 cards, one number per card. \n The cards are arranged in 10 rows and 10 columns, in increasing order in each row (left to right) and each column (top down).\nAll the cards are turned faced down so that you cannot see the numbers written on them.\nCan you devise an algorithm to determine whether a given number is written on one of the cards by turning up less than 20 cards?\n";
    cout << "\n\nOriginal Table:\n";
	printMat(mat, n);
	t1=clock();
	sortMatRowAndColWise(mat, n);
	Sleep(2000);
	cout<<endl;
	cout << "\nTable After Sorting:\n";
	printMat(mat, n);
	r1=printRandoms(0, 9, 1);
	c1=printRandoms(0, 9, 1);
	key=mat[r1][c1];
	cout<<"\nThe card to be searched at random is located at row "<<r1+1<<" and column "<<c1+1<<"."<<endl<<"Number to be searched: "<<key<<endl;
    search(mat, 0, MAX_SIZE - 1, 0, MAX_SIZE - 1, key); 
	t2=clock()-t1;
	cout<<"\nTime taken for computation: "<<(float)t2/CLOCKS_PER_SEC<<" seconds."<<endl;
	cout<<"\nNumber of steps taken to find the card: "<<steps;
	cout<<"\n------------------------------";
	return 0;
}
