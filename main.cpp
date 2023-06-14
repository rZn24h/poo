#include <iostream>
#include <fstream>

// Macro pentru culoarea albastru deschis
#define BLUE "\033[1;34m"
#define RESET "\033[0m"

using namespace std;

struct Joc {
    string nume;
    float pret;
};

struct User {
    string nume;
    string parola;
    string email;
};

// Functie pentru adaugarea unui joc
void AdaugareJoc(Joc joc) {
    ofstream file("jocuri.txt", ios::app);
    if (file.is_open()) {
        file << joc.nume << " " << joc.pret << endl;
        file.close();
        cout << "Joc adaugat cu succes!" << endl;
    } else {
        cout << "Eroare la deschiderea fisierului jocuri.txt" << endl;
    }
}

// Functie pentru stergerea unui joc
void StergereJoc(string numeJoc) {
    ifstream file("jocuri.txt");
    ofstream temp("temp.txt");
    string nume;
    float pret;

    if (file.is_open() && temp.is_open()) {
        bool jocGasit = false;
        while (file >> nume >> pret) {
            if (nume != numeJoc) {
                temp << nume << " " << pret << endl;
            } else {
                jocGasit = true;
            }
        }
        file.close();
        temp.close();

        if (jocGasit) {
            remove("jocuri.txt");
            rename("temp.txt", "jocuri.txt");
            cout << "Joc sters cu succes!" << endl;
        } else {
            remove("temp.txt");
            cout << "Jocul nu exista in lista." << endl;
        }
    } else {
        cout << "Eroare la deschiderea fisierelor jocuri.txt sau temp.txt" << endl;
    }
}

// Functie pentru afisarea tuturor jocurilor
void AfisareJocuri() {
    ifstream file("jocuri.txt");
    string nume;
    float pret;

    if (file.is_open()) {
        cout << "Jocuri disponibile:" << endl;
        while (file >> nume >> pret) {
            cout << "Nume: " << nume << ", Pret: " << pret << endl;
        }
        file.close();
    } else {
        cout << "Eroare la deschiderea fisierului jocuri.txt" << endl;
    }
}

// Functie pentru adaugarea unui utilizator
void AdaugareUser(User user) {
    ofstream file("users.txt", ios::app);
    if (file.is_open()) {
        file << user.nume << " " << user.parola << " " << user.email << endl;
        file.close();
        cout << "Utilizator adaugat cu succes!" << endl;
    } else {
        cout << "Eroare la deschiderea fisierului users.txt" << endl;
    }
}

// Functie pentru stergerea unui utilizator
void StergeUser(string numeUser) {
    ifstream file("users.txt");
    ofstream temp("temp.txt");
    string nume, parola, email;

    if (file.is_open() && temp.is_open()) {
        bool userGasit = false;
        while (file >> nume >> parola >> email) {
            if (nume != numeUser) {
                temp << nume << " " << parola << " " << email << endl;
            } else {
                userGasit = true;
            }
        }
        file.close();
        temp.close();

        if (userGasit) {
            remove("users.txt");
            rename("temp.txt", "users.txt");
            cout << "Utilizator sters cu succes!" << endl;
        } else {
            remove("temp.txt");
            cout << "Utilizatorul nu exista in lista." << endl;
        }
    } else {
        cout << "Eroare la deschiderea fisierelor users.txt sau temp.txt" << endl;
    }
}

// Functie pentru afisarea tuturor utilizatorilor
void AfisareUser() {
    ifstream file("users.txt");
    string nume, parola, email;

    if (file.is_open()) {
        cout << "Utilizatori:" << endl;
        while (file >> nume >> parola >> email) {
            cout << "Nume: " << nume << ", Parola: " << parola << ", Email: " << email << endl;
        }
        file.close();
    } else {
        cout << "Eroare la deschiderea fisierului users.txt" << endl;
    }
}

int main() {
    int optiune;
    Joc joc;
    User user;

    do {
        system("cls");
        cout << BLUE <<"==========================================" << endl;
        cout << BLUE <<"           MAGAZIN DE JOCURI VIDEO         " << endl;
        cout << BLUE <<"=========================================="<< RESET << endl;
        cout << BLUE <<"1. Adaugare joc" << endl;
        cout << BLUE <<"2. Stergere joc" << endl;
        cout << BLUE <<"3. Afisare jocuri" << endl;
        cout << BLUE <<"4. Adaugare utilizator" << endl;
        cout << BLUE <<"5. Stergere utilizator" << endl;
        cout << BLUE <<"6. Afisare utilizatori" << endl;
        cout << BLUE <<"0. Iesire" << endl;
        cout << BLUE <<"==========================================" << RESET << endl;
        cout << BLUE <<"Selecteaza o optiune: ";
        cin >> optiune;

        switch (optiune) {
            case 1:
                cout << "Introdu numele jocului: ";
                cin >> joc.nume;
                cout << "Introdu pretul jocului: ";
                cin >> joc.pret;
                AdaugareJoc(joc);
                break;
            case 2:
                cout << "Introdu numele jocului pentru stergere: ";
                cin >> joc.nume;
                StergereJoc(joc.nume);
                break;
            case 3:
                AfisareJocuri();
                system("pause");
                break;
            case 4:
                cout << "Introdu numele utilizatorului: ";
                cin >> user.nume;
                cout << "Introdu parola utilizatorului: ";
                cin >> user.parola;
                cout << "Introdu adresa de email a utilizatorului: ";
                cin >> user.email;
                AdaugareUser(user);
                break;
            case 5:
                cout << "Introdu numele utilizatorului pentru stergere: ";
                cin >> user.nume;
                StergeUser(user.nume);
                break;
            case 6:
                AfisareUser();
                system("pause");
                break;
            case 0:
                cout << "La revedere!";
                break;
            default:
                cout << "Optiune invalida. Selecteaza din nou." << endl;
        }

        cout << endl;
    } while (optiune != 0);

    return 0;
}
