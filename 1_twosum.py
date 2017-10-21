
def two_sum(nums, target):
    rests = {}
    for n in nums:
        if n in rests.keys():
            return (rests[n], n)
        rest = target - n
        if rest not in rests:
            rests[rest] = n
    return -1

nums = [2, 7, 1, 12, 49, 11, 15]
targets = (9, 17, 11, 56)
for target in targets:
    twosum = two_sum(nums, target)
    print '%d is %d + %d' % (target, twosum[0], twosum[1]) if twosum != -1 else '%d is not achievable' % target

