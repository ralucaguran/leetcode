class Solution(object):
    POWERS_OF_2 = {1<<offset for offset in range(64)}

    def isPowerOfTwo(self, n):
        """
        :type n: int
        :rtype: bool
        """
        return n in self.POWERS_OF_2

sol = Solution()
nums = [n for n in range(2000)]
for num in nums:
    print "%d : %r" % (num, sol.isPowerOfTwo(num))

