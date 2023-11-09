    #include <cs50.h>
    #include <stdio.h>

    int main(void)
    {

        int answer;
        do
        {
            answer = get_int("Height: ");
            int answer2 = answer - 1;

            if (answer >= 1 && answer <= 8)
            {

                // olay burada başlıyor
                for (int i = 1; i <= answer; i++)
                {

                    for (int k = answer2; k > 0; k--)
                    {
                        printf(" ");
                    }

                    for (int j = 1; j <= i; j++)
                    {
                        printf("#");
                    }
                    printf("\n");
                    answer2--;
                }
            }
        }
        while (answer < 1 || answer > 8);


    }