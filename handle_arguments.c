#include <stdio.h>
#include "one_line.c"

void    handle_arguments(char *argv, int rules_up[], int rules_down[], int rules_left[], int rules_right[])
{
    // take the long string with the clues and make it into 4 arrays, with clues for each side as ints
    int i;
    int inner_i;
    char new_array[10];

    inner_i = 0;
    i = 0;
    while (argv[i] != '\0' && i < 32)
    {
        if (argv[i] >= '0' && argv[i] <= '9')
        {
            if (i >= 0 && i < 8)
                rules_up[inner_i] = (argv[i] - '0');
            else if (i >= 8 && i < 16)
                rules_down[inner_i] = (argv[i] - '0');
            else if (i >= 16 && i < 24)
                rules_left[inner_i] = (argv[i] - '0');
            else if (i >= 24 && i < 32)
                rules_right[inner_i] = (argv[i] - '0');
            inner_i++;
            inner_i = inner_i % 4;
        }
        i++;
    }
}

int main(void)
{
    int i;
    int up[4];
    int down[4];
    int left[4];
    int right[4];
    int hold_column[4];
    char argv[] = "2 3 2 1 2 1 3 2 2 3 1 2 1 2 3 2";
    int	possible_solution[4][4] = {{3, 1, 2, 4}, {1, 3, 4, 2}, {4, 2, 3, 1}, {2, 4, 1, 3}};
    handle_arguments(argv, up, down, left, right);

    i = 0;
    while (i < 4)
    {
        // checking row i and column i against their clues (left-right, up-down respectively)
        turn_column_into_row(i, 4, possible_solution, hold_column);
        check_row(up[i], down[i], hold_column);
        check_row(left[i], right[i], possible_solution[i]);
        i++;
    }
    return (0);
}
