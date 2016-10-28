# Starting in the top left corner of a 2*2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner
# How many such routes are there through a 20*20 grid

def fact(x):
    f = 1
    for i in range(x, 1, -1):
        f *= i
    return f

def combination(n, k):
    return (fact(n) / (fact(k) * fact(n - k)))

print combination(40, 20)
