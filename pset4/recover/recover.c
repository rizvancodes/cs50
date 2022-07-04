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

   //declare new buffer of size 512 bytes
   BYTE buffer[512];

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

   FILE *output;

   //begin reading from new file as long as fread returns a value of 512 bytes read
   while (fread(buffer, 512, 1, input) == BLOCK_SIZE)
   {
      
   }

}