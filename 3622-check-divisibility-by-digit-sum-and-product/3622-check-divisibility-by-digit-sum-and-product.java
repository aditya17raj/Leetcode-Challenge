class Solution {
    public static int sumCheck(int n){
        int x=n;
        int sum=0;

        while(x!=0){
            int digit = x % 10;
            sum += digit;
            x = x/10;
        }

        return sum;
    }

    public static int productCheck(int n){
        int x=n;
        int product = 1;

        while(x != 0){
            int digit = x % 10;

            if(digit == 0){
                return 0;
            }

            product *= digit;
            x = x/10;
        }

        return product;
    }

    public boolean checkDivisibility(int n) {
        int total = sumCheck(n) + productCheck(n);

        if(n % total == 0){
            return true;
        }
        else{
            return false;
        }
    }
}