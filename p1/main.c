/*
 * returns the longest set of matching chars between two strings
 *
 */

#include <stdio.h>
#include <string.h>

int longestSubseq(const char[], const char[], char[]);
int possibleResult(int, const char[], const char[], char[]);

int main() {

    // test our function
    char *s1[] = { "", "aaaa", "aa", "ABAZDC", "AGGTAB", "ABBA" };
    char *s2[] = { "", "aa", "aaaa", "BACBAD", "GXTXAYB", "ABCABA" };
    char result[100]; // expected: aa, aa, ABAD, GTAB, ABBA
    for (int i = 0; i < 6; i++) {
        longestSubseq(s1[i], s2[i], result);
        printf("%s\n", result);
    }

    return 0;
}

// returns the longest sub-sequence of (noncontagious!) matching chars between two strings
// "aaaa", "aa"        => "aa"
// "ABAZDC", "BACBAD"  => "ABAD"
// "AGGTAB", "GXTXAYB" => "GTAB"
// "ABBA", "ABCABA"    => "ABBA"
int longestSubseq(const char *s1, const char *s2, char *result) {
    char results[strlen(s1)][strlen(s1)];

    // set final return to be the largest of the possible subseqs
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
 *
 * returns sequence of matching chars from a given index into an char array
 */
int possibleResult(int index, const char *s1, const char *s2, char *result) {
    int resultIndex = 0;
    int lastMatch = 0;
    int i = index;

    // iterate over all chars in s1, starting from given index
    while (i < strlen(s1)) {

        // starting from the last matching index, find all possible matches in s2 to the given s1 char
        for (int j = lastMatch; j < strlen(s2); j++) {

            // if a match exists, add the char to the result, set last match index, and increment s1 index
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