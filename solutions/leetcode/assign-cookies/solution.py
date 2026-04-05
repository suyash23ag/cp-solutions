# Problem  : Assign Cookies
# Difficulty: Easy
# Tags     : Array, Two Pointers, Greedy, Sorting
# URL      : https://leetcode.com/problems/assign-cookies/
# Solved on: 2026-04-05 22:39
# ──────────────────────────────────────────────────

class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        i=0
        j=0
        g=sorted(g)
        s=sorted(s)
        
        while i<len(g) and j<len(s): 
                if s[j]>=g[i]:
                    i+=1
                j+=1
        return i

