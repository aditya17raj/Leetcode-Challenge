class Solution {
public:
    int count(int A, int ind, vector<int>& coins, vector<vector<int>>&dp){
        if(ind == 0){
            if(A % coins[0] == 0) return 1;
            else return 0;
        }

        if(dp[ind][A] != -1)
            return dp[ind][A];

        int notPick = count(A, ind-1, coins, dp);
        int pick = 0;
        if(coins[ind] <= A){
            pick = count(A-coins[ind], ind, coins, dp);
        }

        return dp[ind][A] = pick + notPick;
    }

    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        // vector<vector<int>> dp(n, vector<int>(amount+1, -1));

        // return count(amount, n-1, coins, dp);

        //Tabulation
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));

        for(int a=0; a<=amount; a++){
            if(a % coins[0] == 0) dp[0][a] = 1;
        }

        for(int i=1; i<n; i++){
            for(int a=0; a<=amount; a++){
                long long notPick = dp[i-1][a];

                long long pick = 0;
                if(a >= coins[i])
                    pick = dp[i][a-coins[i]];

                dp[i][a] = pick + notPick;
            }
        }

        return dp[n-1][amount];
    }
};