/**
 * Dieses Programm demonstriert Zeigervariablen
 * und mehrfach indirekte Zeiger.
 *
 * TINF25CS1, 22.10.2025
 */
// Standard-Header
#include <stdio.h>
#include <stdlib.h>


/**
 * Hauptprogramm.
 */
int main(int argc, char*argv[])
{
	int i;
	int a = 3, b = 8;
	int *a_ptr, *b_ptr;
	int **a_2ptr, **b_2ptr;
	int ***a_3ptr, ***b_3ptr;
	void *v1_ptr;
	int ****a_4ptr, ****b_4ptr;
	int *****a_5ptr, *****b_5ptr;
	double x1 = 1.1, *x1_ptr = &x1;
	unsigned char *uc1_ptr;
	printf("Zeigervariablen und mehrfache Indirektheiten:\n");
	a_ptr = &a;
	b_ptr = &b;
	printf("a = %d; b = %d\n", a, b);
	printf("&a = %p; a_ptr = %p; &b = %p; b_ptr = %p\n",
		&a, a_ptr, &b, b_ptr);
	printf(" &a_ptr = %p;  &b_ptr = %p\n", &a_ptr, &b_ptr);
	// Das geht nicht! Man muss sich &a vorstellen - das ist
	//   eine Adresse, also ein Zahlenwert und kein Objekt
	//   im Hauptspeicher. Somit gibt es keine Adresse, die
	//   man abfragen könnte. Infolgedessen ist es unsinnig,
	//   &&a zu schreiben und eine Adresse zu erwarten!
	// a_5ptr = &&&&&a; FALSCH!!!
	a_2ptr = &a_ptr;
	b_2ptr = &b_ptr;
	printf(" a_2ptr = %p;  b_2ptr = %p\n", a_2ptr, b_2ptr);
	printf("&a_2ptr = %p; &b_2ptr = %p\n", &a_2ptr, &b_2ptr);
	a_3ptr = &a_2ptr;
	b_3ptr = &b_2ptr;
	printf(" a_3ptr = %p;  b_3ptr = %p\n", a_3ptr, b_3ptr);
	printf("&a_3ptr = %p; &b_3ptr = %p\n", &a_3ptr, &b_3ptr);
	a_4ptr = &a_3ptr;
	b_4ptr = &b_3ptr;
	printf(" a_4ptr = %p;  b_4ptr = %p\n", a_4ptr, b_4ptr);
	printf("&a_4ptr = %p; &b_4ptr = %p\n", &a_4ptr, &b_4ptr);
	a_5ptr = &a_4ptr;
	b_5ptr = &b_4ptr;
	printf(" a_5ptr = %p;  b_5ptr = %p\n", a_5ptr, b_5ptr);
	printf("&a_5ptr = %p; &b_5ptr = %p\n", &a_5ptr, &b_5ptr);
	// Derferenzieren bedeutet, von einer Zeigervariablen
	//   auszugehen und auf die in ihr enthaltene Speicheradresse
	//   tatsächlich lesen oder schreibend zuzugreifen.
	printf("a = %d; *a_ptr = %d\n", a, *a_ptr);
	printf("*a_4ptr = %p; *a_2ptr = %p\n", *a_4ptr, *a_2ptr);
	printf("*****a_5ptr = %d; ***a_4ptr = %p\n", *****a_5ptr, ***a_4ptr);
	// void-Zeiger
	// Jede typgebundene Zeigervariable kann an einen void-Zeiger
	//   zugewiesen werden; die Typinformation wird einfach abgestreift
	v1_ptr = a_ptr;
	// Sämtliche Varianten eines Zugriffs scheitern bei einem void-Zeiger,
	//    weil die Anzahl (und Formatierung) des Zieles unbekannt sind
	// *v1_ptr; FALSCH, Dereferenzieren prinzipiell unmöglich!
	// *v1_ptr = 5; FALSCH
	// b = *v1_ptr; FALSCH
	// a_ptr = v1_ptr; Hier ist (streng genommen) ein expliziter
	//                  Type-Cast nötig
	a_ptr = (int*)v1_ptr; // RICHTIG!!!
	printf("a = %d; *(int*)v1_ptr = %d\n", a, *(int*)v1_ptr);
	// Zeiger ändern
	// Beim Addieren oder Subtrahieren von 1 bzw. einem Offset-Wert
	//   wird bei typgebundenen Zeigern der Offset mit der Größe
	//   des Zieltyps multipliziert
	a_ptr++;
	printf("v1_ptr = %p; a_ptr = %p\n", v1_ptr, a_ptr);
	printf("x1_ptr = %p; x1 = %.2lf\n", x1_ptr, x1);
	x1_ptr += 8; // Auch Subtraktion möglich
	printf("x1_ptr = %p\n", x1_ptr);
	// Bei void-Zeigern ist dagegen ein Addieren/Subtrahieren eines
	//   Offsets nicht möglich, denn da der Zieltyp nicht bekannt
	//   ist, ist die Zieltypgröße ebenfalls nicht bekannt, und 
	//   somit weiß der Compiler nicht, womit er multiplizieren
	//   müsste. Daher gibt es einen Übersetzungsfehler.
	// v1_ptr++;
	a_ptr = &a; // Wieder den ursprünglichen Wert verwenden
	uc1_ptr = (unsigned char*)a_ptr;
	for(i = 0; i < sizeof(*a_ptr); i++)
		printf("*uc1_ptr = 0x%02X\n", *uc1_ptr++);
	return EXIT_SUCCESS;
} // main
