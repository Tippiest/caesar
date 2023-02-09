#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool isNum(string s);



int main(int k, string argv[])
{
    //convert string of key into a integer

    string arg = argv[1];

    //if the user provides more than one argument then end program
    if ( k != 2 || !isNum(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }



    //if user provides a non number end program

    //int key = atoi(argv[1]);
    string plaintext = get_string("plaintext:");
    string ciphertext = plaintext;
    int i = 0;


    //apply caesar's cipher
    for( i = 0; i < strlen(plaintext); i++)
    {
        printf("text:%c\n", plaintext[i]);

        if(isupper(plaintext[i]))
        {
            if(plaintext[i] + atoi(argv[1]) > 90)
            {
                ciphertext[i] = ('A' + (atoi(argv[1]) - ('Z' - plaintext[i])-1));
            }
            else{
                ciphertext[i] = (plaintext[i] + atoi(argv[1]));
            }
        }

        if(islower(plaintext[i]))
        {

            char tmp = plaintext[i];
            int pi = tmp - 'a';
            char ci = (((pi + atoi(argv[1])) % 26) + 'a' );

            ciphertext[i] = ci;
        }

        //ciphertext[i] = (plaintext[i] + key);
    }
    ciphertext[i] = '\0';

    printf("ciphertext:%s\n", ciphertext);
    return 0;
}

//Inp: a word
//Out: boolean, whether or not the word contains a number
bool isNum(string s)
{


    for(int i = 0; i < strlen(s); i++)
    {
        char cha = s[i];
        if(!isdigit(cha))
        {
            return false;
        }

    }
    return true;
}
