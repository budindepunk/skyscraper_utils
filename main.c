#include <stdio.h>
#include "one_line.c"
#include "handle_arguments.c"
#include "latin_square.c"

int main(void)
{
    int i;
    int check;

    // arrays for holding sets of clues
    int up[4];
    int down[4];
    int left[4];
    int right[4];
    int hold_column[4];

    char argv[] = "2 3 2 1 2 1 3 2 2 3 1 2 1 2 3 2";
    int	possible_solution[4][4] = {{3, 1, 2, 4}, {1, 3, 4, 2}, {4, 2, 3, 1}, {2, 4, 1, 3}};
    
    handle_arguments(argv, up, down, left, right);

    i = 0;
    check = 0;
    check += check_latin_square(4, possible_solution); //checkinf if the solution has no repeated or >n numbers
    while (i < 4)
    {   
        if (check != 0)
        {
            // checking row i and column i against their clues (left-right, up-down respectively)
            turn_column_into_row(i, 4, possible_solution, hold_column);
            check += check_row(up[i], down[i], hold_column);
            check += check_row(left[i], right[i], possible_solution[i]);
        }
        i++;
    }
    if (check == 0)
        printf("correct solution\n");
    else 
        printf("incorrect solution\n");
    return (0);
}
