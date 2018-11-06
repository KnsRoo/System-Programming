#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include "SimpleFunctions.h"

#define ESC_COLOR_GREEN "\033[1m\033[32m"
#define ESC_COLOR_RED "\033[1m\033[31m"
#define ESC_COLOR_RESTORE "\033[0m"

void
print_result(const char *test_name, bool result)
{
    if (result) {
        printf("%s: " ESC_COLOR_GREEN "PASS" ESC_COLOR_RESTORE "\n",
               test_name);
    } else {
        printf("%s: " ESC_COLOR_RED "FAIL" ESC_COLOR_RESTORE "\n",
               test_name);
    }
}

void
test_1(int value)
{
    print_result("Test  1", (1945 == value));
}


void
test_2(int *value)
{
    print_result("Test  2", (777 == *value));
}

void
test_3(int *value)
{
    print_result("Test  3", (0 == value));
}

void
test_4(int **value)
{
    print_result("Test  4", (65535 == *value[0]));
}

void
test_5(char value)
{
    print_result("Test  5", ('Z' == value));
}

void
test_6(void *value)
{
    print_result("Test  6", ((NULL != value) &&
                             (0 == ((char*)value)[3])));
}

void
test_7(void *value, char *str)
{
    print_result("Test  7", ((NULL != str) &&
                             (value == str && 'n' == str[3])));
}

void
test_8(char *first, char *second, char *third)
{
    print_result("Test  8", (third == second + 2 &&
                             second == first + 2));
}

void
test_9(char *first, char *second, char *third)
{
    print_result("Test  9", (third[3] == second[2] + 8 &&
                             second[2] == first[1] + 8));
}

void
test_10(char *a, int b)
{
    print_result("Test 10", ((a != NULL) &&
                             (*a == b && b > 0)));
}

void
test_11(void *orange, void *blue)
{
    print_result("Test 11", (orange != NULL &&
                             orange == blue &&
                             ((char *)blue)[0] == 1 &&
                             *((int *)orange) % 3 == 0));
}
