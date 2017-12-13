import itertools
import datetime


class Solution(object):
    def readBinaryWatch(self, num):
        """
        :type num: int
        :rtype: List[str]
        """
        binary_times = []
        time_combi = itertools.combinations(range(10), num)
        for time_tuple in time_combi:
            hour, minute = 0, 0
            for value in time_tuple:
                if value < 4:
                    hour += 1 << value
                else:
                    minute += 1 << (value-4)
            if hour > 11:
                continue
            try:
                binary_times.append(('{:%-H:%M}'.format(datetime.time(hour, minute))))
            except ValueError:
                pass

        return binary_times
       

sol = Solution()
for num in range(10):
    print '\nBinary watch leds ON : {}'.format(num)
    print '========================'
    print sol.readBinaryWatch(num)

