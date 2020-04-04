#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "./config.h"


uint32_t readValue(FILE* f) {
    uint32_t i;
    fscanf(f, "%i", &i);
    return i;
}


uint32_t readFromFile(char* filename) {
    FILE* f = fopen(filename, "r");
    if ( f == NULL ) {
        exit(1);
    }

    uint32_t val = readValue(f);
    int c = fclose(f);
    if ( c == EOF ) {
        exit(2);
    }

    return val;
}


int main(int argc, char** argv) {
    if ( argc == 1 ) {
        exit(EXIT_FAILURE);
    }
    char* arg = argv[1];

    bool relative = false;
    if ( (arg[0] == '+' || arg[0] == '-') ) {
        relative = true;
        if ( strlen(arg) < 2 ) {
            exit(EXIT_FAILURE);
        }
    }

    uint32_t max_brightness = readFromFile(BACKLIGHT_PATH"max_brightness");
    uint32_t brightness = readFromFile(BACKLIGHT_PATH"brightness");
    int32_t percentage = brightness*100/max_brightness;

    printf("%i\n", max_brightness);
    printf("%i\n", brightness);
    printf("%i\n", percentage);

    return 0;
}
