#include "sandpiles.h"

/**
 * print_grid - Print the sandpiles if they are unstable
 * @grid: Sandpile for print
 */

void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * grid_status - check if sandpile is stable
 * @grid: sandpile to check
 * Return: if is stable return 1 if not return 0
 */

int grid_status(int grid[3][3])
{
	int row, column;

	for (row = 0; row < 3; row++)
	{
		for (column = 0; column < 3; column++)
		{
			if (grid[row][column] > 3)
			{
				return (0);
			}
		}
	}
	return (1);
}

/**
 * process_sandpile - Process sandpile and try convert to perfect sandpile
 * @grid1: Sandpile to try convert to perfect
 */

void process_sandpile(int grid1[3][3])
{
	int d_grid[3][3] = {{0}}, row, column;

	for (row = 0; row < 3; row++)
		for (column = 0; column < 3; column++)
			if (grid1[row][column] > 3)
			{
				if (row == 0)
					d_grid[row][column] -= 1;
				else
					d_grid[row][column] -= 1, d_grid[row - 1][column] += 1;
				if (column == 2)
					d_grid[row][column] -= 1;
				else
					d_grid[row][column] -= 1, d_grid[row][column + 1] += 1;
				if (row == 2)
					d_grid[row][column] -= 1;
				else
					d_grid[row][column] -= 1, d_grid[row + 1][column] += 1;
				if (column == 0)
					d_grid[row][column] -= 1;
				else
					d_grid[row][column] -= 1, d_grid[row][column - 1] += 1;
			}
	sandpiles_sum(grid1, d_grid);
}

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: Sandpile to become stable
 * @grid2: Sandpile to sum
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int column = 0, row = 0;

	for (row = 0; row < 3; row++)
	{
		for (column = 0; column < 3; column++)
		{
			grid1[row][column] += grid2[row][column];
		}
	}
	if (grid_status(grid1) == 0)
	{
		printf("=\n");
		print_grid(grid1);
		process_sandpile(grid1);
	}
}
