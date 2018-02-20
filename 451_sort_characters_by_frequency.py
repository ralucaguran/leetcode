import collections
import heapq

class Solution(object):
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        heap = []
        counter = collections.Counter(s)
        for (k,v) in counter.items():
            heapq.heappush(heap, (-v,k))
        rv = []
        for i in range(len(heap)):
            k,v = heapq.heappop(heap)
            rv.extend((-k)*[v])
        return ''.join(rv)

sol = Solution()
assert sol.frequencySort('tree')=='eert'
assert sol.frequencySort('cccaaa')=='aaaccc'
assert sol.frequencySort('Aabb')=='bbAa'

