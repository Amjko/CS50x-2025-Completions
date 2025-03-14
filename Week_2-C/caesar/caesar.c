/**
 * caesar.c -> Encrypt text with caesar cypher
 * Creation:   January 05, 2025
 * 
 * Purpose: Prompts the user for sequence of characters
 *          to encrypt via caesar cypher with <key> amount
 *          of shifts in the letters.
 * 
 * Problem Source: https://cs50.harvard.edu/x/2025/psets/2/caesar/
 * 
 * Note:    Include in command the key for caesar shift.
 * 
 * Usage: ./caesar key
 * 
 * Output: 
 *         ./caesar 13
 *         plaintext:  Hi there!
 *         ciphertext: Uv gurer! 
 */

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//* Prototype functions
// Function for printing error
int error(int error_number);

// Argc is for how many extensions in a command
// Argv is for what are those extensions
int main(int argc, char *argv[])
{
    //* Check if command-line argument is valid
    if (argc != 2)
    {
        error(1);
    }

    // Loop til end of char
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            error(1);
        }
    }

    // convert string key to int key
    int key = 0;
    key = atoi(argv[1]);

    // Prompt user for plaintext
    char *text = get_string("plaintext: ");     // cs50.h function
    char *cipher_text = text;

    //* Shift letters according to key
    // Get length of text
    int text_length = strlen(text);

    // Loop through each letter
    for (int i = 0; i < text_length; i++)
    {
        // Check if is letter
        if (isalpha(text[i]))
        {
            // Shift letter uppercase
            if (isupper(text[i]))
            {
                cipher_text[i] = ((text[i] - 'A' + key) % 26) + 'A';
            }

            // Shift letter lowercase
            if (islower(text[i]))
            {
                cipher_text[i] = ((text[i] - 'a' + key) % 26) + 'a';
            }
        }
        else
        {
            continue;
        }
    }


    //* Print new ciphered text
    printf("ciphertext: %s\n", cipher_text);

    return 0;
}

// Function for printing error
int error(int error_number)
{
    if (error_number == 1)
    {
        printf("Usage: ./caesar key\n");

        exit(1);
    }

    else if (error_number == 2)
    {
        exit(2);
    }
}
