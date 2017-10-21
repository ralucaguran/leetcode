
class Solution(object):
    def findComplement(self, num):
        """
        :type num: int
        :rtype: int
        """
        # use right shifts to find out the number of relevant bits
        # e.g. num=5: 101 >> 1 = 10, 10 >> 1 = 1, 1 >> 1 = 0 => numRelevantBits = 3
        temp = num
        numRelevantBits = 0
        while temp != 0:
            numRelevantBits += 1
            temp = temp >> 1

        # build a mask
        # e.g. num=5: mask = 11111111 11111111 11111111 11111000
        mask = ~(2**32-1 >> (32-numRelevantBits))

        # compute the bitwise negation of the bitwise or of num and mask
        # e.g. for num=5 return 2: ~(101 | mask) = 10(2)
        return ~(num | mask) if num > 0 else 1


sol = Solution()
for n in (0,1,3,5,111,487593):
    print "%d's complement is %d" % (n, sol.findComplement(n))

