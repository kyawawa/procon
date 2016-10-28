# The following iterative sequence is defined for the set of positive integers:

# n -> n/2 (n is even)
# n -> 3n + 1 (n is odd)

# Using the rule above and starting with 13, we generate the following sequence:

# 13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
# It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

# Which starting number, under one million, produces the longest chain?

# NOTE: Once the chain starts the terms are allowed to go above one million.

def chainCount(num, chain):
    if num == 1:
        return 0
    if num >= 1000000 or chain[num] == 0:
        tmp = chainCount(num / 2 if num % 2 == 0 else 3 * num + 1, chain) + 1
        if num < 1000000:
            chain[num] = tmp
        return tmp
    return chain[num]

chain = [0] * 1000000
longest = 1
for i in range(1, 1000000):
    if (chainCount(i, chain) > longest):
        longest = chainCount(i, chain)
        ans = i

print ans
