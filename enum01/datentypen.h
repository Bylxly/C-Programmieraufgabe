/**
 * Diese Datei enthaelt die moduluebergreifenden
 * Datentypdefinitionen und wird von den C-Dateien
 * ebenso wie von den eigenen Header-Dateien zu Anfang
 * mit #include "datentypen.h" inkludiert.
 */
/**
 * Datentyp fuer Wochentage
 */
#pragma once
enum wochentage_typ {
	Montag = 0, Dienstag, Mittwoch, Donnerstag, Freitag,
	Samstag, Sonnabend = Samstag, Sonntag,
	Monday = Montag, Tuesday, Wednesday, Thursday, Friday,
	Saturday, Sunday
};

enum sprache_typ {
	deutsch, englisch
};