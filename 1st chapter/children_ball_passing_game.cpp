/*
  Exercise taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Page 37
  Exercise text translated from Croatian to English by me.

  N (0 < N <= 100) children is standing in circle and they are passing a ball. In the beginning, the ball is in the first child's hands. 
  Every child passes the ball to the same child (it's best friend). Make a program that prints who has the ball after the first x 
  (0 < x <= 1000) ball passes. Input data is N, x, a1, a2, ..., aN (0 < ai <= N). ai is the number of the child to which the child
  with number i will pass the ball.

  The solution below is mine, generated before looking at the book's solution.
 */

#include <iostream>

using namespace std;

constexpr int MAX_NUMBER_OF_CHILDREN = 100;

int main()
{
  int N;
  int x;
  int A[MAX_NUMBER_OF_CHILDREN];
  cin >> N >> x;
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  int current_child = 1;
  for (int i = 0; i < x; i++)
  {
    cout << A[current_child - 1] << " ";
    current_child = A[current_child - 1];
  }
  cout << endl;
  return 0;
}
