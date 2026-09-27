class Solution {
public:
    bool solve(vector<int>& nums, int ind, int target, vector<vector<int>> &dp){
        if(target == 0) return true;
        if(ind==0) return (nums[0] == target);

        if(dp[ind][target] != -1)
            return dp[ind][target];

        bool notPick = solve(nums, ind-1, target, dp);
        bool pick = false;
        if(target >= nums[ind])
            pick = solve(nums, ind-1, target-nums[ind], dp);

        dp[ind][target] = pick || notPick;

        return dp[ind][target];

    }

    bool isPossible(vector<int>& nums,int n, int target){
        vector<vector<int>> dp(n, vector<int>(target+1, -1));

        return solve(nums, n-1, target, dp);
    }

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totalSum=0;
        for(int i=0; i<n; i++)
            totalSum += nums[i];

        if(totalSum % 2 != 0)
            return false;

        int target=totalSum/2;

        return isPossible(nums, n, target);
    }
};