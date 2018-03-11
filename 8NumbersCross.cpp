// Yasin Ehsan
//8 numbers in a cross
#include<iostream>
#include<cmath>
using namespace std;

bool test(int cross[], int x) {
	static int checkList[8][5] = {
		{-1},
		{0,-1},
		{1,-1},
		{0,1,2,-1},
		{1,2,3,-1},
		{2,4,-1},
		{0,3,4,-1},
		{3,4,5,6,-1},
	};
	//fill in
	for(int i = 0; i < x; i++)
	  if(cross[x] == cross[i])
	  return false;
	for(int i = 0; checkList[x][i] != -1; i++)//sentinal val
	  if(abs(cross[x] - cross[checkList[x][i]]) == 1)//becuz consecutive numbers are one apart
	    return false;
	return true;
} 

void print(int cross[], int cap) {
	static int count = 0;
	cout << " Soultion number: " << ++count << endl;
	cout << " " << cross[1] << cross[2] << endl;
	cout << cross[0] << cross[3] << cross[4] << cross[5] << endl;
	cout << " " << cross[6] << cross[7] << endl;
	return;
}

int main() {
	//use the same 1d 8 crossueens main function
	int cross[8] = {}; 
   int c = 0; //position in cross
   while (c >= 0) { // End the loop if you backtrack from the first column
      c++;
      if(c == 8){
         print(cross, c);
         c--;//backtracking
      }
      else
        cross[c] = -1;
      while (c >= 0) {
         cross[c]++;
         if(cross[c] == 8)
            c--;
         else if(test(cross, c))
          break;
      }
   }
   return 0;
}
