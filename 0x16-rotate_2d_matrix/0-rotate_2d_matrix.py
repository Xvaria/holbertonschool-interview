#!/usr/bin/python3
'''Rotate 2D Matrix'''


def rotate_2d_matrix(matrix):
    '''Given an n x n 2D matrix, rotate it 90 degrees clockwise'''
    for i in range(len(matrix) - 1, -1, -1):
        for j in range(0, len(matrix)):
            matrix[j].append(matrix[i].pop(0))
