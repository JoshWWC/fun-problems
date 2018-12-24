/*
 * returns the longest set of matching chars between two strings
 *
 */

#include <stdio.h>
#include <string.h>
#include <check.h>

int maxMatchingChars(const char[], const char[], char[]);
int possibleResult(int, const char[], const char[], char[]);


START_TEST (possibleResultTest)
    {
        char result[2];
        possibleResult(0, "aaaa", "aa", result);
        ck_assert_str_eq(result, "aa");
        ck_assert_str_eq(result, "aaaaaaa");
    }
END_TEST

int main() {
    return 0;
}

// returns the longest set of noncontagious matching chars between two strings
int maxMatchingChars(const char *s1, const char *s2, char *result) {
    char results[strlen(s1)][strlen(s1)];

    int max = 0;
    for (int i = 0; i < strlen(s1); i++) {
        possibleResult(i, s1, s2, results[i]);
        if (strlen(results[i]) > max) {
            max = (int)strlen(results[i]);
            strcpy(result, results[i]);
        }
    }
    return 0;
}

/* psudeo code:
 * if s1[c1] == s2[c1], add s1[c1], increment both
 * if s1[c2] != s2[c2], increment s2
 * if s1[c2] == s2[c3], add s1[c2], increment both
 * if s1[c3] != s2[c4 ... n], restart s2 at last matching char + 1, increment s1
 * if s1[c4] == s2[c4], add s1[c4], increment both
 */
int possibleResult(int index, const char *s1, const char *s2, char *result) {
    int resultIndex = 0;
    int lastMatch = 0;
    int i = index;
    while (i < strlen(s1)) {
        for (int j = lastMatch; j < strlen(s2); j++) {
            if (s1[i] == s2[j]) {
                result[resultIndex] = s1[i];
                resultIndex++;
                lastMatch = j+1;
                i++;

            }
        }
        i++;
    }
    result[resultIndex] = '\0';

    return 0;

}