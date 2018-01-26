class Solution(object):
    def findErrorNums(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        length = len(nums)
        num_presence = [0]*length
        for n in nums:
            num_presence[n-1] += 1

        duplicate,missing = -1,-1
        for i in range(length):
            if num_presence[i]==0:
                missing = i+1
            elif num_presence[i]==2:
                duplicate = i+1
        return [duplicate,missing]

sol = Solution()
assert sol.findErrorNums([8,2,3,4,5,5,7,1])==[5,6]
assert sol.findErrorNums([2,2])==[2,1]

