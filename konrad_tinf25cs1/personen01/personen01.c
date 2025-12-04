/**
 * Programm für Personendaten und verkettete 
 * Listen.
 *
 * TINF25CS1, 13.11.2025
 */
// Standard-Header
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Eigene Header-Dateien 
#include "datentypen.h"

// Prototypen
struct listen_typ* liste_neues_element();

/**
 * Hauptprogramm.
 */
int main(int argc, char*argv[])
{
	struct listen_typ *anfang_ptr = NULL;
	struct listen_typ *ende_ptr = NULL;
	struct listen_typ *neu_ptr;

	printf("Personen und verkettete Listen\n");
	neu_ptr = liste_neues_element();
	liste_einfuegen(
	return EXIT_SUCCESS;
} // main

struct listen_typ* liste_neues_element()
{
	struct listen_typ *neu_ptr;
	neu_ptr = (struct listen_typ *)calloc(
		1, sizeof(*neu_ptr));
	assert(neu_ptr);
	return neu_ptr;
} // liste_neues_element

void liste_einfuegen(
	struct listen_typ **anfang_2ptr, 
	struct listen_typ **ende_2ptr, 
	struct listen_typ *neu_ptr, 
	struct listen_typ *einfuege_ptr)
{

}