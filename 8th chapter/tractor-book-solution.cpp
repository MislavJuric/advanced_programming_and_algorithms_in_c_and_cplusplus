/*
  Exercise taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Page 313

  In the entire village only Domagoj has a tractor. Domagoj rents out the tractor. The villagers have given DOmagoj their requests for renting out the tractor. He has n requests
  in total and every request consists of two numbers a and b, which means that some villager wants to hire the tractor on day a and return it on day b (on day b the tractor can get
  rented out again). DOmagoj wants to rent out the tractor in such a way that it is rented out as much as possible, so that he can earn the most money and so that he has to work 
  the least. (There is an unwritten rule that tractor has to be at work constantly, so when the tractor isn't rented, Domagoj takes it to the field). Sometimes it happens that multiple
  requests for renting out the tractor start on the same day, so Domagoj has to choose to whom the tractor will be rented out. If the tractor is free on day x and there is a request for
  renting out the tractor from day x, then Domagoj has to rent out the tractor (so that the villagers don't get angry at him). The input data is n (1 <= n <= 1000000) and
  m (1 <= m <= 1000000) and then n times two numbers a and b which describe a particular request (0 <= a < b <= m). Print out the maximum amount of days the tractor can be rented out.

  The solution here is the book's solution.
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
  vector<vector<int>> requests(m + 1);
  vector<int> hasRequest(m + 1, 0);
  int a, b;
  for (int i = 0; i < n; i++)
  {
    cin >> a >> b;
    requests[b].push_back(a);
    hasRequest[a] = 1;
  }
  vector<int> DP(m, -inf); // minus!
  DP[0] = 0; // initialization
  for (int i = 1; i <= m; i++)
  {
    if (!hasRequest[i - 1])
    {
      DP[i] = DP[i - 1]; 
    }
    for (int j = 0; j < requests[i].size(); j++)
    {
      a = requests[i][j];
      DP[i] = max(DP[i], DP[a] + (i - a)); 
    }
  }
  cout << DP[m] << endl;
  return 0;
}

