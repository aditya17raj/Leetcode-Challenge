class Solution {
public:
    int maxProduct(int n) {
        if(n%10 == n)
            return n;

        vector<int> digits;

        while(n){
            int digit = n%10;
            n = n/10;

            digits.push_back(digit);
        }

        sort(digits.begin() , digits.end());
        int size = digits.size();

        return digits[size-1]*digits[size-2];
        
    }
};