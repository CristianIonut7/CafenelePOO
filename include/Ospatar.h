#ifndef OSPATAR_H
#define OSPATAR_H

#include "Angajat.h"

using namespace std;

// Clasa Ospatar, derivata din clasa Angajat
class Ospatar : public Angajat {
private:
    double tarif_ora; // Tarif pe ora pentru ospatar
    double bacsis;    // Bacsis acumulat de ospatar

public:
    // Constructor pentru initializarea unui ospatar
    Ospatar(string nume, int ora_inceput, int ora_sfarsit, double tarif_ora, double bacsis = 0.0);

    // Metoda pentru afisarea detaliilor despre ospatar
    void afisareDetalii() override;

    // Metoda pentru calcularea salariului ospatarului
    double calculSalariu() override;

    // Metoda pentru obtinerea tarifului pe ora al ospatarului
    double getTarif() override;
};

#endif
