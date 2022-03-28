# Prime Factorization Calculator

import sys


def main():
    try:
        num = int(input("Please enter a number: "))
    except ValueError:
        print("\nWhat you typed is not an integer number\nTerminate the program.")
        sys.exit(1)

    while num <= 1:
        print("\nThe number has to be a positive integer larger than 1")
        num = int(input("Please enter a number: "))

    candidates = calc_candidates(num)
    result = calc_factorization(num, candidates)

    show_result(num, result)


# calculate prime numbers from 2 to num using the sieve of eratosthenes
# https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
def calc_primes(num):
    nums = [True] * num

    # since the index of for loop below would not exceeding square root of the num
    m = int(num ** 0.5)

    for i in range(2, m + 1):
        if nums[i]:
            # the loop below starts from i + i because 'i' itself is a prime number
            for j in range(i + i, num, i):
                nums[j] = False

    # where nums[i] is True, i is a prime number
    return [i for i in range(2, num) if nums[i] is True]


# find prime numbers that are factors of the num
def calc_candidates(num):
    primes = calc_primes(num)
    candidates = []
    for p in primes:
        if num % p == 0:
            candidates.append(p)

    return candidates


# using factors, calculate how many times it is used to consist the num
def calc_factorization(num, candidates):
    result = {}

    for c in candidates:
        count = 0
        tmp = num

        # calculate how many times of multiplication needed to make up the num
        while tmp % c == 0 and tmp != 1:
            tmp /= c
            count += 1

        result[c] = count

    return result


# print result of prime_factorization
# num is passed in case of the num is a prime number itself
def show_result(num, result):
    print("result: ", end="")
    if len(result) == 0:
        print(num)
    else:
        for key in result:
            # Dictionary keys are officially ordered as of Python 3.7
            # if you use previous version than that, use sort()
            if key != list(result)[-1]:
                if result[key] == 1:
                    print(f"{key} x", end=" ")
                else:
                    print(f"{key}^{result[key]} x", end=" ")

            else:
                if result[key] == 1:
                    print(f"{key}")
                else:
                    print(f"{key}^{result[key]}")


if __name__ == "__main__":
    main()
