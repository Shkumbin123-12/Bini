#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Enumeracion për statusin e projektit
enum StatusiProjektit {
    I_Nisur,
    I_Perkryer,
    I_Penduar
};

// Struktura për të përfaqësuar një dizajner
struct Dizajner {
    int id;
    string emri;
    string pozita;
    vector<string> projektet;  // Projekte që ka bërë dizajneri
};

// Funksion për të shfaqur statusin e projektit si tekst
string merrStatusinSiTekst(StatusiProjektit statusi) {
    switch (statusi) {
        case I_Nisur: return "I Nisur";
        case I_Perkryer: return "I Perkryer";
        case I_Penduar: return "I Penduar";
        default: return "I Panjohur";
    }
}

// Funksion për të shtuar një dizajner
void shtoDizajner(vector<Dizajner>& dizajneret, int id, string emri, string pozita) {
    dizajneret.push_back({id, emri, pozita});
}

// Funksion për të shtuar një projekt për një dizajner
void shtoProjekt(vector<Dizajner>& dizajneret, int idDizajneri, string projekti) {
    for (auto& dizajner : dizajneret) {
        if (dizajner.id == idDizajneri) {
            dizajner.projektet.push_back(projekti);
            cout << "Projekti " << projekti << " eshte shtuar per dizajnerin " << dizajner.emri << endl;
            return;
        }
    }
    cout << "Dizajneri nuk u gjet.\n";
}

// Funksion për të shfaqur të gjithë dizajnerët dhe projektet e tyre
void shfaqDizajneret(const vector<Dizajner>& dizajneret) {
    cout << "\n---------------------------------------------------------------------------------\n";
    cout << left << setw(10) << "ID" << setw(30) << "Emri" << setw(25) << "Pozita" << "Projekte" << endl;
    cout << "---------------------------------------------------------------------------------\n";
    
    for (const auto& dizajner : dizajneret) {
        cout << left << setw(10) << dizajner.id << setw(30) << dizajner.emri
             << setw(25) << dizajner.pozita;
        if (dizajner.projektet.empty()) {
            cout << "Nuk ka projekte.\n";
        } else {
            for (const auto& projekti : dizajner.projektet) {
                cout << projekti << " ";
            }
            cout << endl;
        }
    }
    cout << "---------------------------------------------------------------------------------\n";
}

// Funksion për të përditësuar statusin e një projekti të dizajnerit
void ndryshoStatusinProjektit(vector<Dizajner>& dizajneret, int idDizajneri, string projekti, StatusiProjektit statusi) {
    for (auto& dizajner : dizajneret) {
        if (dizajner.id == idDizajneri) {
            for (auto& p : dizajner.projektet) {
                if (p == projekti) {
                    cout << "Statusi i projektit " << projekti << " per dizajnerin " << dizajner.emri 
                         << " eshte ndryshuar ne: " << merrStatusinSiTekst(statusi) << endl;
                    return;
                }
            }
            cout << "Projekti nuk u gjet per dizajnerin.\n";
            return;
        }
    }
    cout << "Dizajneri nuk u gjet.\n";
}

// Funksioni kryesor
int main() {
    vector<Dizajner> dizajneret;

    // Shto disa dizajnerë
    shtoDizajner(dizajneret, 1, "Dizajner A", "Grafik");
    shtoDizajner(dizajneret, 2, "Dizajner B", "Web");
    shtoDizajner(dizajneret, 3, "Dizajner C", "Produkt");

    // Shto projekte për dizajnerët
    shtoProjekt(dizajneret, 1, "Logo ABC");
    shtoProjekt(dizajneret, 2, "Website XYZ");
    shtoProjekt(dizajneret, 3, "Dizajn Produkti 123");

    // Shfaq dizajnerët dhe projektet
    shfaqDizajneret(dizajneret);

    // Ndrysho statusin e një projekti
    cout << "\nNdrysho statusin e projektit 'Logo ABC' për Dizajnerin A:\n";
    ndryshoStatusinProjektit(dizajneret, 1, "Logo ABC", I_Perkryer);

    // Shfaq dizajnerët përsëri
    cout << "\nLista pas ndryshimit të statusit:\n";
    shfaqDizajneret(dizajneret);

    return 0;
}
