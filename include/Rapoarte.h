#ifndef RAPOARTE_H
#define RAPOARTE_H

#include <vector>
#include "Comanda.h"
#include "Eveniment.h"
#include "Angajat.h"

using namespace std;

// Clasa Rapoarte pentru generarea de rapoarte financiare
class Rapoarte {
public:
    // Calculeaza veniturile totale din comenzile pentru un oras specificat
    static double calculeazaVenituri(string oras);

    // Calculeaza cheltuielile totale, incluzand costurile evenimentelor si salariile angajatilor
    static double calculeazaCheltuieli(vector<Eveniment> evenimente, vector<Angajat*> angajati);
};

#endif
