/*
  Task text taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Pages 159-160

  Count the number of possible positions of queens on a chessboard such that they don't attack each other.

  I wrote this code; I modeled it after the book's solution for generating permutations, but I wrote the specific code to check for attacks myself
*/

// I traced this through on paper since it was hard for me to understand it immediately; it makes sense

#include <iostream>
#include <vector>

constexpr int MAXI = 8;

using namespace std;

// the key insight is that queens that do attack each other are going to have the same either the sum of the row and column they are in or the difference of the row and column they are in
bool check(int x)
{
  vector<int> row_and_column_sums;
  vector<int> row_and_column_differences;
  int xx = x;
  int current_row = 8; // we start from row H since when I pull out the digits from x, I start from the rightmost digit
  while (xx != 0)
  {
    int current_column = xx % 10;
    int row_and_column_sum = current_row + current_column;
    int row_and_column_difference = current_row - current_column;
    row_and_column_sums.push_back(row_and_column_sum);
    row_and_column_differences.push_back(row_and_column_difference);
    current_row--;
    xx /= 10;
  }
  // check if there are duplicates
  for (int i = 0; i < row_and_column_sums.size(); i++)
  {
    for (int j = i + 1; j < row_and_column_sums.size(); j++) // row and column sums are of the same size
    {
      if ((row_and_column_sums[i] == row_and_column_sums[j]) || (row_and_column_differences[i] == row_and_column_differences[j]))
      {
	return false;
      }
    }
  }
  return true;
}

void rec(int x, int n, int& count)
{
  int digits[MAXI] = {0}; // we are using the elements at the 0 to 7	 indicies
  int xx, i;
  if (n == 0)
  {
    if (check(x))
    {
      count++;
    }
    return;
  }
  xx = x;
  while (xx)
  {
    digits[xx % 10 - 1] = 1; // so it is between 0 and 4
    xx /= 10;
  }
  for (i = 1; i <= MAXI; i++)
  {
    if (!digits[i - 1])
    {
      rec(x * 10 + i, n - 1, count);
    }
  }
}

int main()
{
  int count = 0;
  rec(0,8, count);
  cout << count << endl;
  return 0;
}
