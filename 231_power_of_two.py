class Solution(object):
    def isPowerOfTwo(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if n <= 0: return False
        if n!=1 and n%2: return False
        powers_of_2 = set()
        for i in range(64):
            powers_of_2.add(1 << i)
        return n in powers_of_2

sol = Solution()
#nums = [14, 1024, 0, 1, 79]
nums = [n for n in range(2000)]
for num in nums:
        print "%d : %r" % (num, sol.isPowerOfTwo(num))

