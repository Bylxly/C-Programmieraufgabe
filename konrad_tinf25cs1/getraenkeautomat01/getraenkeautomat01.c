/**
 * Ein einfacher Getraenkeautomat.
 *
 * TINF25CS1, 14.10.2025
 */
// Standard-Header
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Prototypen =
//   = Funktionsprototypen =
//   = Funktionsdeklarationen
int auswahlGetraenkeSorte(void);
int eingabeMenge();
float ermittlePreis(int);
void bezahlen(float zuZahlen);
void ausgabeGetraenke(int, int);

// Globale Variablen
int gl_a;

/**
 * Hauptprogramm.
 */
int main(int argc, char*argv[])
{
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
	// ACHTUNG: Hier ist die entsprechende Variable
	//   vergessen worden, so dass printf() an der
	//   jenigen Stelle im Speicher zugreift, wo
	//   die Variable sein muesste, aber eben nicht
	//   ist. Daher werden irgendwelche Bytes als
	//   vermeintlicher Variablenwert verwendet und
	//   als völlig unsinnige Zahl ausgegeben!
	// printf("sorte = %d\n"); 2. Parameter sorte fehlt!
	// Hier wird auf eine nicht initialisierte lokale
	//   auto-Variable zugegriffen. Lokale auto-Variablen
	//   werden nie automatisch initialisiert, weil das
	//   einen Zeitverlust durch entsprechende Speicher-
	//   zugriffe bedeuten würde.
	//   Wenn im Debug-Modus übersetzt wird, gibt es eine
	//   Warnung, wenn im Release-Modus übersetzt wird,
	//   gibt es nicht einmal eine Warnung. Der Java-
	//   Compiler würde das Programm in keinem Falle 
	//   übersetzen, weil das stets ein grober Fehler ist!
	// printf("sorte = %d\n", sorte);
	// Hier wird ein falscher Formatierungsplatzhalter
	//   verwendet, so dass entweder völliger Unsinn
	//   ausgegeben wird oder aber das Programm abstürzt:
	// sorte = 1;
	// printf("sorte = %c\n", sorte); // z.B. %c statt %d
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
 * Rückgabewert:
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
 * Rückgabewert:
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
 * des gewählten Getränkes.
 *
 * Formale Parameter:
 *   sorte - Sorte des gewählten Getränkes
 *
 * Rückgabewert:
 *   Einzelpreis des Getränkes.
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
	//    Ausdrucks ausdrücklich in den gewünschten
	//    Zieltyp umgewandelt - mit allen
	//    denkbaren Risiken. Nur sinnvolle
	//    Umwandlungen sind mit Type-Casts möglich,
	//    also z.B. geht es nicht, einen Personendatensazz
	//    in eine Zahl zu wandeln!
	//    Auch mit expliziten Type-Casts ist es NICHT
	//    möglich, nachträglich den Datentyp einer
	//    bestimmten Variablen zu ändern.
	switch(sorte) {
		case 0:
		case 1: preis = 0.5f; break;
		case 2: preis = (float)1.0; break;
		case 3: preis = 2.0; break;
		default:
			printf("Falsche sorte = %d in ermittlePreis()!\n",
				sorte);
			exit(EXIT_FAILURE);
	}
	return preis;
} // ermittlePreis


/**
 * Bezahlvorgang nachempfinden.
 *
 * Formale Parameter:
 *   zuZahlen - Zu bezahlender Betrag.
 *
 * Rückgabewert:
 *   Keiner!
 */
void bezahlen(float zuZahlen) 
{
	float einwurf;
	printf("\n--- Bezahlvorgang ---\n");
	// Das ist die einzige annehmende oder fußgesteuerte
	//   Schleife in C (do - while). Si ehißt so, weil
	//   in jedem Falle der Schleifenkörper mindesten 1x
	//   ausgeführt wird und erst nach jedem Ausführen die
	//   Schleifenbedingung ausgewertet wird. Wenn der
	//   Wert der Schleifenbedingung ungleich 0 ist, wird
	//   der Schleifenkörper erneut abgearbeitet.
	do {
		printf("\nEs fehlen noch %.2f Euro.", zuZahlen);
		printf("\nBitte werfen Sie ein Geldstueck ein: ");
		scanf("%f", &einwurf);
		// Kompakte Notation für dyadische Operatoren, also
		//   Operatoren, die 2 Operanden haben und bei denen
		//   der linksseitige Operand das Endergebnis aufnehmen
		//   soll. ACHTUNG: Zuerst wird die rechte Seite
		//   vollständig ausgerechnet, bevor die links vom
		//   Gleichheitszeichen stehende Operation erfolgt!
		// zuZahlen = zuZahlen - einwurf;
		zuZahlen -= einwurf;
		// Beim do-while sollte das while direkt nach der
		//   schließenden } in derselben Zeile angeschrieben
		//   werden, damit man diese Schleife sofort als 
		//   solche erkennt.
	} while(zuZahlen > 0.0); // Semikolon nicht vergessen!
} // bezahlen


/**
 * Simulation der Getränkeausgabe.
 *
 * Formale Parameter:
 *   sorte - Index der Getränkesorte.
 *   menge - Anzahl der Dosen/Flaschen.
 * 
 * Rückgabewert:
 *   Keiner!
 */
void ausgabeGetraenke(int sorte, int menge) 
{
	int i, j;
	printf("\n--- Getraenkeausgabe ---\n");
	// Die for-Schleife ist wohl die häufigste Schleife
	//   in C und kann alternativ durch die while-Schleife
	//   ersetzt werden.
	// Die for-Schleife heißt auch abweisende oder kopfgesteuerte
	//   Schleife, weil vor dem Ausführen des Schleifenkörpers
	//   zuerst die Schleifenbedingung ausgewertet wird und
	//   es daher sein kann, dass diese von vornherein nicht
	//   erfüllt ist und den Schleifenkörper kein einziges Mals
	//   ausgeführt wird.
	// i= ist der sog. Initialisierungsausdruck, der einmalig
	//   vor dem Beginn der Schleife ausgewertet wird.
	// i<menge ist der Test- oder Bedingungsausdruck, der vor
	//   einem möglichen Ausführen des Schleifenlörpers aus.
	//   gewertet wird.
	// i++ ist der Inkrementierungsausdruck, der stets nach dem 
	//   Abarbeiten des Schleifenkörpers ausgeführt wird.
	// Die 3 Ausdrücke müssen durch je ein ; getrennt werden, 
	//   damit der Compiler sie sicher voneinander abgrenzen kann.
	// Manchmal möchte man in den Ausdrücken mehr als 1 Operation
	//   ausführen; dann muss man die Teilausdrücke mit ,
	//   voneinandern trennen.
	// Jeder der 3 ausdrücke kann fehlen, im Extremfall geht 
	//   also dies: for(;;); // Leere Anweisung wird dauerhaft
	//                       //   ausgeführt!!
	// Eine fehlende Schleifenbedingung bedeutet, dass die 
	//   Bedingung dauerhaft erfüllt ist.
	for(i=0, j = menge; i < menge; i++, j--)  
	{
		printf("\nFlasche %d von %d der Sorte %d wurde ausgegeben.",
			i+1, menge, sorte);
	} // for
	printf("... dieselbe Schleife als while-Schleife:\n");
	// Initialisierungsausdruck
	i=0, j = menge; 
	while(i < menge) // Nur der Testausdruck hier!!!
	{
		printf("\nFlasche %d von %d der Sorte %d wurde ausgegeben.",
			i+1, menge, sorte);
		// Inkrementierungsausdruck
		i++, j--; 
	} // for
	// Zum Inkrement bzw. Dekrement: Das ist die einzige
	//   Operation, die sich direkt auf die betreffende
	//   Variable auswirkt:
	//   i + 1; // Hat keine bleibende Wirkung
	//   i++; // i wird um 1 erhöht
	// Unterschied zwischen Präinkrement/dekrement und 
	//    Postinkrement/dekrement:
	// Wenn i als einzelne Anweisung dasteht, gibt es keinen
	//   Unterschied:
	//  i++; Postinkrement i wird um 1 erhöht
	//  ++i; Präinkrement  i wird um 1 erhöht
	// Wenn i Teil einer Formel ist, wird beim Präinkrement
	//   ++i zuerst i erhöht und dann mit dem erhöhten Wert
	//   die Gesamtformel berechnet.
	//   Wenn dagegen ein Postinkrement vorliegt (i++), wird
	//   zuerst mit dem bisherigen Wert die Gesamtformel
	//   berechnet und erst danach i erhöht.
	//   Entsprechendes gilt für das Dekrement.
	return; // Optional
} // ausgabeGetraenke
