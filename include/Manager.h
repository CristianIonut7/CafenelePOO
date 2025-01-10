#ifndef MANAGER_H
#define MANAGER_H

#include "Angajat.h"

using namespace std;

class Manager : public Angajat {
private:
    double salariu_fix;         // Salariul fix al managerului
    double bonus_evenimente;    // Bonus pentru organizarea evenimentelor

public:
    // Constructor pentru initializarea unui manager
    Manager(string nume, int ora_inceput, int ora_sfarsit, double salariu_fix, double bonus_evenimente = 0.0);

    // Afiseaza detalii despre manager
    void afisareDetalii() override;

    // Calculeaza salariul managerului, incluzand eventualele bonusuri
    double calculSalariu() override;

    // Returneaza salariul fix al managerului (folosit ca tarif pentru mostenire)
    double getTarif() override;
};

#endif
