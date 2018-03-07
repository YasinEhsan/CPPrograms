#include <iostream>
using namespace std;

int main() {
  
  
  
  int a[2][2] = {
    {123,94},
    {37826,584967}
  };
  
  cout << "adress of a: " << a << endl;
  cout << "adress of a: " << a[0] << endl;
  cout << "adress of a: " << &a[0][0] << endl << endl;
  
  cout << "adress of a: " << a + 1 << endl;
  cout << "adress of a: " << a[1] << endl;
  cout << "adress of a: " << &a[1][0] << endl << endl;
  
  cout << "value of a[0][0]: " << a[0][0] << endl;
  cout << "value of a[0][0]: " << **a << endl;
   cout << "value of a[0][0]: " << **(a+0) << endl;
  cout << "value of a[0][0]: " << *(*a+0) << endl;
  
  cout << *a << endl;
  
  
  
  //handout
  
  int b[3][2];
  cout <<b+1<<endl;
  
  
  
  return 0;
}