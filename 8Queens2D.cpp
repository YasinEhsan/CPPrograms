// Yasin Ehsan
#include <iostream>
using namespace std;

//programming is a true engima...esp the debugging part 


int main() {
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
//Take away -- I rem. in Java I had seemed to have all the code done and literally spend days finding the small mistakes. Looking at the same code surely helped solidify my concepts and ofc pinpoint my stupidest erorrs. Today was just all a repeat. I guess its true. no pain, no gain! Hope I can become familiar with cpp just as i am with Java
