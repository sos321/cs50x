#include <stdio.h>
#include <ctype.h>
#include "cs50.h"
#include <string.h>
#include <math.h>

int count_letters (string str);
int count_words (string str);
int count_sentences (string str);
int count_grade (float letters, float words, float sentences);

int main (void) {
    
    string str = get_string("Text: ");

    int grade = count_grade(count_letters(str), count_words(str), count_sentences(str)); 

    if (grade < 1) printf("Grade Before Grade 1\n");
    else if (grade > 16) printf("Grade 16+\n");
    else printf("Grade %i\n", grade);
     
}

int count_letters (string str) {

    int letters = 0;

    for (int i = 0; i < strlen(str); i ++){
        if (isalpha(str[i])){
            letters ++;
        }
    }

    return letters;
}

int count_words (string str) {
    int words = 0;

    for (int i = 0; i < strlen(str); i ++){
        if (!isalpha(str[i])){
            if (str[i] == '.' || str[i] == '!' || str[i] == '?') {
                if (i == strlen(str) - 1) {
                    words ++;
                }
            }
            
            if (isspace(str[i])){
                words ++;
            }
        }
    }

    return words;
}

int count_sentences (string str) {
    int sentences = 0;

    for (int i = 0; i < strlen(str); i ++){
        if (str[i] == '.' || str[i] == '?' || str[i] == '!'){           
            sentences ++;
        }
    }

    return sentences;
}

int count_grade (float letters, float words, float sentences) {
    float L = letters / words * 100;
    float S = sentences / words * 100;

    return round(0.0588 * L - 0.296 * S - 15.8);
}