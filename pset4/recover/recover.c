#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>

typedef uint8_t BYTE;
bool st_jpg(BYTE buffer[]);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("file not found\n");
        return 1;
    }
    BYTE buffer[512];
    int found = 0;
    int count = 0;
    char filename[8];
    FILE *img;
    while (fread (buffer, 512, 1, file))
    {
        if (st_jpg(buffer))
        {
            if (!found)
                found = 1;
            else
                fclose(img);

            sprintf(filename, "%03i.jpg", count++);
            img = fopen(filename, "w");
            fwrite(buffer, 512, 1, img);
            if (img == NULL)
            {
                return 1;
            }
        }
        else if (found)
        {
            // keep writing
            fwrite(buffer, 512, 1, img);
        }
    }
    fclose(img);
    fclose(file);
}
//0xff 0xd8 0xff
bool st_jpg(BYTE buffer[])
{
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
        return 1;
    }
    else
        return 0;
}