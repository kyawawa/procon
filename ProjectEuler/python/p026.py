# A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:

# 1/2   =  0.5
# 1/3   =  0.(3)
# 1/4   =  0.25
# 1/5   =  0.2
# 1/6   =  0.1(6)
# 1/7   =  0.(142857)
# 1/8   =  0.125
# 1/9   =  0.(1)
# 1/10  =  0.1
# Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.

# Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.

long_digit = 0
for d in range(2, 1000):
    nume = 1
    cycle = []
    count = 0
    while nume < d:
        nume *= 10
    nume %= d
    while nume > 0:
        if cycle.count(nume) == 0:
            cycle.append(nume)
            count += 1
            nume *= 10
            nume %= d
        else:
            digit = count - cycle.index(nume)
            if long_digit < digit:
                long_digit = digit
                ans = d
            nume = 0

print ans
