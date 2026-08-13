class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        priority_queue<pair<int,int>> maxHeap;

        for(int num : arr) {

            int diff = abs(num - x);

            maxHeap.push({diff, num});

            if(maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        vector<int> ans;

        while(!maxHeap.empty()) {
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};