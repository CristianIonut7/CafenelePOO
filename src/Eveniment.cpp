#include "../include/Eveniment.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

// Constructor
Eveniment::Eveniment(string nume, string data, double cost)
    : nume(nume), data(data), cost(cost) {}

// Returneaza numele evenimentului
string Eveniment::getNume() {
    return nume;
}

// Returneaza data evenimentului
string Eveniment::getData() {
    return data;
}

// Returneaza costul evenimentului
double Eveniment::getCost() {
    return cost;
}

// Afiseaza detalii despre eveniment
void Eveniment::afiseazaEveniment() {
    cout << "Eveniment: " << nume << " | Data: " << data << " | Cost: " << cost << " RON\n";
}

// Citeste lista de evenimente dintr-un fisier CSV
vector<Eveniment> Eveniment::citesteDinCSV(string fisier) {
    vector<Eveniment> evenimente;
    ifstream fin(fisier);
    if (!fin) {
        cerr << "Eroare la deschiderea fisierului " << fisier << "\n";
        return evenimente;
    }

    string linie, nume, data;
    double cost;
    while (getline(fin, linie)) {
        stringstream ss(linie);
        getline(ss, nume, ',');
        getline(ss, data, ',');
        ss >> cost;
        evenimente.emplace_back(nume, data, cost);
    }

    fin.close();
    return evenimente;
}

// Scrie lista de evenimente intr-un fisier CSV
void Eveniment::scrieInCSV(vector<Eveniment> evenimente, string fisier) {
    ofstream fout(fisier);
    if (!fout) {
        cerr << "Eroare la scrierea in fisierul " << fisier << "\n";
        return;
    }

    for (auto eveniment : evenimente) {
        fout << eveniment.getNume() << "," << eveniment.getData() << "," << eveniment.getCost() << "\n";
    }

    fout.close();
}
