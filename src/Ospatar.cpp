#include "../include/Ospatar.h"
#include <iostream>

using namespace std;

// Constructor pentru initializarea unui ospatar
Ospatar::Ospatar(string nume, int ora_inceput, int ora_sfarsit, double tarif_ora, double bacsis)
    : Angajat(nume, "Ospatar", ora_inceput, ora_sfarsit), tarif_ora(tarif_ora), bacsis(bacsis) {}

// Metoda pentru afisarea detaliilor despre ospatar
void Ospatar::afisareDetalii() {
    cout << "Ospatar: " << nume << " | Tura: " << ora_inceput << "-" << ora_sfarsit << "\n";
}

// Metoda pentru calcularea salariului ospatarului
double Ospatar::calculSalariu() {
    return abs(ora_sfarsit - ora_inceput) * tarif_ora;
}

// Metoda pentru obtinerea tarifului pe ora al ospatarului
double Ospatar::getTarif() {
    return tarif_ora;
}
