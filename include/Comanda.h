#ifndef COMANDA_H
#define COMANDA_H

#include "Produs.h"
#include <string>
#include <vector>
#include <utility>
#include <iostream>

class Comanda
{
private:
    string numeClient;                            // Numele clientului care a plasat comanda
    vector<pair<Produs *, int>> produseComandate; // Lista de produse comandate si cantitatile corespunzatoare

public:
    // Constructor pentru initializarea unei comenzi cu numele clientului
    explicit Comanda(string numeClient) : numeClient(numeClient) {}

    // Getter pentru numele clientului
    string getNumeClient()
    {
        return numeClient;
    }

    // Getter pentru lista de produse comandate
    vector<pair<Produs *, int>> getProduseComandate()
    {
        return produseComandate;
    }

    // Adauga un produs in lista de produse comandate
    void adaugaProdus(Produs *produs, int cantitate);

    // Calculeaza totalul valorii comenzii
    double calculeazaTotal();

    // Afiseaza detaliile comenzii
    void afiseazaComanda();
};

#endif