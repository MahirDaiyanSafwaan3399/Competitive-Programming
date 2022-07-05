#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> edge[100];
int visited[100];

bool dfs(int vertex, int parent_node)
{
    bool ans = false;
    visited[vertex] = 1;

    for (int node : edge[vertex])
    {
        if (!visited[node])
        {

            ans |= dfs(node, vertex);
        }
        else if (node != parent_node and visited[node])
        {
            return true;
        }
    }
    return ans;
}

void AddEdge(int u, int v)
{
    edge[u].push_back(v);
}

int main()
{
    int node, number_of_edges;
    cin >> node >> number_of_edges;

    for (int i = 0; i < number_of_edges; i++)
    {
        int u, v;
        cin >> u >> v;
        // connects u with v (u,v);
        // if directed graph
        AddEdge(u, v);
        AddEdge(v, u);
    }
    bool ans = false;
    for (int i = 1; i <= node; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, 0))
            {
                ans = true;
                break;
            }
        }
    }
    if (ans)
    {
        cout << "Cycle found\n";
    }
    else
    {
        cout << "Cycle not found\n";
    }
}
