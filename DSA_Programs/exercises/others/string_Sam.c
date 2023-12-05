#include <stdio.h>
#include <string.h>

#define MAX_SENTENCE 20
#define MAX_WORDS 5
#define MAX_WORD_LENGTH 10

typedef char Sentence[MAX_SENTENCE];
typedef char SentenceMatrix[MAX_WORDS][MAX_WORD_LENGTH];

void tokenizeSentence(char sentence[], char words[MAX_WORDS][MAX_WORD_LENGTH], int *wordCount) {
    char *token;

    for(token = strtok(sentence, " "), *wordCount = 0; token != NULL && *wordCount < MAX_WORDS; (*wordCount)++) {
        strcpy(words[*wordCount], token);
        token = strtok(NULL, " ");
    }
}

void findRecurringWords(char sentence1[], char sentence2[], char sentence3[]) {
    SentenceMatrix words1, words2, words3;
    int wordCount1, wordCount2, wordCount3, i, j, k;

    tokenizeSentence(sentence1, words1, &wordCount1);
    tokenizeSentence(sentence2, words2, &wordCount2);
    tokenizeSentence(sentence3, words3, &wordCount3);

    printf("\n\nRecurring words in all sentences :\n");

    for (i = 0; i < wordCount1; i++) {
        for (j = 0; j < wordCount2; j++) {
            for (k = 0; k < wordCount3; k++) {
                if (strcmp(words1[i], words2[j]) == 0 && strcmp(words1[i], words3[k]) == 0) {
                    printf("%s\n", words1[i]);
                }
            }
        }
    }
}

void printAllSentences(Sentence s1, Sentence s2, Sentence s3)
{
	int i;
	char sentences[3][MAX_SENTENCE];
	
	strcpy(sentences[0], s1);
	strcpy(sentences[1], s2);
	strcpy(sentences[2], s3);
	
	for(i = 0; i < 3; i++) {
		printf("SENTENCE %2d : %-20s\n", i+1, sentences[i]);
	}
}

int main() {
    Sentence 
    sentence1 = { 
      "THE WORLD'S ENDING!"
    },
    sentence2 = {
      "PATAY MIS THE DSA"
    },
    sentence3 = {
      "THIS IS THE LAST"
    };
    
    printAllSentences(sentence1, sentence2, sentence3);
    findRecurringWords(sentence1, sentence2, sentence3);

    return 0;
}
