class Solution {
public:
    int smallestNumber(int n, int t) {
        
        while(n <= 100){
            int k=n;
            int product=1;
            while(k){
                int digit = k%10;
                product *= digit;
                k = k/10;
            }
            if(product % t == 0)
                return n;

            n++;
        }

        return 0;
    }
};