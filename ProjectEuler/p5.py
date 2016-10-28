# 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
# What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

def divide(a, x):
    i = 2
    c = 0
    while x > 1:
        if x % i == 0:
            c += 1
            x /= i
            if c > a[i]:
                a[i] = c
        else:
            c = 0
            i += 1

a = [0] * 21

ans = 1
for i in range(2, 21):
    divide(a, i)

for i in range(2, 21):
    ans *= i ** a[i]

print a
print ans
