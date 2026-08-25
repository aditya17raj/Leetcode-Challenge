class Solution {
    public int missingMultiple(int[] nums, int k) {
        int n=nums.length;

        HashSet<Integer> st = new HashSet<>();

        for(int num : nums){
            st.add(num);
        }

        int x=k;
        while(true){
            if(!st.contains(x)){
                return x;
            }

            x = x+k;
        }
    }
}