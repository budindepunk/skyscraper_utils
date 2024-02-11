
void    handle_arguments_grid(char *argv, int n, int clues_grid[n][n])
{
    // take the long string with the clues and make it into an array with 4 arrays
    int i;
    int array_i;
    int index_i;

    //              clues up       clues down     clues left    clues right
    // clues_grid = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}

    index_i = 0;
    i = 0;
    while (argv[i] != '\0' && i < n * 8)
    {
        if (argv[i] >= '0' && argv[i] <= '9')
        {
            if (i >= 0 && i < 8)
                clues_grid[0][index_i] = (argv[i] - '0');
            else if (i >= 8 && i < 16)
                clues_grid[1][index_i] = (argv[i] - '0');
            else if (i >= 16 && i < 24)
                clues_grid[2][index_i] = (argv[i] - '0');
            else if (i >= 24 && i < 32)
                clues_grid[3][index_i] = (argv[i] - '0');
            index_i ++;
            index_i = index_i % 4;
        }
        i++;
    }
}