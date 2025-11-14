#include <stdio.h>
#include <string.h>
#include <stdint.h>
#define POLY_CRC12 0x80F
#define POLY_CRC16 0x8005
#define POLY_CCITT 0x1021
unsigned int computeCRC(const unsigned char *data, size_t len, unsigned int poly, int bits) {
    unsigned int crc = 0;
    unsigned int msbMask = 1U << (bits - 1);
    unsigned int mask = (1U << bits) - 1;    

    for (size_t i = 0; i < len; i++) {
        crc ^= (data[i] << (bits - 8));
        for (int j = 0; j < 8; j++) {
            if (crc & msbMask) {
                crc = (crc << 1) ^ poly;
            } else {
                crc <<= 1;
            }
            crc &= mask; 
        }
    }
    return crc & mask;
}

int main() {
    unsigned char message[100];

    printf("Enter a string: ");
    fgets((char *)message, sizeof(message), stdin);
    message[strcspn((char *)message, "\n")] = 0; 

    size_t len = strlen((char *)message);

    unsigned int crc12   = computeCRC(message, len, POLY_CRC12, 12);
    unsigned int crc16   = computeCRC(message, len, POLY_CRC16, 16);
    unsigned int crcCCIT = computeCRC(message, len, POLY_CCITT, 16);

    printf("\nMessage: %s\n", message);
    printf("CRC-12    = 0x%03X\n", crc12);
    printf("CRC-16    = 0x%04X\n", crc16);
    printf("CRC-CCITT = 0x%04X\n", crcCCIT);

    return 0;
}
