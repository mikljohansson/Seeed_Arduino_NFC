#include "Ndef.h"

#ifdef NDEF_USE_SERIAL
// Borrowed from Adafruit_NFCShield_I2C
void PrintHex(const byte* data, const long numBytes) {
    int32_t szPos;
    for (szPos = 0; szPos < numBytes; szPos++) {
        PN532_SERIAL.print("0x");
        // Append leading 0 for small values
        if (data[szPos] <= 0xF) {
            PN532_SERIAL.print("0");
        }
        PN532_SERIAL.print(data[szPos] & 0xff, HEX);
        if ((numBytes > 1) && (szPos != numBytes - 1)) {
            PN532_SERIAL.print(" ");
        }
    }
    PN532_SERIAL.println("");
}

// Borrowed from Adafruit_NFCShield_I2C
void PrintHexChar(const byte* data, const long numBytes) {
    int32_t szPos;
    for (szPos = 0; szPos < numBytes; szPos++) {
        // Append leading 0 for small values
        if (data[szPos] <= 0xF) {
            PN532_SERIAL.print("0");
        }
        PN532_SERIAL.print(data[szPos], HEX);
        if ((numBytes > 1) && (szPos != numBytes - 1)) {
            PN532_SERIAL.print(" ");
        }
    }
    PN532_SERIAL.print("  ");
    for (szPos = 0; szPos < numBytes; szPos++) {
        if (data[szPos] <= 0x1F) {
            PN532_SERIAL.print(".");
        } else {
            PN532_SERIAL.print((char)data[szPos]);
        }
    }
    PN532_SERIAL.println("");
}

// Note if buffer % blockSize != 0, last block will not be written
void DumpHex(const byte* data, const long numBytes, const unsigned int blockSize) {
    int i;
    for (i = 0; i < (numBytes / blockSize); i++) {
        PrintHexChar(data, blockSize);
        data += blockSize;
    }
}
#endif
