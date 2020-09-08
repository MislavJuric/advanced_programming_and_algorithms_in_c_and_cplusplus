/*
  Exercise taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Page 341-342

  The student cantina serves 5 varieties of dishes to the students. The cook puts the portions of the meal from big bowls. There are 5 bowls, each with the corresponding meal.
  The problem is that not all meals can be served at once, because on the cook's table only 2 bowls can be placed. When a student comes to the cook and says which of the 5 meals
  he / she wants to eat, if the meal is not on the table, the cook has to remove one of the bowls from the table, take it to the kitchen and get back with a bowl which contains the
  meal the student wants and put it on the table, so she could serve the meal the student wants. Every one of the 5 meals is of differing weight, so each requires a certain amount
  of time to get carried over from the kitchen to the table, or from the table to the kitchen. The cook managed to find out the order sequence of the meals and wants to serve
  the meals as fast as possible. The input data is 5 numbers t (1 <= t <= 1000), which describe the time in seconds required for the meal to be put on the table or removed
  from the table. After that n (1 <= n <= 100000) and then n numbers x (1 <= x <= 5) are inputted, which describe, in order, the meals the students want to eat.
  Serving the meal which is on the pult lasts for 10 seconds. There is no need to wait for the students because all the students are in a line awaiting their portions.
  Before the first student arrives, the cook can put any two bowls on the table. Print out the minimum number of seconds required to serve all the students.

  The solution here is the book's solution.
*/

#include <algorithm>
#include <iostream>

using namespace std;

int n;
int meal[5];
int student[100000];
int memo[5][5][100000]; // memoization
const int inf = 1000000000;

int rec(int a, int b, int x)
{
  if (x == -1)
  {
    return 0;
  }
  if (memo[a][b][x] != inf)
  {
    return memo[a][b][x];
  }

  if (a != student[x] && b != student[x])
  {
    return (memo[a][b][x] = inf);
  }

  int ret = inf;
  if (a == student[x])
  {
    for (int i = 0; i < 5; i++)
    {
      if (i != a)
      {
	ret = min(ret, rec(i, b, x-1) + meal[i] + meal[a] + 10);
      }
    }
    if (b == student[x])
    {
      for (int i = 0; i < 5; i++)
      {
	if (i != b)
	{
	  ret = min(ret, rec(a, i, x-1) + meal[i] + meal[b] + 10);
	}
      }
    }
    ret = min(ret, rec(a, b, x-1) + 10); // don't understand this line - it would be useful to write a few steps of this recursion with pen & paper, to see what this does
  }
  return (memo[a][b][x] = ret);
}

int main()
{
  for (int i = 0; i < 5; i++)
  {
    cin >> meal[i];
  }
  cin >> n;
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      for (int k = 0; k < n; k++)
      {
	memo[i][j][k] = inf;
      }
    }
  }
  for (int i = 0; i < n; i++)
  {
    cin >> student[i];
    student[i]--;
  }
  int solution = inf;
  for (int i = 0; i < 5; i++)
  {
    solution = min(solution, rec(i, student[n-1], n-1));
  }
  cout << solution << endl;
  return 0;
}
