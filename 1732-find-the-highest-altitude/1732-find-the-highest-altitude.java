class Solution {
    public int largestAltitude(int[] gain) {
        int n = gain.length;
        int[] arr= new int[n+1];
       arr[0]=0;
        for(int i=0;i<n;i++){
            arr[i+1]=arr[i]+gain[i];
        }
        int maxi = Integer.MIN_VALUE;
        for(int i=0;i<arr.length;i++){
            maxi = Math.max(maxi,arr[i]);
        }
        return maxi;
    }
}