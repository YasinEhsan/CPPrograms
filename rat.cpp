//Yasin Ehsan

//RAT CLASS + SHortest path NON Recursive
// --> I couldn't upload two files in shortest path project submission, so the non recursive version is here

// RAT CLASS- Learned: friend function implementation and freedom to customize operator funcs

//SHORTEST PATH NR: Recursive code isn't always the more succint
// - DEBUG Hurdles: 1) switched rows and colomns. 2) appended weight matrix instead of the cost matrix

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
}//SHORTEST PATH ENDS HERE

class Rat{
  private:
     int n;
     int d;

  public:
   Rat(){
     n=0;
     d=1;
   }

   Rat(int i, int j){
     n = i;
     d = j;
   }

   Rat(int i){
     n=i;
     d=1;
   }

   int getN(){ return n;}
   int getD(){ return d;}
   void setN(int i){ n=i;}
   void setD(int i){ d=i;}

   Rat operator+(Rat r){
     Rat t;
     t.n = n*r.d + d*r.n; //'this' makes it more clear to me. NOT WORKING
     t.d = d*r.d;
     return t;
   }

    Rat operator-(Rat r){
     Rat t;
     t.n = n*r.d - d*r.n;
     t.d = d*r.d;
     return t;
   }

   Rat operator*(Rat r){
     Rat t;
     t.n = n*(r.n);
     t.d = d*r.d;
     return t;
   }

   Rat operator/(Rat r){
     Rat t;
     t.n = n*(r.d);
     t.d = d*r.n;
     return t;
   }

   // 2 overloaded i/o operators
   friend ostream& operator<<(ostream& os, Rat r);
   friend istream& operator>>(istream& is, Rat& r);
   //end Rat
  };

  int gcd(int a, int b){ // a is greater and b is smaller...Though it doesnt matter
      if(b == 0)
        return a;
      return gcd(b, a%b);
  }

  ostream& operator<<(ostream& os, Rat r){
    if(r.n > r.d){
      if(r.n % r.d == 0)
        os << r.n / r.d << endl;//simplfies to integer
      else
        os<<r.n/r.d<< " " << r.n%r.d  << " / " << r.d <<endl;//creates mixed number
    }
    else
      os<< r.n / gcd(r.n, r.d) << " / " << r.d / gcd(r.n, r.d) <<endl; //reduces function
   return os;
  }

  istream& operator>>(istream& is, Rat& r){
   is>>r.n>>r.d;
   return is;
  }

  int main(){
   cout << "****SHORTEST PATH Non Recursive OUTPUT****\n";
   calculateCosts(); //calling SP NR
   cout << "\n\n****RAT CLASS OUTPUT****\n";

   Rat x(1,2), y(2,3), z;
   z=x*y; // returns 2/6
   cout<<z; // returns 1/3 simplified

   x.setN(3);
   y.setD(2);

   z=x+y;
   cout<<z;

   printf("%s", "\nAyoo, enter a rat");

   cin>>x;
   cout<<x;
   Rat v(5);
   z = x+v;
   cout<<z;

   return 0;
}
