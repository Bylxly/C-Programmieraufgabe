/**
 * Flussdiagramm --> Struktogramm --> C-Programm
 *
 * TINF25CS1, 18.11.2025
 */
// Standard-Header
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototypen
void funktion1(int a, int b, int *c_ptr, int *d_ptr);
void tauschen_int(int *a_ptr, int *b_ptr);
void tauschen_allgemein_1(void *v1_ptr, void *v2_ptr,
						size_t groesse);
void tauschen_allgemein_2(void *v1_ptr, void *v2_ptr,
						size_t groesse);
void tauschen_allgemein_2b(void *v1_ptr, void *v2_ptr,
						size_t groesse);
void tauschen_allgemein_3(void *v1_ptr, void *v2_ptr,
						size_t groesse);

//Progammieraufgabe
void tauschen_allgemein_4(void *v1_ptr, void *v2_ptr,
						size_t groesse);

/**
 * Hauptprogramm
 */
int main(int argc, char*argv[])
{
	int a = 10, b = 20;
	int c = 50, d = 70;

	printf("Call-by-calue und call-by-reference:\n");
	printf("a = %d; b = %d\n", a, b);
	printf("c = %d; d = %d\n", c, d);
	funktion1(a, b, &c, &d);
	printf("a = %d; b = %d\n", a, b);
	printf("c = %d; d = %d\n", c, d);

	printf("a und b vertauschen ...\n");
	tauschen_int(&a, &b);
	printf("a = %d; b = %d\n", a, b);
	tauschen_allgemein_1(&a, &b, sizeof(a));
	printf("a = %d; b = %d\n", a, b);
	tauschen_allgemein_2(&a, &b, sizeof(a));
	printf("a = %d; b = %d\n", a, b);
	tauschen_allgemein_2b(&a, &b, sizeof(a));
	printf("a = %d; b = %d\n", a, b);
	tauschen_allgemein_3(&a, &b, sizeof(a));
	printf("a = %d; b = %d\n", a, b);

	//Programmieraufgabe
	printf("\n\nProgrammieraufgabe\n");
	tauschen_allgemein_4(&a, &b, sizeof(a));
	printf("a = %d; b = %d\n", a, b);

	return EXIT_SUCCESS;
} // main

/**
 * Test-Funktion f�r call-by-value und call-by-reference.
 */
void funktion1(int a, int b, int *c_ptr, int *d_ptr)
{
	printf("a = %d; b = %d\n", a, b);
	printf("*c_ptr = %d; *d_ptr = %d\n", *c_ptr, *d_ptr);
	a = 2*a;
	b = 10*b;
	*c_ptr = *c_ptr + 100;
	*d_ptr = *d_ptr + 1000;
	printf("a = %d; b = %d\n", a, b);
	printf("*c_ptr = %d; *d_ptr = %d\n", *c_ptr, *d_ptr);
} // funktion1

/**
 * Funktion tauscht die Inhalte von 2 int-Werten aus.
 * Mittels Dreieckstausch
 */
void tauschen_int(int *a_ptr, int *b_ptr)
{
	int i_tmp = *a_ptr;
	*a_ptr = *b_ptr;
	*b_ptr = i_tmp;
} // tauschen_int

/**
 * Funktion tauscht die Inhalte von 2 int-Werten aus.
 * Mittels Dreieckstausch
 */
void tauschen_allgemein_1(void *v1_ptr, void *v2_ptr,
						size_t groesse)
{
	char *tmp_ptr;
	char *c1_ptr = (char*)v1_ptr;
	char *c2_ptr = (char*)v2_ptr;
	tmp_ptr = (char*)malloc(groesse);
	assert(tmp_ptr != NULL);
	memcpy(tmp_ptr, v1_ptr, groesse);
	memcpy(v1_ptr, v2_ptr, groesse);
	memcpy(v2_ptr, tmp_ptr, groesse);
	free(tmp_ptr);
} // tauschen_allgemein_1


/**
 * Funktion tauscht die Inhalte von 2 Variablen bel. Typs.
 * Mittels Dreieckstausch
 */
void tauschen_allgemein_2(void *v1_ptr, void *v2_ptr,
						size_t groesse)
{
	static char *tmp_ptr = NULL; // Optional, wird sowieso
					//  automatisch auf NULL initialisiert!
	char*tmp2_ptr;
	char *c1_ptr = (char*)v1_ptr;
	char *c2_ptr = (char*)v2_ptr;
	tmp2_ptr = (char*)realloc(tmp_ptr, groesse);
	assert(tmp2_ptr != NULL);
	tmp_ptr = tmp2_ptr;
	memcpy(tmp_ptr, v1_ptr, groesse);
	memcpy(v1_ptr, v2_ptr, groesse);
	memcpy(v2_ptr, tmp_ptr, groesse);
} // tauschen_allgemein_2

/**
 * Funktion tauscht die Inhalte von 2 Variablen bel. Typs.
 * Mittels Dreieckstausch
 */
void tauschen_allgemein_2b(void *v1_ptr, void *v2_ptr,
						size_t groesse)
{
	static char *tmp_ptr = NULL; // Optional, wird sowieso
					//  automatisch auf NULL initialisiert!
	static size_t kapazitaet = 0; // Optional = 0
	char*tmp2_ptr;
	char *c1_ptr = (char*)v1_ptr;
	char *c2_ptr = (char*)v2_ptr;
	if(groesse > kapazitaet)
	{
		tmp2_ptr = (char*)realloc(tmp_ptr, groesse);
		assert(tmp2_ptr != NULL);
		tmp_ptr = tmp2_ptr;
		kapazitaet = groesse;
	}
	memcpy(tmp_ptr, v1_ptr, groesse);
	memcpy(v1_ptr, v2_ptr, groesse);
	memcpy(v2_ptr, tmp_ptr, groesse);
} // tauschen_allgemein_2b

/**
 * Funktion tauscht die Inhalte von 2 Variablen bel. Datentyps.
 * Mittels Dreieckstausch
 */
void tauschen_allgemein_3(void *v1_ptr, void *v2_ptr,
						size_t groesse)
{
	char *c1_ptr = (char*)v1_ptr;
	char *c2_ptr = (char*)v2_ptr;
	char c_tmp;
	size_t i;
	if(0)
		for(i = 0; i < groesse; i++)
		{
			c_tmp = *c1_ptr;
			*c1_ptr++ = *c2_ptr;
			*c2_ptr++ = c_tmp;
		}
	else
		for(i = 0; i < groesse; i++)
		{
			c_tmp = c1_ptr[i];
			c1_ptr[i] = c2_ptr[i];
			c2_ptr[i] = c_tmp;
		}
} // tauschen_allgemein_3

//Progammieraufgabe
void tauschen_allgemein_4(void *v1_ptr, void *v2_ptr,
                          size_t groesse) {
	char *c1_ptr = (char *) v1_ptr;
	char *c2_ptr = (char *) v2_ptr;
	size_t i;
	for (i = 0; i < groesse; i++) {
		c1_ptr[i] = (char) (c1_ptr[i] ^ c2_ptr[i]);
		c2_ptr[i] = (char) (c1_ptr[i] ^ c2_ptr[i]);
		c1_ptr[i] = (char) (c1_ptr[i] ^ c2_ptr[i]);
	}
}
