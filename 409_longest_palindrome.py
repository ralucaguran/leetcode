class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        ordA= ord('A')
        charFreqs = [0]*(ord('z')+1-ordA)
        for c in s:
            charFreqs[ord(c)-ordA]+=1
        maxPalindromeLen = 0
        firstOdd = True
        for freq in charFreqs:
            maxPalindromeLen+=freq
            if freq%2 == 1:
                if firstOdd:
                    firstOdd = False
                else:
                    maxPalindromeLen-=1
        return maxPalindromeLen
        
sol = Solution()
print sol.longestPalindrome('abccccdd')
print sol.longestPalindrome('')

