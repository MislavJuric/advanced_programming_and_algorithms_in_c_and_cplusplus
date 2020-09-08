/*
  Task text taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Page 182

  Numbers are arranged in a circle and they are passing frisbee. n is inputted (1 <= n <= 1000) and after that n natural numbers
  less than 10^9. Second number is to the right of the first one, third number is to the right of the second one etc.
  The first number is to the right of the last one. At the beginning the first number has the frisbee. If the first number is 5, then he will
  step out of the circle and pass the frisbee to the 5th number to its right. The number who gets the frisbee will step out of the circle and
  pass it to the x-th element to the right, if its value is . Numbers leave the circle and toss the frisbee. Print the numbers in the order
  they left the circle.

  For example, let's say the input is:

  4
  5 7 153 3
  
  In the cricle there are 4 numbers. First number is 5 and it has the frisbee. 5 steps out of the circle and passes the frisbee to the 5th element to its right.
  First element to its right is 7, second is 153, third is 3, fourth is 7 and fifth is 153. Now 153 has the frisbee and steps out of the cricle.
  153 passes the frisbee to the 153. element to its right. First element to its right is 3, second one is 7, third one is 3 etc. 153. element to the right of
  153 is 3. Now 3 has the frisbee, exits the circle and passes it to the 3rd element to its right. First element to its right is a 7, second one to its right is a 7 and
  the third one to its right is a 7. 7 is the last one to hold the frisbee and exits the circle.

  This is the book's solution.
*/

#include <iostream>

using namespace std;

int main()
{
  int n, i, j, frisbee;
  int next, previous, steps;
  int circle[1000][3]; // multiple dimensions used to remember next and previous element information
  cin >> n;
  for (i = 0; i < n; i++)
  {
    cin >> circle[i][0];
    circle[i][1] = i - 1; // previous
    circle[i][2] = i + 1; // next
  }
  circle[n-1][2] = 0; // connecting the last one to the first one
  circle[0][1] = n - 1; // connecting the first one to the last one

  frisbee = 0; // number on index 0 has a frisbee
  for (i = n-1; i; i--) // i tells us how much numbers are there in a circle
  {
    cout << circle[frisbee][0] << " ";
    next = circle[frisbee][2];
    previous = circle[frisbee][1];
    steps = circle[frisbee][0] % i; // which one to the right of the current frisbee holder will get the frisbee - the formula makes sense if you write it down and plug in concrete numbers
    circle[previous][2] = next; // removing a number from the circle
    circle[next][1] = previous; // removing a number from the cricle

    for (j = 0; j < steps; j++)
    {
      frisbee = circle[frisbee][2]; // go to the next element
    }
    if (!steps) // if the loop didn't run
    {
      frisbee = circle[frisbee][1];
    }
  }
  cout << circle[circle[frisbee][2]][0] << endl; // last one remaining
  return 0;
}
