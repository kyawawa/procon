# The prime factors of 13195 are 5, 7, 13 and 29.
# What is the largest prime factor of the number 600851475143 ?

num = 600851475143
i = 3
ans = 0
while num != 1:
    if num % i != 0:
        i += 2
    else:
        num /= i

print i
