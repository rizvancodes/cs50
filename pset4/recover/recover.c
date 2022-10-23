#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

typedef uint8_t BYTE;

int BLOCK_SIZE = sizeof(BYTE) * 512;

int main(int argc, char *argv[])
{
   //check for invalid usage
   if (argc < 2 || argc > 2)
   {
      printf("Usage: ./recover filename.raw\n");
      return 1;
   }

   //declare new buffer of size 512 bytes
   BYTE *buffer = malloc(BLOCK_SIZE);

   //number of jpegs counter
   int jpegnum = 0;

   //filename array to store filename
   char filename[8];

   //open memory card file
   FILE *input = fopen(argv[1], "r");
      if (input == NULL)
      {
         printf("Could not open file.\n");
         return 2;
      }

   FILE *output = fopen(filename, "w");

   //begin reading from new file as long as fread returns a value of 512 bytes read
   while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, input) == 512)
   {
      if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
      {
         if (jpegnum != 0)
         {
            fclose(output);
         }
         sprintf(filename, "%03i.jpg", jpegnum);
         fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, output);
         jpegnum++;
      }
      else if (jpegnum > 0)
      {
         fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, output);
      }
   }

fclose(input);
fclose(output);
free(buffer);

return 0;
}