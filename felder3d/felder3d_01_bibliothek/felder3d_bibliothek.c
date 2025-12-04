#include "felder3d_bibliothek.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Erzeugt ein 3D-Zeiger-Feld für ein 3D-Feld
 * @param ebenen_n Anzahl an Ebenen
 * @param zeilen_n Anzahl an Zeilen
 * @param spalten_n Anzahl an Spalten
 * @param anf_ptr Anfangs Pointer auf das 3D Feld
 * @param elem_size Speichergröße eines Elements
 * @return Anfangs-Zeiger auf 3D-Zeiger-Feld
 */
void*** zugriffsfelder_erzeugen_allg(int ebenen_n, int zeilen_n, int spalten_n, void* anf_ptr, size_t elem_size){
    void *matrix_3d_anf_ptr = anf_ptr;
    void *zeilen_anf_ptr;
    void ***matrix_3d_3ptr;
    int ebene, zeile;
    size_t n_bytes;

    // Die doppelt indirekte Zeigermatrix belegen
    printf("Die doppelt indirekte Zeigermatrix belegen...\n");
    matrix_3d_3ptr = (void***) calloc(ebenen_n, sizeof(void**));
    assert(matrix_3d_3ptr);

    // Fuer jede Ebene die einfach indirekte Zeigermatrix
    //   anlegen und initialisieren
    printf("Fuer jede Ebene die einfach indirekte Zeigermatrix "
        "anlegen...\n");
    zeilen_anf_ptr = matrix_3d_anf_ptr;
    for(ebene = 0; ebene < ebenen_n; ebene++)
    {
        n_bytes = zeilen_n*sizeof(void*);
        matrix_3d_3ptr[ebene] = malloc(n_bytes);
        assert(matrix_3d_3ptr[ebene]);
        for(zeile = 0; zeile < zeilen_n; zeile++)
        {
            matrix_3d_3ptr[ebene][zeile] = zeilen_anf_ptr;
            zeilen_anf_ptr += spalten_n * elem_size;
        }
    }
    return matrix_3d_3ptr;
}

/**
 * Gibt 3D-Zeiger-Matrix im Speicher frei
 * @param matrix_3d_3ptr Anfangs-Zeiger auf 3D-Zeiger-Feld
 * @param ebenen_n Anzahl Ebenen
 */
void zugriffsfelder_freigeben_allg(void*** matrix_3d_3ptr, int ebenen_n) {
    for (int ebene = 0; ebene < ebenen_n; ++ebene) {
        free(matrix_3d_3ptr[ebene]);
    }
    free(matrix_3d_3ptr);
}
