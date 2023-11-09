#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{

    string text = get_string("Text: ");

    int letters = count_letters(text);
//    printf("Letters: %i\n", letters);

    int words = count_words(text);
//    printf("Words: %i\n", words);

    int sentences = count_sentences(text);
//    printf("Sentences: %i\n", sentences);

    double L = (double) letters / (double)words * 100;

    double S = (double) sentences / (double)words * 100;

    double index2 = 0.0588 * L - 0.296 * S - 15.8;

    int index = round(index2);

    if (index > 1 && index < 16)
    {
        printf("Grade %i\n", index);
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }

}



int count_letters(string text) // Burada harf sayıyoruz
{
    int letters = 0;

    for (int i = 0; i < strlen(text); i++)
    {

        if (text[i] >= 97 && text[i <= 122])
        {
            letters++;
        }

        if (text[i] >= 65 && text[i] <= 90)
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)    // burada yalandan kelime sayıyoruz
{
    int words = 1;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }
    return words;
}

int count_sentences(string text)    //burada da yalandan cümle sayıyoruz
{
    int sentences = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}