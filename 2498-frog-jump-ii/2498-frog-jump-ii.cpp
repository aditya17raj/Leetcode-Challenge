class Solution {
public:
    int solve(vector<int>& stones, int ind) {
        // Base case: If we are at the second stone (index 1), 
        // the only possible jump is from index 0.
        if (ind == 1) {
            return stones[1] - stones[0];
        }
        
        // Find the maximum gap in the rest of the array recursively
        int max_of_rest = solve(stones, ind - 1);
        
        // Find the gap if we jump over 1 stone (from ind-2 to ind)
        int current_jump = stones[ind] - stones[ind - 2];
        
        // We want the MAXIMUM single jump cost across the entire chosen path
        return max(max_of_rest, current_jump);
    }

    int maxJump(vector<int>& stones) {
        return solve(stones, stones.size()-1);
    }
};