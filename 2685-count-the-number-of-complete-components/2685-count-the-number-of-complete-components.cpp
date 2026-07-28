class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& adj, vector<bool> &visited, int node, int &vertexCount, int &edgeSum){
        visited[node] = true;
        vertexCount ++;
        edgeSum += adj[node].size();

        for(auto neigh:adj[node]){
            if(!visited[neigh]){
                dfs(adj, visited, neigh, vertexCount, edgeSum);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        for(int i=0; i<edges.size(); i++){
            int u=edges[i][0];
            int v=edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n,false);
        int completeComponents=0;

        for(int i=0; i<n; i++){
            if(!visited[i]){
                int vertexCount=0;
                int edgeSum=0;

                dfs(adj, visited, i, vertexCount, edgeSum);

                if((vertexCount * (vertexCount-1)) == edgeSum)
                    completeComponents++;
            }
        }

        return completeComponents;
    }
};