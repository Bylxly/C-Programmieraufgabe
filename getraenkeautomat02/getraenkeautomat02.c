/**
 * Ein einfacher Getraenkeautomat.
 *
 * TINF25CS1, 14.10.2025
 */
// Standard-Header
#define _CRT_SECURE_NO_WARNINGS
#define EXIT_TYP_FALSCH 3
#include <stdio.h>
#include <stdlib.h>

// Eigene Header-Dateien
#include "ausgaben.h"

// Prototypen =
//   = Funktionsprototypen =
//   = Funktionsdeklarationen
int auswahlGetraenkeSorte(void);
int eingabeMenge();
float ermittlePreis(int);
void bezahlen(float zuZahlen);

// 8.9
void tschuess(void);


// Globale Variablen
int gl_a;

/**
 * Hauptprogramm.
 */
int main(int argc, char*argv[])
{
	atexit(tschuess);
	// Lokale auto Variablen
	int sorte, menge;
	float preis, zuZahlen;
	{
		int lokales_i = 2, lokales_k = lokales_i;
		printf("argc = %d\n", argc);
		// int i; Geht erst an dieser Stelle in neueren
		//   C-Versionen!
		{
			lokales_i;
		}
		lokales_i;
		preis;
	}
	// lokales_i;
	printf("gl_a = %d\n", gl_a);
	sorte = auswahlGetraenkeSorte();
	if(0) printf("sorte = %d\n", sorte);
	preis = ermittlePreis(sorte);
	printf("preis = %d\n", preis);
	menge = eingabeMenge();
	zuZahlen = preis * menge;
	bezahlen(zuZahlen);
	ausgabeGetraenke(sorte, menge);
	printf("\n\nVielen Dank, bitte entnehmen Sie Ihre Getraenke.\n");

	return EXIT_SUCCESS;
} // main


/**
 * Interaktive auswahl des geunschten Getraenkes.
 *
 * Formale Parameter:
 *   KEINE! [() bedeutet eigentlich nur "keine Festlegung",
 *           (void) bedeutet in C KEINE PARAMETER!
 *           (void) ergibt in Java Compiler-Fehler.
 *           () bedeutet in Java "KEINE PARAMETER"
 *
 * R�ckgabewert:
 *   Getraenkesorte als Zahl 1..3.
 */
int auswahlGetraenkeSorte(void)
{
	int sorte;
	printf("Waehlen Sie ihr Getraenk aus:\n");
	printf("1) Wasser (0,50 Euro)\n");
	printf("2) Limonade (1,00 Euro)\n");
	printf("3) Bier (2,00 Euro)\n\n");
	printf("Geben Sie 1, 2 oder 3 ein: ");
	scanf("%d", &sorte);
	return sorte;
} // auswahlGetraenkeSorte


/**
 * Eingabe der Anzahl von Dosen/Flaschen.
 *
 * Formale Parameter:
 *   Keine!
 *
 * R�ckgabewert:
 *  Anzahl der Dosen.
 */
int eingabeMenge(void)
{
	int menge=1;
	printf("\nGeben Sie die gewuenschte Menge ein: ");
	scanf("%d", &menge);
	return menge;
} // eingabeMenge


/**
 * Nachschlagen des Einzelpreises
 * des gew�hlten Getr�nkes.
 *
 * Formale Parameter:
 *   sorte - Sorte des gew�hlten Getr�nkes
 *
 * R�ckgabewert:
 *   Einzelpreis des Getr�nkes.
 */
float ermittlePreis(int sorte) {
	// 0 ist int; int wird hier automatisch
	//  in float umgeweandelt; man spricht von
	//  einem impliziten Type-Cast (einer
	//  automatischen Typumwandlung)
	float preis = 0;
	// preis = 0.0f; Hier wird die Null gleich
	//      als float-Konstante mit 4 Bytes
	//      dargestellt.
	// preis = (float)0.0; Hier spricht man von
	//    einem expliziten Type-Cast. Damit
	//    wird der Datentyp des rechtsseitigen
	//    Ausdrucks ausdr�cklich in den gew�nschten
	//    Zieltyp umgewandelt - mit allen
	//    denkbaren Risiken. Nur sinnvolle
	//    Umwandlungen sind mit Type-Casts m�glich,
	//    also z.B. geht es nicht, einen Personendatensazz
	//    in eine Zahl zu wandeln!
	//    Auch mit expliziten Type-Casts ist es NICHT
	//    m�glich, nachtr�glich den Datentyp einer
	//    bestimmten Variablen zu �ndern.
	switch(sorte) {
		case 0:
		case 1: preis = 0.5f; break;
		case 2: preis = (float)1.0; break;
		case 3: preis = 2.0; break;
		default:
			printf("Falsche sorte = %d in ermittlePreis()!\n",
				sorte);
			exit(EXIT_TYP_FALSCH);
	}
	return preis;
} // ermittlePreis


/**
 * Bezahlvorgang nachempfinden.
 *
 * Formale Parameter:
 *   zuZahlen - Zu bezahlender Betrag.
 *
 * R�ckgabewert:
 *   Keiner!
 */
void bezahlen(float zuZahlen)
{
	float einwurf;
	printf("\n--- Bezahlvorgang ---\n");
	// Das ist die einzige annehmende oder fu�gesteuerte
	//   Schleife in C (do - while). Si ehi�t so, weil
	//   in jedem Falle der Schleifenkörper mindesten 1x
	//   ausgeführt wird und erst nach jedem Ausf�hren die
	//   Schleifenbedingung ausgewertet wird. Wenn der
	//   Wert der Schleifenbedingung ungleich 0 ist, wird
	//   der Schleifenk�rper erneut abgearbeitet.
	do {
		printf("\nEs fehlen noch %.2f Euro.", zuZahlen);
		printf("\nBitte werfen Sie ein Geldstueck ein: ");
		scanf("%f", &einwurf);
		// Kompakte Notation f�r dyadische Operatoren, also
		//   Operatoren, die 2 Operanden haben und bei denen
		//   der linksseitige Operand das Endergebnis aufnehmen
		//   soll. ACHTUNG: Zuerst wird die rechte Seite
		//   vollst�ndig ausgerechnet, bevor die links vom
		//   Gleichheitszeichen stehende Operation erfolgt!
		// zuZahlen = zuZahlen - einwurf;
		zuZahlen -= einwurf;
		// Beim do-while sollte das while direkt nach der
		//   schlie�enden } in derselben Zeile angeschrieben
		//   werden, damit man diese Schleife sofort als
		//   solche erkennt.
	} while(zuZahlen > 0.0); // Semikolon nicht vergessen!
} // bezahlen


void tschuess(void) {
	printf("Tschuess!");
}
