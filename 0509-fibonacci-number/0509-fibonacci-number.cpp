class Solution {
public:
    // using memoization
    int fibo(int n, vector<int> &dp){
        if(n <= 1)
            return n;

        if(dp[n] != -1)
            return dp[n];

        dp[n] = fibo(n-1, dp) + fibo(n-2, dp);

        return dp[n];
    }

    //using tabulation
    int fibonaci(int n){
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=1;

        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }

    //tabulation + space optimization
    int Nthfibonaci(int n){
        int pre=1, pre2=0;

        for(int i=2; i<=n; i++){
            int curi = pre + pre2;
            pre2 = pre;
            pre = curi; 
        }

        return pre;
    }

    int fib(int n) {
        // vector<int> dp(n+1, -1);

        // return fibo(n, dp);

        // return fibonaci(n);

        if(n<=0)
            return n;
        return Nthfibonaci(n);
    }
};