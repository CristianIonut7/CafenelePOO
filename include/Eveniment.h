#ifndef EVENIMENT_H
#define EVENIMENT_H

#include <string>
#include <vector>

using namespace std;

class Eveniment {
private:
    string nume;     // Numele evenimentului
    string data;     // Data evenimentului in formatul YYYY-MM-DD
    double cost;     // Costul evenimentului

public:
    // Constructor pentru initializarea unui eveniment
    Eveniment(string nume, string data, double cost);

    // Getter pentru numele evenimentului
    string getNume();

    // Getter pentru data evenimentului
    string getData();

    // Getter pentru costul evenimentului
    double getCost();

    // Afiseaza detalii despre eveniment
    void afiseazaEveniment();

    // Metode pentru citirea si scrierea evenimentelor din/in fisier CSV
    static vector<Eveniment> citesteDinCSV(string fisier);
    static void scrieInCSV(vector<Eveniment> evenimente, string fisier);
};

#endif