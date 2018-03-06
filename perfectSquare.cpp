//Yasin Ehsan
#include <iostream>
using namespace std;

int main() {
  
  for(int i = 1; i < 100; i++){
   int sq = i*i;
   if(sq % 2 == 1){
     if(sq / 10 % 2 == 1){
       cout << sq << endl;
     }
   }
  }
  cout << "No such number exists" << endl;
}

/*
-Looping through 1 - 100 because the last two digits of the squares after 100 repeat 

-Thus, the program checks all numbers from 1-100. No perfect square is found.

- perfect square does not exist.

*/





