
class Solution(object):
    def searchInsertOn(self, nums, target):
        """
        O(n)
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        idx = 0
        while idx < len(nums):
            if target == nums[idx]:
                return idx
            elif target < nums[idx]:
                break
            idx += 1
        return idx
    
    def searchInsert(self, nums, target):
        """
        O(log(n))
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        (left, right) = (0, len(nums)-1)
        while left <= right:
            mid = left+(right-left)/2
            if target == nums[mid]:
                return mid
            elif target < nums[mid]:
                right = mid-1
            else:
                left = mid+1
        return left

sol = Solution()
nums = [1,3,5,6]
targets = [5,2,7,0]
for target in targets:
    print "%d -> %d" % (target, sol.searchInsert(nums, target))

