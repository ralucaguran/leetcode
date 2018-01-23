class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        if digits[-1] < 9:
            digits[-1] += 1
            return digits

        cur_idx = len(digits) - 1
        while cur_idx >= 0 and digits[cur_idx] == 9:
            digits[cur_idx] = 0
            cur_idx -= 1

        if digits[0] == 0:
            digits.insert(0,1)
        else:
            digits[cur_idx] += 1
        
        return digits


sol = Solution()
assert(sol.plusOne([1,2,3])==[1,2,4])
assert(sol.plusOne([0])==[1])
assert(sol.plusOne([9])==[1,0])
assert(sol.plusOne([1,9])==[2,0])
assert(sol.plusOne([9,9,9,9])==[1,0,0,0,0])
assert(sol.plusOne([9,8,9,9])==[9,9,0,0])

