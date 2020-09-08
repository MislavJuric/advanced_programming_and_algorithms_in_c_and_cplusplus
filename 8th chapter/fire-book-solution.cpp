/*
  Exercise taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Pages 310-311

  A fire caught n (2 <= n <= 1000) trees which are aligned on a line. The tree's worths are different. Every hour the fire deals a certain tree x damage. The firemen are at the m-th tree
  and they have to put out the fire with the least amount of damage as possible (they first put out the fire on the m-th tree). Durign their operation the firemen can't pass by a tree
  without putting out a fire (in an moment the trees where the fire is put out are a continous array of trees). The firemen need 1 hour to put out the fire (they don't spend time while
  traversing between trees). The damage is done all the while firefighters don't put out the fire completely (which means even in the 1 hour of putting the fire out). The input data is n
  and m (0 <= m < n). m is a 0-indexed number which signifies the tree at which the firefighters begin their operation. Then there is n integers x (1 <= x <= 1000) which describe (in order)
  trees aligned on the line. Print out the minimum damage that will be done while all the fires on all the trees will be put out.

  This is the book's solution.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  const int inf = 1000000000;
  int n, m;
  cin >> n >> m;
  vector<int> damage(n);
  for (int i = 0; i < n; i++)
  {
    cin >> damage[i];
  }
  vector<int> vi(n, inf);
  vector<vector<int>> DP(n, vi);
  DP[m][m] = damage[m]; // initialization
  for (int i = 1; i < n; i++) // interval width
  {
    for (int j = 0; j < (n - i); j++) // the beginning tree of the interval
    {
      DP[j][j + i] = min(DP[j + 1][j + i] + damage[j]*(i + 1), DP[j][j + i - 1] + damage[j + i] * (i + 1));
    }
  }
  cout << DP[0][n - 1] << endl;
  return 0;
}
