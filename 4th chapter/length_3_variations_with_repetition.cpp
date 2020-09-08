/*
  Task text taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Page 158

  I adapted the task to write out all the variations with repetition. I solved it before looking at the book's solution.

  Write out all the variations with repetition of the numbers 1, 2, 3, 4 and 5 of length 3.
*/

#include <iostream>
#include <vector>

using namespace std;

void vary(vector<char>& arg)
{
  cout << int(arg[0]) << int(arg[1]) << int(arg[2]) << " ";
  if ((arg[0] == 5) && (arg[1] == 5) && (arg[2] == 5)) 
  {
    return;
  }
  else if (arg[2] < 5)
  {
    arg[2] += 1;
  }
  else if (arg[1] == 5)
  {
    arg[0] += 1;
    arg[1] = 1;
    arg[2] = 1;
  }
  else if (arg[2] == 5)
  {
    arg[2] = 1;
    arg[1] += 1;
  }
  vary(arg);
}

int main()
{
  vector<char> three_digit_number {1, 2, 3};
  vary(three_digit_number);
  return 0;
}
