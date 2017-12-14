from math import sqrt

class Solution(object):
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n < 2:
            return 0
        primes = [True]*n
        primes[0] = False
        primes[1] = False
        nsqrt = int(sqrt(n))
        for i in xrange(2, nsqrt+1):
            if primes[i]:
                primes[i*i:n:i] = [False] * len(primes[i*i:n:i])
        return sum(primes)
       
sol = Solution()
for n in [10**x for x in range(1,8)]:
    print 'There are {1} primes less than {0}.'.format(n, sol.countPrimes(n))

