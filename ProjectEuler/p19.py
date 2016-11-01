# You are given the following information, but you may prefer to do some research for yourself.

# * 1 Jan 1900 was a Monday.
# * Thirty days has September,
#   April, June and November.
#   All the rest have thirty-one,
#   Saving February alone,
#   Which has twenty-eight, rain or shine.
#   And on leap years, twenty-nine.
# * A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
# How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

SUNDAY = 6 # MONDAY = 0

def days(y, m):
    if m in {4, 6, 9, 11}:
        return 30
    elif m == 2:
        if y % 4 == 0 and not (y % 400 != 0 and y % 100 == 0):
            return 29
        else:
            return 28
    else:
        return 31

tmpdays = 0
for i in range(1, 13):
    tmpdays += days(1990, i)

day_of_week = tmpdays % 7
ans = 0

for y in range(1901, 2001):
    for m in range(1, 13):
        if day_of_week == SUNDAY:
            ans += 1
        day_of_week = (day_of_week + days(y, m)) % 7

print ans
