#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to check for a cycle in an undirected graph using BFS
bool isCycleBFS(int n, vector<vector<int>>& adj) {
    vector<bool> visited(n, false);

    for (int start = 0; start < n; start++) {
        if (!visited[start]) {
            // BFS for each connected component
            queue<pair<int, int>> q; // (node, parent)
            q.push({start, -1});
            visited[start] = true;

            while (!q.empty()) {
                auto [node, parent] = q.front();
                q.pop();

                for (int neighbor : adj[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push({neighbor, node});
                    } else if (neighbor != parent) {
                        // If visited and not the parent, cycle detected
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    int n = 5; // Number of nodes
    vector<vector<int>> adj(n);

    // Add edges (undirected graph)
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[3].push_back(4);
    adj[4].push_back(3);

    adj[4].push_back(1); // Cycle: 4 -> 1

    if (isCycleBFS(n, adj)) {
        cout << "Cycle detected!" << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    return 0;
}
