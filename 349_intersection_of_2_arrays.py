class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        return list(set(nums1)&set(nums2))
#        if len(nums1)>len(nums2):
#            numset = set(nums2)
#            numarr = nums1
#        else:
#            numset = set(nums1)
#            numarr = nums2
#        res = []
#        for n in numarr:
#            if n in numset:
#                res.append(n)
#                numset.remove(n)
#        return res

sol = Solution()
nums1 = [1,2,2,1]
nums2 = [2,2]
assert(sol.intersection(nums1,nums2)==[2])

