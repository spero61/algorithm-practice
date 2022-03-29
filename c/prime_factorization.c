#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

typedef struct prime_factors
{
    int number; // a factors
    int count;  // how many times this factor is multiplied by
}
prime_factors;

int array_length(const int *arr);
int *calc_primes(const int n);
int *calc_candidates(const int n);
prime_factors *calc_factorization(const int n, const int *candidates);
void show_result(const prime_factors *result, const int result_length);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./file [positive integer number]\ne.g., ./prime_factorization 100\n");
        return 1;
    }

    int n = atoi(argv[1]);

    int *candidates = calc_candidates(n);
    if (candidates == NULL)
    {
        return 2;
    }

    prime_factors *result = calc_factorization(n, candidates);
    if (result == NULL)
    {
        free(candidates);
        return 2;
    }

    int size = array_length(candidates);
    show_result(result, size);

    // free memory
    free(result);
    free(candidates);
    return 0;
}

// return array_length
int array_length(const int *arr)
{
    int count = 0;
    while (*arr)
    {
        ++count;
        ++arr;
    }

    return count;
}

// calculate prime numbers up to n harness the sieve of eratosthenes
// https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
int *calc_primes(const int n)
{
    // declare temporary bool array
    bool *tmp_arr = malloc(sizeof(bool) * (n + 1));
    if (tmp_arr == NULL)
    {
        printf("Could not allocate memory for bool *tmp_arr\n");
        return NULL;
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
        return NULL;
    }

    for (int i = 2, idx = 0; i <= n; ++i)
    {
        if (tmp_arr[i])
        {
            primes[idx] = i;
            ++idx;
        }
    }

    free(tmp_arr);
    return primes;
}

// candidates are prime numbers that are consist of n and it is the subset of primes
int *calc_candidates(const int n)
{
    int *primes = calc_primes(n);
    if (primes == NULL)
    {
        printf("Could not allocate memory for int *primes\n");
        return NULL;
    }

    int primes_length = array_length(primes);
    int *candidates = malloc(sizeof(int) * primes_length);
    if (candidates == NULL)
    {
        printf("Could not allocate memory for int *candidates\n");
        free(primes);
        return NULL;
    }

    // initialize each variable of candidates to True using memset
    memset(candidates, 0, sizeof(int) * primes_length);

    // idx is used to fill candidates array when only if condition is true
    for (int i = 0, idx = 0; i < primes_length; ++i)
    {
        if (n % primes[i] == 0)
        {
            candidates[idx++] = primes[i];
        }
    }

    free(primes);
    return candidates;
}

prime_factors *calc_factorization(const int n, const int *candidates)
{
    int size = array_length(candidates);
    prime_factors *result = malloc(sizeof(prime_factors) * size);
    if (result == NULL)
    {
        printf("Could not allocate memory for prime_factors *result\n");
        return NULL;
    }

    // initializing result's fields to 0 repectively
    for (int i = 0; i < size; ++i)
    {
        result[i].number = 0;
        result[i].count = 0;
    }

    for (int i = 0, idx = 0; i < size; ++i)
    {
        // if it reached where there is no more prime numbers remaining
        if (candidates[i] == 0)
        {
            // because values of left candidates[i]s are also 0
            break;
        }

        // reset count and tmp
        int count = 0;
        int tmp = n;

        // calculate how many times of multiplication needed to make up 'n'
        while (tmp % candidates[i] == 0 && tmp != 1)
        {
            tmp /= candidates[i];
            ++count;
        }
        if (count != 0)
        {
            result[idx].number = candidates[i];
            result[idx].count = count;
            ++idx;
        }
    }

    return result;
}

// find prime numbers up to n first then calculate the prime factorization, print them
void show_result(const prime_factors *result, const int result_length)
{
    // // show result as a list of result
    // for (int i = 0; i < result_length; ++i)
    // {
    //     if (result[i].count != 0)
    //     {
    //         printf("number: %i, count: %i\n", result[i].number, result[i].count);
    //     }
    //     else
    //     {
    //         break;
    //     }
    // }

    // calculate effective length of the result where result[i].count is not 0
    int count = 0;
    for (int i = 0; i < result_length; ++i)
    {
        if (result[i].count == 0)
        {
            break;
        }
        ++count;
    }

    // show result as a equation using count
    printf("result:");
    for (int i = 0; i < count; ++i)
    {
        if (i != count - 1)
        {
            result[i].count == 1 ? printf(" %i x", result[i].number) : printf(" %i^%i x", result[i].number, result[i].count);
        }
        // if it is the last prime factor
        else
        {
            result[i].count == 1 ? printf(" %i\n", result[i].number) : printf(" %i^%i\n", result[i].number, result[i].count);
        }

    }
    return;
}