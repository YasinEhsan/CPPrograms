//Yasin Ehsan
//shortest_path REcursive
//Learned: IN ccp(at least in repl.it) -1%5 retuerns -1. Sup to b 4.
// Fix: (-1 + 5)%5.
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int NUM_ROWS = 5, NUM_COLS = 6; //'const' = final in java
string path[NUM_ROWS][NUM_COLS];

int calculateCost(int i, int j) {
   static int weight[NUM_ROWS][NUM_COLS] = {{3,4,1,2,8,6},
                                            {6,1,8,2,7,4},
                                            {5,9,3,9,9,5},
                                            {8,4,1,3,2,6},
                                            {3,7,2,8,6,4}};
   static int cost[NUM_ROWS][NUM_COLS]; //pre set to '0'

   //Base case 1
   if(cost[i][j] != 0)
      return cost[i][j];

   //BAse case2
   if (j == 0) {
      path[i][j] = to_string(i);
      return weight[i][j];
   }

   int up = calculateCost((i-1 + NUM_ROWS) % NUM_ROWS, j-1); //*****MAJOR MOD PRBLM
   int left = calculateCost(i, j-1);
   int down = calculateCost((i+1)%NUM_ROWS, j-1);
   int minCost = min(min(up,down), left);


   //THE MEAT OF THE PROBLM
   // Update the path matrix (store the path to the current square in path[i][j]):
   // If up is the minimum, get the shortest path to the up-left square from the path matrix and concatenate it with the current row.
    if(minCost==up)
      path[i][j] = path[(i-1 + NUM_ROWS) % NUM_ROWS][j-1] + to_string(i);//
    else if(minCost==down)
      path[i][j] = path[(i+1)%NUM_ROWS][j-1] + to_string(i+1);
    else
      path[i][j] = path[i][j-1] + to_string(i);

    cost[i][j] = weight[i][j] + minCost;

    return cost[i][j];
}

int main() {
   int minRow = 0;

  for(int i = 0; i < NUM_ROWS; i++)
    if(calculateCost(minRow, NUM_COLS-1) > calculateCost(i, NUM_COLS-1))
        minRow = i;

   cout << "The length of the shortest path is " << calculateCost(minRow, NUM_COLS-1);
   cout << ".\nThe rows of the path from left to right are " << path[minRow][NUM_COLS-1] << ".";

   return 0;
}
