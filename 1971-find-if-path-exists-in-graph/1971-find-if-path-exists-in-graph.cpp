class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination)
            return true;
            
        unordered_map<int, vector<int>> adj;
        for(int i=0; i<edges.size(); i++){
            int u=edges[i][0];
            int v=edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        queue<int> q;
        q.push(source);
        visited[source]=true;

        while(!q.empty()){
            int front=q.front();
            q.pop();

            for(auto neigh:adj[front]){
                if(neigh == destination){
                    return true;
                }
                if(!visited[neigh]){
                    q.push(neigh);
                    visited[neigh]=true;
                }
            }
        }

        return false;
    }
};