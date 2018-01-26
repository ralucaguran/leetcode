class Solution(object):
    def findErrorNums(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        nums.sort()
        size = len(nums)
        for idx in range(size-1):
            if nums[idx] == nums[idx+1]:
                break
        duplicate = nums[idx]
        missing = size*(size+1)/2-sum(set(nums))
        return [duplicate, missing]

sol = Solution()
assert sol.findErrorNums([8,2,3,4,5,5,7,1])==[5,6]
assert sol.findErrorNums([2,2])==[2,1]

