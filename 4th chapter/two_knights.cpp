/*
  Implementation taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Page 173

  Input the numbers a, b, c and d (1 <= a, b, c, d <= 8) which represent two locations of knights on a chessboard. Then input x (1 <= x < 10) and check 
  whether the knight can come from the field (a, b) to the field (c, d) in x or less moves.

  A caveat: My code checks not only if the knight from (a, b) can come to (c, d), but it checks all possible combinations of movements of the two knights

  I wrote this before looking at the book's solution. After that, I added the corrections as indicated in the comments. The book also uses memoization in its solution.
*/

#include <iostream>
#include <vector>

using namespace std;

struct OffsetPair
{
  int x;
  int y;
};

vector<OffsetPair> offset_pairs{OffsetPair{-1, -2}, OffsetPair{-2, -1}, OffsetPair{-2, 1}, OffsetPair{-1, 2}, OffsetPair{1, 2}, OffsetPair{2, 1}, OffsetPair{2, -1}, OffsetPair{1, -2}};
int rec_count = 0; // number of times recursion was called - for debugging purposes

bool check(int a, int b, int c, int d, int x)
{
  rec_count++;
  // I added this if. I forgot to check for boundary conditions.
  if ((a < 0) || (a > 7) || (b < 0) || (b > 7) || (c < 0) || (c > 7) || (d < 0) || (d > 7))
  {
    return false;
  }
  if (x == 0)
  {
    return false;
  }
  if ((a == c) && (b == d) && (x > 0))
  {
    return true;
  }
  return (check(a + offset_pairs[0].x, b + offset_pairs[0].y, c, d, x - 1) ||
	  check(a + offset_pairs[1].x, b + offset_pairs[1].y, c, d, x - 1) ||
	  check(a + offset_pairs[2].x, b + offset_pairs[2].y, c, d, x - 1) ||
	  check(a + offset_pairs[3].x, b + offset_pairs[3].y, c, d, x - 1) ||
	  check(a + offset_pairs[4].x, b + offset_pairs[4].y, c, d, x - 1) ||
	  check(a + offset_pairs[5].x, b + offset_pairs[5].y, c, d, x - 1) ||
	  check(a + offset_pairs[6].x, b + offset_pairs[6].y, c, d, x - 1) ||
	  check(a + offset_pairs[7].x, b + offset_pairs[7].y, c, d, x - 1) ||
	  check(a, b, c + offset_pairs[0].x, d + offset_pairs[0].y, x - 1) ||
	  check(a, b, c + offset_pairs[1].x, d + offset_pairs[1].y, x - 1) ||
	  check(a, b, c + offset_pairs[2].x, d + offset_pairs[2].y, x - 1) ||
	  check(a, b, c + offset_pairs[3].x, d + offset_pairs[3].y, x - 1) ||
	  check(a, b, c + offset_pairs[4].x, d + offset_pairs[4].y, x - 1) ||
	  check(a, b, c + offset_pairs[5].x, d + offset_pairs[5].y, x - 1) ||
	  check(a, b, c + offset_pairs[6].x, d + offset_pairs[6].y, x - 1) ||
	  check(a, b, c + offset_pairs[7].x, d + offset_pairs[7].y, x - 1)    );
}

int main()
{
  int a, b, c, d, x;
  cin >> a >> b >> c >> d >> x;
  // I added the decrements below; I need my coordinates to be zero based
  a--;
  b--;
  c--;
  d--;
  if (check(a, b, c, d, x))
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
  cout << rec_count << endl;
  return 0;
}
