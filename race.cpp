// http://venus.cs.qc.cuny.edu/~jchen/CS211/Projects/Race/


#include<iostream>
using namespace std;

int main() {
   while (true) {
      string runners;
      cout << "Enter the race outcome: ";
      cin >> runners;
      // If the user entered "done", exit the program
      if(runners.compare("done") == 0)
        return 0;



      int numTeams = 0;       // The number of teams
      int scores[26] = {}; // scores[i] keeps track of the total score of team i
      int counts[26] = {}; // counts[i] keeps track of the number of runners on team i


      for (int i = 0; i < runners.length(); ++i) {

        // For each runner in the race, Increase the team's score by the runner's rank (the rank is 1 more than the index)
        // If it's the first runner of that particular team, update the total number of teams
         // Update the number of runners on the team
        char temp = runners[i];
        cout << temp << endl;
        if(scores[(int)temp - 65] == 0)
          ++numTeams;
        scores[(int)temp - 65] += i+1;
        cout <<(int)temp - 65 << endl;

      }


      // If the teams do not all have the same number of runners,
         // Print an error message and ask for input again (go back to the beginning of the loop)


      // for(int i = 0; i < counts.length; i++)
      //   if(count[0] != count[i]){
      //     printf("%s", "you suck. NOT SAME # of runners");
      //     continue;
      //   }


      // Print the number of teams
      // Print the number of runners on each team
      printf("There are %d teams.\nThere are %d runners.\n",numTeams, numTeams);


      // For each letter from A-Z,
         // If that team participated,
            // Print the name of the team and its average score
            // Also keep track of which team(s) has the best score
      for(int e: scores){
        // printf("%c: %d\n", (char)counts[0], counts[0]);
        cout << (char)counts[0];
      }


      // Print the name of the winning team and its average score (if it's a tie, you may either pick one arbitrarily or print all of the winners)
   }
   return 0;
}
