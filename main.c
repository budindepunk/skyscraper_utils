#include <stdio.h>
#include "one_line.c"
#include "handle_arguments.c"
#include "handle_arguments_grid.c"
#include "latin_square.c"

int main(int argc, char **argv)
{
    int i;
    int check;
    int hold_column[4];
    int clues_grid[4][4];

    // char argv[] = "2 3 2 1 2 1 3 2 2 3 1 2 1 2 3 2";
    int	possible_solution[4][4] = {{3, 1, 2, 4}, {1, 3, 4, 2}, {4, 2, 3, 1}, {2, 4, 1, 3}};
    
    // we want to receive a string as a parameter when running, and arrange that input into a 2d array
    // otherwise just uncomment the string above and remove "[1]" down here
    handle_arguments_grid(argv[1], 4, clues_grid);

    i = 0;
    check = 0;
    check += check_latin_square(4, possible_solution); 
    // ruling out non-latin square solutions
    
    while (i < 4)
    {   
        if (check != 0)
        {
            // checking row i and column i against their clues (left-right, up-down respectively)
            // clues_grid[0] is clues for UP
            // clues_grid[1] is clues for DOWN
            // clues_grid[2] is clues for LEFT
            // clues_grid[3] is clues for RIGHT
            turn_column_into_row(i, 4, possible_solution, hold_column);
            check += check_row(clues_grid[0][i], clues_grid[1][i], hold_column);
            check += check_row(clues_grid[2][i], clues_grid[3][i], possible_solution[i]);
        }
        i++; 
    }
    if (check == 0)
        printf("correct solution\n");
    else 
        printf("incorrect solution\n");
    return (0);
}