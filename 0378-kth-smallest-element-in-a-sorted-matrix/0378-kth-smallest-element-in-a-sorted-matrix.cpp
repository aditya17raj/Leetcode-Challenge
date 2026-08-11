class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();

        priority_queue<int> maxHeap;

        for(int i=0;i <n; i++){
            for(int j=0; j<m; j++){
                int element = matrix[i][j];

                maxHeap.push(element);
                if(maxHeap.size() > k){
                    maxHeap.pop();
                }
            }
        }

        return maxHeap.top();
    }
};