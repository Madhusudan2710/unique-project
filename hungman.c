#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

int main() {
    char name[50];
    printf("What is your name? ");
    scanf("%s", name);
    printf("Hello, %s! Time to Play HangMan!\n", name);
    sleep(1);
    printf("Start guessing...\n");
    sleep(1);

    const char *words[] = {"computer", "python", "lolita"};
    int wordsCount = sizeof(words) / sizeof(words[0]);
    srand((unsigned int)time(NULL));
    const char *word = words[rand() % wordsCount];

    char guesses[26];
    guesses[0] = '\0';

    int turns = 10;
    while (turns > 0) {
        int failed = 0;
        for (int i = 0; i < strlen(word); i++) {
            char currentChar = word[i];
            if (strchr(guesses, currentChar) != NULL) {
                printf("%c", currentChar);
            } else {
                printf("_");
                failed++;
            }
        }

        if (failed == 0) {
            printf("\nYou won!\nThe word is: %s\n", word);
            break;
        }

        printf("\nGuess a character: ");
        char guess;
        scanf(" %c", &guess);
        strncat(guesses, &guess, 1);

        if (strchr(word, guess) == NULL) {
            turns--;
            printf("Wrong!\nYou have %d more guesses\n", turns);
        }

        if (turns == 0) {
            printf("You Lose! Better luck next time\n");
        }
    }

    return 0;
}