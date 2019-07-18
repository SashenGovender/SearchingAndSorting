#include <iostream>
#include <queue>
#include <stack>
#include <vector>

class Searching
{
public:

   //-------------------------------------------------------------------------------------------------------------------------

   int BinarySearch(int arr[], int startIndex, int endIndex, int key)
   {
      while (startIndex <= endIndex)
      {
         int middle = (startIndex + endIndex) / 2;
         if (arr[middle] < key)
         {
            startIndex = middle + 1;
         }
         else if (arr[middle] > key)
         {
            endIndex = middle - 1;
         }
         else
         {
            return middle;
         }
      }
      return -1;
   }

   //-------------------------------------------------------------------------------------------------------------------------
   void DepthFirstSearch()
   {
      std::vector <int> adj[10];
      bool visited[10];

      int nodes, edges;
      std::cin >> nodes; //Number of nodes
      std::cin >> edges; //Number of edges

      int x, y;
      for (int i = 0; i < edges; i++)
      {
         std::cin >> x >> y;
         adj[x].push_back(y);                   //Edge from vertex x to vertex y
         adj[y].push_back(x);                   //Edge from vertex y to vertex x
      }

      for (int i = 0; i < nodes; i++)
      {
         visited[i] = false;
      }

      int startNode;
      std::cin >> startNode;

      std::stack <int> st;

      st.push(startNode);
      while (!st.empty())
      {
         int v = st.top();
         st.pop();

         if (visited[v] == false)//check if the vertex has been visited
         {
            visited[v] = true;
            for (int u : adj[v])
            {
               if (visited[u] == false)
               {
                  st.push(u);
               }
            }
         }
      }

      int visit = 0;
      for (int i = 0; i < nodes; i++) {
         if (visited[i] == false) {
            visit++;
         }
      }
      std::cout << visit;
   }

   void BreathFirstSearch()
   {
      std::vector <int> adj[10];
      bool visited[10];

      int nodes, edges;
      std::cin >> nodes; //Number of nodes
      std::cin >> edges; //Number of edges

      int x, y;
      for (int i = 0; i < edges; i++)
      {
         std::cin >> x >> y;
         adj[x].push_back(y);                   //Edge from vertex x to vertex y
         adj[y].push_back(x);                   //Edge from vertex y to vertex x
      }

      for (int i = 0; i < nodes; i++)
      {
         visited[i] = false;
      }

      int startNode;
      std::cin >> startNode;

      std::queue<int> qu;
      qu.push(startNode);

      while (!qu.empty())
      {
         int v = qu.front();
         qu.pop();

         if (visited[v] == false)//check if the vertex has been visited
         {
            visited[v] = true;
            for (int u : adj[v])
            {
               if (visited[u] == false)
               {
                  qu.push(u);
               }
            }
         }
      }

      int visit = 0;
      for (int i = 0; i < nodes; i++) {
         if (visited[i] == false) {
            visit++;
         }
      }
      std::cout << visit;
   }
};