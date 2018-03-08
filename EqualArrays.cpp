/*
Yasin Ehsan
---


THE PROBLEM:

The equivalent function should return true if array a can be shifted (by any amount) such that it is equivalent to array b. If the shift went past the end of the array, it should loop back to the beginning. 
---


THE SOLUTION: 

1) @isEquiv: a function that checks if two arrays are equivalent.

2) @shift: rotates each element of the array to the left by one position. The first position is stored in a temporary variable and inserted into the last position of the array.

3) Bringing it all together -- @equivalent: @isEquiv checks whether a fuction is Equivalent. If found, @Equivalent returns true. If not, @shift is called. This is repeated "size" times. If "true" is not returned by "size" iterations, no solution exists. False is returned.
*/

#include <iostream>
using namespace std;

void shift(int b [], int size){
  int temp = b[0];
  for(int i = 0; i < size-1; i++)
    b[i] = b[i + 1];
  b[size - 1] = temp;//inserting the first element into the last position
}

bool isEquiv(int a [], int b [], int size){
  for(int i = 0; i < size; i++)
    if(a[i] != b[i])//returns false at first occurence of mismatch
      return false;
  return true;//returns true if all positions of 'both' arrays are identical
}

bool equivalent(int a [], int b [], int size){
  for(int i = 0; i < size; i++ ){
    if(isEquiv(a, b, size))
      return true;
    else
      shift(b,size);
  }
  return false;
}

int main() {
   cout << boolalpha; // to print bool values as true/false instead of 1/0
   
   int a1[5] = {1, 2, 3, 4, 5};
   int a2[5] = {3, 4, 5, 1, 2};
   cout << equivalent(a1, a2, 5) << endl; // true
   
   int b1[3] = {2, 6, 3};
   int b2[3] = {2, 3, 3};
   cout << equivalent(b1, b2, 3) << endl; // false
   
   int c1[4] = {2, 3, 4, 1};
   int c2[4] = {1, 4, 3, 2};
   cout << equivalent(c1, c2, 4) << endl; // false
   
   int d1[4] = {3, 2, 3, 1};
   int d2[4] = {3, 1, 3, 2};
   cout << equivalent(d1, d2, 4) << endl; // true
   
   int e1[5] = {1, 1, 1, 1, 2};
   int e2[5] = {1, 1, 1, 2, 1};
   cout << equivalent(e1, e2, 5) << endl; // true
   
   return 0;
}