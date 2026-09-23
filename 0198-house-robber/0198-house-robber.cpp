class Solution {
public:
    int solve(vector<int>& nums, int ind, vector<int>& dp){
        if(ind == 0)
            return nums[ind];

        if(ind < 0)
            return 0;

        if(dp[ind] != -1)
            return dp[ind];

        int pick = nums[ind] + solve(nums, ind-2, dp);

        int notPick = 0 + solve(nums, ind-1, dp);

        dp[ind] = max(pick, notPick);

        return dp[ind];
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n, -1);

        return solve(nums, n-1, dp);
    }
};