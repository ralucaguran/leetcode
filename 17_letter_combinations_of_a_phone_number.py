class Solution(object):

    lettersPerDigit = {'2':['a','b','c'],'3':['d','e','f'],
            '4':['g','h','i'],'5':['j','k','l'],'6':['m','n','o'],
            '7':['p','q','r','s'],'8':['t','u','v'],'9':['w','x','y','z']}

    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """ 
        size = len(digits)
        if size == 0: return []
        if size == 1: return Solution.lettersPerDigit[digits]

        firstDigitLetters = Solution.lettersPerDigit[digits[0]]
        remainingLettersCombi = self.letterCombinations(digits[1:])
        return [letter+rest 
                for letter in firstDigitLetters 
                for rest in remainingLettersCombi]


sol = Solution()
digitSeqs = ["", "9", "23", "232", "999999", "72988252"]
for digitSeq in digitSeqs:
    print sol.letterCombinations(digitSeq)

