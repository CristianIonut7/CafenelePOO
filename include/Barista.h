#ifndef BARISTA_H
#define BARISTA_H

#include "Angajat.h"

using namespace std;

// Clasa derivata Barista, mosteneste clasa de baza Angajat
class Barista : public Angajat {
private:
    double tarif_ora;      // Tarif pe ora pentru Barista
    double bonus_vanzari;  // Bonus pentru vanzari realizate

public:
    // Constructor
    Barista(string nume, int ora_inceput, int ora_sfarsit, double tarif_ora, double bonus_vanzari = 0.0);

    // Metoda pentru afisarea detaliilor specifice unui Barista
    void afisareDetalii() override;

    // Metoda pentru calcularea salariului unui Barista
    double calculSalariu() override;

    // Getter pentru tarif (tarif pe ora)
    double getTarif() override;
};

#endif