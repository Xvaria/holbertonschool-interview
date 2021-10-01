#include "slide_line.h"

/**
 * slide_line - slides and merges an array of integers
 * @line: array of integers
 * @size: size array
 * @direction: slided & merged to the direction
 * Return: 1 upon success, or 0 upon failure
 */

int slide_line(int *line, size_t size, int direction)
{
	int index = 0, index_2 = 0, size_int = size, tmp = 0;

	if (line == NULL || (direction != 0 && direction != 1))
		return (0);

	if (direction == 0)
	{
		for (index = 0; index < size_int; index++)
		{
			if (line[index] == line[index + 1] && line[index] != 0)
			{
				line[index_2++] = line[index] + line[index + 1],
				index++;
				line[index_2] = 0;
			}
			else if (line[index] != 0)
			{
				if (tmp == line[index])
				{
					line[--index_2] = tmp * 2;
					index_2++;
					tmp = 0;
				}
				else
					line[index_2++] = line[index], tmp =
					line[index];
			}
		}
		for (index = index_2; index < size_int; index++)
			line[index] = 0;
	}
	else
	{
		index_2 = size - 1;

		for (index = size_int - 1; index > -1; index--)
		{
			if (line[index] == line[index - 1] && line[index] != 0)
			{
				line[index_2--] = line[index] +
				line[index - 1], index--;
				line[index_2] = 0;
			}
			else if (line[index] != 0)
			{
				if (tmp == line[index])
				{
					line[++index_2] = tmp * 2;
					index_2--;
					tmp = 0;
				}
				else
					line[index_2--] = line[index],
					tmp = line[index];
			}
		}
		for (index = index_2; index > -1; index--)
			line[index] = 0;
	}
	return (1);
}
