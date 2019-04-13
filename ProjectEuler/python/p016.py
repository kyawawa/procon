# 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
# What is the sum of the digits of the number 2^1000?

num = 2**1000
ans = 0

while num > 0:
    ans += num % 10
    num /= 10

print ans

## If you can't calculate 2**1000
num = [0] * 333 # log_10(2**1000) < 1000 * 1/3
num[0] = 1

for i in range(1000):
    c = 0
    for j in range(333):
        num[j] *= 2
        c_tmp = num[j] / 10
        num[j] = num[j] % 10 + c
        c = c_tmp

print sum(num)
