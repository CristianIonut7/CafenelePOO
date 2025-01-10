#ifndef ANGAJAT_H
#define ANGAJAT_H

#include <iostream>
#include <string>

using namespace std;

// Clasa abstracta pentru angajati
class Angajat {
protected:
    string nume;          // Numele angajatului
    string functie;       // Functia angajatului
    int ora_inceput;      // Ora de inceput a turei
    int ora_sfarsit;      // Ora de sfarsit a turei

public:
    // Constructor pentru initializarea atributelor de baza ale unui angajat
    Angajat(string nume, string functie, int ora_inceput, int ora_sfarsit);

    // Destructor virtual pentru a asigura curatarea resurselor in clasele derivate
    virtual ~Angajat() = default;

    // Metoda virtuala pura pentru afisarea detaliilor unui angajat
    virtual void afisareDetalii() = 0;

    // Metoda virtuala pura pentru calcularea salariului unui angajat
    virtual double calculSalariu() = 0;

    // Getter pentru numele angajatului
    string getNume();

    // Getter pentru functia angajatului
    string getFunctie();

    // Getter pentru ora de inceput a turei
    int getOraInceput();

    // Getter pentru ora de sfarsit a turei
    int getOraSfarsit();

    // Getter virtual pentru tarif (specific fiecarui tip de angajat)
    virtual double getTarif() = 0;
};

#endif