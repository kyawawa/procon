# By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
# What is the 10001st prime number?

def isPrime(x):
    i = 3
    while i * i <= x:
        if x % i == 0:
            return False
        i += 2

    return True

ans = 1
count = 1

while count < 10001:
    ans += 2
    if isPrime(ans):
        count += 1

print ans
