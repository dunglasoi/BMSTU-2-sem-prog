#include <stdio.h>
#include <stdint.h>

void print_binary(unsigned int value);
int check_input(unsigned int byte1, unsigned int byte2, unsigned int byte3, unsigned int byte4);

int main() 
{
    unsigned int byte1, byte2, byte3, byte4;
    printf("Enter four bytes in decimal notation:\n");
    int rc = scanf("%u %u %u %u", &byte1, &byte2, &byte3, &byte4);
    if (rc != 4 || check_input(byte1, byte2, byte3, byte4))
    {
        printf("Error: Input\n");
        return -1;
    }    
    // Pack the bytes into a 32-bit unsigned integer
    unsigned int packed_value = (byte1 << 24) | (byte2 << 16) | (byte3 << 8) | byte4;
    // Output the binary representation of the packed value
    printf("Result: ");
    print_binary(packed_value);
    printf(" ");

    // Unpack the bytes from the packed value
    unsigned int unpacked_byte1 = (packed_value >> 24) & 0xFF;
    unsigned int unpacked_byte2 = (packed_value >> 16) & 0xFF;
    unsigned int unpacked_byte3 = (packed_value >> 8) & 0xFF;
    unsigned int unpacked_byte4 = packed_value & 0xFF;

    printf("%u %u %u %u", unpacked_byte1, unpacked_byte2, unpacked_byte3, unpacked_byte4);
    return 0;
}

void print_binary(unsigned int value)
{
    for (int i = 31; i >= 0; i--) 
    {
        unsigned int mask = 1u << i;
        printf("%d", (value & mask) ? 1 : 0);
    }
}

int check_input(unsigned int byte1, unsigned int byte2, unsigned int byte3, unsigned int byte4)
{
    if (byte1 > 255 || byte2 > 255 || byte3 > 255 || byte4 > 255)
    {
        return 1;
    }
    return 0;
}
