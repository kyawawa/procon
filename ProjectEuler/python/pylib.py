def divisors(x):
    divisors = []
    i = 1
    while i * i <= x:
        if x % i == 0:
            divisors.append(i)
            if i not in {1, x / i}:
                divisors.append(x / i)
        i += 1
    return divisors

def isPrime(x):
    if x == 2:
        return True
    elif x % 2 == 0 or x < 0:
        return False
    i = 3
    while i * i <= x:
        if x % i == 0:
            return False
        i += 2
    return True
