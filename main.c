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
        exit(EXIT_FAILURE);
    }

    uint32_t val = readValue(f);

    int c = fclose(f);
    if ( c == EOF ) {
        exit(EXIT_FAILURE);
    }

    return val;
}


int main(int argc, char** argv) {
    if ( argc == 1 ) {
        exit(EXIT_FAILURE);
    }
    #define arg argv[1]

    bool relative = false;
    if ( arg[0] == '+' || arg[0] == '-' ) {
        relative = true;
        if ( strlen(arg) < 2 ) {
            exit(EXIT_FAILURE);
        }
    }

    int32_t brightness, percentage, max_brightness;
    max_brightness = readFromFile(BACKLIGHT_PATH"max_brightness");

    int32_t argval;
    int err = sscanf(arg, "%i", &argval);
    if ( err == EOF ) {
        exit(EXIT_FAILURE);
    }

    if ( argval > 100 ) {
        exit(EXIT_FAILURE);
    }

    percentage = argval;

    if ( relative ) {
        brightness = readFromFile(BACKLIGHT_PATH"brightness");
        percentage = (brightness*100/max_brightness)+argval;
        if ( percentage < 0 || percentage > 100 ) {
            exit(EXIT_FAILURE);
        }
    }

    brightness = percentage*max_brightness/100;


    FILE* f = fopen(BACKLIGHT_PATH"brightness", "w");
    if ( f == NULL ) {
        exit(EXIT_FAILURE);
    }

    err = fprintf(f, "%i\n", brightness);
    if ( err < 0 ) {
        exit(EXIT_FAILURE);
    }

    err = fclose(f);
    if ( err == EOF ) {
        exit(EXIT_FAILURE);
    }

    return 0;
}
