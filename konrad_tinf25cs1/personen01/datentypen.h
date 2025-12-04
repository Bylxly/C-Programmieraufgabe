#pragma once

#define KUERZEL_LEN 5

struct namens_typ {
	char *vorname_ptr;
	char *nachname_ptr;
	char kuerzel[KUERZEL_LEN];
};

struct personen_typ {
	int personen_id;
	double gehalt;
	struct namens_typ name;
};

struct listen_typ {
	struct listen_typ *next_ptr;
	struct listen_typ *back_ptr;
	void*daten_vptr;
};