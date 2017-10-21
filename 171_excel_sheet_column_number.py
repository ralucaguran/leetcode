import string

class Solution(object):
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        size = len(s)
        rev = reversed(s)
        alphabet = {k:v for (k, v) in zip(string.ascii_uppercase, range(1,27))}
        num=0
        k=0
        for c in rev:
            num += alphabet[c]*26**k
            k+=1
        return num
       
sol = Solution()
print sol.titleToNumber('ABC')
