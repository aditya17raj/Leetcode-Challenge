class Solution {
public:
    bool bfs(int src, vector<int> &vis, vector<vector<int>>& graph){
        queue<int> q;
        q.push(src);
        vis[src] = 0;

       while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto neigh : graph[node]){
                if(vis[neigh] == -1){
                    q.push(neigh);
                    vis[neigh] = vis[node]==0?1:0;
                }
                else{
                    if(vis[neigh] == vis[node])
                        return false;
                }
            }
       }

       return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();

        vector<int> vis(V, -1);

        for(int i=0; i<V; i++){
            if(vis[i] == -1){
                bool ans = bfs(i, vis, graph);

                if(ans == false) return false;
            }
        }

        return true;
    }
};