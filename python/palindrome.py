# check whether given text is a palindrome (case insensitive)


def is_palindrome(str):
    first = 0
    last = len(str) - 1
    while first < last:
        if str[first] != str[last]:
            return False
        first += 1
        last -= 1
    return True


text = input("Enter a word to check whether it is a palindrome:\n")
print(f"{text} is", end="")
if not is_palindrome(text.lower()):
    print(" NOT", end="")
print(" a palindrome")
