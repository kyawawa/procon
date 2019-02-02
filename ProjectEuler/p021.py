# Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
# If d(a) = b and d(b) = a, where a != b, then a and b are an amicable pair and each of a and b are called amicable numbers.

# For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

# Evaluate the sum of all the amicable numbers under 10000.

def sumOfDivisors(x):
    divisors = []
    i = 1
    while i * i <= x:
        if x % i == 0:
            divisors.append(i)
            if i not in {1, x / i}:
                divisors.append(x / i)
        i += 1
    return sum(divisors)

def searchAmicable(bef, num, checked, amicables):
    if num >= 10000 or checked[num] == 1:
        return
    sum_num = sumOfDivisors(num)
    if bef == sum_num:
        amicables.append(bef)
        amicables.append(num)
        checked[bef] = 1
        checked[num] = 1
    else:
        checked[num] = 1
        searchAmicable(num, sum_num, checked, amicables)

checked = [0] * 10000
checked[0] = 1
checked[1] = 1
amicables = []
for i in range(2, 10000):
    searchAmicable(0, i, checked, amicables)

print amicables
print sum(amicables)
