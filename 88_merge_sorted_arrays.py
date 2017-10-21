class Solution(object):
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: void Do not return anything, modify nums1 in-place instead.
        """
        # sanitize inputs
        nums1 = nums1[:m]
        nums2 = nums2[:n]
        nums1.extend(nums2)
        (i, j, k) = (m-1, n-1, m + n -1)
        import pdb; pdb.set_trace()
        while i >= 0 and j >= 0:
            if nums1[i] > nums2[j]:
                nums1[k] = nums1[i]
                i-=1
            elif nums1[i] < nums2[j]:
                nums1[k] = nums2[j]
                j-=1
            else:
                nums1[k] = nums1[i]
                i-=1
                k-=1
                nums1[k] = nums2[j]
                j-=1
            k-=1
        if j > i:
            nums1[:k+1] = nums2[:j+1]

sol = Solution()
nums1 = [2,5,7,11,21]
nums2 = [1,2,3,9,10,14,29]
nums1 = [0]
nums2 = [1]
sol.merge(nums1, 0, nums2, len(nums2))
print nums1

