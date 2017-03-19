//CS50 pset2: Vigenere Cipher

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool error = false;

int printerror(void);

int main(int argc, string argv[])
{
    //make sure there are two command line arguments
    if (argc != 2)
    {
        return printerror();
    }
    else
    {
        //loop through the key
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            //make sure the key consists of letters
            if (!isalpha(argv[1][i]))
            {
                error = true;
            }
        }
        if (error == true)
        {
            return printerror();
        }
    }

    //proceed if the key is correct
    if (error == false)
    {
        //store key as a string and get its length
        string key = argv[1];
        int keylength = strlen(key);

        //get plain text from the user
        printf("plaintext: ");
        string plaintext = get_string();

        if (plaintext != NULL)
        {
            printf("ciphertext: ");

            //iterate over every letter of plain text
            for (int i = 0, j = 0, n = strlen(plaintext); i < n; i++)
            {
                //get key for the letter
                int letterkey = tolower(key[j % keylength]) - 'a';

                //handle letter case of plain text, incrementing j only if a letter gets enciphered
                if (isalpha(plaintext[i]))
                {
                    if (isupper(plaintext[i]))
                    {
                        printf("%c", 'A' + (plaintext[i] - 'A' + letterkey) % 26);
                        j++;
                    }
                    else
                    {
                        printf("%c", 'a' + (plaintext[i] - 'a' + letterkey) % 26);
                        j++;
                    }
                }
                else
                {
                    //if the character is not alphabetic, print it unchanged
                    printf("%c", plaintext[i]);
                }
            }
        }
        //print a new line and finish the program
        printf("\n");
        return 0;
    }
}

//print error message
int printerror(void)
{
    printf("Usage: ./vigenere k\n");
    return 1;
}
