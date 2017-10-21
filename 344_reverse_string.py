class Solution(object):
    def reverseString(self, s):
        """
        :type s: str
        :rtype: str
        """
        l = list(s)
	mid = len(l)/2
        (first, second) = (0, len(l)-1) 
        while first < mid:
            (l[first], l[second]) = (l[second], l[first])
            first += 1
            second -= 1
        return "".join(l)
        
s = "hello"
sol = Solution()
sol.reverseString(s)

