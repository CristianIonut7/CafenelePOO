#include <iostream>
#include <string>
#include <set>
#include <fstream>
#include "../include/Cafenea.h"
#include "../include/Angajat.h"
#include "../include/Produs.h"
#include "../include/Comanda.h"
#include "../include/Eveniment.h"
#include "../include/Barista.h"
#include "../include/Manager.h"
#include "../include/Ospatar.h"
#include "../include/Rapoarte.h"

using namespace std;

// Functie care afiseaza meniul principal al aplicatiei
void afiseazaMeniuPrincipal()
{
    cout << "\n========== Meniu Principal ==========" << endl;
    cout << "1. Gestioneaza Angajati" << endl;
    cout << "2. Gestioneaza Produse" << endl;
    cout << "3. Gestioneaza Comenzi" << endl;
    cout << "4. Gestioneaza Evenimente" << endl;
    cout << "5. Rapoarte" << endl;
    cout << "6. Iesi din aplicatie" << endl;
    cout << "=====================================" << endl;
    cout << "Alege o optiune: ";
}


// Funcție pentru gestionarea meniului angajaților
void meniuAngajati(Cafenea cafenea)
{
    int optiune; // Variabilă pentru opțiunea selectată de utilizator
    do
    {
        try
        {
            // Afișarea meniului pentru gestionarea angajaților
            cout << "\n========== Meniu Angajati ==========\n";
            cout << "1. Adauga Angajat\n";
            cout << "2. Elimina Angajat\n";
            cout << "3. Afiseaza Angajati\n";
            cout << "4. Modifica Angajat\n";
            cout << "5. Inapoi la Meniul Principal\n";
            cout << "====================================\n";
            cout << "Alege o optiune: ";

            string input;
            cin >> input;
            cin.ignore(); // Eliminăm newline-ul rămas în buffer

            // Validare: verificăm dacă inputul este numeric
            for (char c : input)
            {
                if (!isdigit(c))
                {
                    throw std::invalid_argument("Optiunea introdusa nu este un numar valid.");
                }
            }

            // Conversia inputului în int
            optiune = stoi(input);

            // Gestionarea fiecărei opțiuni din meniu
            switch (optiune)
            {
            case 1: // Adăugare angajat
            {
                string nume, functie;
                int oraInceput, oraSfarsit;
                double parametru;

                // Solicităm utilizatorului detaliile angajatului
                cout << "Nume angajat: ";
                getline(cin, nume);
                cout << "Functie (Barista/Manager/Ospatar): ";
                getline(cin, functie);
                cout << "Ora inceput: ";
                cin >> oraInceput;
                cout << "Ora sfarsit: ";
                cin >> oraSfarsit;
                cout << "Tarif (Barista/Ospatar) sau Salariu Fix (Manager): ";
                cin >> parametru;
                cin.ignore(); // Curățăm bufferul după input numeric

                Angajat *angajatNou; // Pointer pentru angajatul nou

                // Determinăm tipul angajatului pe baza funcției specificate
                if (functie == "Barista")
                {
                    angajatNou = new Barista(nume, oraInceput, oraSfarsit, parametru);
                }
                else if (functie == "Manager")
                {
                    angajatNou = new Manager(nume, oraInceput, oraSfarsit, parametru);
                }
                else if (functie == "Ospatar")
                {
                    angajatNou = new Ospatar(nume, oraInceput, oraSfarsit, parametru);
                }
                else
                {
                    cout << "Functie invalida!\n";
                    break;
                }

                // Salvăm angajatul în fișier și eliberăm memoria
                cafenea.adaugaAngajatInFisier(angajatNou);
                delete angajatNou;
                break;
            }
            case 2: // Eliminare angajat
            {
                string nume;

                // Afișăm lista de angajați existenți
                cafenea.afiseazaAngajati();

                // Solicităm utilizatorului numele angajatului de eliminat
                cout << "Nume angajat: ";
                getline(cin, nume);

                // Eliminăm angajatul din fișier
                cafenea.eliminaAngajatDinFisier(nume);
                break;
            }
            case 3: // Afișare angajați
                cafenea.afiseazaAngajati();
                break;

            case 4: // Modificare angajat
            {
                string nume;

                // Afișăm lista de angajați existenți
                cafenea.afiseazaAngajati();

                // Solicităm utilizatorului numele angajatului de modificat
                cout << "Nume angajat pentru modificare: ";
                getline(cin, nume);

                // Solicităm atributul de modificat și noua valoare
                string atribut, nouaValoare;
                cout << "Alege atributul de modificat (nume/functie/oraInceput/oraSfarsit/tarif): ";
                getline(cin, atribut);
                cout << "Introduce noua valoare pentru " << atribut << ": ";
                getline(cin, nouaValoare);

                // Modificăm angajatul în fișier
                cafenea.modificaAngajatInFisier(nume, atribut, nouaValoare);
                break;
            }
            case 5: // Revenire la meniul principal
                cout << "Revenire la meniul principal.\n";
                break;

            default: // Opțiune invalidă
                cout << "Optiune invalida!\n";
                break;
            }
        }
        catch (exception &e)
        {
            // Gestionăm eventualele erori și afișăm mesajele corespunzătoare
            cout << "Eroare: " << e.what() << "\n";
            cout << "Te rugam sa introduci un numar intre 1 si 4.\n";
        }
    } while (optiune != 5); // Continuăm până când utilizatorul selectează opțiunea 5
}

// Functie pentru gestionarea meniului produselor
void meniuProduse(Cafenea cafenea)
{
    int optiune; // Optiunea selectata de utilizator
    do
    {
        try
        {
            // Afisam meniul pentru gestionarea produselor
            cout << "\n========== Meniu Produse ==========" << endl;
            cout << "1. Adauga Produs" << endl;
            cout << "2. Elimina Produs" << endl;
            cout << "3. Afiseaza Produse" << endl;
            cout << "4. Modifica Produs" << endl;
            cout << "5. Inapoi la Meniul Principal" << endl;
            cout << "====================================" << endl;
            cout << "Alege o optiune: ";

            // Citim optiunea utilizatorului si o validam
            string input;
            cin >> input;
            cin.ignore();

            // Verificam daca input-ul contine doar cifre
            for (char c : input)
            {
                if (!isdigit(c))
                {
                    throw std::invalid_argument("Optiunea introdusa nu este un numar valid.");
                }
            }

            // Convertim input-ul intr-un int
            optiune = stoi(input);

            // Gestionam fiecare optiune
            switch (optiune)
            {
            case 1: // Adaugare produs
            {
                string numeProdus;
                double pret;
                int stoc;

                // Solicitam detaliile produsului de la utilizator
                cout << "Nume produs: ";
                getline(cin, numeProdus);
                cout << "Pret: ";
                cin >> pret;
                cout << "Stoc: ";
                cin >> stoc;
                cin.ignore();

                // Cream un nou produs si il adaugam in fisier
                Produs produsNou(numeProdus, pret, stoc);
                cafenea.adaugaProdusInFisier(produsNou);
                break;
            }
            case 2: // Eliminare produs
            {
                string nume;

                // Afisam lista de produse disponibile
                cafenea.afiseazaProduse();

                // Solicitam numele produsului de eliminat
                cout << "Nume produs: ";
                getline(cin, nume);

                // Eliminam produsul din fisier
                cafenea.eliminaProdusDinFisier(nume);
                break;
            }
            case 3: // Afisare produse
                // Afisam toate produsele disponibile
                cafenea.afiseazaProduse();
                break;

            case 4: // Modificare produs
            {
                string nume;

                // Afisam lista de produse disponibile
                cafenea.afiseazaProduse();

                // Solicitam numele produsului de modificat
                cout << "Nume produs pentru modificare: ";
                getline(cin, nume);

                // Solicitam atributul de modificat si noua valoare
                string atribut, nouaValoare;
                cout << "Alege atributul de modificat (nume/pret/stoc): ";
                getline(cin, atribut);
                cout << "Introduce noua valoare pentru " << atribut << ": ";
                getline(cin, nouaValoare);

                // Modificam produsul in fisier
                cafenea.modificaProdusInFisier(nume, atribut, nouaValoare);
                break;
            }
            case 5: // Revenire la meniul principal
                cout << "Revenire la meniul principal." << endl;
                break;

            default: // Optiune invalida
                cout << "Optiune invalida!" << endl;
                break;
            }
        }
        catch (exception &e)
        {
            // Gestionam erorile si afisam mesajul corespunzator
            cout << "Eroare: " << e.what() << endl;
            cout << "Te rugam sa introduci un numar intre 1 si 5." << endl;
        }
    } while (optiune != 5); // Repetam pana cand utilizatorul alege sa revina la meniul principal
}

// Functia care gestioneaza meniul comenzilor
void meniuComenzi(Cafenea cafenea)
{
    int optiune; // Optiunea selectata de utilizator
    do
    {
        try
        {
            // Afisare meniu pentru comenzile disponibile
            cout << "\n========== Meniu Comenzi ==========" << endl;
            cout << "1. Adauga Comanda" << endl;
            cout << "2. Elimina Comanda" << endl;
            cout << "3. Afiseaza Comenzi" << endl;
            cout << "4. Modifica Comanda" << endl;
            cout << "5. Inapoi la Meniul Principal" << endl;
            cout << "====================================" << endl;
            cout << "Alege o optiune: ";

            // Validarea introducerii optiunii
            string input;
            cin >> input;
            cin.ignore();

            // Verificam daca toate caracterele introduse sunt cifre
            for (char c : input)
            {
                if (!isdigit(c))
                {
                    throw invalid_argument("Optiunea introdusa nu este un numar valid.");
                }
            }

            // Convertim optiunea in int
            optiune = stoi(input);

            switch (optiune)
            {
            case 1: // Adauga comanda
            {
                // Solicitam numele clientului pentru comanda
                string numeClient;
                cout << "Introdu numele clientului: ";
                getline(cin, numeClient);

                // Cream o noua comanda pentru clientul specificat
                Comanda comandaNoua(numeClient);

                // Incarcam produsele disponibile pentru orasul curent si le afisam
                cafenea.incarcaProduseDinFisier();
                cafenea.afiseazaProduseDisponibile();

                // Adaugam produse la comanda
                string numeProdus;
                int cantitate;

                while (true)
                {
                    cout << "Nume produs (sau 'stop' pentru a finaliza comanda): ";
                    getline(cin, numeProdus);

                    // Daca utilizatorul introduce "stop", iesim din bucla
                    if (numeProdus == "stop")
                    {
                        break;
                    }

                    // Cautam produsul specificat
                    Produs *produs = cafenea.cautaProdus(numeProdus);
                    if (!produs)
                    {
                        cout << "Produsul nu a fost gasit in orasul " << cafenea.getOras() << ".\n";
                        continue;
                    }

                    // Solicitam cantitatea dorita
                    cout << "Cantitate: ";
                    cin >> cantitate;
                    cin.ignore();

                    // Adaugam produsul la comanda
                    comandaNoua.adaugaProdus(produs, cantitate);
                    cout << "Produsul a fost adaugat la comanda.\n";
                }

                // Afisam comanda inainte de finalizare
                comandaNoua.afiseazaComanda();

                // Salvam comanda in fisier
                cafenea.adaugaComandaInFisier(comandaNoua);
                break;
            }
            case 2: // Elimina comanda
            {
                // Solicitam numele clientului pentru comanda de eliminat
                string nume;
                cafenea.afiseazaComenzi();
                cout << "Nume client pentru comanda de eliminat: ";
                getline(cin, nume);
                cafenea.eliminaComandaDinFisier(nume);
                break;
            }
            case 3: // Afiseaza comenzile
                cafenea.afiseazaComenzi();
                break;
            case 4: // Modifica comanda
            {
                // Solicitam numele clientului pentru comanda de modificat
                string numeClient;
                cafenea.afiseazaComenzi();
                cout << "Introdu numele clientului pentru a modifica comanda: ";
                getline(cin, numeClient);
                cafenea.modificaComandaInFisier(numeClient);
                break;
            }
            case 5: // Inapoi la meniul principal
                cout << "Revenire la meniul principal." << endl;
                break;
            default: // Optiune invalida
                cout << "Optiune invalida!" << endl;
                break;
            }
        }
        catch (exception &e)
        {
            // Afișam eroarea daca apare
            cout << "Eroare: " << e.what() << endl;
            cout << "Te rugam sa introduci un numar intre 1 si 5." << endl;
        }
    } while (optiune != 5); // Repetam pana cand utilizatorul alege sa se intoarca la meniul principal
}

// Functia care gestioneaza meniul evenimentelor
void meniuEvenimente(Cafenea cafenea)
{
    int optiune; // Optiunea selectata de utilizator
    do
    {
        try
        {
            // Afisam meniul pentru gestionarea evenimentelor
            cout << "\n========== Meniu Evenimente ==========" << endl;
            cout << "1. Adauga Eveniment" << endl;
            cout << "2. Elimina Eveniment" << endl;
            cout << "3. Afiseaza Evenimente" << endl;
            cout << "4. Modifica Eveniment" << endl;
            cout << "5. Inapoi la Meniul Principal" << endl;
            cout << "=====================================" << endl;
            cout << "Alege o optiune: ";

            // Validare pentru introducerea optiunii
            string input;
            cin >> input;
            cin.ignore();

            // Verificam daca input-ul contine doar cifre
            for (char c : input)
            {
                if (!isdigit(c))
                {
                    throw std::invalid_argument("Optiunea introdusa nu este un numar valid.");
                }
            }

            // Convertim input-ul in int
            optiune = stoi(input);

            switch (optiune)
            {
            case 1: // Adauga eveniment
            {
                string numeEveniment, data;
                double cost;

                // Solicitam datele pentru eveniment
                cout << "Nume eveniment: ";
                getline(cin, numeEveniment);
                cout << "Data (YYYY-MM-DD): ";
                getline(cin, data);
                cout << "Cost: ";
                cin >> cost;
                cin.ignore();

                // Cream un obiect de tip Eveniment si il adaugam in fisier
                Eveniment evenimentNou(numeEveniment, data, cost);
                cafenea.adaugaEvenimentInFisier(evenimentNou);
                break;
            }
            case 2: // Elimina eveniment
            {
                string nume;
                // Afisam evenimentele existente
                cafenea.afiseazaEvenimente();
                cout << "Nume eveniment: ";
                getline(cin, nume);

                // Stergem evenimentul specificat
                cafenea.eliminaEvenimentDinFisier(nume);
                break;
            }
            case 3: // Afiseaza evenimente
                cafenea.afiseazaEvenimente();
                break;
            case 4: // Modifica eveniment
            {
                string nume;
                // Afisam evenimentele existente
                cafenea.afiseazaEvenimente();
                cout << "Nume eveniment pentru modificare: ";
                getline(cin, nume);

                string atribut, nouaValoare;
                // Solicitam atributul de modificat si noua valoare
                cout << "Alege atributul de modificat (nume/data/cost): ";
                getline(cin, atribut);

                cout << "Introduce noua valoare pentru " << atribut << ": ";
                getline(cin, nouaValoare);

                // Modificam atributul in fisier
                cafenea.modificaEvenimentInFisier(nume, atribut, nouaValoare);
                break;
            }
            case 5: // Revenire la meniul principal
                cout << "Revenire la meniul principal." << endl;
                break;
            default: // Optiune invalida
                cout << "Optiune invalida!" << endl;
                break;
            }
        }
        catch (exception &e)
        {
            // Afișam eroarea daca apare
            cout << "Eroare: " << e.what() << endl;
            cout << "Te rugam sa introduci un numar intre 1 si 5." << endl;
        }
    } while (optiune != 5); // Repetam pana cand utilizatorul alege sa se intoarca la meniul principal
}

// Functie pentru gestionarea meniului de rapoarte
void meniuRapoarte(Cafenea cafenea)
{
    int optiune; // Optiunea selectata de utilizator
    do
    {
        try
        {
            // Afisam meniul pentru gestionarea rapoartelor
            cout << "\n========== Meniu Rapoarte ==========\n";
            cout << "1. Genereaza Raport in CSV (Venituri, Cheltuieli, Profit)\n";
            cout << "2. Vizualizeaza Raport din CSV\n";
            cout << "3. Inapoi la Meniul Principal\n";
            cout << "====================================\n";
            cout << "Alege o optiune: ";

            string input;
            cin >> input;
            cin.ignore();

            // Validam input-ul: verificam daca contine doar cifre
            for (char c : input)
            {
                if (!isdigit(c))
                {
                    throw invalid_argument("Optiunea introdusa nu este un numar valid.");
                }
            }

            // Convertim input-ul in int
            optiune = stoi(input);

            switch (optiune)
            {
            case 1: // Generare raport in CSV
            {
                // Incarcam evenimentele si angajatii din fisiere
                vector<Eveniment> evenimente = cafenea.incarcaEvenimenteDinFisier();
                vector<Angajat *> angajati = cafenea.incarcaAngajatiDinFisier();

                // Calculam veniturile, cheltuielile si profitul
                double venituri = Rapoarte::calculeazaVenituri(cafenea.getOras());
                double cheltuieli = Rapoarte::calculeazaCheltuieli(evenimente, angajati);
                double profit = venituri - cheltuieli;

                // Deschidem fisierul raport.csv pentru scriere
                ofstream fout("../data/raport.csv");
                if (!fout)
                {
                    cerr << "Eroare la crearea fisierului raport.csv\n";
                    break;
                }

                // Scriem datele calculate in fisier
                fout << "Venituri,Cheltuieli,Profit\n";
                fout << venituri << "," << cheltuieli << "," << profit << "\n";

                fout.close();
                cout << "Raportul a fost generat cu succes.\n";
                break;
            }
            case 2: // Vizualizare raport din CSV
            {
                // Deschidem fisierul raport.csv pentru citire
                ifstream fin("../data/raport.csv");
                if (!fin)
                {
                    cerr << "Eroare la deschiderea fisierului raport.csv\n";
                    break;
                }

                // Afisam continutul fisierului linie cu linie
                string linie;
                while (getline(fin, linie))
                {
                    cout << linie << "\n";
                }

                fin.close();
                break;
            }
            case 3: // Revenire la meniul principal
                cout << "Revenire la meniul principal.\n";
                break;
            default: // Optiune invalida
                cout << "Optiune invalida!\n";
                break;
            }
        }
        catch (exception &e)
        {
            // Gestionam erorile si afisam mesajul corespunzator
            cout << "Eroare: " << e.what() << endl;
            cout << "Te rugam sa introduci un numar intre 1 si 3." << endl;
        }
    } while (optiune != 3); // Repetam pana cand utilizatorul alege sa revina la meniul principal
}

int main()
{
    set<string> oraseDisponibile = {"Bucuresti", "Brasov", "Craiova", "Cluj", "Severin"};
    string oras;
    cout << "Orase disponibile:\nBucuresti\nBrasov\nCraiova\nCluj\nSeverin\n";
    cout << "Introduceti orasul cafenelei pe care doriti sa o gesionati:\n";
    do
    {
        getline(cin, oras);
        if (oraseDisponibile.find(oras) == oraseDisponibile.end())
        {
            cout << "Oras invalid! Te rugam sa alegi unul dintre orasele disponibile:\n";
        }
    } while (oraseDisponibile.find(oras) == oraseDisponibile.end());
    Cafenea cafenea(oras);
    cout << "Ai selectat cafeneaua din orasul: " << oras << "\n";

    int optiune;

    do
    {
        try
        {
            afiseazaMeniuPrincipal();

            // Validare introducere optiune
            string input;
            cin >> input;
            cin.ignore(); // Ignor newline-ul ramas

            // Verificam daca input-ul este numeric
            for (char c : input)
            {
                if (!isdigit(c))
                {
                    throw invalid_argument("Optiunea introdusa nu este un numar valid.");
                }
            }

            // Conversie input la int
            optiune = stoi(input);

            switch (optiune)
            {
            case 1:
                meniuAngajati(cafenea);
                break;
            case 2:
                meniuProduse(cafenea);
                break;
            case 3:
                meniuComenzi(cafenea);
                break;
            case 4:
                meniuEvenimente(cafenea);
                break;
            case 5:
                meniuRapoarte(cafenea);
            case 6:
                cout << "Iesire din aplicatie. La revedere!\n";
                break;
            default:
                cout << "Optiune invalida! Te rugam sa alegi din nou.\n";
                break;
            }
        }
        catch (exception &e)
        {
            // Prindem exceptiile si afisam mesajul de eroare
            cout << "Eroare: " << e.what() << "\n";
            cout << "Te rugam sa introduci un numar intre 1 si 5.\n";
        }
    } while (optiune != 6);

    return 0;
}