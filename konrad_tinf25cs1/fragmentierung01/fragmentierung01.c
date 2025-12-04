/**
 * Hauptspeicherfragmentierung.
 *
 * TINF25CS1, 06.11.2025
 */ 
// System-Header
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// Datentypendefinitionen
struct block_listen_typ {
	// Verkettungszeiger zum naechsten Listenelement
	struct block_listen_typ *next_ptr;
	// Zeiger auf den zugehoerigen Heap-Speicherblock
	void *block_vptr;
};

/**
 * Hauptprogramm
 */
int main(int argc, char*argv[])
{
	size_t blockgroesse = 100*1000*1000;
	size_t n_bloecke_belegt = 0;
	void *block_anf_ptr;
	struct block_listen_typ *neu_ptr;
	struct block_listen_typ *anfang_ptr = NULL;
	struct block_listen_typ *lauf_ptr;
	void*hilfs_ptr;
	size_t blockgroesse2;

	printf("Speicherfragmentierung testen:\n");
	while(1)
	{
		block_anf_ptr = malloc(blockgroesse);
		if(block_anf_ptr == NULL)
			break;
		n_bloecke_belegt++;
		neu_ptr = (struct block_listen_typ*)
			calloc(1, sizeof(struct block_listen_typ));
		assert(neu_ptr != NULL);
		printf("Listenelement belegt bei %p\n", neu_ptr);
		neu_ptr->block_vptr = block_anf_ptr;
		neu_ptr->next_ptr = NULL;
		if(anfang_ptr == NULL)
			anfang_ptr = neu_ptr;
		else
		{
			neu_ptr->next_ptr = anfang_ptr;
			anfang_ptr = neu_ptr;
		}
		if(n_bloecke_belegt >1)
			printf("Block belegt bei %p; delta = %u\n", block_anf_ptr, 
				(unsigned char*)block_anf_ptr - 
				(unsigned char*)anfang_ptr->next_ptr->block_vptr);
		else
			printf("Block belegt bei %p\n", block_anf_ptr);
		}
	printf("n_bloecke_belegt = %u\n", n_bloecke_belegt);

	printf("Liste durchlaufen und Speicherbloecke verkleinern:\n");
	lauf_ptr = anfang_ptr;
	while(lauf_ptr)
	{
		hilfs_ptr = realloc(lauf_ptr->block_vptr, 1);
		if(hilfs_ptr != lauf_ptr->block_vptr)
		{
			printf("Block wurde verlagert!\n");
			lauf_ptr->block_vptr = hilfs_ptr;
		}
		lauf_ptr = lauf_ptr->next_ptr;
	}
	
	printf("Freigeben des Speicherblockes an Adresse %p\n",
		anfang_ptr->next_ptr->next_ptr->next_ptr->block_vptr);
	free(anfang_ptr->next_ptr->next_ptr->next_ptr->block_vptr);

	blockgroesse2 = 1.5*blockgroesse;
	printf("Testweise einen Speicherblock in Groesse von %u belegen:\n",
		blockgroesse2);
	hilfs_ptr = malloc(blockgroesse2);
	if(hilfs_ptr == NULL)
		printf(" .... :-( Schade, das Belegen ist misslungen!\n");
	else
		printf("Cool! Speicher wurde reserviert! Adresse = %p\n",
			hilfs_ptr);

	return EXIT_SUCCESS;
} // main
