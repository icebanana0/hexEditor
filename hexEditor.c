#include <stdio.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024

void printHex(unsigned char* buffer, int num) 
{
    for (int i = 0; i < num; i++) 
    {
        if (i % 10 == 0) 
        {
            printf("\n");
        }

        printf("%.2X ", buffer[i]);
    }

    printf("\n");
}

int main(int argc, char** argv) 
{
    if (argc != 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    FILE* f = fopen(argv[1], "rb");
    if (!f) {
        printf("Error: Unable to open file %s\n", argv[1]);
        return 1;
    }

    unsigned char buffer[BUFFER_SIZE];
    int num_of_bytes;
    while ((num_of_bytes = fread(buffer, 1, BUFFER_SIZE, f)) > 0) {
        printHex(buffer, num_of_bytes);
    }

    fclose(f);

    return 0;
}
