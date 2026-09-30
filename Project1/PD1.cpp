#include <iostream>
#include <string>

using namespace std;

class CAutomobilis {

private: // Gali pasiekti pačios klasės metodai ir jai suteiktą prieigą turinčios friend funkcijos ar klasės

    string marke;  // Automobilio markė
    int pagaminimoMetai; // Pagaminimo metai
    double kaina;        // Kaina eurais
    char kategorija;     // Kategorijos raidė pvz C

protected: //Gali pasiekti pati klasė, jos friend ir išvestinės klasės pagal paveldėjimo prieigos taisykles

    //metodas nepasiekiamas is ()main, bet gali buti paveldetas, tiesiog isveda antraste
    void parodytiAntraste() const {
        cout << "+++DUOMENYS+++" << endl;
    }


public: //Kodas už klasės ribų, main() gali kurti objektus ir kviesti jų metodus.

    CAutomobilis() // Numatytasis konstruktorius: sukuria objektą be argumentu.
        : marke("Nezinoma"),
        pagaminimoMetai(0),
        kaina(0.0),
        kategorija('N') {
    }

    CAutomobilis(const string& naujaMarke, int metai, double naujaKaina, char naujaKategorija) // Konstruktorius su parametrais : leidžia nurodyti pradinius duomenis.
        : marke(naujaMarke),
        pagaminimoMetai(metai),
        kaina(naujaKaina),
        kategorija(naujaKategorija) {
    }

    CAutomobilis(const CAutomobilis& naujasAutomobilis) // Kopijavimo konstruktorius: sukuria objektą iš kito objekto.
        : marke(naujasAutomobilis.marke),
        pagaminimoMetai(naujasAutomobilis.pagaminimoMetai),
        kaina(naujasAutomobilis.kaina),
        kategorija(naujasAutomobilis.kategorija) {
    }

    // publik metodai keičia privačius objekto duomenis.

    void pakeistiMarke(const std::string& naujaMarke) { //marke
        marke = naujaMarke;
    }

    void pakeistiKaina(const double naujaKaina) { //kaina, isvedimu jei kaina ivesta neigiama
        if (naujaKaina >= 0.0) {
            kaina = naujaKaina;
        }
        else {
            cout << "Klaida: kaina negali buti neigiama" << endl;
        }
    }

    void pakeistiMetus(const int metai) { //metai
        if (metai >= 1900) {
            pagaminimoMetai = metai;
        }
        else {
            cout << "Klaida: metai negali buti ankstesni uz 1900" << endl;
        }
    }

    void pakeistiKategorija(const char naujaKategorija) { //kategorija
        kategorija = naujaKategorija;
    }

    void isvestiDuomenis() const { //duomenu isvedimas, iskviecia antraste is protected
        parodytiAntraste();
        cout << "Marke: " << marke << '\n'
            << "Pagaminimo metai: " << pagaminimoMetai << '\n'
            << "Kaina: " << kaina << " EUR" << '\n'
            << "Kategorija: " << kategorija << '\n' << endl;
    }

};

int main() {
    CAutomobilis pirmasAutomobilis; //sukuriamas numatytuoju konstruktoriumi
    pirmasAutomobilis.pakeistiMarke("Toyota"); //pakeiciama marke
    pirmasAutomobilis.pakeistiKaina(5000.0); //pakeiciama kaina

    CAutomobilis antrasAutomobilis("Volkswagen", 2010, 2000.0, 'C'); //sukuriamas su parametrais

    CAutomobilis treciasAutomobilis(antrasAutomobilis); //sukuriamas kopijuojant antra ir pakeiciant parametrus
    treciasAutomobilis.pakeistiKaina(6000.0);
    treciasAutomobilis.pakeistiMetus(2015);


    //spausdinimas i konsole
    cout << "Pirmas automobilis" << endl;
    pirmasAutomobilis.isvestiDuomenis();

    cout << "Antras automobilis" << endl;
    antrasAutomobilis.isvestiDuomenis();

    cout << "Trecias automobilis" << endl;
    treciasAutomobilis.isvestiDuomenis();

}

//Pakeitimas testui