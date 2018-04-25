#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int NUM_ROWS = 5, NUM_COLS = 6;
string path[NUM_ROWS][NUM_COLS];

// Calculates the cost of every square and fills in the cost matrix.
void calculateCosts() {
   static int weight[NUM_ROWS][NUM_COLS] = {{3,4,1,2,8,6},
                                            {6,1,8,2,7,4},
                                            {5,9,3,9,9,5},
                                            {8,4,1,3,2,6},
                                            {3,7,2,8,6,4}};
   // Declare the cost matrix.
   _____
   // Copy the leftmost column of the weight matrix to the cost matrix, and initialize the leftmost column of the path matrix.
   _____
   // For each remaining column,
      // Calculate the cost of each square in the column (non-recursively),
      // and store the correct number in the cost matrix and the correct string in the path matrix.
   _____

   int minRow = 0;
   // Check which square in the rightmost column has the lowest cost.  Store the row number of that square in minRow.
   _____
   
   cout << "The length of the shortest path is " << cost[minRow][NUM_COLS-1];
   cout << ".\nThe rows of the path from left to right are " << path[minRow][NUM_COLS-1] << ".";
}

int main() {
   calculateCosts();

   return 0;
}
