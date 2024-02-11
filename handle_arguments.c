
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