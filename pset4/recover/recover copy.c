#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
 //check for invalid usage
 if (argc < 2 || argc > 2)
 {
    printf("Usage: ./recover filename.raw\n");
    return 1;
 }

//declare new buffer
BYTE buffer[512];

//number of jpegs
int jpegnum = 0;

//name of current file
char filename[8];

//store filename as ###.jpg in filename
sprintf(filename, "%03i.jpg", jpegnum);

//open memory card file
FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 2;
    }

FILE *output = NULL;

//begin reading from new file as long as fread returns a value of 512 bytes read
while (fread(buffer, 512, 1, input) == BLOCK_SIZE)
{
//begin reading from raw file
   fread(buffer, 512, 1, input);
//look for beginning of jpeg
   if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
   {
      jpegnum++;
      if (jpegnum == 1)
      {
         output = fopen(filename, "w");
         fwrite(buffer, 512, 1, output);
      }
      else
      {
         fclose(output);
         //store filename as ###.jpg in filename
         sprintf(filename, "%03i.jpg", jpegnum);
         output = fopen(filename, "w");
         fwrite(buffer, 512, 1, output);
      }
   }
   else
   {
      //continue to write 512 bytes until a new jpeg is found
      fwrite(buffer, 512, 1, output);
   }

}

fclose(input);
fclose(output);

}