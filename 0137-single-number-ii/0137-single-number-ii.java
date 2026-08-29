class Solution {
    public int singleNumber(int[] nums) {
        HashMap<Integer,Integer> m = new HashMap<>();

        for(int i=0; i<nums.length; i++){
            m.put(nums[i] , m.getOrDefault(nums[i] , 0)+1);
        }

        Set<Integer> s = m.keySet();

        for(int key:s){
            if(m.get(key) != 3){
                return key;
            }
        }

        return -1;
    }
}