#include <Windows.h>
#include <iostream>
#include <string>
#include <fcntl.h>

byte &PasswordCreater() {
    byte ASCII[14];
    int pwLength = 0;

    ASCII[7] = 0xb3;
    ASCII[8] = 0x9e;
    ASCII[9] = 0xba;
    ASCII[10] = 0x19;
    ASCII[11] = 0xd2;
    ASCII[12] = 0xe2;
    ASCII[13] = 0xe6;
    ASCII[0] = 0xac;
    ASCII[1] = 0x9e;
    ASCII[2] = 0xe7;
    ASCII[3] = 0x61;
    ASCII[4] = 0xda;
    ASCII[5] = 0x32;
    ASCII[6] = 0x4a;


    auto LooksLikePW = (byte*)malloc(8);

    while (pwLength < 8) {
        LooksLikePW[pwLength] = (ASCII[pwLength] ^ ASCII[(long)pwLength + 7]) << ((byte)pwLength & 0x1f) & 0x32;
        pwLength += 1;
    };

    LooksLikePW[1] = LooksLikePW[1] | 0x33;
    *LooksLikePW = *LooksLikePW ^ LooksLikePW[1] + 0x2e;
    LooksLikePW[2] = LooksLikePW[2] ^ 0x53;
    LooksLikePW[3] = LooksLikePW[3] ^ 0x6c;
    LooksLikePW[3] = LooksLikePW[3] + 6;
    LooksLikePW[4] = 0x45;
    LooksLikePW[5] = LooksLikePW[2] * '\b' + 0x5c;
    LooksLikePW[6] = LooksLikePW[6] ^ 0x58;
    LooksLikePW[7] = 0;

    return *LooksLikePW;
}

int main() {
    std::cout << &PasswordCreater();

    return 0;
}
