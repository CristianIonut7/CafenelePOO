#include "../include/Angajat.h"
#include <iostream>

using namespace std;

// Constructor pentru clasa Angajat
Angajat::Angajat(string nume, string functie, int ora_inceput, int ora_sfarsit)
    : nume(nume), functie(functie), ora_inceput(ora_inceput), ora_sfarsit(ora_sfarsit) {}

// Getter pentru numele angajatului
string Angajat::getNume() {
    return nume;
}

// Getter pentru functia angajatului
string Angajat::getFunctie() {
    return functie;
}

// Getter pentru ora de inceput a turei
int Angajat::getOraInceput() {
    return ora_inceput;
}

// Getter pentru ora de sfarsit a turei
int Angajat::getOraSfarsit() {
    return ora_sfarsit;
}
