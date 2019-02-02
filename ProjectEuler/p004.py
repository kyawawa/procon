# A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 * 99
# Find the largest palindrome made from the product of two 3-digit numbers.

def isPalindrome(x):
    if x / 100000 == x % 10 and (x / 10000) % 10 == (x / 10) % 10 and (x / 1000) % 10 == (x / 100) % 10:
        return True
    return False

ans = 0
for i in range(100, 1000):
    for j in range(i, 1000):
        if isPalindrome(i * j) and i * j > ans:
            ans = i * j

print ans
