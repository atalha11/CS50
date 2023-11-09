#include <stdio.h>
#include <cs50.h>

int main (void)

{
long number = get_long ("Card number ? \n");
int basamak = 1;
long ahmet = number;
do {
ahmet = (ahmet/10);
basamak++;

} while (ahmet >= 10 );
         int a = number%100/10*2;
         int b = number%10000/1000*2;
         int c = number%1000000/100000*2;
         int d = number%100000000/10000000*2;
         int e = number%10000000000/1000000000*2;
         int f = number%1000000000000/100000000000*2;
         int g = number%100000000000000/10000000000000*2;
         int h = number%10000000000000000/1000000000000000*2;
        if (a>9){
        a=a-9;}

        if (b>9){
        b=b-9;}

        if (c>9){
        c=c-9;}

        if (d>9){
        d=d-9;}

        if (e>9){
         e=e-9;}

         if (f>9){
         f=f-9;}

         if (g>9){
         g=g-9;}

         if (h>9){
         h=h-9;}

         int birinci = a+b+c+d+e+f+g+h;

         int as = number%10;
         int bs = number%1000/100;
         int cs = number%100000/10000;
         int ds = number%10000000/1000000;
         int es = number%1000000000/100000000;
         int fs = number%100000000000/10000000000;
         int gs = number%10000000000000/1000000000000;
         int hs = number%1000000000000000/100000000000000;

        int ikinci = as+bs+cs+ds+es+fs+gs+hs;

        if ((birinci+ikinci)%10!=0)
        printf("INVALID\n");

        else if
        (basamak == 16 && number >= 5100000000000000 && 5599999999999999 >= number )
          printf("MASTERCARD\n");

         else if (basamak == 15 && number <= 349999999999999 && 340000000000000<=number)
      printf ("AMEX\n");
      else if (basamak == 15 && number >= 370000000000000 && number <= 379999999999999)
      printf ("AMEX\n");

        else if (basamak == 13 && number <= 4999999999999 && number >= 4000000000000)
        printf ("VISA\n");
        else if (basamak ==16  &&  number > 4000000000000000 && number <= 4999999999999999)
        printf ("VISA\n");

        else
        printf("INVALID\n");
}