# If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
# If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

# NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.

def firstDisit(x):
    if x == 0:
        return ""
    words = ["one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
    return words[x - 1]

def secondDisit(x):
    u20 = ["ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]
    words = ["twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"]
    if x < 10:
        return firstDisit(x)
    elif x < 20:
        return u20[x - 10]
    else:
        return words[x / 10 - 2] + firstDisit(x % 10)

def thirdDisit(x):
    if len(secondDisit(x % 100)) == 0:
        return firstDisit(x / 100) + "hundred"
    else:
        return firstDisit(x / 100) + "hundredand" + secondDisit(x % 100)

def letters(x):
    if x < 10:
        return len(firstDisit(x))
    elif x < 100:
        return len(secondDisit(x))
    else:
        return len(thirdDisit(x))

ans = 0
for i in range(1, 1000):
    ans += letters(i)

ans += len("onethousand")

print ans
