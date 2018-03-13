#include<iostream>
using namespace std;

int main() {
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
