#!/usr/bin/python3
''' UTF-8 Validation '''


def validUTF8(data):
    '''Determines if a given data set represents a valid UTF-8 encoding'''
    i = 0

    for code in data:
        byte = format(code, '#010b')[-8:]
        if i == 0:
            for b in byte:
                if b == '0':
                    break
                i += 1
            if i == 0:
                continue
            if i == 1 or i > 4:
                return False
        else:
            if not (byte[0] == '1' and byte[1] == '0'):
                return False
        i -= 1
    return i == 0
