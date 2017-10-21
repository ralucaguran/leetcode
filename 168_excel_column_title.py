
class Solution(object):
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        alphabet = [chr(letter) for letter in range(ord('A'), ord('Z')+1)]
        title = []
        while n:
            n-=1
            title.append(alphabet[n%26])
            n/=26
        return ''.join(reversed(title))

sol = Solution()
for n in range(1,1000):
    print '%d->%s' % (n,sol.convertToTitle(n))

