#include "cs50.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void encrypt (string plaintext, string key);
void decrypt (string ciphertext, string key);

int main (int argc, string argv[]) {
    if (argc < 3 || argc > 3) {
        printf("Usage: ./substitution KEY d/e (decrypt/encrypt)");

        return 1;
    }

    const string key = argv[1];
    const string operation = argv[2];

    if (strlen(key) != 26){
        printf("Key must contain 26 characters.");
        return 1;
    }
    if (strlen(operation) != 1) {
        printf("Operation must contain either d/e (decrypt/encrypt)");
        return 1;
    }

    string input = get_string("text: ");

    if (strcmp(operation, "e") == 0) encrypt(input, key);
    else if (strcmp(operation, "d") == 0) decrypt(input, key);

    return 0;
}

void encrypt (string plaintext, string key) {
    char key_lower [26];
    char key_upper [26];

    for (int i = 0; i < 26; i++){
        key_lower[i] = tolower(key[i]);
        key_upper[i] = toupper(key[i]);
    } 

    for (int i = 0; i < 26; i++){
        if (isalpha(plaintext[i])) {
            if (islower(plaintext[i])) plaintext[i] = key_lower[(int)plaintext[i] - 97];
            else if (isupper(plaintext[i])) plaintext[i] = key_upper[(int)plaintext[i] - 65];
        }
    }

    printf("ciphertext: %s\n", plaintext);
}

void decrypt (string ciphertext, string key) {
    char key_lower [26];
    char key_upper [26];

    for (int i = 0; i < 26; i++){
        key_lower[i] = tolower(key[i]);
        key_upper[i] = toupper(key[i]);
    } 

    for (int i = 0; i < 26; i++){
        if (isalpha(ciphertext[i])){
            if (islower(ciphertext[i])) {
                for (int j = 0; j < 26; j ++){
                    if (key_lower[j] == (char)ciphertext[i]){
                        ciphertext[i] = (char) j + 97;

                        break;
                    }
                    else continue;               
                }
            }
            if (isupper(ciphertext[i])) {
                for (int j = 0; j < 26; j ++){
                    if (key_upper[j] == (char)ciphertext[i]){
                        ciphertext[i] = (char) j + 65;

                        break;
                    }
                    else continue;               
                }
            }
        }
    }

    printf("plaintext: %s\n", ciphertext);
}