#include "../include/Comanda.h"
#include <iostream>
#include <string>
using namespace std;

// Adauga un produs la comanda
void Comanda::adaugaProdus(Produs* produs, int cantitate) {
    if (produs->getStoc() < cantitate) {
        cerr << "Stoc insuficient pentru produsul " << produs->getNume() << "\n";
        return;
    }
    produseComandate.emplace_back(produs, cantitate);
    produs->reduceStoc(cantitate); // Actualizam stocul produsului
}

// Calculeaza totalul comenzii
double Comanda::calculeazaTotal() {
    double total = 0.0;
    for (auto& produs : produseComandate) {
        total += produs.first->getPret() * produs.second;
    }
    return total;
}

// Afiseaza detalii despre comanda
void Comanda::afiseazaComanda() {
    cout << "\nComanda pentru clientul: " << numeClient << "\n";
    for (auto& produs : produseComandate) {
        cout << produs.first->getNume() << " x" << produs.second
             << " = " << produs.first->getPret() * produs.second << " RON\n";
    }
    cout << "Total: " << calculeazaTotal() << " RON\n";
}
