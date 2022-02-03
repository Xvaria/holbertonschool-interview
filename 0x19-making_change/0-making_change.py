#!/usr/bin/python3
"""Change comes from within"""


def makeChange(coins, total):
    """
    Determine the fewest number of coins needed to meet a given amount total
    """
    if total <= 0:
        return 0

    placeholder = total + 1

    numb = {0: 0}

    for i in range(1, total + 1):
        numb[i] = placeholder

        for coin in coins:
            current = i - coin
            if current < 0:
                continue

            numb[i] = min(numb[current] + 1, numb[i])

    if numb[total] == total + 1:
        return -1

    return numb[total]
