#ifndef FELDER3D_01_BIBLIOTHEK_LIBRARY_H
#define FELDER3D_01_BIBLIOTHEK_LIBRARY_H
#include <stdio.h>

// Prototypen
void*** zugriffsfelder_erzeugen_allg(int ebenen_n, int zeilen_n, int spalten_n, void* anf_ptr, size_t elem_size);
void zugriffsfelder_freigeben_allg(void*** matrix_3d_3ptr, int ebenen_n);


#endif // FELDER3D_01_BIBLIOTHEK_LIBRARY_H