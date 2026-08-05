class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n,0);
        vector<bool> suspicius(n, false);

        for(int i=0; i<invocations.size(); i++){
            int u = invocations[i][0];
            int v = invocations[i][1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        q.push(k);
        suspicius[k]=true;

        while(!q.empty()){
            int front = q.front();
            q.pop();

            for(auto neigh:adj[front]){
                indegree[neigh]--;
                if(!suspicius[neigh]){
                    q.push(neigh);
                    suspicius[neigh]=true;
                }
            }
        }

        for(int i=0; i<n; i++){
            if(suspicius[i]==true && indegree[i]>0){
                vector<int> ans;
                for(int i=0; i<n; i++){
                    ans.push_back(i);
                }

                return ans;
            }
        }

        vector<int> ans;
        for(int i=0; i<n; i++){
            if(!suspicius[i])
                ans.push_back(i);
        }

        return ans;
    }
};