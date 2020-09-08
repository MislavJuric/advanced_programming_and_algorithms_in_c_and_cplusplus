/*
  Exercise taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Page 61
  Exercise text translated from Croatian to English by me.

  Input n (1 <= n <= 1000), then n numbers. Output them sorted ascendingly (lower value numbers first, higher value numbers later).

  The solution below is generated before looking at the book's solution.
*/

#include <iostream>

using namespace std;

int main()
{
  int n;
  int A[1000];
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> A[i];
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (A[i] > A[j])
      {
	int temp = A[j];
	A[j] = A[i];
	A[i] = temp;
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    cout << A[i] << " ";
  }
  cout << endl;
}
