#include<iostream>
using namespace std;

int backtracking() {
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

//int 1d
//8numin cross
//perfect sq
//stable marraige
//integration
//fancy queens

int 2dQueens() {
  int q[8][8] = {};// Initialize the board to 0
  int r = 0, c = 0;// Start in the 1st row, 1st column
  q[r][c] = 1; // Place the first queen on the upper left corner 
  
  
  nextCol:
    c++;
    if(c == 8)
      goto print;
    r = -1;
  
  nextRow:
    r++;
    if(r == 8)
      goto backtrack;
      
    for(int i = 0; i < c; i++) //chks left
      if(q[r][i] == 1) 
        goto nextRow;
        
    for(int i = 1; (r-i)>=0 && (c-i)>=0; i++)//up diag chk
      if(q[r-i][c-i] == 1) 
        goto nextRow;
        
    for(int i = 1; (r+i)<8 && (c-i)>=0; i++)//down diag chk
       if(q[r+i][c-i] == 1) 
        goto nextRow;
         
    q[r][c] = 1;
    goto nextCol;
      
      
  backtrack:
    c--;
    if(c == -1)
      return 0;
    r = 0;
    while(q[r][c] != 1)
       r++;
    ////////q[r][c] == 0; MANZZ MANZZ I SPENT HOURS looking at the nity grity of this code -- here was my erorr!! double equals isnt assignment... Hope i can finesse the midterm
    q[r][c] = 0; 
    goto nextRow;
     
  print:
    static int numSolutions = 0;
      cout << "Solution #" << ++numSolutions << ":\n";
      for(int i=0; i<8;i++){
   	for(int j=0; j<8;j++){
   		cout<<q[i][j];
   	}
   	cout<<endl;
   }
   cout<<endl;
      goto backtrack;
}
