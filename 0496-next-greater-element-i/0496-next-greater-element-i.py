class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        stack=[]
        mp ={}
        # range(start, stop, step)
        # st.top()-->stack[-1]
        for i in range(len(nums2)-1,-1,-1):
            while stack and stack[-1]<=nums2[i]:
                stack.pop()
            if not stack:
                mp[nums2[i]]=-1
            else:
                mp[nums2[i]]=stack[-1]
            stack.append(nums2[i])
        return [mp[x] for x in nums1]


        