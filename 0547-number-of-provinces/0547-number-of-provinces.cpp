class Solution {
public:
    void bfs(int node, vector<vector<int>>& isConnected,
             vector<bool>& visited) {

        queue<int> q;
        q.push(node);
        visited[node] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int nei = 0; nei < isConnected.size(); nei++) {
                if (isConnected[curr][nei] == 1 && !visited[nei]) {
                    visited[nei] = true;
                    q.push(nei);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();

        vector<bool> visited(n, false);

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                bfs(i, isConnected, visited);
                cnt++;
            }
        }

        return cnt;
    }
};