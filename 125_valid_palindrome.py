
class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        sAlnum = ''.join(c for c in s if c.isalnum())
#        sAlnum = filter(str.isalnum, s)
        sAlnumLower = sAlnum.lower()
        return sAlnumLower == sAlnumLower[::-1]	

sol = Solution()
strs = ["A man, a plan, a canal: Panama", "", "race a car"]
for s in strs:
	print sol.isPalindrome(s)

