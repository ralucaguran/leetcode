class Solution(object):
    def findErrorNums(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        nums_dict = {}
        for num in nums:
            if nums_dict.has_key(num):
                nums_dict[num] += 1
            else:
                nums_dict[num] = 1
        duplicate,missing = -1,-1
        for num in range(1,len(nums)+1):
            if nums_dict.has_key(num):
                if nums_dict[num] == 2:
                    duplicate = num
            else:
                missing = num
        return [duplicate, missing]

sol = Solution()
assert sol.findErrorNums([8,2,3,4,5,5,7,1])==[5,6]
assert sol.findErrorNums([2,2])==[2,1]

