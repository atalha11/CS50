#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int sumCheck = 0;
    int basamak_sayisi = 0;
    int evenodd;

// 2. aşamanın başlangıcı
    long test2 = get_long("Kart no gir kardeş: ");
    long test3 = test2;
    long test4 = test2;

    while (test2 > 0)
    {
        test2 = test2 / 10;
        basamak_sayisi ++;
    }

    if (basamak_sayisi % 2 == 0)
    {
        evenodd = 0; // çift
    }
    else
    {
        evenodd = 1; // tek
    }
// 2. aşamanın sonu

// 3. aşamanın başlangıcı

    long islem_yapilan_basamak;
    long islem_yapilmis_basamak;
    long holy = 10;
    long moly = 1;
    int x; // altı çizili basamağı iki ile çarpıp buna assign edicem 9 dan büyük mü diye check edicem

    if (evenodd == 0)   // basamak sayısı çift ise
    {
        islem_yapilmis_basamak = 0;
        holy = holy * 10;
        moly = moly * 10;

        while (islem_yapilmis_basamak < basamak_sayisi)
        {
            islem_yapilan_basamak = (test3 % holy ) / moly;
            x = islem_yapilan_basamak * 2;

            if (x > 99)
            {
                sumCheck += (x % 1000) / 100;       // varsa yüzler basamağını alıyorum ve ekliyorum
            }

            if (x > 9)
            {
                sumCheck += (x % 100) / 10;        // varsa onlar basamağını alıyorum ve ekliyorum
            }

            sumCheck += x % 10;                     // birler basamağını alıyorum ve ekliyorum

            holy = holy * 100;
            moly = moly * 100;
            islem_yapilmis_basamak += 2;
        }

        islem_yapilan_basamak = 0;
        islem_yapilmis_basamak = 0;
        holy = 10;
        moly = 1;

        while (islem_yapilmis_basamak < (basamak_sayisi - 1))
        {
            islem_yapilan_basamak = (test3 % holy) / moly;

            sumCheck += islem_yapilan_basamak;

            holy = holy * 100;
            moly = moly * 100;

            if (islem_yapilmis_basamak == 0)
            {
                islem_yapilmis_basamak ++;
            }
            else
            {
                islem_yapilmis_basamak += 2;
            }
        }
    }

    if (evenodd == 1)   // basamak sayısı tek ise:
    {
        islem_yapilmis_basamak = 0;

        while (islem_yapilmis_basamak < basamak_sayisi)
        {
            islem_yapilan_basamak = (test3 % holy) / moly;
            x = islem_yapilan_basamak * 2;

            if (x > 99)
            {
                sumCheck += (x % 1000) / 100;       // varsa yüzler basamağını alıyorum ve ekliyorum
            }

            if (x > 9)
            {
                sumCheck += (x % 100) / 10;        // varsa onlar basamağını alıyorum ve ekliyorum
            }

            sumCheck += x % 10;                     // birler basamağını alıyorum ve ekliyorum

            holy = holy * 100;
            moly = moly * 100;

            if (islem_yapilmis_basamak == 0)
            {
                islem_yapilmis_basamak ++;
            }
            else
            {
                islem_yapilmis_basamak += 2;
            }

        }

        islem_yapilan_basamak = 0;
        islem_yapilmis_basamak = 0;
        holy = 100;
        moly = 10;

        while (islem_yapilmis_basamak < basamak_sayisi - 1)
        {
            islem_yapilan_basamak = (test3 % holy) / moly;
            sumCheck += islem_yapilan_basamak;

            holy = holy * 100;
            moly = moly * 100;
            islem_yapilmis_basamak += 2;
        }
    }

    if (sumCheck % 10 == 0)
    {


        while (test4 > 99)
        {
            test4 = test4 / 10;
        }

        if (test4 == 34 || test4 == 37)
        {
            printf("AMEX\n");
        }
        else if (test4 >= 51 && test4 <= 55)
        {
            printf("MASTERCARD\n");
        }
        else if (test4 >= 40 && test4 <= 49)
        {
            printf("VISA\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
    printf("%i",sumCheck);

/*
    int test = get_int("4 haneli sayı gir");
    int birler_basamagi = (test % 10)/1;                // (test % holy)/moly
    int onlar_basamagi  = (test % 100)/10;
    int yüzler_basamagi = (test % 1000)/100;
    int binler_basamagi = (test % 10000)/1000;

    printf("%i\n%i\n%i\n%i\n", birler_basamagi,onlar_basamagi,yüzler_basamagi,binler_basamagi);
*/

/*
    int basamak=0;
    int evenodd;

    int test2 = get_int("sayı gir: ");

        while(test2 > 0)
        {
            test2 = test2 / 10;
            basamak ++;
        }

        if (basamak % 2 == 0)
        {
            evenodd = 0; // çift
        }
        else
        {
            evenodd = 1; // tek
        }

        printf("%i\n", evenodd);
    */

}