//http://venus.cs.qc.edu/~waxman/211/Output%20for%20the%20k%20out%20of%20n%20bishops%20problem.pdf


//http://venus.cs.qc.edu/~waxman/211/k%20bishops%20on%20an%20nXn%20chessboard.pdf


//Yasin Ehsan
//K Bishops
//Learned:

#include <iostream>
#include <cmath>
using namespace std;

//c is the position of the bishop array
//n is the n by n grid

bool ok(int q[], int c, int n) {
   for(int i =0; i < n; i++)
      if (abs(q[c]%n - q[i]%n) == abs(q[c]/n - q[i]/n))//diag test
         return false;
   return true;
}

int kBish(int n) {
   int* q = new int [n]; //Dynamic memory
   int c = 0;
   int count = 0;
   while (c >= 0) {
      c++;
      if(c == n){
         count++;
         c--;
      }
      else
        q[c] = -1;
      while (c >= 0) {
         q[c]++;
         if(q[c] == n) c--;
         else if(ok(q, c, n))
          break;
      }
   }
   delete [] q; //NEW syntax
   return count;
}

int main() {
   int n, k;
   cout << "Enter two Integers: ";
   cin >> n >> k;
   if(n == -1)
    return 0;

   //cout << "\n n k #Bishops\n";
   printf("%s\n", "n k #Bishops");
   for(int i =0; i<k; i++)
     printf("%d %d %d \n", n, i+1, kBish(n));



   return 0;
}
