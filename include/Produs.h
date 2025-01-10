#ifndef PRODUS_H
#define PRODUS_H

#include <string>
#include <iostream>
using namespace std;

// Clasa Produs pentru reprezentarea unui produs in cafenea
class Produs
{
private:
    string nume;   // Numele produsului
    double pret;   // Pretul produsului
    int stoc;      // Stocul disponibil pentru produs

public:
    // Constructor pentru initializarea unui produs
    Produs(string nume, double pret, int stoc)
        : nume(nume), pret(pret), stoc(stoc) {}

    // Metoda pentru obtinerea numelui produsului
    string getNume()
    {
        return nume;
    }

    // Metoda pentru obtinerea pretului produsului
    double getPret()
    {
        return pret;
    }

    // Metoda pentru obtinerea stocului produsului
    int getStoc()
    {
        return stoc;
    }

    // Metoda pentru reducerea stocului produsului
    void reduceStoc(int cantitate)
    {
        stoc -= cantitate;
    }

    // Metoda pentru cresterea stocului produsului
    void cresteStoc(int cantitate)
    {
        stoc += cantitate;
    }

    // Metoda pentru afisarea detaliilor despre produs
    void afiseazaProdus()
    {
        cout << nume << " - Pret: " << pret << " RON, Stoc: " << stoc << '\n';
    }
};

#endif
