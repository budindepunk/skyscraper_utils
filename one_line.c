#include <stdio.h>
#include <unistd.h>

void    check_row(int fromleft, int fromright, int line[])
{
    // ideally this get an extra param "line_size", in this case 4
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
        printf("%s", "this row is correct\n");
        return ;
    }
    else
    {
        printf("%s", "this row is not correct\n");
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

int main(void)
{
    int example_grid[4][4] = {{2, 1, 4, 3}, {3, 4, 1, 2}, {4, 2, 3, 1}, {1, 3, 2, 4}};
    int test0[4];
    int test1[4];
    int test2[4];
    int test3[4];

    check_row(2, 2, example_grid[0]);
    check_row(2, 2, example_grid[1]);
    check_row(1, 3, example_grid[2]);
    check_row(3, 1, example_grid[3]);
    turn_column_into_row(0, 4, example_grid, test0);
    turn_column_into_row(1, 4, example_grid, test1);
    turn_column_into_row(2, 4, example_grid, test2);
    turn_column_into_row(3, 4, example_grid, test3);

    check_row(3, 2, test0);
    check_row(2, 2, test1);
    check_row(1, 3, test2);
    check_row(2, 1, test3);

    return (0);
}