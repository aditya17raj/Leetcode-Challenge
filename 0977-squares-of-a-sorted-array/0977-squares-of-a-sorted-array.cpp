class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());

        int i=0, j=nums.size()-1, k=nums.size()-1;

        while(i <= j){
            if(nums[j]*nums[j] >= nums[i]*nums[i]){
                ans[k] = nums[j]*nums[j];
                j--, k--;
            }
            else{
                ans[k] = nums[i]*nums[i];
                i++, k--;
            }
        }

        return ans;
    }
};