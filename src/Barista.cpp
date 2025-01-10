#include "../include/Barista.h"
#include <iostream>

using namespace std;

// Constructor pentru clasa Barista
Barista::Barista(string nume, int ora_inceput, int ora_sfarsit, double tarif_ora, double bonus_vanzari)
    : Angajat(nume, "Barista", ora_inceput, ora_sfarsit), tarif_ora(tarif_ora), bonus_vanzari(bonus_vanzari) {}

// Metoda pentru afisarea detaliilor Barista
void Barista::afisareDetalii()
{
    cout << "Barista: " << nume << " | Ore: " << ora_inceput << "-" << ora_sfarsit << "\n";
}

// Metoda pentru calculul salariului Barista
double Barista::calculSalariu()
{
    return abs(ora_sfarsit - ora_inceput) * tarif_ora;
}

// Getter pentru tariful orar al Barista
double Barista::getTarif()
{
    return tarif_ora;
}
