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

  This is my solution before looking at the book's solution.
*/

#include <iostream>

using namespace std;

// "Aborting mission" and looking at the book's solution after trying to debug for a short while

int main()
{
  int arr[1000];
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  int temp = 0;
  int index = 0;
  cout << arr[index] << " ";
  while (temp < (n - 1))
  {
    int old_index = index;
    int curr = arr[index];
    int count = 0;
    while (count < curr)
    {
      if (arr[index] == -1)
      {
	continue;
      }
      if (arr[index] == curr)
      {
	index++;
	continue;
      }
      index++;
      count++;
    }
    index = index % n;
    cout << arr[index] << " ";
    arr[old_index] = -1;
    temp++;
  }
  cout << endl;
  return 0;
}
