//Yasin Ehsan
//Shortest path non-recursively
//Learned: Recursive code isn't always the more succint

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int NUM_ROWS = 5, NUM_COLS = 6;
string path[NUM_ROWS][NUM_COLS];

void calculateCosts() {
   static int weight[NUM_ROWS][NUM_COLS] = {{3,4,1,2,8,6},
                                            {6,1,8,2,7,4},
                                            {5,9,3,9,9,5},
                                            {8,4,1,3,2,6},
                                            {3,7,2,8,6,4}};
   static int cost [NUM_ROWS][NUM_COLS]; //Should be static so the cost remains same reagardless of many time the function is called

   // Copy the leftmost column of the weight matrix to the cost matrix, and initialize the leftmost column of the path matrix.
    for(int i = 0; i < NUM_ROWS; i++){
      cost[i][0] = weight[i][0];
      path[i][0] = to_string(i);
    }

   // For each remaining column,
      // Calculate the cost of each square in the column (non-recursively),
      // and store the correct number in the cost matrix and the correct string in the path matrix.
   for(int i = 1; i < NUM_COLS; i++){
     for(int j = 0; j < NUM_ROWS; j++){

       //Determining the cheapest option
       int up = cost[(j-1 + NUM_ROWS)%NUM_ROWS][i-1];  //next col thus J + 1
       int left = cost[j][i-1]; //Becuz this prog is non-recursive we increment J rather decrement J
       int down = cost[(j+1)%NUM_ROWS][i-1];
       int minCost = min(min(up,down), left);

       //storing variable
      if(minCost==up)
        path[j][i] = path[(j-1 + NUM_ROWS) % NUM_ROWS][i-1] + to_string(j);
      else if(minCost==left)
         path[j][i] = path[j][i-1] + to_string(j);
      else
        path[j][i] = path[(j+1)%NUM_ROWS][i-1] + to_string(j);


      cost[j][i] = weight[j][i] + minCost;
     }
   }



   int minRow = 0;
   // Check which square in the rightmost column has the lowest cost.  Store the row number of that square in minRow
   for(int i = 0; i < NUM_ROWS; i++)
      if(cost[minRow][NUM_COLS-1] > cost[i][NUM_COLS-1])
        minRow = i;

  cout << "The length of the shortest path is " << cost[minRow][NUM_COLS-1];
  cout << ".\nThe rows of the path from left to right are " << path[minRow][NUM_COLS-1] << ".";
}

int main() {
   calculateCosts();

   return 0;
}
