//
// Created by xlcz on 10/12/2023.
//

#ifndef TREBUCHET_H
#define TREBUCHET_H
#include <stdio.h>

// silver star

void trebuchet() {
    FILE* file = fopen("input.txt", "r");
    char line[128];
    int counter = 0;
    while (fgets(line, sizeof(line), file)) {
        int firstDigit = -1, lastDigit = 0;

        for (int i = 0; i < sizeof(line); i++) { // Foreach line in fgets
            if (line[i] == '\n') break; // End of sentence, skip current iterator
            const int asInt = (line[i] - 0) - 48; // Convert to integer values (0-9)
            if (asInt < 0 || asInt > 9) continue; // not an integer
            if (firstDigit == -1) {
                firstDigit = asInt * 10; // Emulates string concatenation, first digit will always be * 10 while second digit is added
            }
            lastDigit = asInt;
        }
        counter += (firstDigit + lastDigit); // Increment counter
        line[0] = "\0"; // clear line
    }
    printf("%i", counter); // Print output
    fclose(file);
}

#endif //TREBUCHET_H
