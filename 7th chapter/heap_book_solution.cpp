/*
  Exercise taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Pages 284-286

  In a bakery a burek is being sold. On the beginning of the day n bureks are baked, each one with quality of x. As time passes, new bureks are baked of differing quality, customers come
  and buy bureks. When a customer comes, he tells the baker: "Give me the best burek you've got!". The baker chooses the best burek she has and sells it to him.
  Help the bakery do business as best as possible by enabling the baker to always sell the best burek. n (1 <= n <= 100000) and after that n numbers x are inputted. The number x describes the
  quality of the burek. After that m is inputted, then m (1 <= m <= 100000) numbers y. y describes the events that take place during the day. If y is 0, it means that a customer came along and bought
  the best burek, so the quality of the sold burek must be printed out or "None!" if there are no bureks. If y is not 0, that means that a new burek is baked with quality y which can be bought
  from that moment on.

  The point of this exercise is to implement the heap data structure without using STL.

  The solution here is the book's solution.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> heap;

void push(int x)
{
  heap.push_back(x);
  int t = heap.size() - 1;
  while (t/2 && heap[t] > heap[t/2])
  {
    heap[t] ^= heap[t/2];
    heap[t/2] ^= heap[t];
    heap[t] ^= heap[t/2];
    t /= 2;
  }
}

void pop()
{
  heap[1] = heap.back();
  heap.pop_back();
  int t = 1, r;
  while (1)
  {
    if (t*2 + 1 < heap.size())
    {
      if (heap[t*2] > heap[t*2 + 1])
      {
	r = t*2;
      }
      else
      {
	r = t*2 + 1;
      }
    }
    else if (t*2 < heap.size())
    {
      r = t*2;
    }
    else
    {
      break;
    }
    if (heap[r] > heap[t])
    {
      heap[r] ^= heap[t];
      heap[t] ^= heap[r];
      heap[r] ^= heap[t];
      t = r;
    }
    else
    {
      break;
    }
  }
}

int main()
{
  heap.push_back(0); // index 0 is not used
  int n, x;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    push(x); // fill in the heap
  }
  int m, y;
  cin >> m;
  for (int i = 0; i < m; i++)
  {
    cin >> y;
    if (!y) // a customer came in (!0 == 1)
    {
      if (heap.size() > 1)
      {
	cout << heap[1] << " ";
	pop();
      }
      else
      {
	cout << "None! ";
      }
    }
    else
    {
      push(y);
    }
  }
  return 0;
}
