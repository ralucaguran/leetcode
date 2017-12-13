class Solution(object):
    def getHint(self, secret, guess):
        """
        :type secret: str
        :type guess: str
        :rtype: str
        """
        bulls,cows = 0,0
        secret_count = 10*[0]
        guess_count = 10*[0]
        length = len(secret)
        for idx in range(length):
            if guess[idx] == secret[idx]:
                bulls += 1
            else:
                secret_count[ord(secret[idx])-ord('0')] += 1
                guess_count[ord(guess[idx])-ord('0')] += 1

        for idx in range(10):
            cows += min(secret_count[idx], guess_count[idx])

        return '{}A{}B'.format(bulls,cows)

sol = Solution()
assert sol.getHint('1807', '7810') == '1A3B'
assert sol.getHint('1123', '0111') == '1A1B'
assert sol.getHint('1122', '2211') == '0A4B'

