/*
 * ru: Этот файл НЕЛЬЗЯ МОДИФИЦИРОВАТЬ
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Dictionary.h"

#define ESC_COLOR_GREEN "\033[1m\033[32m"
#define ESC_COLOR_RED "\033[1m\033[31m"
#define ESC_COLOR_RESTORE "\033[0m"

int main() {
    Dictionary *dictionary;
    int result;
    const char *s;
    char *s1 = malloc(100);

    /*
     * Initialize the dictionary data structure.
     */
    dictionary = dictionary_create();

    /* _add() */
    result = dictionary_add(dictionary, "key", "value");
    if (result != 0) { printf("_add():" ESC_COLOR_RED " FAIL: failed, and it should have been successful." ESC_COLOR_RESTORE "\n"); }
    else { printf("_add(): " ESC_COLOR_GREEN "PASS" ESC_COLOR_RESTORE "\n"); }

    result = dictionary_add(dictionary, "key2", "value");
    if (result != 0) { printf("_add():" ESC_COLOR_RED " FAIL: failed, and it should have been successful." ESC_COLOR_RESTORE "\n"); }
    else { printf("_add(): " ESC_COLOR_GREEN "PASS" ESC_COLOR_RESTORE "\n"); }

    result = dictionary_add(dictionary, "key3", "value");
    if (result != 0) { printf("_add():" ESC_COLOR_RED " FAIL: failed, and it should have been successful." ESC_COLOR_RESTORE "\n"); }
    else { printf("_add(): " ESC_COLOR_GREEN "PASS" ESC_COLOR_RESTORE "\n"); }

    result = dictionary_add(dictionary, "key", "value2");
    if (result == 0) { printf("_add():" ESC_COLOR_RED " FAIL: was successful, and it should've failed." ESC_COLOR_RESTORE "\n"); }
    else { printf("_add(): " ESC_COLOR_GREEN "PASS" ESC_COLOR_RESTORE "\n"); }

    /* _remove() */
    dictionary_remove(dictionary, "key3");

    /* _get() */
    s = dictionary_get(dictionary, "non-existant");
    if (s != NULL) { printf("_get():" ESC_COLOR_RED " FAIL: was successful, and it should've failed." ESC_COLOR_RESTORE "\n"); }
    else { printf("_get(): " ESC_COLOR_GREEN "PASS" ESC_COLOR_RESTORE "\n"); }

    s = dictionary_get(dictionary, "key");
    if (s == NULL || strcmp(s, "value") != 0) { printf("_get():" ESC_COLOR_RED " FAIL: failed or was not the expected result." ESC_COLOR_RESTORE "\n"); }
    else { printf("_get(): " ESC_COLOR_GREEN "PASS" ESC_COLOR_RESTORE "\n"); }

    /* _add() */
    strcpy(s1, "value");
    result = dictionary_add(dictionary, "key3", s1);
    if (result != 0) { printf("_add():" ESC_COLOR_RED " FAIL: failed, and it should have been successful." ESC_COLOR_RESTORE "\n"); }
    else { printf("_add(): " ESC_COLOR_GREEN "PASS" ESC_COLOR_RESTORE "\n"); }

    strcpy(s1, "bad key-value");
    /* _get() */
    s = dictionary_get(dictionary, "key3");
    if (s == NULL || strcmp(s, "value") != 0) { printf("_get():" ESC_COLOR_RED " FAIL: failed or was not the expected result." ESC_COLOR_RESTORE "\n"); }
    else { printf("_get(): " ESC_COLOR_GREEN "PASS" ESC_COLOR_RESTORE "\n"); }

    /*
     * Free up the memory used by the dictionary and close the file.
     */
    dictionary_destroy(dictionary);
    free(s1);

    return 0;
}
