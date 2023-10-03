#include <stdio.h>
#include <string.h>
#define MAX 50

typedef char String[MAX];

int checkIfPalindrome(String pl)
{
    int retVal;
    String temp;

    strcpy(temp, pl);
    strrev(temp);
    retVal = strcmp(pl, temp) == 0 ? 1 : 0;

    return retVal;
}

int getNumberOfOccurrences(String word1, String word2) 
{
    int word1Length = strlen(word1);
    int word2Length = strlen(word2);
    int count = 0;

    for (int i = 0; i <= word1Length - word2Length; i++) {
        int j;
        for (j = 0; j < word2Length; j++) {
            if (word1[i + j] != word2[j]) {
                break;
            }
        }
        if (j == word2Length) {
            count++;
        }
    }

    return count;
}

int main() 
{
    String palindrome = { "chuuhc" };
    checkIfPalindrome(palindrome) ? printf("%s IS A PALINDROME!\n", palindrome) : printf("%s IS NOT A PALINDROME", palindrome);

    String word = { "baba black sheep baba ba" };
    String occurence = { "sheep" };
    printf("%d is the number of times it came out!\n", getNumberOfOccurrences(word, occurence));

    return 0;
}