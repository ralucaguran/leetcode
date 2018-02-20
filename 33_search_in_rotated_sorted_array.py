class Solution(object):
    def find_pivot(self, nums):
        start, end = 0, len(nums)-1
        if nums[start] <= nums[end]:
            return -1
        while start < end:
            mid = start + (end-start)/2
            if nums[mid] < nums[0]:
                end = mid
            else:
                start = mid+1
        return start

    def binary_search(self, nums, start, end, target):
        while start <= end:
            mid = start + (end-start)/2
            if target < nums[mid]:
                end = mid - 1
            elif target > nums[mid]:
                start = mid + 1
            else:
                return mid
        return -1

    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if len(nums) == 0:
            return -1
        pivot_pos = self.find_pivot(nums)
        if pivot_pos == -1:
            return self.binary_search(nums, 0, len(nums)-1, target)
        if target >= nums[0]:
            return self.binary_search(nums, 0, pivot_pos-1, target)
        return self.binary_search(nums, pivot_pos, len(nums)-1, target)

sol = Solution()
assert sol.find_pivot([4,5,6,7,0,1,2]) == 4
assert sol.find_pivot([6,7,1,2,3,4,5]) == 2
assert sol.find_pivot([1,0]) == 1
assert sol.find_pivot([1]) == -1
assert sol.find_pivot([1,2,3]) == -1
assert sol.find_pivot([5,1,3]) == 1

nums = [4,5,6,7,0,1,2]
for idx,n in enumerate(nums):
    assert sol.search(nums, n) == idx

nums = [3,1]
assert sol.search(nums,0) == -1

nums = [5,1,3]
assert sol.search(nums,5) == 0

