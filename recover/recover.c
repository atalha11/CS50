#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check for invalid usage
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    // input_file şu anda card.raw ı point ediyor. read modundayız
    // eğer invalid bir file deniyorsa kullanıcı, input_file null olacak:
    if (input_file == NULL)
    {
        printf("Invalid file !");
        return 2;
    }

    // 512 byte lık blokları depolamak için array oluşturuyoruz:
    // unsigned char kullanıyormuşuz, sadece pozitif basıyormuş bünyeye

    unsigned char buffer[512];

    int counter = 0; // kaç tane image olduğunu sayacak.

    // output için yine file pointer yapıyoruz:
    FILE *output_file = NULL;
    // null çünkü henüz output yok

    // yer açıyoruz:
    char *filename = malloc(8 * sizeof(char));

    // blokları okumaya başla
    while (fread(buffer, sizeof(char), 512, input_file))
    {
        // JPEG startı var mı diye check ediyoruz:
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff & (buffer [3] & 0xf0) == 0xe0)
        {
            sprintf(filename, "%03i.jpg", counter);

            output_file = fopen(filename, "w");

            counter++;
        }

        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output_file);
        }
    }
    free(filename);
    fclose(output_file);
    fclose(input_file);

    return 0;
}