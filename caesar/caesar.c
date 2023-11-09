#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, string argv[])
{

    int distance = 0; // bunu ileride kullanıyorum hesap için.

    if (argc != 2)
    {
        printf("Usage: ./caesar key");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        // argv[1] girdiğimiz değer anlamına geliyor.
        // girdiğimiz değerin i. elemanını kontrol ediyoruz.
        // isalpha ve !isalphayı kullan.
        if (isalpha(argv[1][i]))
        {
            printf("Usage: ./caesar key");
            return 1;
        }
    }

    int k = atoi(argv[1]) % 26;
    string text = get_string("plaintext: ");
    printf("ciphertext: ");

    for (int i = 0; i < strlen(text); i++)
    {
        if (!isalpha(text[i]))
        {
            printf("%c", text[i]);
        }
        else
        {
            if (isupper(text[i]))
            {
                distance = 65;
            }
            else
            {
                distance = 97;
            }

            int pli = text[i] - distance;
            int ci = (pli + k) % 26;
            int result = ci + distance;

            printf("%c", result);
        }
    }
    printf("\n");
    return 0;

}