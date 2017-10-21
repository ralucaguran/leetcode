
class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        nums_dict = {}
        idx = 0
        while idx < len(nums):
            if nums[idx] in nums_dict and idx-nums_dict[nums[idx]] <= k:
                return True
            else:
                nums_dict[nums[idx]] = idx
            idx += 1
        return False

sol = Solution()
nums = [1,2,3,4,1,5,1]
k = 6
print sol.containsNearbyDuplicate(nums, k)
