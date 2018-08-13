// CrypTools - GitHub
// Monday, 13 August 2018
// ROT13 Cipher to encrypt text

/****
Compile with:
$ make
Encrypt with:
$ ./rot13 < input.txt
****/

#include <stdio.h>
#include <stdlib.h>

// ASCII VALUES LATIN ALPHABET
#define MINCAP 65
#define MAXCAP 90

#define MINLOW 97
#define MAXLOW 122

void encode (char letter);

int main (int argc, const char *argv[]) {
    int c = 0;
    while ((c = getchar()) != EOF) {
       encode(c);
    }
    printf("\n");
    return EXIT_SUCCESS;
}

void encode (char letter) {
    int numAscii = letter;
    int firstLetter;
    if (numAscii >= MINCAP && numAscii <= MAXCAP) {
        firstLetter = MINCAP;
    } else if (numAscii >= MINLOW && numAscii <= MAXLOW) {
        firstLetter = MINLOW;
    } else {
        putchar(letter);
        return;
    }
    numAscii -= (firstLetter - 13);
    numAscii = (numAscii % 26);
    numAscii += firstLetter;
    putchar(numAscii);
}
