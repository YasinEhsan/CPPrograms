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

------------------------------------------------------------------------------------------
//integration
//n queens
//memory stuff 
------------------------------------------------------------------------------------------
//fancy queens
bool ok(int q[], int c) {
   for (int i = 0; i < c; ++i)
      if (q[i] == q[c] || abs(q[i] - q[c]) == c - i)
         return false;
   return true;
}
void print(int q[])
for(int i =0; i < 8; i++){
     if(board[i][q[i]] == &wb)
      board[i][q[i]] = &bq; //THIS IS WHERE I STRUGGLED: "Double equal" is assignment
     else
      board[i][q[i]] = &wq;
 }

//Stable Marriage
bool ok(int q[], int c) {
for(int i = 0; i < c; i++){
    if(q[i] == q[c])
      return false;//row test 
    if(mp[i][q[i]] > mp[i][q[c]] && wp[q[c]][c] > wp[q[c]][i] || mp[c][q[c]] > mp[c][q[i]] && wp[q[i]][i] > wp[q[i]][c])
      return false;//edge case. 
  }
  return true; 
}


//8numin cross
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

//1dQueens
bool ok(int q[], int c) {
   for(int i =0; i < c; i++) //each i from 0 to c-1
      if (q[i] == q[c] || abs(c-i) == abs(q[c]-q[i]))
         return false;
   return true;
}

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
