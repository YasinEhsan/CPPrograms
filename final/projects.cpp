/*
CONTENTS
- Hanoi
- kBish
- SP
- SP NR
- Rat
*/

//HANOI towers
int main() {
   vector<int> t[3];
   int n;
   cout << "Please enter the number of rings to move: ";
   cin >> n;
   cout << endl;
   // The initial value of to depends on whether n is odd or even
   int from = 0, to = (2-n%2), candidate = 1, move = 0;

   // Initialize the towers
   for(int i = n + 1; i >= 1; --i)
      t[0].push_back(i);
   t[1].push_back(n+1);
   t[2].push_back(n+1);

   while (t[1].size() < n+1) { // while t[1] does not contain all of the rings
      cout << "Move #" << ++move << ": Transfer ring " << candidate << " from tower " << char(from +'A') << " to tower " << char(to +'A') << "\n";



      // Move the ring from the "from tower" to the "to tower" (first copy it, then delete it from the "from tower")
     t[to].push_back(t[from].back());
     t[from].pop_back();



      // from = the index of the tower with the smallest ring that has not just been moved: (to+1)%3 or (to+2)%3
      if (t[(to + 1)%3].back() >  t[(to + 2)%3].back())
         from = (to + 2)%3;
      else
         from = (to + 1)%3;



      // candidate = the ring on top of the t[from] tower
      candidate = t[from].back();



      // to = the index of the closest tower on which the candidate can be placed: (from+1)%3 or (from+2)%3
      // (compare the candidate with the ring on the closer tower; which tower is "closer" depends on whether n is odd or even)

      if(n%2 ==0){
        if (t[(from + 2)%3].back() > candidate )
           to = (from + 2)%3;
        else
           to = (from + 1)%3;
      }
      else{
        if (t[(from + 1)%3].back() > candidate )
           to = (from + 1)%3;
        else
           to = (from + 2)%3;
      }
   }
   return 0;
}
//HANOI ENDS


//K Bishops
bool ok(int q[], int c, int n) {
   for(int i =0; i < c; i++) //each i from 0 to c-1
      if ((q[c]/n - q[i]/n) == abs(q[c]%n - q[i]%n))//THE MEAT OF THE PBLM
         return false;
   return true;
}

int kBish(int n, int k) {
   int* q = new int [n]; //Dynamic memory
   int c = 0;
   int count = 0;
   while (c >= 0) {
      c++;
      if(c == k){//k is the length of array q
         count++;
         c--;
      }
      else
        q[c] = q[c-1]; //q[c] = -1;
      while (c >= 0) {
         q[c]++;
         if(q[c] == n*n) c--;//n*n is max value of q[c]
         else if(ok(q, c, n))
          break;
      }
   }
   delete [] q;
   return count;
}
//K BISH ENDS



//SP
onst int NUM_ROWS = 5, NUM_COLS = 6; //'const' = final in java
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
//SP ENDS

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
//RAT AND SP NR ENDS
