/*
  Exercise taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Page 170

  Write out the steps needed to arrange a 2D array that is 2x3 to this:

  1 2 3
  4 5 6

  Use DFS for this.

  The solution generated here is mine, before looking at the book's solution.
*/

/*
  My general procedure:
  
  1. Create a vector of 2x3 arrays
  2. In the recursion, remember all of the 2x3 arrays
  3. Check if the current 2x3 is the solution
  4a. If not, change the configuration and see if you already have it in the vector of 2x3 arrays
  4b. If you have it in the vector, don't recurse - change another thing (before changing it revert the 2x3 back to its original at the start of the recursion)
  4c. If you don't have it in the vector, recurse

  Notes: Can't have a vector of arrays https://stackoverflow.com/questions/6159000/vector-of-multidimensional-arrays
*/

#include <iostream>

using namespace std;

// stores all the previous configurations
int history[46656][2][3];

bool checkSolution(int input[][])
{
  if ((input[0][0] == 1) && (input[0][1] == 2) && (input[0][2] == 3) && (input[1][0] == 4) && (input[1][1] == 5) && (input[1][2] == 6))
  {
    return true;
  }
  return false;
}

void dfs(int input[][])
{
  // check if it is the solution
  if (checkSolution(input))
  {
    return;
  }
  // try out a possible action

  // this seems hard to implement - I'd have to have a collection of all possible actions and then if one already exists in history (see comment below) I'd have to do another action
  // must be a simpler solution
  
  // check if it is already present in history
  // if it is, go to the other possible action
  // if it is not, recurse with the new configuration
}

int main()
{
  int input[2][3];
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cin >> input[i][j];
    }
  }
  dfs(input);
  return 0;
}
