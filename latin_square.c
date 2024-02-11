#include <stdio.h>
#include <unistd.h>

void	latin_square(int n)
{
	int	row;
	int	column;
	int	arr[n][n];

	row = 0;
	while (row < n)
	{
		column = 0;
		while (column < n)
		{
			arr[row][column] = (row + column) % n + 1;
			printf("%d ", arr[row][column]);
			column++;
		}
		printf("%s", "\n");
		row++;
	}
}

void	check_latin_square(int n, int grid[n][n])
{
	int	row;
	int	column;
	int	i;
	
	row = 0;
	while (row < n)
	{
		column = 0;
		while (column < n)
		{
			i = 0;
			while (i < n)
			{
				if (grid[row][column] > n || grid[row][column] < 1) // checks if the number is too high
				{
					printf("%s", "not a latin square :(\n");
					return ;
				}
				else if (grid[row][column] == grid[row][i]) // checks if the number repeats in the row
				{
					if (column == i) // asks it to not compare with itself
						break;
					printf("%s", "not a latin square :(\n");
					return ;
				}
				else if (grid[row][column] == grid[i][column]) // checks if repeats in the column
				{
					if (row == i) // asks it to not compare with itself
						break;
					printf("%s", "not a latin square :(\n");
					return ;
				}
				i++;
			}
			column++;
		}
		row++;
	}
	printf("%s", "latin square :)\n");
}