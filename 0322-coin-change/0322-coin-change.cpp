class Solution {
public:
    int minCoin(vector<int>& coins, int ind, int T, vector<vector<int>> &dp){
        if(ind == 0){
            if(T % coins[0] == 0) return T/coins[0];
            else return 1e9;
        }

        if(dp[ind][T] != -1) return dp[ind][T];

        int notPick = 0 + minCoin(coins, ind-1, T, dp);
        int pick = 1e9;
        if(coins[ind] <= T)
            pick = 1 + minCoin(coins, ind, T-coins[ind], dp);

        return dp[ind][T] = min(pick, notPick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        // vector<vector<int>> dp(n, vector<int>(amount+1, -1));

        // int ans = minCoin(coins, n-1, amount, dp);

        // if(ans >= 1e9) return -1;
        // else return ans;

        vector<vector<int>> dp(n, vector<int>(amount+1, 0));

        for(int T=0; T<=amount; T++){
            if(T % coins[0] == 0)
                dp[0][T] = T/coins[0];
            else
                dp[0][T] = 1e9;
        }

        for(int ind=1; ind<n; ind++){
            for(int T=0; T<=amount; T++){
                int notPick = 0 + dp[ind-1][T];
                int pick = 1e9;
                if(coins[ind] <= T)
                    pick = 1 + dp[ind][T-coins[ind]];

                dp[ind][T] = min(pick, notPick);
            }
        }

        int ans = dp[n-1][amount];
        if(ans >= 1e9)
            return -1;
        else 
            return ans;
    }
};