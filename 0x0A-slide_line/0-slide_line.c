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
	int i = 0, j = 0, count = size, ind = 0, tmp = 0, rest = 0;

	if (!line || (direction != 0 || direction != 1))
		return (0);

	if (direction == 0)
	{
		ind = 0;
		for (i = 0; i < count; i++)
		{
			if (line[i] != 0)
				for (j = 1 + i; j < count; j++)
				{
					if (line[j] == 0)
						continue;
					else if (line[i] == line[j])
					{
						tmp = line[i] + line[j];
						line[j] = 0;
						line[i] = 0;
						line[ind] = tmp;
						ind++;
						i++;
						break;
					}
					else
					{
						line[ind] = line[i];
						ind++;
						break;
					}
				}
			if (i == count - 1)
			{
				tmp = line[i];
				line[i] = 0;
				line[ind] = tmp;
				ind++;
			}
		}
	}

	else if (direction == 1)
	{
		ind = count - 1;
		for (i = count - 1; i >= 0; i--)
		{
			if (line[i] != 0)
				for (j = count - 2 - rest; j >= 0; j--)
				{
					if (line[j] == 0)
						continue;
					else if (line[i] == line[j])
					{
						tmp = line[i] + line[j];
						line[j] = 0;
						line[i] = 0;
						line[ind] = tmp;
						ind--;
						i--;
						rest++;
						break;
					}
					else
					{
						line[ind] = line[i];
						ind--;
						break;
					}
				}
			rest++;
			if (i == 0)
			{
				tmp = line[i];
				line[i] = 0;
				line[ind] = tmp;
				ind--;
			}
		}
	}
	return (1);
}
