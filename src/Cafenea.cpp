#include "../include/Cafenea.h"
#include "../include/Produs.h"
#include "../include/Eveniment.h"
#include "../include/Angajat.h"
#include "../include/Comanda.h"
#include "../include/Barista.h"
#include "../include/Manager.h"
#include "../include/Ospatar.h"
#include "../include/Rapoarte.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// Constructor al clasei Cafenea, initializeaza orasul
Cafenea::Cafenea(string oras) : oras(oras) {}

// Destructor al clasei Cafenea, elibereaza memoria alocata
Cafenea::~Cafenea()
{
    elibereazaMemorie(); // Apel pentru eliberarea memoriei asociate
}

// Returneaza orasul cafenelei
string Cafenea::getOras()
{
    return this->oras; // Acces direct la membrul oras
}

// Afiseaza lista angajatilor din orasul specificat
void Cafenea::afiseazaAngajati()
{
    // Deschide fisierul angajati.csv pentru citire
    ifstream fin("../data/angajati.csv");
    if (!fin)
    {
        cerr << "Eroare la deschiderea fisierului angajati.csv\n";
        return; // Iesire in caz de eroare
    }

    // Afișare antet tabel pentru lista angajatilor
    cout << "Angajati in orasul " << oras << ":\n";
    cout << "----------------------------------------------------------\n";
    cout << "Nume          | Functie       | Ora Inceput | Ora Sfarsit | Tarif\n";
    cout << "----------------------------------------------------------\n";

    string linie;

    // Citire fisier linie cu linie
    while (getline(fin, linie))
    {
        stringstream ss(linie); // Creeaza un stream pentru linia citita
        string orasDinCSV, nume, functie, oraInceput, oraSfarsit, tarif;

        // Citire campuri separate prin virgula
        getline(ss, orasDinCSV, ',');
        getline(ss, nume, ',');
        getline(ss, functie, ',');
        getline(ss, oraInceput, ',');
        getline(ss, oraSfarsit, ',');
        getline(ss, tarif, ',');

        // Verifica daca orasul din fisier corespunde orasului curent
        if (orasDinCSV == oras)
        {
            // Afisare detalii angajat
            cout << nume << " | " << functie << " | " << oraInceput << "         | "
                 << oraSfarsit << "         | " << tarif << "\n";
        }
    }

    fin.close(); // Inchidere fisier
}

// Afiseaza lista produselor disponibile pentru orasul specificat
void Cafenea::afiseazaProduse()
{
    // Deschide fisierul produse.csv pentru citire
    ifstream fin("../data/produse.csv");
    if (!fin)
    {
        // Afiseaza un mesaj de eroare daca fisierul nu poate fi deschis
        cerr << "Eroare la deschiderea fisierului produse.csv\n";
        return; // Iesire din functie in caz de eroare
    }

    // Afiseaza un antet pentru tabelul de produse
    cout << "Produse disponibile in orasul " << oras << ":\n";
    cout << "------------------------------------------\n";
    cout << "Nume Produs       | Pret   | Stoc\n";
    cout << "------------------------------------------\n";

    string linie;

    // Parcurge fisierul linie cu linie
    while (getline(fin, linie))
    {
        stringstream ss(linie); // Creeaza un stream pentru linia citita
        string orasDinCSV, numeProdus, pret, stoc;

        // Extrage campurile separate prin virgula
        getline(ss, orasDinCSV, ',');
        getline(ss, numeProdus, ',');
        getline(ss, pret, ',');
        getline(ss, stoc, ',');

        // Verifica daca orasul din fisier corespunde orasului curent
        if (orasDinCSV == oras)
        {
            // Afiseaza detalii despre produs
            cout << numeProdus << "           | " << pret << "    | " << stoc << "\n";
        }
    }

    fin.close(); // Inchide fisierul dupa procesare
}

// Afiseaza lista comenzilor pentru orasul specificat
void Cafenea::afiseazaComenzi()
{
    // Deschide fisierul comenzi.csv pentru citire
    ifstream fin("../data/comenzi.csv");
    if (!fin)
    {
        // Afiseaza un mesaj de eroare daca fisierul nu poate fi deschis
        cerr << "Eroare la deschiderea fisierului comenzi.csv\n";
        return; // Iesire din functie in caz de eroare
    }

    // Afiseaza un antet pentru tabelul de comenzi
    cout << "Comenzi in orasul " << oras << ":\n";
    cout << "--------------------------------------------------------\n";
    cout << "Nume Client     | Produse comandate        | Pret Total\n";
    cout << "--------------------------------------------------------\n";

    string linie;

    // Parcurge fisierul linie cu linie
    while (getline(fin, linie))
    {
        stringstream ss(linie); // Creeaza un stream pentru linia citita
        string orasDinCSV, numeClient, produseComandate, pretTotal;

        // Extrage campurile separate prin virgula
        getline(ss, orasDinCSV, ',');
        getline(ss, numeClient, ',');
        getline(ss, produseComandate, ',');
        getline(ss, pretTotal, ',');

        // Verifica daca orasul din fisier corespunde orasului curent
        if (orasDinCSV == oras)
        {
            // Afiseaza detalii despre comanda
            cout << numeClient << "       | " << produseComandate << " | " << pretTotal << "\n";
        }
    }

    fin.close(); // Inchide fisierul dupa procesare
}

// Afiseaza lista evenimentelor pentru orasul specificat
void Cafenea::afiseazaEvenimente()
{
    // Deschide fisierul evenimente.csv pentru citire
    ifstream fin("../data/evenimente.csv");
    if (!fin)
    {
        // Afiseaza un mesaj de eroare daca fisierul nu poate fi deschis
        cerr << "Eroare la deschiderea fisierului evenimente.csv\n";
        return; // Iesire din functie in caz de eroare
    }

    // Afiseaza un antet pentru tabelul de evenimente
    cout << "Evenimente in orasul " << oras << ":\n";
    cout << "--------------------------------------------------------\n";
    cout << "Nume Eveniment       | Data          | Cost\n";
    cout << "--------------------------------------------------------\n";

    string linie;

    // Parcurge fisierul linie cu linie
    while (getline(fin, linie))
    {
        stringstream ss(linie); // Creeaza un stream pentru linia citita
        string orasDinCSV, numeEveniment, data, cost;

        // Extrage campurile separate prin virgula
        getline(ss, orasDinCSV, ',');
        getline(ss, numeEveniment, ',');
        getline(ss, data, ',');
        getline(ss, cost, ',');

        // Verifica daca orasul din fisier corespunde orasului curent
        if (orasDinCSV == oras)
        {
            // Afiseaza detalii despre eveniment
            cout << numeEveniment << "       | " << data << " | " << cost << "\n";
        }
    }

    fin.close(); // Inchide fisierul dupa procesare
}

// Adauga un angajat in fisierul angajati.csv
void Cafenea::adaugaAngajatInFisier(Angajat *angajatNou)
{
    // Deschidem fisierul angajati.csv in modul append (adaugare la sfarsit)
    ofstream fout("../data/angajati.csv", ios::app);
    if (!fout)
    {
        // Afisam un mesaj de eroare daca fisierul nu poate fi deschis
        std::cerr << "Eroare la deschiderea fisierului angajati.csv\n";
        return;
    }

    // Scriem in fisier detaliile angajatului, separate prin virgule
    fout << oras << ","                      // Orasul cafenelei
         << angajatNou->getNume() << ","    // Numele angajatului
         << angajatNou->getFunctie() << "," // Functia angajatului
         << angajatNou->getOraInceput() << "," // Ora de inceput
         << angajatNou->getOraSfarsit() << "," // Ora de sfarsit
         << angajatNou->getTarif() << "\n"; // Tarif/Salariu

    // Inchidem fisierul dupa adaugare
    fout.close();
}

// Adauga un produs in fisierul produse.csv
void Cafenea::adaugaProdusInFisier(Produs produsNou)
{
    // Deschidem fisierul produse.csv in modul append (adaugare la sfarsit)
    ofstream fout("../data/produse.csv", ios::app);
    if (!fout)
    {
        // Afisam un mesaj de eroare daca fisierul nu poate fi deschis
        cerr << "Eroare la deschiderea fisierului produse.csv\n";
        return;
    }

    // Scriem in fisier detaliile produsului, separate prin virgule
    fout << oras << ","                   // Orasul cafenelei
         << produsNou.getNume() << ","   // Numele produsului
         << produsNou.getPret() << ","   // Pretul produsului
         << produsNou.getStoc() << "\n"; // Stocul disponibil

    // Inchidem fisierul dupa adaugare
    fout.close();
}

// Adauga o comanda in fisierul comenzi.csv
void Cafenea::adaugaComandaInFisier(Comanda comanda)
{
    // Deschidem fisierul comenzi.csv in modul append (adaugare la sfarsit)
    ofstream fout("../data/comenzi.csv", ios::app);
    if (!fout)
    {
        // Afisam un mesaj de eroare daca fisierul nu poate fi deschis
        cerr << "Eroare la deschiderea fisierului comenzi.csv\n";
        return;
    }

    // Scriem orasul si numele clientului in fisier
    fout << oras << "," << comanda.getNumeClient() << ",";

    // Preluam lista de produse comandate si cantitatile
    auto produse = comanda.getProduseComandate();

    // Serializam produsele in format CSV: nume1:qty1;nume2:qty2
    for (auto produs : produse)
    {
        fout << produs.first->getNume() << ":" << produs.second << ";";
    }

    // Adaugam totalul comenzii la finalul liniei
    fout << "," << comanda.calculeazaTotal() << "\n";

    // Inchidem fisierul dupa adaugare
    fout.close();
}

// Adauga un eveniment in fisierul evenimente.csv
void Cafenea::adaugaEvenimentInFisier(Eveniment evenimentNou)
{
    // Deschidem fisierul evenimente.csv in modul append (adaugare la sfarsit)
    ofstream fout("../data/evenimente.csv", ios::app);
    if (!fout)
    {
        // Afisam un mesaj de eroare daca fisierul nu poate fi deschis
        cerr << "Eroare la deschiderea fisierului evenimente.csv\n";
        return;
    }

    // Scriem detaliile evenimentului in fisier
    fout << oras << ","                  // Orasul cafenelei
         << evenimentNou.getNume() << "," // Numele evenimentului
         << evenimentNou.getData() << "," // Data evenimentului (format YYYY-MM-DD)
         << evenimentNou.getCost() << "\n"; // Costul evenimentului

    // Inchidem fisierul dupa adaugare
    fout.close();
}

// Elimina un angajat din fisierul angajati.csv pe baza numelui si a orasului
void Cafenea::eliminaAngajatDinFisier(string nume)
{
    // Deschidem fisierul angajati.csv pentru citire
    ifstream fin("../data/angajati.csv");
    if (!fin)
    {
        // Afisam un mesaj de eroare daca fisierul nu poate fi deschis
        cerr << "Eroare la deschiderea fisierului angajati.csv\n";
        return;
    }

    // Cream un fisier temporar pentru a stoca datele ramase
    ofstream fout("../data/angajati_temp.csv");
    if (!fout)
    {
        // Afisam un mesaj de eroare daca fisierul temporar nu poate fi creat
        cerr << "Eroare la crearea fisierului temporar\n";
        fin.close(); // Inchidem fisierul sursa
        return;
    }

    string linie;
    // Parcurgem fiecare linie din fisierul sursa
    while (getline(fin, linie))
    {
        stringstream ss(linie);
        string orasDinCSV, numeDinCSV;

        // Extragem orasul si numele angajatului din linie
        getline(ss, orasDinCSV, ',');
        getline(ss, numeDinCSV, ',');

        // Verificam daca linia curenta nu corespunde angajatului care trebuie eliminat
        if (!(orasDinCSV == oras && numeDinCSV == nume))
        {
            // Daca nu corespunde, scriem linia in fisierul temporar
            fout << linie << "\n";
        }
    }

    // Inchidem fisierele deschise
    fin.close();
    fout.close();

    // Stergem fisierul original si il inlocuim cu fisierul temporar
    remove("../data/angajati.csv");
    rename("../data/angajati_temp.csv", "../data/angajati.csv");
}

// Elimina un produs din fisierul produse.csv pe baza numelui produsului
void Cafenea::eliminaProdusDinFisier(string numeProdus)
{
    // Deschidem fisierul produse.csv pentru citire
    ifstream fin("../data/produse.csv");
    if (!fin)
    {
        // Afisam un mesaj de eroare daca fisierul nu poate fi deschis
        cerr << "Eroare la deschiderea fisierului produse.csv\n";
        return;
    }

    // Cream un fisier temporar pentru a stoca produsele ramase
    ofstream fout("../data/produse_temp.csv");
    if (!fout)
    {
        // Afisam un mesaj de eroare daca fisierul temporar nu poate fi creat
        cerr << "Eroare la crearea fisierului temporar\n";
        fin.close(); // Inchidem fisierul sursa
        return;
    }

    string linie;
    // Parcurgem fiecare linie din fisierul sursa
    while (getline(fin, linie))
    {
        // Verificam daca linia contine numele produsului care trebuie eliminat
        if (linie.find(numeProdus) == string::npos)
        {
            // Daca produsul nu este gasit in linia curenta, scriem linia in fisierul temporar
            fout << linie << "\n";
        }
    }

    // Inchidem fisierele deschise
    fin.close();
    fout.close();

    // Stergem fisierul original si il inlocuim cu fisierul temporar
    remove("../data/produse.csv");
    rename("../data/produse_temp.csv", "../data/produse.csv");
}

// Elimina o comanda din fisierul comenzi.csv pe baza numelui clientului si actualizeaza stocurile produselor
void Cafenea::eliminaComandaDinFisier(string numeClient)
{
    // Deschidem fisierul comenzi.csv pentru citire
    ifstream fin("../data/comenzi.csv");
    if (!fin)
    {
        // Afisam un mesaj de eroare daca fisierul nu poate fi deschis
        cerr << "Eroare la deschiderea fisierului comenzi.csv\n";
        return;
    }

    // Cream un fisier temporar pentru a stoca comenzile ramase
    ofstream fout("../data/comenzi_temp.csv");
    if (!fout)
    {
        // Afisam un mesaj de eroare daca fisierul temporar nu poate fi creat
        cerr << "Eroare la crearea fisierului temporar\n";
        fin.close(); // Inchidem fisierul sursa
        return;
    }

    string linie;
    // Parcurgem fiecare linie din fisierul sursa
    while (getline(fin, linie))
    {
        // Verificam daca linia contine numele clientului care trebuie eliminat
        if (linie.find(numeClient) != string::npos)
        {
            // Procesam produsele din comanda care trebuie eliminata
            stringstream ss(linie);
            string orasDinCSV, clientDinCSV, produse, total;
            getline(ss, orasDinCSV, ',');  // Orasul
            getline(ss, clientDinCSV, ',');  // Numele clientului
            getline(ss, produse, ',');  // Produsele comandate
            getline(ss, total, ',');  // Totalul comenzii

            // Verificam daca clientul curent este cel pentru care eliminam comanda
            if (clientDinCSV == numeClient)
            {
                stringstream ssProduse(produse); // Parcurgem produsele din comanda
                string produs;

                while (getline(ssProduse, produs, ';'))
                {
                    string numeProdus;
                    int cantitate;

                    stringstream ssProdus(produs);
                    getline(ssProdus, numeProdus, ':'); // Extragerea numelui produsului
                    ssProdus >> cantitate;              // Extragerea cantitatii

                    // Incarcam produsele si cautam produsul in lista disponibila
                    incarcaProduseDinFisier();
                    Produs *produs = cautaProdus(numeProdus);
                    if (produs)
                    {
                        // Actualizam stocul produsului in fisier
                        modificaProdusInFisier(numeProdus, "stoc", to_string((produs->getStoc() - cantitate)));
                    }
                    else
                    {
                        // Afisam un mesaj de eroare daca produsul nu este gasit
                        cerr << "Produsul \"" << numeProdus << "\" nu a fost gasit in stoc!\n";
                    }
                }
                continue; // Sarim peste scrierea acestei comenzi în fisierul temporar
            }
        }
        // Scriem linia curenta in fisierul temporar daca comanda nu apartine clientului specificat
        fout << linie << "\n";
    }

    // Inchidem fisierele deschise
    fin.close();
    fout.close();

    // Stergem fisierul original si il inlocuim cu fisierul temporar
    remove("../data/comenzi.csv");
    rename("../data/comenzi_temp.csv", "../data/comenzi.csv");
}

// Elimină un eveniment specific din fișierul evenimente.csv
void Cafenea::eliminaEvenimentDinFisier(string numeEveniment)
{
    // Deschidem fișierul evenimente.csv pentru citire
    ifstream fin("../data/evenimente.csv");
    if (!fin)
    {
        // Afișăm un mesaj de eroare dacă fișierul nu poate fi deschis
        cerr << "Eroare la deschiderea fisierului evenimente.csv\n";
        return;
    }

    // Creăm un fișier temporar pentru a stoca evenimentele rămase
    ofstream fout("../data/evenimente_temp.csv");
    if (!fout)
    {
        // Afișăm un mesaj de eroare dacă fișierul temporar nu poate fi creat
        cerr << "Eroare la crearea fisierului temporar\n";
        fin.close(); // Închidem fișierul sursă
        return;
    }

    string linie;
    // Parcurgem fiecare linie din fișierul sursă
    while (getline(fin, linie))
    {
        // Verificăm dacă linia conține numele evenimentului care trebuie eliminat
        if (linie.find(numeEveniment) == string::npos)
        {
            // Dacă evenimentul nu este cel care trebuie eliminat, îl scriem în fișierul temporar
            fout << linie << "\n";
        }
    }

    // Închidem fișierele deschise
    fin.close();
    fout.close();

    // Ștergem fișierul original și îl înlocuim cu fișierul temporar
    remove("../data/evenimente.csv");
    rename("../data/evenimente_temp.csv", "../data/evenimente.csv");
}

// Modifică un atribut specific al unui angajat din fișierul angajati.csv
void Cafenea::modificaAngajatInFisier(string nume, string atribut, string nouaValoare)
{
    // Deschidem fișierul angajati.csv pentru citire
    ifstream fin("../data/angajati.csv");
    if (!fin)
    {
        // Dacă fișierul nu poate fi deschis, afișăm un mesaj de eroare și ieșim
        cerr << "Eroare la deschiderea fisierului angajati.csv\n";
        return;
    }

    vector<string> angajati; // Vector pentru stocarea liniilor din fișier
    string linie, orasDinCSV, numeDinCSV, functie, oraInceput, oraSfarsit, tarif;
    bool angajatGasit = false; // Indicator pentru verificarea existenței angajatului

    // Citim fișierul linie cu linie
    while (getline(fin, linie))
    {
        stringstream ss(linie);

        // Citim atributele fiecărui angajat din fișier
        getline(ss, orasDinCSV, ',');
        getline(ss, numeDinCSV, ',');
        getline(ss, functie, ',');
        getline(ss, oraInceput, ',');
        getline(ss, oraSfarsit, ',');
        getline(ss, tarif, ',');

        // Verificăm dacă angajatul corespunde numelui și orașului specificat
        if (orasDinCSV == oras && numeDinCSV == nume)
        {
            angajatGasit = true;

            // Modificăm atributul specificat
            if (atribut == "nume")
            {
                numeDinCSV = nouaValoare;
            }
            else if (atribut == "functie")
            {
                functie = nouaValoare;
            }
            else if (atribut == "oraInceput")
            {
                oraInceput = nouaValoare;
            }
            else if (atribut == "oraSfarsit")
            {
                oraSfarsit = nouaValoare;
            }
            else if (atribut == "tarif")
            {
                tarif = nouaValoare;
            }
            else
            {
                // Dacă atributul este invalid, afișăm un mesaj de eroare
                cerr << "Atribut invalid!\n";
                fin.close();
                return;
            }

            // Ștergem angajatul existent
            eliminaAngajatDinFisier(nume);

            // Creăm un obiect nou de tip angajat cu valorile modificate
            Angajat *angajatNou = nullptr;
            if (functie == "Barista")
            {
                angajatNou = new Barista(numeDinCSV, stoi(oraInceput), stoi(oraSfarsit), stod(tarif));
            }
            else if (functie == "Manager")
            {
                angajatNou = new Manager(numeDinCSV, stoi(oraInceput), stoi(oraSfarsit), stod(tarif));
            }
            else if (functie == "Ospatar")
            {
                angajatNou = new Ospatar(numeDinCSV, stoi(oraInceput), stoi(oraSfarsit), stod(tarif));
            }

            // Adăugăm angajatul modificat în fișier și eliberăm memoria alocată
            if (angajatNou)
            {
                adaugaAngajatInFisier(angajatNou);
                delete angajatNou;
            }
        }
    }

    fin.close(); // Închidem fișierul

    // Verificăm dacă angajatul a fost găsit și modificat
    if (!angajatGasit)
    {
        cerr << "Angajatul \"" << nume << "\" nu a fost gasit.\n";
    }
    else
    {
        cout << "Angajatul \"" << nume << "\" a fost modificat cu succes.\n";
    }
}

void Cafenea::modificaProdusInFisier(string nume, string atribut, string nouaValoare)
{
    // Deschidem fisierul cu produsele in mod de citire
    ifstream fin("../data/produse.csv");
    if (!fin)
    {
        // Daca fisierul nu poate fi deschis, afisam eroare si parasim functia
        cerr << "Eroare la deschiderea fisierului produse.csv\n";
        return;
    }

    // Creem un vector pentru a stoca liniile din fisier
    vector<string> produse;
    string linie, orasDinCSV, numeDinCSV, pret, stoc;
    bool produsGasit = false;

    // Citim fisierul linie cu linie
    while (getline(fin, linie))
    {
        stringstream ss(linie);

        // Extragem valorile din fiecare linie folosind separatorul ','
        getline(ss, orasDinCSV, ',');
        getline(ss, numeDinCSV, ',');
        getline(ss, pret, ',');
        getline(ss, stoc, ',');

        // Verificam daca orasul si numele produsului corespund cu cele date
        if (orasDinCSV == oras && numeDinCSV == nume)
        {
            produsGasit = true;

            // Modificam atributul corespunzator daca este gasit
            if (atribut == "nume")
            {
                numeDinCSV = nouaValoare;
            }
            else if (atribut == "pret")
            {
                pret = nouaValoare;
            }
            else if (atribut == "stoc")
            {
                stoc = nouaValoare;
            }
            else
            {
                // Daca atributul este invalid, afisam eroare si inchidem fisierul
                cerr << "Atribut invalid!\n";
                fin.close();
                return;
            }

            // Eliminam produsul vechi din fisier si adaugam produsul modificat
            eliminaProdusDinFisier(nume);
            Produs produsNou(numeDinCSV, stod(pret), stoi(stoc));
            adaugaProdusInFisier(produsNou);
        }
    }

    // Inchidem fisierul
    fin.close();

    // Verificam daca produsul a fost gasit si afisam un mesaj corespunzator
    if (!produsGasit)
    {
        cerr << "Produsul \"" << nume << "\" nu a fost gasit.\n";
    }
    else
    {
        cout << "Produsul \"" << nume << "\" a fost modificat cu succes.\n";
    }
}

void Cafenea::modificaEvenimentInFisier(string nume, string atribut, string nouaValoare)
{
    // Deschidem fisierul cu evenimentele in mod de citire
    ifstream fin("../data/evenimente.csv");
    if (!fin)
    {
        // Daca fisierul nu poate fi deschis, afisam eroare si parasim functia
        cerr << "Eroare la deschiderea fișierului evenimente.csv\n";
        return;
    }

    // Creem un vector pentru a stoca liniile din fisier
    vector<string> evenimente;
    string linie, orasDinCSV, numeDinCSV, data, cost;
    bool evenimentGasit = false;

    // Citim fisierul linie cu linie
    while (getline(fin, linie))
    {
        stringstream ss(linie);

        // Extragem valorile din fiecare linie folosind separatorul ','
        getline(ss, orasDinCSV, ',');
        getline(ss, numeDinCSV, ',');
        getline(ss, data, ',');
        getline(ss, cost, ',');

        // Verificam daca orasul si numele evenimentului corespund cu cele date
        if (orasDinCSV == oras && numeDinCSV == nume)
        {
            evenimentGasit = true;

            // Modificam atributul corespunzator daca este gasit
            if (atribut == "nume")
            {
                numeDinCSV = nouaValoare;
            }
            else if (atribut == "data")
            {
                data = nouaValoare;
            }
            else if (atribut == "cost")
            {
                cost = nouaValoare;
            }
            else
            {
                // Daca atributul este invalid, afisam eroare si inchidem fisierul
                cerr << "Atribut invalid!\n";
                fin.close();
                return;
            }

            // Eliminam evenimentul vechi din fisier si adaugam evenimentul modificat
            eliminaEvenimentDinFisier(nume);
            Eveniment evenimentNou(numeDinCSV, data, stod(cost));
            adaugaEvenimentInFisier(evenimentNou);
        }
    }

    // Inchidem fisierul
    fin.close();

    // Verificam daca evenimentul a fost gasit si afisam un mesaj corespunzator
    if (!evenimentGasit)
    {
        cerr << "Evenimentul \"" << nume << "\" nu a fost găsit.\n";
    }
    else
    {
        cout << "Evenimentul \"" << nume << "\" a fost modificat cu succes.\n";
    }
}

void Cafenea::modificaClientInFisier(string nume, string nouaValoare)
{
    // Deschidem fisierul comenzi.csv in mod de citire
    ifstream fin("../data/comenzi.csv");
    if (!fin)
    {
        // Daca fisierul nu poate fi deschis, afisam eroare si parasim functia
        cerr << "Eroare la deschiderea fișierului comenzi.csv\n";
        return;
    }

    // Creem un fisier temporar pentru a stoca modificarile
    ofstream fout("../data/comenzi_temp.csv");
    if (!fout)
    {
        // Daca fisierul temporar nu poate fi creat, afisam eroare si parasim functia
        cerr << "Eroare la crearea fișierului temporar comenzi_temp.csv\n";
        fin.close();
        return;
    }

    string linie, orasDinCSV, clientDinCSV, produse, total;
    bool clientGasit = false;

    // Citim fisierul comenzi.csv linie cu linie
    while (getline(fin, linie))
    {
        stringstream ss(linie);

        // Extragem valorile din fiecare linie folosind separatorul ','
        getline(ss, orasDinCSV, ',');
        getline(ss, clientDinCSV, ',');
        getline(ss, produse, ',');
        getline(ss, total, ',');

        // Verificam daca orasul si numele clientului corespund cu cele date
        if (orasDinCSV == oras && clientDinCSV == nume)
        {
            clientGasit = true;
            // Actualizam numele clientului cu noua valoare
            clientDinCSV = nouaValoare;
        }

        // Scriem linia (modificata sau nu) in fisierul temporar
        fout << orasDinCSV << "," << clientDinCSV << "," << produse << "," << total << "\n";
    }

    // Inchidem ambele fisiere
    fin.close();
    fout.close();

    // Daca clientul a fost gasit, inlocuim fisierul vechi cu cel temporar
    if (clientGasit)
    {
        remove("../data/comenzi.csv");
        rename("../data/comenzi_temp.csv", "../data/comenzi.csv");
        cout << "Numele clientului \"" << nume << "\" a fost modificat cu succes.\n";
    }
    else
    {
        // Daca clientul nu a fost gasit, stergem fisierul temporar si afisam eroare
        remove("../data/comenzi_temp.csv");
        cerr << "Clientul \"" << nume << "\" nu a fost găsit.\n";
    }
}

void Cafenea::modificaComandaInFisier(string numeClient)
{
    // Pasul 1: Ștergem comanda veche a clientului
    eliminaComandaDinFisier(numeClient);

    // Pasul 2: Creăm o comandă nouă pentru clientul specificat
    cout << "Modificăm comanda pentru clientul: " << numeClient << "\n";

    Comanda comandaNoua(numeClient);
    // Incarcam produsele disponibile din fisier si le afisam
    incarcaProduseDinFisier();
    afiseazaProduseDisponibile();

    string numeProdus;
    int cantitate;

    // Citim produsele comandate de client
    while (true)
    {
        cout << "Nume produs (sau 'stop' pentru a finaliza comanda): ";
        getline(cin, numeProdus);

        // Daca utilizatorul scrie "stop", finalizam comanda
        if (numeProdus == "stop")
        {
            break;
        }

        // Cautam produsul in lista de produse
        Produs *produs = cautaProdus(numeProdus);
        if (!produs)
        {
            // Daca produsul nu a fost gasit, afisam un mesaj de eroare
            cout << "Produsul nu a fost găsit în orașul " << oras << ".\n";
            continue;
        }

        // Cerem cantitatea dorita pentru produs
        cout << "Cantitate: ";
        cin >> cantitate;
        cin.ignore();

        // Verificam daca exista suficient stoc pentru produs
        if (produs->getStoc() < cantitate)
        {
            // Daca stocul nu este suficient, afisam un mesaj de eroare
            cout << "Stoc insuficient pentru produsul " << produs->getNume() << ".\n";
        }
        else
        {
            // Adaugam produsul in comanda
            comandaNoua.adaugaProdus(produs, cantitate);
            cout << "Produsul a fost adăugat la comandă.\n";
        }
    }

    // Pasul 3: Salvăm comanda nouă în fișier
    adaugaComandaInFisier(comandaNoua);

    // Afisam un mesaj de succes dupa ce comanda a fost actualizata
    cout << "Comanda a fost modificată cu succes!\n";
}

void Cafenea::actualizeazaStocProduse(vector<string> produseDeRestocat)
{
    // Deschidem fisierul produse.csv in mod de citire
    ifstream fin("../data/produse.csv");
    if (!fin)
    {
        // Daca fisierul nu poate fi deschis, afisam eroare si parasim functia
        cerr << "Eroare la deschiderea fișierului produse.csv\n";
        return;
    }

    // Creem un fisier temporar pentru a stoca modificarile
    ofstream fout("../data/produse_temp.csv");
    if (!fout)
    {
        // Daca fisierul temporar nu poate fi creat, afisam eroare si parasim functia
        cerr << "Eroare la crearea fișierului temporar produse_temp.csv\n";
        fin.close();
        return;
    }

    string linie;
    // Citim fisierul produse.csv linie cu linie
    while (getline(fin, linie))
    {
        stringstream ss(linie);
        string orasDinCSV, numeProdus, pret, stoc;
        // Extragem valorile din fiecare linie folosind separatorul ','
        getline(ss, orasDinCSV, ',');
        getline(ss, numeProdus, ',');
        getline(ss, pret, ',');
        getline(ss, stoc, ',');

        // Verificam daca orasul din linie corespunde cu orasul curent
        if (orasDinCSV == oras)
        {
            // Verificam daca produsul face parte din lista de produse de restocat
            for (auto produs : produseDeRestocat)
            {
                if (produs == numeProdus)
                {
                    // Daca produsul se afla in lista, actualizam stocul
                    int stocNou = stoi(stoc) - 1; // Reducem stocul cu 1
                    fout << orasDinCSV << "," << numeProdus << "," << pret << "," << stocNou << "\n";
                    goto nextLine; // Trecem la următoarea linie din fișier
                }
            }
        }

        // Daca produsul nu a fost gasit in lista de restocat, scriem linia nemodificata
        fout << linie << "\n";
    nextLine:;
    }

    // Inchidem ambele fisiere
    fin.close();
    fout.close();

    // Inlocuim fisierul original cu fisierul temporar
    remove("../data/produse.csv");
    rename("../data/produse_temp.csv", "../data/produse.csv");
}

void Cafenea::incarcaProduseDinFisier()
{
    // Curatam lista de produse disponibile
    produseDisponibile.clear();

    // Deschidem fisierul produse.csv in mod de citire
    ifstream fin("../data/produse.csv");
    if (!fin)
    {
        // Daca fisierul nu poate fi deschis, afisam eroare si parasim functia
        cerr << "Eroare la deschiderea fișierului produse.csv\n";
        return;
    }

    string linie, orasDinCSV, nume;
    double pret;
    int stoc;

    // Citim fisierul linie cu linie
    while (getline(fin, linie))
    {
        stringstream ss(linie);
        // Extragem valorile din fiecare linie folosind separatorul ','
        getline(ss, orasDinCSV, ',');
        getline(ss, nume, ',');
        ss >> pret;
        ss.ignore();
        ss >> stoc;

        // Filtrăm produsele în funcție de orașul curent
        if (orasDinCSV == oras)
        {
            // Adaugam produsul in lista de produse disponibile
            produseDisponibile.emplace_back(nume, pret, stoc);
        }
    }

    // Inchidem fisierul
    fin.close();
}

void Cafenea::afiseazaProduseDisponibile()
{
    // Afisam lista de produse disponibile in orasul curent
    cout << "\nProduse disponibile în orașul " << oras << ":\n";
    for (auto produs : produseDisponibile)
    {
        // Afisam detaliile fiecarui produs
        produs.afiseazaProdus();
    }
}

Produs *Cafenea::cautaProdus(string nume)
{
    // Cautam produsul dupa nume in lista de produse disponibile
    for (auto &produs : produseDisponibile)
    {
        if (produs.getNume() == nume)
        {
            // Daca produsul este gasit, returnam un pointer catre acesta
            return &produs;
        }
    }
    // Daca produsul nu este gasit, returnam nullptr
    return nullptr;
}

vector<Comanda> Cafenea::incarcaComenziDinFisier()
{
    vector<Comanda> comenzi;

    // Deschidem fisierul comenzi.csv in mod de citire
    ifstream fin("../data/comenzi.csv");
    if (!fin)
    {
        // Daca fisierul nu poate fi deschis, afisam eroare si returnam lista goala de comenzi
        cerr << "Eroare la deschiderea fișierului comenzi.csv\n";
        return comenzi;
    }

    string linie;
    // Citim fisierul linie cu linie
    while (getline(fin, linie))
    {
        stringstream ss(linie);
        string orasDinCSV, clientDinCSV, produse, total;

        // Extragem valorile din fiecare linie folosind separatorul ','
        getline(ss, orasDinCSV, ',');
        getline(ss, clientDinCSV, ',');
        getline(ss, produse, ',');
        getline(ss, total, ',');

        // Verificam daca orasul din linie corespunde cu orasul curent
        if (orasDinCSV == oras)
        {
            // Cream un obiect Comanda pentru clientul curent
            Comanda comanda(clientDinCSV);

            // Extragem lista de produse comandate
            stringstream ssProduse(produse);
            string produs;
            while (getline(ssProduse, produs, ';'))
            {
                stringstream ssProdus(produs);
                string numeProdus;
                int cantitate;

                // Extragem numele produsului si cantitatea
                getline(ssProdus, numeProdus, ':');
                ssProdus >> cantitate;

                // Cautam produsul in lista de produse disponibile
                Produs *produsPtr = cautaProdus(numeProdus);
                if (produsPtr)
                {
                    // Daca produsul exista, il adaugam in comanda
                    comanda.adaugaProdus(produsPtr, cantitate);
                    cout << "lol"; // Acesta pare a fi un mesaj de test, probabil se poate elimina
                }
            }

            // Adaugam comanda in lista de comenzi
            comenzi.push_back(comanda);
        }
    }

    // Inchidem fisierul
    fin.close();

    // Returnam lista de comenzi incarcate
    return comenzi;
}

vector<Eveniment> Cafenea::incarcaEvenimenteDinFisier()
{
    vector<Eveniment> evenimente;

    // Deschidem fisierul evenimente.csv in mod de citire
    ifstream fin("../data/evenimente.csv");
    if (!fin)
    {
        // Daca fisierul nu poate fi deschis, afisam eroare si returnam lista goala de evenimente
        cerr << "Eroare la deschiderea fișierului evenimente.csv\n";
        return evenimente;
    }

    string linie;
    // Citim fisierul linie cu linie
    while (getline(fin, linie))
    {
        stringstream ss(linie);
        string orasDinCSV, numeEveniment, data, cost;

        // Extragem valorile din fiecare linie folosind separatorul ','
        getline(ss, orasDinCSV, ',');
        getline(ss, numeEveniment, ',');
        getline(ss, data, ',');
        getline(ss, cost, ',');

        // Verificam daca orasul din linie corespunde cu orasul curent
        if (orasDinCSV == oras)
        {
            // Cream un obiect Eveniment si il adaugam in lista de evenimente
            Eveniment eveniment(numeEveniment, data, stod(cost));
            evenimente.push_back(eveniment);
        }
    }

    // Inchidem fisierul
    fin.close();

    // Returnam lista de evenimente incarcate
    return evenimente;
}

vector<Angajat *> Cafenea::incarcaAngajatiDinFisier()
{
    vector<Angajat *> angajati;

    // Deschidem fisierul angajati.csv in mod de citire
    ifstream fin("../data/angajati.csv");
    if (!fin)
    {
        // Daca fisierul nu poate fi deschis, afisam eroare si returnam lista goala de angajati
        cerr << "Eroare la deschiderea fișierului angajati.csv\n";
        return angajati;
    }

    string linie;
    // Citim fisierul linie cu linie
    while (getline(fin, linie))
    {
        stringstream ss(linie);
        string orasDinCSV, nume, functie, oraInceput, oraSfarsit, tarif;

        // Extragem valorile din fiecare linie folosind separatorul ','
        getline(ss, orasDinCSV, ',');
        getline(ss, nume, ',');
        getline(ss, functie, ',');
        getline(ss, oraInceput, ',');
        getline(ss, oraSfarsit, ',');
        getline(ss, tarif, ',');

        // Verificam daca orasul din linie corespunde cu orasul curent
        if (orasDinCSV == oras)
        {
            // Cream un obiect Angajat in functie de functie
            Angajat *angajat = nullptr;
            if (functie == "Barista")
            {
                // Cream un obiect Barista
                angajat = new Barista(nume, stoi(oraInceput), stoi(oraSfarsit), stod(tarif));
            }
            else if (functie == "Manager")
            {
                // Cream un obiect Manager
                angajat = new Manager(nume, stoi(oraInceput), stoi(oraSfarsit), stod(tarif));
            }
            else if (functie == "Ospatar")
            {
                // Cream un obiect Ospatar
                angajat = new Ospatar(nume, stoi(oraInceput), stoi(oraSfarsit), stod(tarif));
            }

            // Daca angajatul a fost creat, il adaugam in lista
            if (angajat)
            {
                angajati.push_back(angajat);
            }
        }
    }

    // Inchidem fisierul
    fin.close();

    // Returnam lista de angajati incarcati
    return angajati;
}

void Cafenea::elibereazaMemorie()
{
    // Parcurgem lista de angajati si eliberam memoria alocata pentru fiecare angajat
    for (auto angajat : angajati)
    {
        delete angajat; // Eliberam memoria alocata pentru obiectul Angajat
    }

    // Curatam lista de angajati
    angajati.clear();
}