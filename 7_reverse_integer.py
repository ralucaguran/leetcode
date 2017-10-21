

def rev_int(n):
    if n < 0:
        return -rev_int(abs(n))
    nrev = 0
    while (n != 0):
        rest = n%10
        n = n/10
        nrev = nrev*10 + rest
    return nrev

for n in [-9, 0, 3, 9, 123, -123, 34985, 3648723487234774, 922337203685477580799, 1534236469]:
    print '%d reverted is %d' % (n, rev_int(n))

