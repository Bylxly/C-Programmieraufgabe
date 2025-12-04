/**
 * Ein Programm, das Variablen und
 * Adressen zum Thema hat.
 *
 * TINF25CS1, 20.10.2025
 */
// Standard-Header
#include <stdio.h>
#include <stdlib.h>

// Eigene Prototypen
int summieren(int a, int b);

// Globale Variablen
int gl_a, gl_b;
double gl_x1 = 4.5, gl_x2 = 7.1;

/**
 * Hauptprogramm.
 */
int main(int argc, char*argv[])
{
	// Lokale static Variablen
	static int lst_a, lst_b;
	static double lst_x1 = 4.5, lst_x2 = 7.1;
	// Lokale auto Variablen
	int a, b;
	int i;
	double x1 = -3.5, x2 = 0.1;

	printf("Variablen und Adressen:\n");

	printf("Globale Variablen:\n");
	printf("gl_a = %d; gl_b = %d\n", gl_a, gl_b);
	printf("&gl_a = %p; &gl_b = %p\n", &gl_a, &gl_b);
	printf("gl_x1 = %lf; gl_x2 = %lf\n", gl_x1, gl_x2);
	printf("&gl_x1 = %p; &gl_x2 = %p\n", &gl_x1, &gl_x2);
	printf("Lokale static Variablen:\n");
	printf("lst_a = %d; lst_b = %d\n", lst_a, lst_b);
	printf("&lst_a = %p; &lst_b = %p\n", &lst_a, &lst_b);
	printf("lst_x1 = %lf; lst_x2 = %lf\n", lst_x1, lst_x2);
	printf("&lst_x1 = %p; &lst_x2 = %p\n", &lst_x1, &lst_x2);
	printf("Lokale auto Variablen:\n");
	// a und b sind als lokale auto-Variablen nicht automatisch
	//   initialisiert worden, so dass die nächste Anweisung
	//   unsinnige Werte ausgibt.
	// ACHTUNG: 
	//   Im Debug-Modus wird zumindest eine Warnung ausgegeben;
	//     --> daher auch ALLE Warnungen immer beheben nach 
	//         jedem erneuten Übersetzen!
	//   Im Release-Modus gibt es KEINE (!!!) Warnung!!
	//   Der Java-Compiler würde einen Übersetzungsfehler
	//     ausgeben und keinen übersetzten Code erzeugen.
	//     --> Beim Java hat man aus den Problemen des C gelernt!
	// printf("a = %d; b = %d\n", a, b);
	printf("&a = %p; &b = %p\n", &a, &b);
	printf("x1 = %lf; x2 = %lf\n", x1, x2);
	printf("&x1 = %p; &x2 = %p\n", &x1, &x2);
	printf("Die Kommandozeilenparameter:\n");
	printf("argc = %d; &argc = %p\n", argc, &argc);
	printf("argv = %p; &argv = %p\n", argv, &argv);
	printf("argv[0] = %p; argv[0] = %s\n", argv[0], argv[0]);
	for(i = 1; i < argc; i++)
	{
		printf("argv[i=%d] = %p; argv[i=%d] = %s\n", i, argv[i], i, argv[i]);
		printf("&argv[i=%d] = %p; argv+i = %p\n", i, &argv[i], argv+i);
	}
	printf("argv[argc] = %p\n", argv[argc]);

	printf("Einsprungadressen der Funktionen:\n");
	printf("Anfangadresse von main() = %p\n", main);
	printf("Anfangadresse von summieren() = %p\n", summieren);
	printf("Anfangadresse von printf() = %p\n", printf);
	printf("Anfangadresse von fprintf() = %p\n", fprintf);

	{
		int summe = summieren(3, 8);
		printf("summe = %d; &summe = %p\n", summe, &summe);
	}

	printf("Ohne argc geht's auch:\n");
	printf("for...\n");
	for(i = 0; argv[i] != NULL; i++)
		printf("argv[i=%d] = %s\n", i, argv[i]);
	printf("while...\n");
	i = -1; 
	while(argv[++i] != NULL)
		printf("argv[i=%d] = %s\n", i, argv[i]);
	printf("do-while...\n");
	i = 0; 
	do
	{
		printf("argv[i=%d] = %s\n", i, argv[i]);
	} while(argv[++i] != NULL);

	return EXIT_SUCCESS;
} // main


/**
 * 2 Ganzzahlen addieren.
 *
 * Formale Parameter:
 *   a - 1. Summand.
 *   b - 2. Summand.
 *
 * Rückgabewert:
 *   Summe von a und b.
 */
int summieren(int a, int b)
{
	int ergebnis;
	ergebnis = a + b;
	printf("summieren(): a = %d; &a = %p\n", a, &a);
	printf("summieren(): b = %d; &b = %p\n", b, &b);
	printf("summieren(): ergebnis = %d; &ergebnis = %p\n", ergebnis, &ergebnis);
	return ergebnis;
} // summieren

