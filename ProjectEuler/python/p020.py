# n! means n * (n - 1) * ... * 3 * 2 * 1

# For example, 10! = 10 * 9 * ... * 3 * 2 * 1 = 3628800,
# and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

# Find the sum of the digits in the number 100!

num = [0] * 200 # 100! < 100**100 => log_10 100! < log_10 100**100 = 200
num[0] = 1
digit = 1
for i in range(1, 101):
    c = 0
    for j in range(digit):
        num[j] *= i
        num[j] += c
        c = num[j] / 10
        num[j] %= 10
        if j == digit - 1 and c > 0:
            while c > 0:
                digit += 1
                j += 1
                num[j] += c % 10
                c /= 10

print num[::-1]
print sum(num)
