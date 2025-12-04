/**
 * 3D-Felder auf dem Heap mit Indexzugriffen.
 *
 * TINF25CS1, 10.11.2025
 */
// Standard-Header
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Eigene Bibliotheken
#include "felder3d_bibliothek.h"

// Prototypen
double*** zugriffsfelder_erzeugen(int ebenen_n, int zeilen_n, int spalten_n, double* anf_ptr);
void zugriffsfelder_freigeben(double*** matrix_3d_3ptr, int ebenen_n);

/**
 * Hauptprogramm.
 */
int main(int argc, char*argv[])
{
	int ebenen_n = 3, ebene;
	int zeilen_n = 5, zeile;
	int spalten_n = 4, spalte;
	double *matrix_3d_anf_ptr, *lauf_ptr;
	double ***matrix_3d_3ptr;
	int n_bytes;
	int n_elem_in_ebene;
	int lin_index;

	printf("Dynamische 3D-Felder mit Indexzugriffen\n");

	// Speicherplatz fuer das 3D-Feld belegen
	printf("Speicherplatz fuer das 3D-Feld belegen...\n");
	n_bytes = ebenen_n * zeilen_n * spalten_n * sizeof(*matrix_3d_anf_ptr);
	//oder so: ... sizeof(double);
	matrix_3d_anf_ptr = (double*) malloc(n_bytes);
	assert(matrix_3d_anf_ptr); // oder so: matrix_3d_anf_ptr != NULL
	
	// Das 3D-Feld initialisieren (100*ebene+10*zeile+spalte)
	printf("Das 3D-Feld initialisieren...\n");
	lauf_ptr = matrix_3d_anf_ptr;
	for(ebene = 0; ebene < ebenen_n; ebene++)
	{
		for(zeile = 0; zeile < zeilen_n; zeile++)
		{
			for(spalte = 0; spalte < spalten_n; spalte++)
			{
				*lauf_ptr++ = 100*ebene+10*zeile+spalte;
			}
		}
	}

	// Das 3D-Feld "klassisch" ausgeben
	printf("Das 3D-Feld \"klassisch\" ausgeben:\n");
	n_elem_in_ebene = zeilen_n*spalten_n;
	for(ebene = 0; ebene < ebenen_n; ebene++)
	{
		for(zeile = 0; zeile < zeilen_n; zeile++)
		{
			for(spalte = 0; spalte < spalten_n; spalte++)
			{
				lin_index = ebene*n_elem_in_ebene +
					zeile*spalten_n + spalte;
				printf("%05.1lf   ", *(matrix_3d_anf_ptr+lin_index));
				if(0)printf("%5.1lf   ", matrix_3d_anf_ptr[lin_index]);
			}
			printf("\n");
		}
		printf("\n");
	}

	// Programmieraufgabe:

	matrix_3d_3ptr = (double***) zugriffsfelder_erzeugen(ebenen_n,
		zeilen_n, spalten_n, matrix_3d_anf_ptr);

	// Die jetzt moeglich gewordene Indexschreibweise
	//   verwenden, um das Feld erneut auszugeben
	printf("Ausgeben mittels Indexnotation:\n");
	for(ebene = 0; ebene < ebenen_n; ebene++)
	{
		for(zeile = 0; zeile < zeilen_n; zeile++)
		{
			for(spalte = 0; spalte < spalten_n; spalte++)
			{
				printf("%05.1lf   ", 
					matrix_3d_3ptr[ebene][zeile][spalte]);
			}
			printf("\n");
		}
		printf("\n");
	}

	// Programmieraufgabe weiter:

	short ebenen2_n = 6, ebene2;
	short zeilen2_n = 3, zeile2;
	short spalten2_n = 5, spalte2;
	short *matrix2_3d_anf_ptr, *lauf_ptr2;
	short ***matrix2_3d_3ptr;
	short n2_bytes;

	printf("Dynamische 3D-Felder mit Indexzugriffen\n");

	// Speicherplatz fuer das 3D-Feld belegen
	printf("Speicherplatz fuer das 3D-Feld belegen...\n");
	n2_bytes = ebenen2_n * zeilen2_n * spalten2_n * sizeof(*matrix2_3d_anf_ptr);
	//oder so: ... sizeof(double);
	matrix2_3d_anf_ptr = (short*) malloc(n2_bytes);
	assert(matrix2_3d_anf_ptr); // oder so: matrix_3d_anf_ptr != NULL

	// Das 3D-Feld initialisieren (100*ebene+10*zeile+spalte)
	printf("Das 3D-Feld initialisieren...\n");
	lauf_ptr2 = matrix2_3d_anf_ptr;
	for(ebene2 = 0; ebene2 < ebenen2_n; ebene2++)
	{
		for(zeile2 = 0; zeile2 < zeilen2_n; zeile2++)
		{
			for(spalte2 = 0; spalte2 < spalten2_n; spalte2++)
			{
				*lauf_ptr2++ = 100*ebene2+10*zeile2+spalte2;
			}
		}
	}

	matrix2_3d_3ptr = (short***) zugriffsfelder_erzeugen_allg(ebenen2_n,
	zeilen2_n, spalten2_n, matrix2_3d_anf_ptr, sizeof(short));

	// Die jetzt moeglich gewordene Indexschreibweise
	//   verwenden, um das Feld erneut auszugeben
	printf("Ausgeben mittels Indexnotation:\n");
	for(ebene2 = 0; ebene2 < ebenen2_n; ebene2++)
	{
		for(zeile2 = 0; zeile2 < zeilen2_n; zeile2++)
		{
			for(spalte2 = 0; spalte2 < spalten2_n; spalte2++)
			{
				printf("%03hd   ",
					matrix2_3d_3ptr[ebene2][zeile2][spalte2]);
			}
			printf("\n");
		}
		printf("\n");
	}


	zugriffsfelder_freigeben_allg((void***) matrix_3d_3ptr, ebenen_n);
	zugriffsfelder_freigeben_allg((void***) matrix2_3d_3ptr, ebenen2_n);
	free(matrix_3d_anf_ptr);
	free(matrix2_3d_anf_ptr);
	return EXIT_SUCCESS;
}
// main


/**
 * Erzeugt ein double 3D-Zeiger-Feld für ein 3D-Feld
 * @param ebenen_n Anzahl an Ebenen
 * @param zeilen_n Anzahl an Zeilen
 * @param spalten_n Anzahl an Spalten
 * @param anf_ptr Anfangs Pointer auf das 3D Feld
 * @return Anfangs-Zeiger auf 3D-Zeiger-Feld
 */
double*** zugriffsfelder_erzeugen(int ebenen_n, int zeilen_n, int spalten_n, double* anf_ptr){
	double *matrix_3d_anf_ptr = anf_ptr;
	double *zeilen_anf_ptr;
	double ***matrix_3d_3ptr;
	int ebene, zeile;
	size_t n_bytes;

	// Die doppelt indirekte Zeigermatrix belegen
	printf("Die doppelt indirekte Zeigermatrix belegen...\n");
	matrix_3d_3ptr = (double***) calloc(ebenen_n, sizeof(double**));
	assert(matrix_3d_3ptr);

	// Fuer jede Ebene die einfach indirekte Zeigermatrix
	//   anlegen und initialisieren
	printf("Fuer jede Ebene die einfach indirekte Zeigermatrix "
		"anlegen...\n");
	zeilen_anf_ptr = matrix_3d_anf_ptr;
	for(ebene = 0; ebene < ebenen_n; ebene++)
	{
		n_bytes = zeilen_n*sizeof(double*);
		matrix_3d_3ptr[ebene] = (double**)realloc(NULL, n_bytes);
		assert(matrix_3d_3ptr[ebene]);
		for(zeile = 0; zeile < zeilen_n; zeile++)
		{
			matrix_3d_3ptr[ebene][zeile] = zeilen_anf_ptr;
			zeilen_anf_ptr += spalten_n;
		}
	}
	return matrix_3d_3ptr;
}

/**
 * Gibt 3D-Zeiger-Matrix im Speicher frei
 * @param matrix_3d_3ptr Anfangs-Zeiger auf 3D-Zeiger-Feld
 * @param ebenen_n Anzahl Ebenen
 */
void zugriffsfelder_freigeben(double*** matrix_3d_3ptr, int ebenen_n) {
	for (int ebene = 0; ebene < ebenen_n; ++ebene) {
		free(matrix_3d_3ptr[ebene]);
	}
	free(matrix_3d_3ptr);
}
