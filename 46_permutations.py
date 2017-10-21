class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        size = len(nums)
        if size == 0: return [[]]
        if size == 1: return [[nums[0]]]
        oldPerms = [[nums[0]]]
        for idx in xrange(1, size):
            perms = []
            for oldPerm in oldPerms:
                for idxPerm in xrange(len(oldPerm)+1):
                    newPerm = oldPerm[:]
                    newPerm.insert(idxPerm, nums[idx])
                    perms.append(newPerm)
            oldPerms = perms
        return perms


sol = Solution()
for nums in [[],[1],[1,2],[1,2,3],[1,2,3,4]]:
    print sol.permute(nums)

sol.permute([n for n in xrange(10)])

