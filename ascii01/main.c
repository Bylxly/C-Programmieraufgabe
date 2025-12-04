/**
 * ASCII-Zeichentabelle ausgeben
 *
 * TINF25CS1, 23.10.2025
 */
//Standart-Header
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Prototypen
int my_isdigit(int z);

int my_iscntrl(int z);
int my_islower(int z);
int my_isupper(int z);

// Programmieraufgabe
size_t my_strlen(char *ptr);

/**
 * Hauptprogramm
 */
int main(int argc, char *argv[]) {
    int a, b;

    printf("ASCII-Zeichentabelle\n");

    printf("isdigit:\n");
    printf("Dec |  Hex |  Hex |  Oct | Sym | isdigit | my_isdigit || equal?\n");
    for (int i = 0; i < 128; i++) {
        printf("%3d | 0x%02X | 0x%02x | 0%03o | %3c |", i, i, i, i, (i < 32) ? ' ' : i);
        a = isdigit(i);
        b = my_isdigit(i);
        printf(" %7d | %d \t\t  || %d\n", a, b, a == b);
    }

    printf("iscntrl:\n");
    printf("Dec |  Hex |  Hex |  Oct | Sym | iscntrl | my_iscntrl || equal?\n");
    for (int i = 0; i < 128; i++) {
        printf("%3d | 0x%02X | 0x%02x | 0%03o | %3c |", i, i, i, i, (i < 32) ? ' ' : i);
        a = iscntrl(i);
        b = my_iscntrl(i);
        printf(" %7d | %d \t\t  || %d\n", a, b, a == b);
    }

    printf("islower:\n");
    printf("Dec |  Hex |  Hex |  Oct | Sym | islower | my_islower || equal?\n");
    for (int i = 0; i < 128; i++) {
        printf("%3d | 0x%02X | 0x%02x | 0%03o | %3c |", i, i, i, i, (i < 32) ? ' ' : i);
        a = islower(i);
        b = my_islower(i);
        printf(" %7d | %d \t\t  || %d\n", a, b, a == b);
    }

    printf("isupper:\n");
    printf("Dec |  Hex |  Hex |  Oct | Sym | isupper | my_isupper || equal?\n");
    for (int i = 0; i < 128; i++) {
        printf("%3d | 0x%02X | 0x%02x | 0%03o | %3c |", i, i, i, i, (i < 32) ? ' ' : i);
        a = isupper(i);
        b = my_isupper(i);
        printf(" %7d | %d \t\t  || %d\n", a, b, a == b);
    }

    //Programmieraufgabe

    printf("\n\n\n\n\n");

    char string[] = "Test1234";

    printf("Test1234\n");
    printf("Strlen: %lu, Mystrlen: %lu", strlen(string), my_strlen(string));

    return EXIT_SUCCESS;
}

/**
 * Selbst implementierte Variante von isdigit.
 * Siehe ctype.h bzw. Anhang A von Goll!
 */
int my_isdigit(int z) {
    return '0' <= z && z <= '9';
}

/**
 * Selbst implementierte Variante von iscntrl.
 */
int my_iscntrl(int z) {
    return (0 <= z && z <= 31) || z == 127;
}

/**
 * Selbst implementierte Variante von islower.
 */
int my_islower(int z) {
    return 'a' <= z && z <= 'z';
}

/**
 * Selbst implementierte Variante von isupper.
 */
int my_isupper(int z) {
    return 'A' <= z && z <= 'Z';
}


// Programmieraufgabe

/**
 * Selbst implementierte Variante von strlen.
 */
size_t my_strlen(char *ptr) {
    size_t len = 0;
    while ( *ptr != '\0') {
        len++;
        ptr++;
    }
    return len;
}
