## 12.1 Grenzen Sie das Interpretieren vom Kompilieren ab!
- Interpretieren: Quelltext wird zur Laufzeit schrittweise eingelesen, analysiert und direkt ausgeführt.  
- Kompilieren: Quelltext wird vor der Ausführung vollständig in Maschinencode übersetzt.  

## 12.2 Wie oft müssen der Präprozessor, der Compiler und der Linker laufen, um ein Projekt mit 10 C-Quelldateien vollständig neu zu übersetzen?
- Präprozessor: 10× (für jede .c-Datei einmal).  
- Compiler: 10× (jede .c → eine .o).  
- Linker: 1× (aus 10 .o und Bibliotheken wird 1 Programm erzeugt).  

## 12.3 Erläutern Sie die 3 wichtigsten Aufgaben des Präprozessors!
- Einfügen von Headern mit `#include` 
- Makroersetzung mit `#define`
- Bedingte Übersetzung mit `#if`, `#ifdef`, `#ifndef`

## 12.4 Was ist eine Object-Datei?
- Ergebnis der Übersetzung einer Quelltextdatei (.c) in Maschinencode (.o, .obj).  
- Enthält Maschinencode, Symboltabellen und Relokationsinformationen, aber noch kein vollständiges Programm.  

## 12.5 Was enthält eine Bibliotheksdatei?
- Sammlung mehrerer Objektdateien in einer Datei (statisch: .a, .lib; dynamisch: .so, .dll).  
- Enthält kompilierten Code von Funktionen, der beim Linken eingebunden bzw. zur Laufzeit geladen wird.  

## 12.6 Welcher Zusammenhang besteht zwischen einer Header-Datei und einer Bibliotheksdatei?
- Header: Deklarationen (Funktionsprototypen, Typdefinitionen, Konstanten) für den Compiler.  
- Bibliothek: Implementierungen dieser deklarierten Funktionen.  

## 12.7 Welche Aufgaben erfüllen Header-Dateien, und was enthalten sie weit überwiegend?
- Stellen Schnittstellen bereit: Funktionsprototypen, Typen, Makros, Konstanten.  
- Ermöglichen dem Compiler, Aufrufe und Typen zu prüfen
- Enthalten Deklarationen

## 12.8 Was versteht man unter einem Assemblerprogramm und welche Vor- und Nachteile hat ein Assemblerprogramm gegenüber einem C-Programm?
- Assemblerprogramm: Quelltext in Assemblersprache
- Vorteile: sehr effiziente, hardwarenahe, fein optimierbare Programme; volle Kontrolle über Register und Speicher.  
- Nachteile: schwer zu lesen, zu warten und zu portieren; Entwicklung langsamer und fehleranfälliger als in C.  

## 12.9 Wie bezeichnet man das Übersetzen eines Assemblerprogrammes?
- Assemblieren

## 12.10 Welcher Zusammenhang besteht zwischen einem Assemblerprogramm und Maschinen-Code?
- Jeder Assemblerbefehl entspricht direkt einem oder wenigen Maschinenbefehlen.  
- Der Assembler übersetzt Assemblerbefehle in binären Maschinen-Code.  

## 12.11 Umreißen Sie grob die Kenntnisse, die man sich aneignen muss, um mit Assembler programmieren zu können!
- Prozessor- und Befehlssatzarchitektur 
- Speicher- und Adressierungsmodelle
- Calling Conventions, ABI, Umgang mit Interrupts und Systemaufrufen.  

## 12.12 Erklären Sie, welche Speicherbereiche es gibt, welche Eigenschaften sie haben und wozu sie jeweils verwendet werden!
- Text/Code-Segment: Enthält ausführbaren Maschinen-Code; meist schreibgeschützt.  
- Datensegment (initialisierte globale/statische Daten): Feste Adresse, während Programmlauf vorhanden.  
- BSS-Segment (uninitialisierte globale/statische Daten): Wird mit 0 vorinitialisiert.  
- Heap: Dynamisch verwalteter Bereich für Speicher aus `malloc`/`free`; wächst typischerweise nach oben.  
- Stack: Bereich für lokale Variablen, Parameter, Rücksprungadressen; wächst i.d.R. nach unten, wird automatisch verwaltet.  

## 12.13 Zählen Sie alle Variablenarten von C auf und erklären Sie ihre jeweiligen Merkmale!
 - Stack: automatisch verwalteter schneller Bereich für lokale Variablen und Funktionsaufrufe, Lebensdauer nur während des Blocks.
 - Heap: dynamischer Speicherbereich für malloc/free, flexibel, Lebensdauer bis zur Freigabe.
 - .data: statischer Bereich für initialisierte globale/static-Variablen, Lebensdauer gesamte Programmlaufzeit.
 - .bss: statischer Bereich für nicht initialisierte globale/static-Variablen (automatisch 0), Lebensdauer gesamte Programmlaufzeit.
 - Text/Code-Segment: schreibgeschützter Bereich für ausführbaren Programmcode.
 - Konstantenbereich: schreibgeschützter Bereich für String-Literale und konstante Daten.

## 12.14 Erklären Sie, welche Funktionen C für das Verwalten des Heaps bereitstellt und wie diese genutzt werden!
- `malloc(size)`: reserviert size Bytes, liefert `void*`-Zeiger oder `NULL` bei Fehler; Inhalt nicht initialisiert.  
- `calloc(n, size)`: reserviert `n * size` Bytes, Inhalt wird auf 0 gesetzt.  
- `realloc(ptr, newsize)`: ändert Größe eines bereits allokierten Bereichs, kann verschieben und neuen Zeiger liefern.  
- `free(ptr)`: gibt zuvor allokierten Speicher zurück; danach Zeiger ungültig.  
- Nutzung: Zeiger prüfen, zugehörige `free`-Aufrufe sicherstellen.  

## 12.15 Was versteht man unter einer Speicherleiche?
- Nicht mehr erreichbarer, aber nicht freigegebener Speicher auf dem Heap.  

## 12.16 Was versteht man unter der Fragmentierung des Heap-Speichers?
- Viele kleine freie Lücken zwischen belegten Blöcken, große zusammenhängende Blöcke nicht mehr verfügbar.  

## 12.17 Welche Arten von erweiterten Datentypen sieht C vor, und welche wichtigen Aussagen lassen sich über diese festhalten?
- Arrays: Feste Anzahl gleichartiger Elemente
- struct: Gruppieren unterschiedliche Datentypen; Elemente in festgelegter Reihenfolge im Speicher
- union: Alle Mitglieder teilen sich denselben Speicher; Größe = Größe des größten Members; nur ein sinnvoller Member gleichzeitig verwendbar.  
- enum: Symbolische Namen für ganzzahlige Konstanten; basieren auf Integer  

## 12.18 Was versteht man unter dem Alignment bei strukturierten Datentypen und wie kann man die negativen Auswirkungen ohne großen Aufwand minimieren?
- Alignment: Datentypen müssen an Adressen liegen, die ein Vielfaches ihrer Ausrichtung sind (z.B. 4-Byte-Grenze für `int`).  
- Compiler fügt ggf. Padding zwischen Struct-Feldern und am Ende der Struct ein, um Ausrichtungsanforderungen zu erfüllen.  
- Minimierung: Felder im Struct nach fallender Größe anordnen, um Padding zu reduzieren.

## 12.19 Erklären Sie, wie die Elemente mehrdimensionaler Felder im Hauptspeicher angeordnet werden und welche Werte daher bekannt sein müssen, um auf ein bestimmtes Element eines dreidimensionalen Feldes zugreifen zu können!
- Im Hauptspeicher werden mehrdimensionale Felder als 1D Array angelegt. 
- Beispiel 3D: `T a[X][Y][Z]`; zuerst alle Z-Elemente von `a[0][0]`, dann `a[0][1]`, …, dann `a[1][0]` usw.  
- Für den Zugriff auf `a[i][j][k]` müssen `X`, `Y`, `Z` (Dimensionen), Elementgröße `sizeof(T)` und die Indizes `i`, `j`, `k` bekannt sein.  

## 12.20 Umreißen Sie den Trick, um auch bei mehrdimensionalen Feldern die mathematisch orientierte Schreibweise mit eckigen Klammern anwenden zu können!
- Man legt ein 3D-Zeigerfeld an, und initialisiert dieses so, dass man die mehr dimensionale Felder, als Array in Arrays aufrufen kann `a[i][j][k]`
- ansonsten `a[i*Y*Z + j*Z + k]`

## 12.21 Welche Arbeitsteilung zwischen Anwendungs- und Bibliotheksentwickler kommt beim Programmieren und Aufrufen von Bibliotheksfunktionen zum Einsatz?
- Bibliotheksentwickler: Implementiert Funktionen, erstellt Objekt-/Bibliotheksdateien und passende Header  
- Anwendungsentwickler: Inkludiert Header, linkt Bibliothek, nutzt Funktionen über die dokumentierte Schnittstelle.  

## 12.22 Welcher grundsätzlichen Vorgehensweise folgt man, wenn man eine Bibliotheksfunktion entwickeln möchte?
- Schnittstelle entwerfen: Funktionsnamen, Parameter, Rückgabewert festlegen und im Header deklarieren.  
- Funktion in einer oder mehreren .c-Dateien implementieren und zu Objektdateien kompilieren.  
- Aus Objektdateien Bibliothek bauen (statisch oder dynamisch) und Header bereitstellen.