/*
  Exercise taken from from Kusalić, D. (2012). Napredno programiranje i algoritmi u C-u i C++-u (3rd ed.). Element. Page 234

  Students from a class are passing a ball. Every student randomly picks one of his/her friends and passes the ball. Not all students are friends.
  What is the least amount of balls the professor has to give to the students in order for everyone to get the ball? 

  Input data is number of students: n (2 <= n <= 10000) and m (1 <= m <= 100000), and then m pairs of numbers a and b (1 <= a,b <= n).
  a and b represent the students which are friends.

  The solution here is mine, before looking at the book's solution.
*/

#include <iostream>
#include <queue>

using namespace std;

int count = 0;

void flood_fill(int n, int **adjecency_matrix, bool visited[])
{
  queue<int> to_process;
  for (int current_node_index = 0; current_node_index < n; current_node_index++)
  {
    if (visited[current_node_index] == false)
    {
      visited[current_node_index] = true;
      count++;
      to_process.push(current_node_index);
      while (!to_process.empty()) // infinite loop
      {
	current_node_index = to_process.front();
	to_process.pop();
	for (int i = 0; i < n; i++)
	{
	  if ((adjecency_matrix[current_node_index][i] == 1) && (visited[i] == false))
	  {
	    visited[i] = true;
	    to_process.push(i);
	  }
	}
      }
    }
  }
}

int main()
{
  int n, m;
  cin >> n >> m;
  int **adjecency_matrix = new int*[n];
  for (int i = 0; i < n; i++)
  {
    adjecency_matrix[i] = new int[n];
  }
  bool *visited = new bool[n];
  for (int i = 0; i < n; i++)
  {
    visited[i] = false;
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      adjecency_matrix[i][j] = 0;
    }
  }
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    adjecency_matrix[a-1][b-1] = 1;
    adjecency_matrix[b-1][a-1] = 1;
  }
  flood_fill(n, adjecency_matrix, visited);
  cout << count << endl;
  delete[] adjecency_matrix;
  delete[] visited;
  return 0;
}
