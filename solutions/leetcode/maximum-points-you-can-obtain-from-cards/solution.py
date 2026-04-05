# Problem  : Maximum Points You Can Obtain from Cards
# Difficulty: Medium
# Tags     : Array, Sliding Window, Prefix Sum
# URL      : https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
# Solved on: 2026-04-05 22:39
# ──────────────────────────────────────────────────

class Solution:
    def maxScore(self, nums: List[int], k: int) -> int:
        if len(nums)==k:
            return sum(nums)
        pts=sum(nums)
        mx=0
        ls=0
        r=len(nums)-1
        for i in range(k):
            ls+=nums[i]
        mx=ls
        rs=0
        for i in range(k-1,-1,-1):
            ls-=nums[i]
            rs+=nums[r]
            mx=max(mx,ls+rs)
            r-=1
        return mx

        
        

            
