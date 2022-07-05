#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> edge[100];
int visited[100];

vector<vector<int>> connected_components;
vector<int> current_connected_components;

void dfs(int vertex)
{
    // jekono ekta source dhore oita ke visit korbo
    // if (visited[source] != 1)
    // {
    //     // cout << "Marked the node: " << source << endl;
    // }
    current_connected_components.push_back(vertex);
    visited[vertex] = 1;

    for (int node : edge[vertex])
    {
        if (!visited[node])
        {
            // assuming x as source we go to the depth
            // cout << "The node " << x << " is not visited so call dfs(" << x << ")" << endl;
            dfs(node);
        }
    }
    // cout << "Comming from : " << source << endl;
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

    // If connected graph
    // dfs(1);

    // Otherwise call for each node
    for (int i = 1; i <= node; i++)
    {
        if (!visited[i])
        {
            // total number of call on dfs() is the number of connected_components in a graph
            current_connected_components.clear();
            dfs(i);
            connected_components.push_back(current_connected_components);
        }
    }

    for (auto x : connected_components)
    {
        for (int y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
    // cout << connected_components.size() << endl;
}
