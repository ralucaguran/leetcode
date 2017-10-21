
class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        words = s.split()
	return len(words[-1]) if len(words)>0 else 0

sol = Solution()
strs = ["", "Hello World", "Boooo", "The Last Mohican"]
for s in strs:
    print s + ":" + str(sol.lengthOfLastWord(s))

