
class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        size = len(nums)
        i = j = 0
        while True:
            while (j < size and nums[j] == val):
                j += 1
            if j == size: break
            nums[i] = nums[j]
            i += 1
            j += 1
        return i


nums = [3,3,3,2,2,3,4,3,3,5]
sol = Solution()
size = sol.removeElement(nums, 3)
print nums, size

