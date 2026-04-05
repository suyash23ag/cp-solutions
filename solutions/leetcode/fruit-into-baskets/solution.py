# Problem  : Fruit Into Baskets
# Difficulty: Medium
# Tags     : Array, Hash Table, Sliding Window
# URL      : https://leetcode.com/problems/fruit-into-baskets/
# Solved on: 2026-04-05 22:39
# ──────────────────────────────────────────────────

class Solution:
    def totalFruit(self, nums: List[int]) -> int:
        freq={}
        i=0
        j=0
        mx=0
        while j<len(nums):
            freq[nums[j]]=freq.get(nums[j],0)+1
            if len(freq)>2:
                freq[nums[i]]-=1
                if freq[nums[i]]==0:
                    del freq[nums[i]]
                i+=1
            if len(freq)<=2:
                mx=max(mx,j-i+1)
            j+=1
        return mx

