#!/usr/bin/python3
'''Lockboxes'''


def canUnlockAll(boxes):
    '''determines if all the boxes can be opened'''
    for i in range(len(boxes)):
        if(boxes[i]):
            continue
        else:
            if(i != len(boxes) - 1):
                return False
    return True
