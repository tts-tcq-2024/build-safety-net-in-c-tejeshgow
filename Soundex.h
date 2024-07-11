#ifndef SOUNDEX_H
#define SOUNDEX_H
 
#include "Soundex.h"
#include <ctype.h>
#include <string.h>
 

#define GET_SOUNDEX(c) (\
    (c == 'B' || c == 'F' || c == 'P' || c == 'V') ? '1' : \
    (c == 'C' || c == 'G' || c == 'J' || c == 'K' || c == 'Q' || c == 'S' || c == 'X' || c == 'Z') ? '2' : \
    (c == 'D' || c == 'T') ? '3' : \
    (c == 'L') ? '4' : \
    (c == 'M' || c == 'N') ? '5' : \
    (c == 'R') ? '6' : \
    '0')
char getSoundexCode(char c) {
    c = toupper(c);
    return GET_SOUNDEX(c);
}
void addcode(int *sIndex, char code, char *soundex) {
    if (code != '0' && code != soundex[*sIndex - 1]) {
        soundex[*sIndex] = code;
        (*sIndex)++;
    }
}
void padding(int *sIndex, char *soundex) {
    while (*sIndex < 4) {
        soundex[*sIndex] = '0';
        (*sIndex)++;
    }
    soundex[4] = '\0';
}
void generateSoundex(const char *name, char *soundex) {
    int len = strlen(name);
    soundex[0] = toupper(name[0]);
    int sIndex = 1;
    for (int i = 1; i < len && sIndex < 4; i++) {
        char code = getSoundexCode(name[i]);
        addcode(&sIndex, code, soundex);
    }
    padding(&sIndex, soundex);
}
 
#endif // SOUNDEX_H
