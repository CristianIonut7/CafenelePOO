#ifndef CAFENEA_H
#define CAFENEA_H

#include "Angajat.h"
#include "Produs.h"
#include "Eveniment.h"
#include "Comanda.h"
#include <vector>
#include <string>

using namespace std;

// Clasa care gestioneaza operatiunile unei cafenele
class Cafenea {
private:
    string oras; // Orasul in care se afla cafeneaua
    vector<Produs> produseDisponibile; // Lista cu produsele disponibile in cafenea
    vector<Angajat*> angajati; // Lista cu angajatii cafenelei
    vector<Produs> produse; // Lista cu toate produsele
    vector<Eveniment> evenimente; // Lista cu evenimentele organizate de cafenea
    vector<Comanda> comenzi; // Lista cu comenzile clientilor

public:
    // Constructor pentru initializarea unei cafenele
    Cafenea(string oras);

    // Destructor pentru eliberarea memoriei
    ~Cafenea();
    
    // Getter pentru orasul cafenelei
    string getOras();

    // Afiseaza lista angajatilor cafenelei
    void afiseazaAngajati();

    // Afiseaza lista produselor disponibile
    void afiseazaProduse();   

    // Afiseaza lista comenzilor plasate
    void afiseazaComenzi();

    // Afiseaza lista evenimentelor organizate
    void afiseazaEvenimente();
    
    // Adauga un angajat in fisierul CSV
    void adaugaAngajatInFisier(Angajat* angajat);

    // Adauga un produs in fisierul CSV
    void adaugaProdusInFisier(Produs produs);

    // Adauga o comanda in fisierul CSV
    void adaugaComandaInFisier(Comanda comanda);

    // Adauga un eveniment in fisierul CSV
    void adaugaEvenimentInFisier(Eveniment eveniment);

    // Elimina un angajat din fisierul CSV pe baza numelui
    void eliminaAngajatDinFisier(string numeAngajat);

    // Elimina un produs din fisierul CSV pe baza numelui
    void eliminaProdusDinFisier(string numeProdus);

    // Elimina o comanda din fisierul CSV pe baza numelui clientului
    void eliminaComandaDinFisier(string numeClient);

    // Elimina un eveniment din fisierul CSV pe baza numelui evenimentului
    void eliminaEvenimentDinFisier(string numeEveniment);

    // Modifica atributul unui angajat in fisierul CSV
    void modificaAngajatInFisier(string nume, string atribut, string nouaValoare);

    // Modifica atributul unui produs in fisierul CSV
    void modificaProdusInFisier(string nume, string atribut, string nouaValoare);

    // Modifica atributul unui eveniment in fisierul CSV
    void modificaEvenimentInFisier(string nume, string atribut, string nouaValoare);

    // Modifica numele unui client in fisierul CSV
    void modificaClientInFisier(string nume, string nouaValoare);

    // Modifica o comanda in fisierul CSV
    void modificaComandaInFisier(string nume);

    // Actualizeaza stocul produselor in fisierul CSV
    void actualizeazaStocProduse(vector<string> produseDeRestocat);

    // Incarca produsele din fisierul CSV
    void incarcaProduseDinFisier();

    // Afiseaza lista produselor disponibile in orasul cafenelei
    void afiseazaProduseDisponibile();

    // Cauta un produs in lista produselor disponibile
    Produs* cautaProdus(string nume);

    // Incarca comenzile din fisierul CSV
    vector<Comanda> incarcaComenziDinFisier();

    // Incarca evenimentele din fisierul CSV
    vector<Eveniment> incarcaEvenimenteDinFisier();

    // Incarca angajatii din fisierul CSV
    vector<Angajat*> incarcaAngajatiDinFisier();

    // Elibereaza memoria folosita de angajati
    void elibereazaMemorie();
};

#endif