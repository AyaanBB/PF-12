#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *resizeBuffer(char *buffer, size_t *capacity) {
    *capacity *= 2;
    buffer = (char *)realloc(buffer, *capacity);
    if (buffer == NULL) {
        printf("Memory allocation failed during resizing!\n");
        exit(1);
    }
    return buffer;
}

void toLowerCase(char *word) {
    for (int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
}

void addWord(char **words, int *freq, int *size, char *word) {
    for (int i = 0; i < *size; i++) {
        if (strcmp(words[i], word) == 0) {
            freq[i]++;
            return;
        }
    }
    words[*size] = strdup(word);
    freq[*size] = 1;
    (*size)++;
}

void countWordFrequency(char *buffer) {
    char **words = (char **)malloc(100 * sizeof(char *));
    int *freq = (int *)malloc(100 * sizeof(int));
    int size = 0, capacity = 100;

    char *word = strtok(buffer, " \n\t.,!?;:()\"\'");
    while (word != NULL) {
        toLowerCase(word);
        addWord(words, freq, &size, word);

        if (size >= capacity) {
            capacity *= 2;
            words = (char **)realloc(words, capacity * sizeof(char *));
            freq = (int *)realloc(freq, capacity * sizeof(int));
        }

        word = strtok(NULL, " \n\t.,!?;:()\"\'");
    }

    printf("Word Frequencies:\n");
    for (int i = 0; i < size; i++) {
        printf("%s: %d\n", words[i], freq[i]);
        free(words[i]);
    }

    free(words);
    free(freq);
}

int main() {
    FILE *file;
    char *buffer;
    size_t capacity = 1024, length = 0;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    buffer = (char *)malloc(capacity);
    if (buffer == NULL) {
        printf("Memory allocation failed!\n");
        fclose(file);
        return 1;
    }

    int c;
    while ((c = fgetc(file)) != EOF) {
        buffer[length++] = (char)c;
        if (length >= capacity) {
            buffer = resizeBuffer(buffer, &capacity);
        }
    }
    buffer[length] = '\0';

    fclose(file);
    countWordFrequency(buffer);

    free(buffer);
    return 0;
}
