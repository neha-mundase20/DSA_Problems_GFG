//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template
class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Min-heap priority queue: {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        int n = adj.size(); // Number of vertices
        vector<int> dist(n, INT_MAX); // Distance vector initialized to infinity
        
        dist[src] = 0;    // Distance to the source is always zero
        pq.push({0, src}); // Push the source into the priority queue
        
        while (!pq.empty()) {
            // Get the top element of the priority queue (shortest distance so far)
            int curr_dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            // Skip if this distance is already outdated
            if (curr_dist > dist[node]) continue;
            
            // Traverse all neighbors of the current node
            for (pair<int, int> neighbor_pair : adj[node]) {
                int neighbor = neighbor_pair.first;
                int weight = neighbor_pair.second;

                // Relax the edge (node -> neighbor)
                if (dist[node] + weight < dist[neighbor]) {
                    dist[neighbor] = dist[node] + weight; // Update the shortest distance
                    pq.push({dist[neighbor], neighbor}); // Push updated distance into priority queue
                }
            }
        }
        
        return dist; // Return the shortest distances from the source to all vertices
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends