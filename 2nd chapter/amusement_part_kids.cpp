/*
  Exercise taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Page 98
  Exercise text translated from Croatian to English by me.

  A teacher is brining children to an amusement park. When the children are having fun the teacher has to pay for it; otherwise she doesn't have to.
  Each kid selects in advance when it willl have fun. The teacher pays every minute in proportion to the number of children having fun.
  The input is n (1 <= n <= 100 000) and m (1 <= m <= 1 000 000). Then there is n a,b pairs (1 <= a <= b <= 100 000) where very pair represents
  an inclusive interval within which a child is having fun. If in one minute x number of children is having fun, then that minute the teacher 
  pays (m - x) * x money. (There will never be more than m kids having fun). How much money will the teacher spend?

  This solution was generated before looking at the book's solution.
*/

// struct koji sadržava brojeve a i b za intervale i u for petlji ideš po vremenskim trenucima od 1 do najvećeg i brojiš koliko djece je tu (test sa veće od donje granice manje od gornje granice)

#include <iostream>

using namespace std;

struct Interval
{
  int a;
  int b;
};

int main()
{
  int n, m;
  cin >> n >> m;
  Interval intervals[100000]; // maximum number of intervals
  int maximum = 0;
  int total_price = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> intervals[i].a >> intervals[i].b;
    if (intervals[i].b > maximum)
    {
      maximum = intervals[i].b;
    }
  }
  for (int i = 1; i <= maximum; i++) // iterating over discrete time moments
  {
    int children_count = 0;
    for (int j = 0; j < n; j++)
    {
      if ((i >= intervals[j].a) && (i <= intervals[j].b))
      {
	children_count++;
      }
    }
    total_price += ((m - children_count) * children_count);
  }
  cout << total_price << endl;
}
