#include "../include/Manager.h"
#include <iostream>

using namespace std;

// Constructor pentru clasa Manager
Manager::Manager(string nume, int ora_inceput, int ora_sfarsit, double salariu_fix, double bonus_evenimente)
    : Angajat(nume, "Manager", ora_inceput, ora_sfarsit), salariu_fix(salariu_fix), bonus_evenimente(bonus_evenimente) {}

// Funcție pentru afișarea detaliilor despre manager
void Manager::afisareDetalii() {
    cout << "Manager: " << nume << " | Program: " << ora_inceput << "-" << ora_sfarsit << "\n";
}

// Funcție pentru calculul salariului managerului
double Manager::calculSalariu() {
    return salariu_fix;
}

// Funcție pentru a obține salariul fix al managerului
double Manager::getTarif() {
    return salariu_fix;
}
