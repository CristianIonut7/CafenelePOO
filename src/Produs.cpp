#include "../include/Produs.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

// Constructor pentru clasa Produs
Produs::Produs(string nume, double pret, int stoc) : nume(nume), pret(pret), stoc(stoc) {}

// Funcție pentru a obține numele produsului
string Produs::getNume() {
    return nume;
}

// Funcție pentru a obține prețul produsului
double Produs::getPret() {
    return pret;
}

// Funcție pentru a obține stocul produsului
int Produs::getStoc() {
    return stoc;
}
