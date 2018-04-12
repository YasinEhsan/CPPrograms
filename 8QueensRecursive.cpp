// recursive eight queens
#include <iostream>
#include <cmath>
using namespace std;
bool ok(int * q, int i){
  
 for (int k=0; k <i; k++)
    if((q[k]==q[i]) || (abs(q[k]-q[i])==i-k))
      return false; //conflict, go back and try next row
 return true; //this one's ok, return and move on to next column
}
void print(int * q){
 static int count =0;
 cout<<++count<<endl;

 for (int k=0; k<8; k++)
 cout<< q[k];cout<<endl;
}
void move(int* q, int i) /* try place in col i*/ {
 if(i==8) {
    print(q);
    return;
 }

 for(int j=0;j<8;j++) /*j is the row value */ {
    q[i]=j;
    if(ok(q,i)) // try and place a queen in row j of col i,if yes
       move(q,i+1); // go to next column otherwise try next j
 }

 // no value of j worked so return;
};
int main(){
 int q[8];
 move(q,0);
 system("pause");
} 
