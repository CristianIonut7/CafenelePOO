#include "../include/Rapoarte.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

// Funcție pentru a calcula veniturile unui oraș specificat, pe baza comenzilor din fișierul comenzi.csv
double Rapoarte::calculeazaVenituri(string oras) {
    ifstream fin("../data/comenzi.csv"); // Deschidem fișierul comenzi.csv
    if (!fin) { // Verificăm dacă fișierul s-a deschis corect
        cerr << "Eroare la deschiderea fișierului comenzi.csv\n";
        return 0.0;
    }

    double venituri = 0.0; // Variabila care acumulează veniturile
    string linie;

    // Citim fiecare linie din fișierul CSV
    while (getline(fin, linie)) {
        stringstream ss(linie); // Creăm un flux pentru a separa valorile
        string orasDinCSV, client, produse, total;

        // Extragem valorile câmpurilor din linie
        getline(ss, orasDinCSV, ','); // Orașul asociat comenzii
        getline(ss, client, ',');    // Numele clientului
        getline(ss, produse, ',');  // Lista produselor comandate
        getline(ss, total, ',');    // Totalul comenzii

        // Dacă orașul din linie corespunde orașului specificat
        if (orasDinCSV == oras) {
            try {
                venituri += stod(total); // Adăugăm totalul comenzii la venituri (convertim din string în double)
            } catch (invalid_argument& e) { // Gestionăm posibile erori de conversie
                cerr << "Eroare la conversia totalului comenzii: " << total << "\n";
            }
        }
    }

    fin.close(); // Închidem fișierul
    return venituri; // Returnăm veniturile calculate
}

// Funcție pentru a calcula cheltuielile totale pe baza evenimentelor și salariilor angajaților
double Rapoarte::calculeazaCheltuieli(vector<Eveniment> evenimente, vector<Angajat *> angajati) {
    double total = 0.0; // Variabila care acumulează cheltuielile

    // Adăugăm costurile fiecărui eveniment
    for (auto &eveniment : evenimente) {
        total += eveniment.getCost();
    }

    // Adăugăm salariile fiecărui angajat
    for (auto &angajat : angajati) {
        total += angajat->calculSalariu();
    }

    return total; // Returnăm cheltuielile totale
}
