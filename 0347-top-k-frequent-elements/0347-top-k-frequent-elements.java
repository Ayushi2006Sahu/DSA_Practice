class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        int n = nums.length;
        HashMap<Integer,Integer>mp = new HashMap<>();
        for(int i=0;i<n;i++){
            mp.put(nums[i],mp.getOrDefault(nums[i],0)+1);
        }
        // 1->3 , 2->2 ,3->1
        // max heap 
        int[]ans = new int[k];
        PriorityQueue<Integer>pq = new PriorityQueue<>((a,b)->Integer.compare(mp.get(b),mp.get(a)));
        pq.addAll(mp.keySet());
        for(int i=0;i<k;i++){
             ans[i]=pq.poll();
        }
        return ans;
    }
}