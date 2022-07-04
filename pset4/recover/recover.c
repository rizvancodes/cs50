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

//look for beginning of jpeg

//open a new jpeg to write into

//continue to write 512 bytes until a new jpeg is found

//close new jpeg and begin to write a new jpeg

}