/*
  Task text taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Page 158

  Write out all the permutations of the array "abcde"

  This program was written before looking at the book's solution
*/

#include <iostream>
#include <vector>

using namespace std;


// iterative solution I tried to construct before the recursive one
// I find it hard to systematically generate permutations, even on paper - I get confused
// I should first do this systematic generation on paper, then switch to iterative code, then to recursive code

void permute_iterative(vector<char>& arr)
{
  for (int i = 0; i < arr.size(); i++)
  {
    for (int j = 0; j < arr.size(); j++)
    {
      char temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      cout << arr[0] << arr[1] << arr[2] << arr[3] << arr[4] << endl;
      arr[j] = arr[i];
      arr[i] = temp;
    }
  }
}

int main()
{
  vector<char> arr {'a', 'b', 'c', 'd', 'e'};
  permute_iterative(arr);
  return 0;
}
