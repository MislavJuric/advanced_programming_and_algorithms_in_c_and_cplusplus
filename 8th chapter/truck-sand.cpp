/*
  Exercise taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Pages 332-333

  Sand is poured in a truck. In the truck x m^3 of sand can be placed. There are in total n kinds of sand. The input data is n (1 <= n <= 100000) and x, and then n pairs of numbers a and b which describe
  a certain type of sand. a is the amount of sand in m^3 which we have, while b is the total value of the a m^3 of sand. The truck should be loaded so that the total value inside it is as large
  as possible. From every type of sand we can take as much m^3 as we want (we don't have to always take the entire a).

  The solution here is the book's solution. It is a greedy solution.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
  int n, x; cin >> n >> x;
  vector<pair<double, int>> input;
  int a, b;
  for (int i = 0; i < n; i++)
  {
    cin >> a >> b;
    input.push_back(make_pair((double) b / a, a));
  }
  sort(input.begin(), input.end());
  double solution = 0;
  for (int i = n - 1; i >= 0; i--)
  {
    if (input[i].second < x)
    {
      x -= input[i].second;
      solution += input[i].second * input[i].first;
    }
    else
    {
      solution += x * input[i].first;
      break;
    }
  }
  cout << solution << endl;
  return 0;
}
