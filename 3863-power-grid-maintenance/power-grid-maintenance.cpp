class Solution {
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& component) {
        vis[node] = true;
        component.push_back(node);
        for (int neighbor : adj[node]) {
            if (!vis[neighbor]) {
                dfs(neighbor, adj, vis, component);
            }
        }
    }
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<vector<int>> adj(c + 1);
        for (auto& edge : connections) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> vis(c + 1, false);
        vector<vector<int>> components;
        for (int i = 1; i <= c; i++) {
            if (!vis[i]) {
                vector<int> component;
                dfs(i, adj, vis, component);
                components.push_back(component);
            }
        }
        // Next layer: process the queries using these components
        vector<int> stationToComp(c + 1);
        vector<set<int>> compStations(components.size());
        vector<bool> isOnline(c + 1, true);
        
        for (int i = 0; i < components.size(); i++) {
            for (int station : components[i]) {
                stationToComp[station] = i;
                compStations[i].insert(station);
            }
        }
        
        vector<int> result;
        for (auto& query : queries) {
            int type = query[0];
            int x = query[1];
            
            if (type == 1) {
                if (isOnline[x]) {
                    result.push_back(x);
                } else {
                    int compIdx = stationToComp[x];
                    if (compStations[compIdx].empty()) {
                        result.push_back(-1);
                    } else {
                        result.push_back(*compStations[compIdx].begin());
                    }
                }
            } else if (type == 2) {
                if (isOnline[x]) {
                    isOnline[x] = false;
                    int compIdx = stationToComp[x];
                    compStations[compIdx].erase(x);
                }
            }
        }
        
        return result;
    }
};