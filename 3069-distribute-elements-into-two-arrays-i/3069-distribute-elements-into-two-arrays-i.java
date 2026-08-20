class Solution {
    public int[] resultArray(int[] nums) {
        ArrayList<Integer> arr1 = new ArrayList<>();
        ArrayList<Integer> arr2 = new ArrayList<>();

        arr1.add(nums[0]);
        arr2.add(nums[1]);

        int n=0, m=0;

        for(int i=2; i<nums.length; i++){
            if(arr1.get(n) > arr2.get(m)){
                arr1.add(nums[i]);
                n++;
            }else{
                arr2.add(nums[i]);
                m++;
            }
        }

        int[] ans = new int[nums.length];
        int ind=0;
        n=0;
        m=0;
        while(n < arr1.size()){
            ans[ind++] = arr1.get(n);
            n++;
        }

        while(m < arr2.size()){
            ans[ind++] = arr2.get(m);
            m++;
        }

        return ans;
    }
}