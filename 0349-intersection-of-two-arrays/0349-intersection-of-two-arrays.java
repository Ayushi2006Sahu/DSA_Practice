class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        int n1= nums1.length;
        int n2 = nums2.length;
        HashSet<Integer>st = new HashSet<>();
        for(int x:nums1){
            st.add(x);
        }
        HashSet<Integer>anst = new HashSet<>();
        for(int x:nums2){
            if(st.contains(x)){
                anst.add(x);
            }
        }
        int[] ans = new int[anst.size()];
        // ans =[0]
        int i=0;
        for(int x:anst){
            ans[i]=x;
            i++;
        }
        return ans;
    }
}