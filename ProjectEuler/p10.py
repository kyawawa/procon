# The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
# Find the sum of all the primes below two million.

def isOddPrime(x):
    i = 3
    while i * i <= x:
        if x % i == 0:
            return False
        i += 2
    return True

ans = 2
i = 3
while i < 2000000:
    if isOddPrime(i):
        ans += i
    i += 2

print ans
