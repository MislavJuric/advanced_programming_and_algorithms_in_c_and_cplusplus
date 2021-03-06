/*
  Exercise taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Pages 284-285

  In a bakery a burek is being sold. On the beginning of the day n bureks are baked, each one with quality of x. As time passes, new bureks are baked of differing quality, customers come
  and buy bureks. When a customer comes, he tells the baker: "Give me the best burek you've got!". The baker chooses the best burek she has and sells it to him.
  Help the bakery do business as best as possible by enabling the baker to always sell the best burek. n (1 <= n <= 100000) and after that n numbers x are inputted. The number x describes the
  quality of the burek. After that m is inputted, then m (1 <= m <= 100000) numbers y. y describes the events that take place during the day. If y is 0, it means that a customer came along and bought
  the best burek, so the quality of the sold burek must be printed out or "None!" if there are no bureks. If y is not 0, that means that a new burek is baked with quality y which can be bought
  from that moment on.

  The point of this exercise is to implement the heap data structure without using STL.

  The solution here is mine (before looking at the book's solution).
*/

#include <iostream>

using namespace std;

class Heap // could be parametarized with a template, but right now I'm just focused on implementing the heap
           // this is a max heap
{
  private:

    struct Node
    {
      int value; 
      Node* rightChild;
      Node* leftChild;
      Node* parent;
    };
  
    Node* heap_root = null;
    Node* last_inserted = null; // points at the lastly inserted element on the heap

  public:

    Heap() { }
  
    void insert_into_heap(int arg)
    {
      if (heap_root == null)
      {
	heap_root = new Node{arg, null, null, null};
	last_inserted = heap_root;
      }
      else
      {
	// figure out who will be the parent of the new element
	if (last_inserted == last_inserted->parent->rightChild) // if this holds, you have to go to the parent of the last inserted's sibling
	{

	}
	// TODO: Try a better way of doing this - I'd have to "look up" to last_inserted->parent's parent and then see if last_inserted->parent is his right child etc...
	// this would entail complicated recursions...(first going up, then down). There must be a better way, but I don't see it currently
	
	// construct the new element
	Node* new_heap_element = new Node{arg, null, null, };
        // attach the new element at the right place in the heap (bubble up)
      }
    }
};

int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    insert_into_heap(x, heap);
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; i++)
  {
    int y;
    cin >> y;
    if (y == 0)
    {
      int best = pop_heap();
      if (best != -1) // let's say -1 indicates no bureks available for sale
      {
	cout << best << " ";
      }
      else
      {
	cout << "None!" << " ";
      }
    }
    else
    {
      insert_into_heap(y);
    }
  }
  return 0;
}
