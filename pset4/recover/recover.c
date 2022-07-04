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
FILE *f = fopen(argv[1], "r");

//declare new buffer
BYTE buffer[malloc(BLOCK_SIZE * blocknum)];
//count the number of blocks read for each jpeg
int blocknum = 0
while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, argv[1]) == BLOCK_SIZE)
{
//begin reading from raw file
//look for beginning of jpeg

}

//open a new jpeg to write into

//continue to write 512 bytes until a new jpeg is found

//stop and close new jpeg

//repeat and begin to write a new jpeg

}