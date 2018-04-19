//this is a microsoft interveiw q.
//was on the 211 eleven midterm
//shortest path can be found by 2n choose n OR m + n choose n for a rectangle grid
//Yasin Ehsan
#include <iostream>
using namespace std;

int cal(int, int);

int main() {
  int n, m;
  cout << "Enter val";
  cin >> n >> m;
  
  printf("\t%d\n", cal(n, m));
}

int cal(int n, int m){
  if(n == 1 || m == 1)
    return 1;
  return cal(n-1, m) + cal(n, m-1);
}

