/*
  Exercise taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Pages 310-311

  A fire caught n (2 <= n <= 1000) trees which are aligned on a line. The tree's worths are different. Every hour the fire deals a certain tree x damage. The firemen are at the m-th tree
  and they have to put out the fire with the least amount of damage as possible (they first put out the fire on the m-th tree). Durign their operation the firemen can't pass by a tree
  without putting out a fire (in an moment the trees where the fire is put out are a continous array of trees). The firemen need 1 hour to put out the fire (they don't spend time while
  traversing between trees). The damage is done all the while firefighters don't put out the fire completely (which means even in the 1 hour of putting the fire out). The input data is n
  and m (0 <= m < n). m is a 0-indexed number which signifies the tree at which the firefighters begin their operation. Then there is n integers x (1 <= x <= 1000) which describe (in order)
  trees aligned on the line. Print out the minimum damage that will be done while all the fires on all the trees will be put out.

  The solution here is mine, before I looked at the book's solution.

  Note: There's a bug somewhere below, not sure exactly where.
*/

/*
  Here I have fiddled with the indicies so that I figure out how to achieve the numbers below

  counter = 0
  1 1
  2 2
  3 3
  
  counter = 1
  1 2
  2 3
  3 4

  counter = 2
  i < (n - counter - 1)
  j = (i + counter); j <= (i + counter); j++
  1 3
  2 4
  3 5
*/

#include <iostream>
#include <algorithm>

using namespace std;

#define INF 1000000

int main()
{
  int n, m;
  cin >> n >> m;
  int damage[n];
  int intervals[n][n];
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    damage[i] = x;
  }
  int hour = 1;
  for (int i  = 0; i < n; i++)
  {
    intervals[i][i] = INF;
  }
  intervals[m][m] = 0;
  int counter = 0;
  while (counter != n)
  {
    for (int i = 0; i < (n - counter); i++)
    {
      for (int j = (i + counter); j <= (i + counter); j++)
      {
	int putting_out_fire_low = damage[i] * hour;
	int putting_out_fire_high = damage[j] * hour;
	intervals[i][j] = min((intervals[i][j - 1] + putting_out_fire_high), (intervals[i + 1][j] + putting_out_fire_low));
      }
      hour++;
    }
    counter++;
  }
  cout << intervals[0][n - 1] << endl;
  return 0;
}
