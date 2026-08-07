class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int,int> degree;

        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            degree[u]++;
            degree[v]++;
        }

        for(auto it : degree) {
            if(it.second == edges.size())
                return it.first;
        }

        return -1;
    }
};