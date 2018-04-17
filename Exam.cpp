#include <iostream>
using namespace std;

void p(int);

int main() {
  p(0);
}

void p(int x){
  if (x == 3)
    return;
  //cout << x << endl;
  p(x+1);
  cout << x << endl;
}
