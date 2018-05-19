//Yasin Ehsan
//K Bishops
//Learned:
// + backtacking diff way
// + col and row test based on div and mod


#include <iostream>
#include <cmath>
using namespace std;

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

int main() {
   int n, k;
   n =0;
   while(n != -1){
     cout << "Enter two Integers: ";
     cin >> n >> k;
     if(n == -1)
      return 0;
     printf("%s\n", "n k #Bishops");
     printf("%d %d %d \n\n", n, k, kBish(n, k));
   }
   return 0;
}
