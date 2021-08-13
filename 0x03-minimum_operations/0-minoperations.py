#!/usr/bin/python3
'''Minimum Operations'''


def minOperations(n):
    '''Minimum Operations'''
    operations = 0
    div = 2
    while(n >= div):
        while((n % div) != 0):
            div += 1
        operations += div
        n /= div
    return(operations)
