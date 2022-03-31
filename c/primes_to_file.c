#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define _CRT_SECURE_NO_DEPRECATE  // to deal with fopen error in windows

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./file [positive integer number]\ne.g., ./primes_to_txt 100\n");
        return 1;
    }

    int n = atoi(argv[1]);

    // declare temporary bool array
    bool *tmp_arr = malloc(sizeof(bool) * (n + 1));
    if (tmp_arr == NULL)
    {
        printf("Could not allocate memory for bool *tmp_arr\n");
        return 2;
    }

    // initialize each variable of tmp_arr to True using memset
    memset(tmp_arr, true, sizeof(bool) * (n + 1));

    // deal with 0 and 1 manually
    // tmp_arr's value: tmp_arr[x] = true represents integer x is a prime number
    tmp_arr[0] = false;
    tmp_arr[1] = false;

    // Since the index of for loop below would not exceeding square root of the num
    int m = (int)sqrt(n);
    for (int i = 2; i <= m; ++i)
    {
        // if integer 'i' is not yet crossed out, then keep this 'i' as a prime number
        // meaning that keep tmp_arr[i] == true
        if (tmp_arr[i])
        {
            // then cross out i's multiples, except i itself, by setting tmp_arr[j]'s value to false
            for (int j = i + i; j <= n; j += i)
            {
                tmp_arr[j] = false;
            }
        }
    }

    int count = 0;
    for (int i = 2; i <= n; ++i)
    {
        if (tmp_arr[i])
        {
            ++count;
        }
    }

    int *primes = malloc(sizeof(int) * count);
    if (primes == NULL)
    {
        free(tmp_arr);
        printf("Could not allocate memory for int *primes\n");
        return 2;
    }

    int idx = 0;
    for (int i = 2; i <= n; ++i)
    {
        if (tmp_arr[i])
        {
            primes[idx++] = i;
        }
    }

    FILE *file = fopen("primes.txt", "w");

    if (file == NULL)
    {
        printf("Could not open prime.txt");
        return 3;
    }

    // save as txt file and there's no space between numbers to reduce file size
    fprintf(file, "{");
    for (int i = 0; i < idx - 1; ++i)
    {
        fprintf(file, "%i,", primes[i]);
    }
    fprintf(file, "%i", primes[idx - 1]);
    fprintf(file, "}");

    fclose(file);

    free(tmp_arr);
    free(primes);
    return 0;
}
