#include <stdio.h>
#include <unistd.h>

int    check_row(int fromleft, int fromright, int line[])
{
    // ideally this get an extra param "line_size", in this case 4
    // 0 = correct; 1 = incorrect
    int i;
    int last_seen_left;
    int last_seen_right;
    int counter_fromleft;
    int counter_fromright;

    counter_fromleft = 0;
    counter_fromright = 0;
    last_seen_left = 0;
    last_seen_right = 0;
    i = 0;
    while (i < 4)
    {
        if (line[i] > last_seen_left)
        {
            last_seen_left = line[i];
            counter_fromleft++;
        }
        i++;
        // i exits this loop being 1 more than the last one in the array. before turning back we need to sbstract 1
    }
    i--;
    while (i >= 0)
    {
        if (last_seen_right == 0 || line [i] > last_seen_right)
        {
            last_seen_right = line[i];
            counter_fromright++;
        }
        i--;
    }
    if (counter_fromleft == fromleft && counter_fromright == fromright)
    {
        return (0);
    }
    else
    {
        return (1);
    }
}

void    turn_column_into_row(int column, int n, int grid[n][n], int result[])
{
    int i;

    i = 0;
    while (i < n)
    {
        result[i] = grid[i][column];
        i++;
    }

}

void    print_row(int line[], int n)
{
    int i;

    i = 0;
    while (i < n)
    {
        printf("%d", line[i]);
        i++;
    }
    printf("\n");
}