class Solution {
    public static void solve(int[] nums, int i, int n, List<Integer>cur, List<List<Integer>> ans){
        if(i == n){
            ans.add(new ArrayList(cur));
            return;
        }

        //taken
        cur.add(nums[i]);
        solve(nums, i+1, n, cur, ans);

        //backtrack
        cur.remove(cur.size()-1);

        //not taken
        solve(nums, i+1, n, cur, ans);

    }
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> cur = new ArrayList<>();
        int n=nums.length;

        solve(nums, 0, n, cur, ans);
        return ans;
    }
}