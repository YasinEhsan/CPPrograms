#include<iostream>
using namespace std;

int backtracking() {
   int q[8] = {}; 
   int c = 0;
   while (c >= 0) { // End the loop if you backtrack from the first column
      c++;
      if(c == 8){
         print(q);
         c--;
      }
      else
        q[c] = -1;
      while (c >= 0) {
         q[c]++;
         if(q[c] == 8)
            c--;
         else if(ok(q, c))
          break;
      }
   }
   return 0;
}

//recursive version
void move(int* q, int i) /* try place in col i*/ {
 if(i==8) {
    print(q);
    return;
 }

 for(int j=0;j<8;j++) /*j is the row value */ {
    q[i]=j;
    if(ok(q,i)) // try and place a queen in row j of col i,if yes
       move(q,i+1); // go to next column otherwise try next j
 }
	
//pointers 101

//Gcf recursive
int GCF(int a, int b) {
	if(b == 0)
		return a;
	return GCF(b, a % b);	
}
//LCM recur
int LCM(int a, int b)	{
	return a *( b / GCF(a,b));
}
------------------------------------------------------------------------------------------
//n queens
//towers of hanoi	
//b1: Find all possible ways of multupling 144
//b2: Dijkstra's Algorithm
//notes...
	
	
	
	
	
	
------------------------------------------------------------------------------------------
	
//Fibonacci
int fib(int n){
	if(n==1 || n==2) 
		return 1;
	return fib(n-1)+fib(n-2);
};
void main(){
	for(int i=1; i<70; i++)
	cout<<" fib("<<i<<") = "<<fib(i)<<endl; //slows down at 47ish
}
	
//fancy queens
bool ok(int q[], int c) {
   for (int i = 0; i < c; ++i)
      if (q[i] == q[c] || abs(q[i] - q[c]) == c - i)
         return false;
   return true;
}
void print(int q[]){
   /*Some part... */ (*board[i][j])[k][l]; 
   typedef char box[5][7];   // box is now a data type: a 5x7 2D array of characters
   box bb, wb, *board[8][8];
	
 for(int i =0; i < 8; i++){
     if(board[i][q[i]] == &wb)
      board[i][q[i]] = &bq; //THIS IS WHERE I STRUGGLED: "Double equal" is assignment
     else
      board[i][q[i]] = &wq;
 }

//Stable Marriage...pattern?
bool ok(int q[], int c) {
for(int i = 0; i < c; i++){
    if(q[i] == q[c])
      return false;//row test 
    if(mp[i][q[c]] < mp[i][q[i]] && wp[q[c]][i] < wp[q[c]][c] 
       
       || 
       
       mp[c][q[i]] < mp[c][q[c]] && wp[q[i]][c] < wp[q[i]][i])
      return false;//edge case. 
  }
  return true; 
}

//8numin cross
bool test(int cross[], int x) {
	static int checkList[8][5] = {
		{-1},
		{0,-1},
		{1,-1},
		{0,1,2,-1},
		{1,2,3,-1},
		{2,4,-1},
		{0,3,4,-1},
		{3,4,5,6,-1},
	};
	//fill in
	for(int i = 0; i < x; i++)
	  if(cross[x] == cross[i])
	  return false;
	for(int i = 0; checkList[x][i] != -1; i++)//sentinal val
	  if(abs(cross[x] - cross[checkList[x][i]]) == 1)//becuz consecutive numbers are one apart
	    return false;
	return true;
} 

//1dQueens
bool ok(int q[], int c) {
   for(int i =0; i < c; i++) //each i from 0 to c-1
      if (q[i] == q[c] || abs(c-i) == abs(q[c]-q[i]))
         return false;
   return true;
}

int 2dQueens() {
  int q[8][8] = {};// Initialize the board to 0
  int r = 0, c = 0;// Start in the 1st row, 1st column
  q[r][c] = 1; // Place the first queen on the upper left corner 
  
  
  nextCol:
    c++;
    if(c == 8)
      goto print;
    r = -1;
  
  nextRow:
    r++;
    if(r == 8)
      goto backtrack;
      
    for(int i = 0; i < c; i++) //chks left
      if(q[r][i] == 1) 
        goto nextRow;
        
    for(int i = 1; (r-i)>=0 && (c-i)>=0; i++)//up diag chk
      if(q[r-i][c-i] == 1) 
        goto nextRow;
        
    for(int i = 1; (r+i)<8 && (c-i)>=0; i++)//down diag chk
       if(q[r+i][c-i] == 1) 
        goto nextRow;
         
    q[r][c] = 1;
    goto nextCol;
      
      
  backtrack:
    c--;
    if(c == -1)
      return 0;
    r = 0;
    while(q[r][c] != 1)
       r++;
    ////////q[r][c] == 0; MANZZ MANZZ I SPENT HOURS looking at the nity grity of this code -- here was my erorr!! double equals isnt assignment... Hope i can finesse the midterm
    q[r][c] = 0; 
    goto nextRow;
     
  print:
    static int numSolutions = 0;
      cout << "Solution #" << ++numSolutions << ":\n";
      for(int i=0; i<8;i++){
   	for(int j=0; j<8;j++){
   		cout<<q[i][j];
   	}
   	cout<<endl;
   }
   cout<<endl;
      goto backtrack;
}
//n Queens	
Order        < ------  Ordinary Queens  ------ >              < ----- Superqueens ----- >
(“N”)      Total Solutions       Unique Solutions            Total Sol.         Unique Sol.
------------------------------------------------------------------------------------------
1                        1                      1                    1                   1
2                        0                      0                    0                   0
3                        0                      0                    0                   0
4                        2                      1                    0                   0
5                       10                      2                    0                   0
6                        4                      1                    0                   0
7                       40                      6                    0                   0
8                       92                     12                    0                   0
9                      352                     46                    0                   0
10                     724                     92                    4                   1   
	
// A C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph
  
#include <stdio.h>
#include <limits.h>
  
// Number of vertices in the graph
#define V 9
  
// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
   // Initialize min value
   int min = INT_MAX, min_index;
  
   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
  
   return min_index;
}
  
// A utility function to print the constructed distance array
int printSolution(int dist[], int n)
{
   printf("Vertex   Distance from Source\n");
   for (int i = 0; i < V; i++)
      printf("%d tt %d\n", i, dist[i]);
}
// driver program to test above function
int main()
{
   /* Let us create the example graph discussed above */
   int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
  
    dijkstra(graph, 0);
  
    return 0;
}
//finds all divisors: discrete math 101 style
#include<cmath>
void printDivisors(int n) {
    for (int i=1; i<=sqrt(n); i++){
        if (n%i == 0){
            if (n/i == i)
                cout << i << " x " << i;
            else 
                cout << i << " x " << n/i << endl;
        }
    }
}

