#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFF_LIMIT 100

int checkUserInput(long num, char *nptr, char *endptr) {
    // shamelessly taken from stack overflow.
    if (nptr == endptr) {
        printf("number : %ld invalid (no digits found, 0 "
               "returned)\n",
               num);
        return 1;
    } else if (errno == ERANGE && num == LONG_MIN) {
        printf("number : %ld invalid (underlow occurred)\n", num);
        return 1;
    } else if (errno == EINVAL) {
        printf("number : %ld invalid (base contains supported "
               "value)\n",
               num);
        return 1;
    } else if (errno != 0 && num == 0) {
        printf("number : %ld invalid (unspecified error "
               "occurred)\n",
               num);
        return 1;
    } else if (errno == 0 && nptr && !*endptr) {
        printf("number : %ld valid (and represents all "
               "characters read)\n",
               num);
    } else if (errno == 0 && nptr && *endptr != 0) {
        printf("number : %ld valid (but additional characters "
               "remain)\n",
               num);
    }

    return 0;
}

int main() {
    char aPtr[BUFF_LIMIT], bPtr[BUFF_LIMIT], optPtr[BUFF_LIMIT];
    char *aEndPtr = NULL, *bEndPtr = NULL, *optEndPtr = NULL;
    long a, b;
    int opt, checkResult;

    // get Input of user for the first number
    printf("Please input your first number: ");
    fgets(aPtr, BUFF_LIMIT, stdin);

    // Set errno to 0 prior to string to long conversion
    errno = 0;

    a = strtol(aPtr, &aEndPtr, 10);
    checkResult = checkUserInput(a, aPtr, aEndPtr);

    // if the number is not a valid int, then exit
    if (checkResult == 1) {
        return 1;
    }

    // get input of user for the second number
    printf("Please input your second number: ");
    fgets(bPtr, BUFF_LIMIT, stdin);

    // Set errno to 0 prior to string to long conversion
    errno = 0;

    b = strtol(bPtr, &bEndPtr, 10);
    checkResult = checkUserInput(b, bPtr, bEndPtr);

    // if the number is not a valid int, then exit
    if (checkResult == 1) {
        return 1;
    }

    // get input of user for operand choice
    printf("\nPlease select your opt: \n \
      1. addition\n \
      2. subtraction\n \
      3. multiplication\n \
      4. division\n");
    fgets(optPtr, BUFF_LIMIT, stdin);

    // Set errno to 0 prior to string to long conversion
    errno = 0;

    opt = strtol(optPtr, &optEndPtr, 10);
    checkResult = checkUserInput(opt, optPtr, optEndPtr);

    // if the number is not a valid int, then exit
    // if valid, check if a valid option for an operand
    if (checkResult == 1) {
        return 1;
    } else if (opt < 1 || opt > 4) {
        printf("Not a valid opt.");
        return 2;
    }

    // choose math operator based on operand and print out the solution
    switch (opt) {
    case 1:
        printf("The result is: %ld", a + b);
        break;
    case 2:
        printf("The result is: %ld", a - b);
        break;
    case 3:
        printf("The result is: %ld", a * b);
        break;
    case 4:
        if (b == 0) {
            printf("Cannot divide by zero.\n");
            break;
        }
        printf("The result is: %ld\n", a / b);
        break;
    default:
        printf("Something went wrong.\n");
    }

    return 0;
}
