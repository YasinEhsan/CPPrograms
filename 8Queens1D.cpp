//Yasin Ehsan
//1d8queens
//Learned:
// - back tracking: done from the main function. I always used to create my own func.
// - all the tests can be done in one if statement
// - How simpler data structure could mean less implementation


#include <iostream>
#include <cmath>
using namespace std;

// Returns true if the queen in column c is ok
bool ok(int q[], int c) {
   for(int i =0; i < c; i++) //each i from 0 to c-1
      if (q[i] == q[c] || abs(c-i) == abs(q[c]-q[i]))//
         return false;
   return true;
}
void print(int q[]) {
   static int numSolutions = 0;
   cout << "Solution #" << ++numSolutions << ": ";
  for(int i = 0; i < 8; i++)
    cout << q[i];
     cout << "\n";
}
int main() {
   int q[8] = {};
   int c = 0;
   while (c >= 0) {
      c++;
      if(c == 8){
         print(q);
         c--;
      }
      else
        q[c] = -1;
      while (c >= 0) {
         q[c]++;
         if(q[c] == 8) c--;
         else if(ok(q, c))
          break;
      }
   }
   return 0;
}
