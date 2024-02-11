#include <stdio.h>

void    handle_arguments(char *argv, int rules_up[], int rules_down[], int rules_left[], int rules_right[])
{
    int i;
    int inner_i;
    char new_array[10];

    inner_i = 0;

    while (argv[i] != '\0' && i < 32)
    {
        if (argv[i] == ' ')
        {
            printf("i is %d. i found a space\n", i);
        }
        else if (argv[i] >= '0' && argv[i] <= '9')
        {
            // inner_i = 0;
            if (i >= 0 && i < 8)
            {
                // while (inner_i < 4)
                // {
		printf("i is %d and inner_i is %d. im putting %c at rules_up loop %d\n", i, inner_i, argv[i], inner_i);
                rules_up[inner_i] = argv[i];
                inner_i++;
		inner_i = inner_i % 4;
                // }
                // inner_i = 0;
            }
            else if (i >= 8 && i < 16)
            {
                // while (inner_i < 4)
                // {
                printf("i is %d and inner_i is %d. im putting %c at rules_down loop %d\n", i, inner_i, argv[i], inner_i);
                rules_down[inner_i] = argv[i];
                inner_i++;
		inner_i = inner_i % 4;
                // }
                // inner_i = 0;
            }
            else if (i >= 16 && i < 24)
            {
                // while (inner_i < 4)
                // {
                printf("i is %d and inner_i is %d. im putting %c at rules_left loop %d\n", i, inner_i, argv[i], inner_i);
                rules_left[inner_i] = argv[i];
                inner_i++;
		inner_i = inner_i % 4;
                // }
                // inner_i = 0;
            }
            else if (i >= 24 && i < 32)
            {
                // while (inner_i < 4)
                // {
                printf("i is %d and inner_i is %d. im putting %c at rules_right loop %d\n", i, inner_i, argv[i], inner_i);
                rules_right[inner_i] = argv[i];
                inner_i++;
		inner_i = inner_i % 4;
                // }
            }
        }
        i++;       
    }
}

int main(void)
{
    int up[4];
    int down[4];
    int left[4];
    int right[4];
    char argv[] = "1 2 3 4 2 3 4 1 3 4 1 2 4 1 2 3";
    handle_arguments(argv, up, down, left, right);
    return (0);
}
