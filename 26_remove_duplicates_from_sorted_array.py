class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        numsSize = len(nums)
        uniqueNumsSize = numsSize
        i,j = 0,1
        while j<numsSize:
            if nums[j] == nums[i]:
                j += 1
                uniqueNumsSize -= 1
            else:
                nums[i+1] = nums[j]
                i,j = i+1, j+1
        return uniqueNumsSize

sol = Solution()
nums = [1,1,1,1,2,2,2,3,4]
print sol.removeDuplicates(nums)
print nums

