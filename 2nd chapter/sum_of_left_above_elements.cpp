/*
  Exercise taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Page 65
  Exercise text translated from Croatian to English by me.

  Input n and m (1 <= n,m < 10), and then n rows with m numbers in a row. n rows with m numbers describes a matrix with nxm elements.
  Print the matrix with the same number of elements, where each element is the sum of the elements that have less or equal
  column or low index (the sum of all elements which are "left and above the element).

  The solution below is mine, generated after looking at the book's solution and trying to re-create it.
 */

#include <iostream>

using namespace std;

// bug somewhere here...

int main()
{
  int n, m;
  cin >> n >> m;
  int input[10][10];
  int A[10][10];
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      A[i][j] = 0;
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> input[i][j];
    }
  }
  cout << "n = " << n << endl;
  cout << "m = " << m << endl;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << input[i][j] << " ";
    }
    cout << endl;
  }
  for (int ii = 0; ii < n; ii++)
  {
    for (int jj = 0; jj < m; jj++)
    {
      for (int i = 0; i <= ii; i++)
      {
	for (int j = 0; j <= jj; j++)
	{
	  A[ii][jj] += input[i][j];
	}
      }
    }
  }
  cout << "----------------------------------------" << endl;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << A[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
