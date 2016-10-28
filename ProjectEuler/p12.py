# The sequence of triangle numbers is generated by adding the natural numbers. So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first ten terms would be:

# 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

# Let us list the factors of the first seven triangle numbers:

#  1: 1
#  3: 1,3
#  6: 1,2,3,6
# 10: 1,2,5,10
# 15: 1,3,5,15
# 21: 1,3,7,21
# 28: 1,2,4,7,14,28
# We can see that 28 is the first triangle number to have over five divisors.

# What is the value of the first triangle number to have over five hundred divisors?


# https://en.wikipedia.org/wiki/Divisor_function
def numDivisors(x):
    p = [] # prime factor
    i = 2
    count = 0
    while x > 1:
        if x % i == 0:
            count += 1
            x /= i
        else:
            if count > 0:
                p.append(count)
                count = 0
            i += 1
    if count > 0:
        p.append(count)
        count = 0
    num = 1
    for i in range(len(p)):
        num *= (p[i] + 1)
    return num

def nthTriNum(n):
    return ((1 + n) * n) / 2

n = 100
ans = nthTriNum(n)
while numDivisors(ans) < 500:
    n += 1
    ans = nthTriNum(n)

print ans
