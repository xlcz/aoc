//
// Created by xlcz on 10/12/2023.
//

#ifndef TREBUCHET_H
#define TREBUCHET_H
#include <stdio.h>

// silver star

void trebuchet() {
    FILE* file = fopen("input.txt", "r");
    char chunk[128];
    int counter = 0;
    while (fgets(chunk, sizeof(chunk), file)) {
        int firstDigit = -1;
        int lastDigit = 0;
        for (int i = 0; i < sizeof(chunk); i++) {
            if (chunk[i] == '\n') break;
            const int asciiCode = chunk[i] - 0;

            const int asInt = asciiCode - 48;
            if (asInt >= 0 && asInt <= 9) {
                if (firstDigit == -1) {
                    firstDigit = asInt * 10;
                }
                lastDigit = asInt;
            }
        }
        counter += (firstDigit + lastDigit);
        chunk[0] = "\0";
    }
    printf("%i", counter);
    fclose(file);
}

#endif //TREBUCHET_H
