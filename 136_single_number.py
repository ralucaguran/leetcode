class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return reduce(lambda x,y: x^y, nums)

sol = Solution()
assert(sol.singleNumber([1,2,1,3,3,4,2,5,5])==4)
assert(sol.singleNumber([1])==1)

