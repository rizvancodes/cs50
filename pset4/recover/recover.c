#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

typedef uint8_t BYTE;

int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
 //check for invalid usage
 if (argc < 2 || argc > 2)
 {
    printf("Usage: ./recover filename.raw\n");
    return 1;
 }

//open memory card file
FILE *input = fopen(argv[1], "r");


//declare new buffer
BYTE buffer[malloc(BLOCK_SIZE)];
//number of jpegs
int jpegnum = 0;
//name of current file
char *filename;
filename = malloc(sizeof(char) * 8);
//begin reading from new file as long as fread returns a value of 512 bytes read
while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, argv[1]) == BLOCK_SIZE)
{
//begin reading from raw file
   fread(buffer, sizeof(BYTE), BLOCK_SIZE, input);
//look for beginning of jpeg
   if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
   {
      //if another signature is found stop and close new jpeg
      fclose(output)
      //count number of jpegs
      jpegnum++;
      //store filename as ###.jpg in filename
      sprintf(filename, "%03i.jpg", jpegnum);
      //open new jpeg file
      FILE *output = fopen(filename. "w");
      fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, output);
   }
   else
   {
      //continue to write 512 bytes until a new jpeg is found
      fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, output);
   }
   free(filename);
   free(buffer);

}


//stop and close new jpeg

//repeat and begin to write a new jpeg

}