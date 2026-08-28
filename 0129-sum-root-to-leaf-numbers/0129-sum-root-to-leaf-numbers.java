import java.util.ArrayList;

class Solution {
    // 1. Removed 'static' so the sum resets for every new LeetCode test case
    public int sum = 0; 

    public void findSum(ArrayList<Character> num){
        int tempSum = 0;
        for(int i = 0; i < num.size(); i++){
            char c = num.get(i);
            // 2. Fixed Math: Shift the existing number left by multiplying by 10, then add the new digit
            tempSum = (tempSum * 10) + (int)(c - '0'); 
        }
        sum += tempSum;
    }

    public void solve(TreeNode root, ArrayList<Character> num){
        if (root == null) {
            return;
        }

        // 3. Add the current node's value first before checking if it's a leaf
        int n = root.val;
        char c = (char)(n + '0');
        num.add(c);

        // If it's a leaf node, compute the path number
        if(root.left == null && root.right == null){
            findSum(num);
            num.remove(num.size() - 1); // Backtrack before returning
            return;
        }

        solve(root.left, num);
        solve(root.right, num);
        
        num.remove(num.size() - 1); // Backtrack
        return;
    }

    public int sumNumbers(TreeNode root) {
        if(root == null){
            return 0;
        }
        sum = 0; // Reset sum explicitly
        ArrayList<Character> num = new ArrayList<>();
        solve(root, num);
        return sum;
    }
}
