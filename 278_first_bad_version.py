# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
def isBadVersion(version):
    return True if version > 10 else False

class Solution(object):
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        left, right = 1,n 
        first_bad = -1
        while left <= right:
            mid = left + (right-left)/2
            if isBadVersion(mid):
                right = mid - 1
                first_bad = mid
            else:
                left = mid + 1
        return first_bad

#import bisect
#
#class Solution(object):
#    def firstBadVersion(self, n):
#        return bisect.bisect_left([isBadVersion(x) for x in range(n)],True)

sol = Solution()
assert(sol.firstBadVersion(15)==11)

