# A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4.
# If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:
# 012   021   102   120   201   210
# What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?

import math

# digit counts from left
def findDigitNum(digit, count, num_list, ans):
    i = 0
    while count + math.factorial(9 - digit) < 1000000 and i < 10 - digit: # take care of range
        count += math.factorial(9 - digit)
        i += 1
    ans.append(num_list[i])
    num_list.remove(num_list[i])
    print count, i
    return count

num = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
count = 0
ans = []

for digit in range(10):
    count = findDigitNum(digit, count, num, ans)

for x in ans:
    print x,
