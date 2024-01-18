#include <iostream> //: Uključuje biblioteku za standardni unos/izlaz u
#include <conio.h> // Uključuje biblioteku za funkcije vezane za tastaturu i ekran ( nije standardna biblioteka i može se ponašati različito na različitim kompajlerima)
#include <string> //Uključuje biblioteku za rad sa stringovima.
#include <vector> //Uključuje biblioteku za rad sa vektorima, koji su dinamički nizovi
#include <windows.h>
#include <iomanip> // Uključuje biblioteku za manipulaciju ulazno-izlaznim operacijama, poput postavljanja širine ispisa
#include <fstream> // Uključuje biblioteku za rad sa datotekama
#include <chrono> //: Uključuje biblioteku za rad s vremenskim funkcijama
#include <thread> // Uključuje biblioteku za rad s nitima (multithreading)
#include <CallFunky.h>
using namespace std;


struct KorisnickiPodaci {
    string korisnickoIme;
    string lozinka;
};

const KorisnickiPodaci adminPodaci = {"admin", "admin"};


//Klasa Korisnik
class Korisnik{

private:
    string Ime,Prezime,Datum_Rodenja,Tekuci_Racun, JMBG, Drzavljanstvo;
     double tekuciRacun;
    vector<double> transakcije;




public:
    //Ovdje se nalazi seteri
    void setime(string a){Ime = a;}
    void setprezime(string b){Prezime = b;}
    void setdate(string c){Datum_Rodenja = c;}
    void setisbn (string d){Tekuci_Racun = d;}
    void setJMBG (string e){JMBG = e;}
    void setdrzavljanstvo(string f){Drzavljanstvo = f;}

    //A dok su ovdje nalaze geteri
    string getime(){return Ime;}
    string getprezime(){return Prezime;}
    string getdate(){return Datum_Rodenja;}
    string getisbn(){return Tekuci_Racun;}
    string getJMBG(){return JMBG;}
    string getDrzavljanstvo() {return Drzavljanstvo;}

void uplata(double iznos) {
        tekuciRacun += iznos;
        transakcije.push_back(iznos);
    }

    // Izvrsi isplatu sa tekuceg racuna
    void isplata(double iznos) {
        // Implementirajte isplatu prema vašim pravilima
        // Ovdje možete dodati validaciju i slično
        tekuciRacun -= iznos;
        transakcije.push_back(-iznos); // Dodajemo negativnu vrijednost za isplate
    }
vector<double> getPregledTransakcija() const {
        return transakcije;
    }

    // Pregled stanja na tekucem racunu
    double pregledStanja() {

        return 0.0;
    }


};
//Ovdje se nalazi klasa 2. Radnik
class Radnik{

private:
    string ime, prezime, jmbg, tekuci, spol, tekuci_Racun;

     double tekuciRacun;
    vector<double> transakcije;


public:
    void setName (string Ime) {ime = Ime;}
    void setForname(string Prezime) {prezime = Prezime;}
    void setJMBG (string jmbG) {jmbg = jmbG;}
    void setTekuci (string TekUci) {tekuci = TekUci;}
    void setSpol (string Spol) {spol = Spol;}


    string getName() {return ime;}
    string getForname(){return prezime;}
    string getJMBG(){return jmbg;}
    string getTekuci(){return tekuci;}
    string getSpol(){return spol;}

    void uplata(double iznos) {
        tekuciRacun += iznos;
        transakcije.push_back(iznos);
    }
    // Izvrsi isplatu sa tekuceg racuna
    void isplata(double iznos) {
        // Implementirajte isplatu prema vašim pravilima
        // Ovdje možete dodati validaciju i slično
        tekuciRacun -= iznos;
        transakcije.push_back(-iznos); // Dodajemo negativnu vrijednost za isplate
    }
    vector<double> getPregledTransakcija() const {
        return transakcije;
    }

    // Pregled stanja na tekucem racunu
    double pregledStanja() {
        return 0.0; // Placeholder value; replace it with the actual balance
    }
};



void Menig() { // Glavna funk koja se poziva u meni funkciju
    cout << "Upravljanje radom banke "<< endl;

    cout << "\n\n" << endl;

    cout << "\t[1] | Korisnik | \n";
    cout << "\t[2] | Radnik   |  \n";
    cout << "\t[3] | Transakcija Korsnika  | \n"; // Dodana nova opcija
    cout << "\t[4] | Transakcija Radnika  | \n"; // Dodana nova opcija
    cout << "\t[5] | EXIT     | \n\n";

    cout << "\n\n" << endl;
    cout << "Unesite svoj zeljeni izbor: \n\a" << endl;
}


void AddKorisnika(int nesto);
void EditKorisnika(int nesto);
void ViewPogledajKosinika(int nesto);
void ObrisiKorisnika(int nesto);
void quit();
void prikaziPomoc();
void AddRadnika(int nesto);
void EditRadnika(int nesto);
void DeleteRadnika(int nesto);
void ViewRadnika(int nesto);
void prikaziPomocRadnika();
void transakcijeKorisnika(Korisnik korisnici[], int brojKorisnika);
void pregledTabeleTransakcija(Korisnik korisnici[], int brojKorisnika);
void transakcijeRadnika(Radnik radnik[], int brojRadnika);
void pregledTabeleTransakcijaRadnika(Radnik radnik[], int brojRadnika);
bool ProvjeriLogin();
//Brojac u ovom slucaju je nesto
int nesto = 0;



//Funkcija koja ce povecanje brojaca
void increment(int a){
	a++;
	nesto=a;
}
//Funkcija koja ce smanjuje brojaca
void decrment(int a){
a--;
nesto = a;}


//Ogranicavanje broja unesenih Radnika i Korisnika
Korisnik korisnik [15];
Radnik radnik [15];


int main(){
system("Color 0A");


 /*if (!ProvjeriLogin()) {
        cout << "Ne/*uspjela prijava. Program se zatvara.\n";
        return 0;
    }*/

//ovdje smo stavaili brojac za switch da budne izborMoj
int izbormoj;

system("CLS");
Menig();
cin>>izbormoj;
system("CLS");
bool izlaz(false);

    do{
        switch(izbormoj){

    case 1:
        //system("CLS");. Ova naredba se koristi u C++ programima kako bi se očistio sadržaj konzole
        system("CLS");
        cout<<"Korisnik:\n\a";
        cout<<"| [1] Dodaj  Korisnika: \n\a";
        cout<<"| [2] Uredi  Korsinika: \n\a";
        cout<<"| [3] Obrisi  Korisnika: \n\a";
        cout<<"| [4] Pregledaj mi sve Korisnike \n\a";
        cout<<"| [5] Nazad na glavni Main \n\a";
        cout<<"| [6] Exit \n\a";
        cout<<"| [7] Pomoć \n";

        int izbor;
        cout<< "Unesite izbor: \n\a";
        cin>>izbor;
        system("CLS");
        switch(izbor){
        case 1:
//        AddKorisnika(nesto);
            break;
        case 2:
        EditKorisnika(nesto);
            break;
        case 3:
        ObrisiKorisnika(nesto);
            break;
            case 4:
        ViewPogledajKosinika(nesto);
            break;
            case 5:
        main();
            break;
            case 6:
        quit();
            break;
            case 7:
        prikaziPomoc();
            break;
            default:
                cout<<"Poresan unos. \n\n\a Pritisnite bilo koji taster da nastavite..."<<endl;
                _getch();
                main();
                break;
        }
        //E sada nam slijedi case 2 za radnika
            case 2:
                cout<<"Radnik \n\n";
                cout<< "| [1] Dodaj Radnika\n\a";
                cout<< "| [2] Izbrisi Radnika \n\a";
                cout<< "| [3] Uredi Ranika \n\a";
                cout<< "| [4] Pronadi sve Radnike \n\a";
                cout<< "| [5] Nazad na glavni Main \n\a";
                cout<< "| [6] Exit \n\a";
                cout<<"| [7] Pomoć \n";
                cout<<"Unesite izbor: ";
                cin>>izbor;
                system("CLS");
                switch(izbor){
            case 1:
                AddRadnika(nesto);
                break;
            case 2:
              DeleteRadnika(nesto);
                break;
            case 3:
                EditRadnika(nesto);;
                break;
            case 4:
                ViewRadnika(nesto);
                break;
            case 5:
                main();
                break;
            case 6:
               quit();
            case 7:
                prikaziPomocRadnika();
                break;
            default:
                    cout<<"Pogresan unos.\n\n Pritisnite bilo koji taster da nastavite..."<<endl;
            _getch();
            main();
            break;
                }
            case 3:
                transakcijeKorisnika(korisnik, nesto);
                break;
            case 4:
            transakcijeRadnika(radnik, nesto);
                break;
            case 5:
                quit();
                default:
                    cout<<"Pogresan unos.\n\n Pritisnite bilo koji taster da nastavite..."<<endl;
                    _getch();

                    main();
                    break;
        }
                    break;
            }while(!izlaz);{
            cout<< "THE END PROGRAM" <<endl;
            }
            _getch();
            return 0;
}


//Dodaj korisnika


void AddKorisnika(int nesto){

   string Ime,Prezime,Datum_Rodenja,Tekuci_Racun, JMBG, Drzavljanstvo;

    cout<<"Dodaj korisnika\n\n\a";
    if(nesto<15){
       cout<< "- Ime: ";
       cin>>Ime;

       cout<< "- Prezime: ";
       cin>> Prezime;

       cout <<"- Datum_Rodenja:";
       cin>> Datum_Rodenja;

       cout <<"- Drzavljanstvo";
       cin>> Drzavljanstvo;
       cout<< "- Tekuci_Racun: ";
       cin>> Tekuci_Racun;


       while(JMBG.length() !=5){
        cout<< "- Unesite JMBG: ";
        cin>>JMBG;

        if(JMBG.length() !=5){
           cout<<"JMBG mora imati 13 cifara"<<endl;
                cout<<"Ponovo unesite JMBG: ";
                cin>>JMBG;
        }
       }
       while(Tekuci_Racun.length() !=5){
        cout<< "Tekuci_Racun mora imati 16 cifara ";
        cin>>Tekuci_Racun;

        if(Tekuci_Racun.length() !=5){
           cout<<"Tekuci_Racun mora imati 16 cifara"<<endl;
                cout<<"Ponovo unesite Tekuci_Racun: ";
                cin>>Tekuci_Racun;
        }
       }
		korisnik[nesto].setime(Ime);
		korisnik[nesto].setprezime(Prezime);
		korisnik[nesto].setJMBG(JMBG);
		korisnik[nesto].setdate(Datum_Rodenja);
        korisnik[nesto].setisbn(Tekuci_Racun);
        korisnik[nesto].setdrzavljanstvo(Drzavljanstvo);
	increment(nesto);	//pozivanje funkcije za povecanje brojaca
		cout<<"\nKORISNIK USPJESNO DODAN!\n\nPritisnite bilo koji taster da nastavite . . .";
		_getch();
		main();
	}
	else{
		cout<<"DOSEGLI STE MAKSIMALNI BROJ KORISNIKA KOJI SE MOGU DODATI!\n\nPritisnite bilo koji taster da nastavite . . .";
		_getch();
		main();
	}
}

void transakcijeKorisnika(Korisnik korisnici[], int brojKorisnika) {

    string jmbg;
    cout << "Unesite JMBG korisnika: ";
    cin >> jmbg;

    bool pronadjen = false;
    int indeksKorisnika;

    // Pronađi korisnika s unesenim JMBG-om
    for (int i = 0; i < brojKorisnika; ++i) {
        if (korisnici[i].getJMBG() == jmbg) {
            pronadjen = true;
            indeksKorisnika = i;
            break;
        }
    }

    if (pronadjen) {
        int izbor;
        do {
            // Prikazi izbor za transakcije
            cout << "\n[1] Uplata\n[2] Isplata\n[3] Pregled transakcija pojedinog korisnika\n[4] Pregled tabele transakcija za sve korisnike\n[5] Nazad na glavni meni\n";
            cout << "Unesite izbor: ";
            cin >> izbor;

            switch (izbor) {
                 case 1: {
    // Unesite iznos uplate
    double iznosUplate;
    cout << "Unesite iznos uplate: ";
    cin >> iznosUplate;

    // Izvrši uplatu
    korisnici[indeksKorisnika].uplata(iznosUplate);
    cout << "Uplata uspješno izvršena.\n";

    // Prikazi novo stanje računa
    double novoStanje = korisnici[indeksKorisnika].pregledStanja();


    break;}
                case 2: {
    // Unesite iznos isplate
    double iznosIsplate;
    cout << "Unesite iznos isplate: ";
    cin >> iznosIsplate;

    // Izvrši isplatu
    korisnici[indeksKorisnika].isplata(iznosIsplate);
    cout << "Isplata uspješno izvršena.\n";

    // Prikazi novo stanje računa
    double novoStanje = korisnici[indeksKorisnika].pregledStanja();


    break;
}
                case 3: {
                    // Pregled transakcija pojedinog korisnika
                    cout << "Transakcije korisnika:\n";
                    auto transakcije = korisnici[indeksKorisnika].getPregledTransakcija();
                    for (double transakcija : transakcije) {
                        if (transakcija > 0) {
                            cout << "Uplata: " << transakcija << endl;
                        } else {
                            cout << "Isplata: " << -transakcija << endl;
                        }
                    }
                    break;
                }
                case 4: {
                    // Prikazi tabelu transakcija za sve korisnike
                    pregledTabeleTransakcija(korisnici, brojKorisnika);
                    break;
                }
                case 5:
                    main();
                    break;
                default:
                    cout << "Pogrešan izbor. Molimo pokušajte ponovo.\n";
                    break;
            }
        } while (izbor != 5);
    } else {
        cout << "Korisnik s unesenim JMBG-om nije pronađen.\n";
        main();
    }
}


void pregledTabeleTransakcija(Korisnik korisnici[], int brojKorisnika) {
    // Otvaranje fajla za pisanje
    ofstream izvestaj("izvestaj.txt");

    // Postavljanje širina za svaki deo tabele
    const int sirinaIme = 20;
    const int sirinaPrezime = 20;
    const int sirinaJMBG = 15;
    const int sirinaRacun = 20;
    const int sirinaTransakcije = 20;
    const int sirinaDrzavljanstvo = 20;

    // Prikazi zaglavlje tabele u konzoli
    cout << left << setw(sirinaIme) << "Ime"
         << setw(sirinaPrezime) << "Prezime"
         << setw(sirinaJMBG) << "JMBG"
         << setw(sirinaRacun) << "Tekuci Racun"
         << setw(sirinaTransakcije) << "Transakcije"
         << setw(sirinaDrzavljanstvo) << "Državljanstvo" << endl;

    // Linija razdvajanja između zaglavlja i podataka
    cout << setfill('-') << setw(sirinaIme + sirinaPrezime + sirinaJMBG + sirinaRacun + sirinaTransakcije + sirinaDrzavljanstvo) << "-" << setfill(' ') << endl;

    // Prikazi transakcije za svakog korisnika i upisivanje u fajl
    for (int i = 0; i < brojKorisnika; ++i) {
        cout << left << setw(sirinaIme) << korisnici[i].getime()
             << setw(sirinaPrezime) << korisnici[i].getprezime()
             << setw(sirinaJMBG) << korisnici[i].getJMBG()
             << setw(sirinaRacun) << korisnici[i].getisbn()
             << setw(sirinaDrzavljanstvo) << korisnici[i].getDrzavljanstvo();

        izvestaj << korisnici[i].getime() << " " << korisnici[i].getprezime() << " " << korisnici[i].getJMBG() << " " << korisnici[i].getisbn();

        auto transakcije = korisnici[i].getPregledTransakcija();
        for (double transakcija : transakcije) {
            if (transakcija > 0) {
                cout << " Uplata: " << transakcija;
                izvestaj << " Uplata: " << transakcija << ",";
            } else {
                cout << " Isplata: " << -transakcija;
                izvestaj << " Isplata: " << -transakcija << ",";
            }
        }

        cout << endl;
        izvestaj << endl;
    }

    // Linija razdvajanja između tabele i poruke
    cout << setfill('-') << setw(sirinaIme + sirinaPrezime + sirinaJMBG + sirinaRacun + sirinaTransakcije + sirinaDrzavljanstvo) << "-" << setfill(' ') << endl;

    // Zatvaranje fajla
    izvestaj.close();

    cout << "Izvestaj je sacuvan u izvestaj.txt" << endl;

    // Automatsko otvaranje izveštaja u Notepad-u
    cout << "Da li želite otvoriti izveštaj u Notepad-u? (da/ne): ";
    string odgovor;
    cin >> odgovor;

    if (odgovor == "da" || odgovor == "Da" || odgovor == "DA") {
        // Koristimo system poziv za otvaranje Notepad-a
        system("notepad izvestaj.txt");
    } else {
        return;  // Napuštanje trenutne funkcije (vraca na opcije)
    }
}

void Uplata(Korisnik& korisnik) {
    double iznos;
    cout << "Unesite iznos uplate: ";
    cin >> iznos;
    korisnik.uplata(iznos);
    cout << "Uplata uspjesno izvrsena.\n";
}
void Isplata(Korisnik& korisnik) {
    double iznos;
    cout << "Unesite iznos isplate: ";
    cin >> iznos;
    korisnik.isplata(iznos);
    cout << "Isplata uspjesno izvrsena.\n";
}
void PregledStanja(Korisnik& korisnik) {
    double stanje = korisnik.pregledStanja();
    cout << "Stanje na tekucem racunu: " << stanje << "\n";
}
void transakcijeRadnika(Radnik radnik[], int brojRadnika){
    string jmbg;
    cout << "Unesite JMBG radnika: ";
    cin >> jmbg;

    bool pronadjen = false;
    int indeksRadnika;

    // Pronađi korisnika s unesenim JMBG-om
    for (int i = 0; i < brojRadnika; ++i) {
        if (radnik[i].getJMBG() == jmbg) {
            pronadjen = true;
            indeksRadnika = i;
            break;
        }
    }

    if (pronadjen) {
        int izbor;
        do {
            // Prikazi izbor za transakcije
            cout << "\n[1] Uplata\n[2] Isplata\n[3] Pregled transakcija pojedinog radnika\n[4] Pregled tabele transakcija za sve korisnike\n[5] Nazad na glavni meni\n";
            cout << "Unesite izbor: ";
            cin >> izbor;

            switch (izbor) {
                 case 1: {
    // Unesite iznos uplate
    double iznosUplate;
    cout << "Unesite iznos uplate: ";
    cin >> iznosUplate;

    // Izvrši uplatu
    radnik[indeksRadnika].uplata(iznosUplate);
    cout << "Uplata uspješno izvršena.\n";

    // Prikazi novo stanje računa
    double novoStanje = radnik[indeksRadnika].pregledStanja();


    break;}
                case 2: {
    // Unesite iznos isplate
    double iznosIsplate;
    cout << "Unesite iznos isplate: ";
    cin >> iznosIsplate;

    // Izvrši isplatu
    radnik[indeksRadnika].isplata(iznosIsplate);
    cout << "Isplata uspješno izvršena.\n";

    // Prikazi novo stanje računa
    double novoStanje = radnik[indeksRadnika].pregledStanja();


    break;
}
                case 3: {
                    // Pregled transakcija pojedinog korisnika
                    cout << "Transakcije korisnika:\n";
                    auto transakcije = radnik[indeksRadnika].getPregledTransakcija();
                    for (double transakcija : transakcije) {
                        if (transakcija > 0) {
                            cout << "Uplata: " << transakcija << endl;
                        } else {
                            cout << "Isplata: " << -transakcija << endl;
                        }
                    }
                    break;
                }
                case 4: {
                    // Prikazi tabelu transakcija za sve korisnike
                      pregledTabeleTransakcijaRadnika(radnik, brojRadnika);
                    break;
                }
                case 5:
                    main();
                    break;
                default:
                    cout << "Pogrešan izbor. Molimo pokušajte ponovo.\n";
                    break;
            }
        } while (izbor != 5);
    } else {
        cout << "Radnik s unesenim JMBG-om nije pronađen.\n";
        main();
    }
}
void pregledTabeleTransakcijaRadnika(Radnik radnici[], int brojRadnika) {
    // Otvaranje fajla za pisanje
    ofstream izvestaj("izvestaj_radnici.txt");

    // Postavljanje širina za svaki deo tabele
    const int sirinaIme = 20;
    const int sirinaPrezime = 20;
    const int sirinaJMBG = 15;
    const int sirinaRacun = 20;
    const int sirinaTransakcije = 20;

    // Prikazi zaglavlje tabele u konzoli
    cout << left << setw(sirinaIme) << "Ime"
         << setw(sirinaPrezime) << "Prezime"
         << setw(sirinaJMBG) << "JMBG"
         << setw(sirinaRacun) << "Tekuci Racun"
         << setw(sirinaTransakcije) << "Transakcije" << endl;

    // Linija razdvajanja između zaglavlja i podataka
    cout << setfill('-') << setw(sirinaIme + sirinaPrezime + sirinaJMBG + sirinaRacun + sirinaTransakcije) << "-" << setfill(' ') << endl;

    // Prikazi transakcije za svakog radnika i upisivanje u fajl
    for (int i = 0; i < brojRadnika; ++i) {
        cout << left << setw(sirinaIme) << radnici[i].getName()
             << setw(sirinaPrezime) << radnici[i].getForname()
             << setw(sirinaJMBG) << radnici[i].getJMBG()
             << setw(sirinaRacun) << radnici[i].getTekuci();

        izvestaj << radnici[i].getName() << " " << radnici[i].getForname() << " " << radnici[i].getJMBG() << " " << radnici[i].getTekuci();

        auto transakcije = radnici[i].getPregledTransakcija();
        for (double transakcija : transakcije) {
            if (transakcija > 0) {
                cout << " Uplata: " << transakcija;
                izvestaj << " Uplata: " << transakcija << ",";
            } else {
                cout << " Isplata: " << -transakcija;
                izvestaj << " Isplata: " << -transakcija << ",";
            }
        }

        cout << endl;
        izvestaj << endl;
    }

    // Linija razdvajanja između tabele i poruke
    cout << setfill('-') << setw(sirinaIme + sirinaPrezime + sirinaJMBG + sirinaRacun + sirinaTransakcije) << "-" << setfill(' ') << endl;

    // Zatvaranje fajla
    izvestaj.close();

    cout << "Izvestaj o radnicima je sacuvan u izvestaj_radnici.txt" << endl;

    // Automatsko otvaranje izveštaja u Notepad-u
    cout << "Da li želite otvoriti izveštaj o radnicima u Notepad-u? (da/ne): ";
    string odgovor;
    cin >> odgovor;

    if (odgovor == "da" || odgovor == "Da" || odgovor == "DA") {
        // Koristimo system poziv za otvaranje Notepad-a
        system("notepad izvestaj_radnici.txt");
    } else {
        return;  // Napuštanje trenutne funkcije (vraca na opcije)
    }
}


void Uplata(Radnik& radnik) {
    double iznos;
    cout << "Unesite iznos uplate: ";
    cin >> iznos;
    radnik.uplata(iznos);
    cout << "Uplata uspjesno izvrsena.\n";
}
void Isplata(Radnik& radnik) {
    double iznos;
    cout << "Unesite iznos isplate: ";
    cin >> iznos;
    radnik.isplata(iznos);
    cout << "Isplata uspjesno izvrsena.\n";
}
void PregledStanja(Radnik& radnik) {



    double stanje = radnik.pregledStanja();
    cout << "Stanje na tekucem racunu: " << stanje << "\n";
}
void ViewPogledajKosinika(int nesto) {
    cout << "POGLEDAJTE SVE KORISNIKE\n\n";

    if (nesto == 0) {
        cout << "Trenutno nema dodanih korisnika.\n\n Pritisnite bilo koji taster da nastavite... ";
        _getch();
        return;  // Exit the function if there are no users
    }

    // Zaglavlje tabele
    cout << setw(15) << "JMBG" << setw(15) << "Ime" << setw(15) << "Prezime" << setw(20) << "Datum_Rodenja" << setw(15) << "Tekuci_Racun" << setw(20) <<"Državljanstvo" << endl;

    for (int i = 0; i < nesto; i++) {
        // Podaci o korisniku
        cout << setw(15) << korisnik[i].getJMBG()
             << setw(15) << korisnik[i].getime()
             << setw(15) << korisnik[i].getprezime()
             << setw(20) << korisnik[i].getdate()
             << setw(15) << korisnik[i].getisbn()
             << setw(20) << korisnik[i].getDrzavljanstvo()<< endl;

        // Opcije transakcija za trenutnog korisnika
    }

    cout << " \n Pritisnite bilo koji taster da nastavite . . .";
    _getch();
    main();
}
void ObrisiKorisnika(int nesto){
string jmbg;
int izbo;
cout<< "Izbrisi korisnika \n\n";
if(nesto==0){
    	cout<<"NEMA KORISNIKA ZA BRISANJE!\n\nPritisnite bilo koji taster da nastavite . . .";
		_getch();
		main();
	}
cout<<"Unesite nam JMBG: ";
cin>>jmbg;
for(int i=0;i<nesto; i++){
    if(korisnik[i].getJMBG()==jmbg){
        cout<<"\n KORISNIK PRONADJEN \n\n";
        cout<<"Želite li izbrisati?\n[1]Da\n[2]Ne\n\nUnesite izbor: ";
        cin>>izbo;
        if(izbo == 1){
            korisnik[i].setime("");
            korisnik[i].setprezime("");
            korisnik[i].setJMBG("");
            for(int a=i;a<nesto;a++){

					korisnik[a] = korisnik[a+1];
				}
				korisnik[9].setime("");
				korisnik[9].setprezime("");
				korisnik[9].setJMBG("");

				decrment(nesto);
				cout<<"\nKORISNIK USPJEŠNO OBRISAN!\n\nPritisnite bilo koji taster da nastavite . . .";
				_getch();
				main();
			}
			else{
				main();
			}
		}
	}
	cout<<"\nKORISNIK NIJE PRONAĐEN!\n\nPritisnite bilo koji taster da nastavite . . .";
	_getch();
	main();
}
void EditKorisnika(int nesto) {
    system("CLS");
    string editjmbg, choice;
    string jmbg, ime, prezime;

    cout << "\n Uredi korisnika \n\n\a" << endl;
    if (nesto == 0) {
        cout << "Nema Korisnika za uredivanja! \n\n Pritisnite bilo koji taster da nastavite . . .";
        _getch();
        main();
    }
    cout << "Unesite JMBG korisnika kojeg želite urediti: ";
    cin >> editjmbg;
    for (int i = 0; i < nesto; i++) {
        if (korisnik[i].getJMBG() == editjmbg) {
            cout << "\nKORISNIK PRONADJEN\n\n";
            cout << "Želite li izmijeniti:\n[1] Ime\n[2] Prezime\n\nUnesite izbor: ";
            cin >> choice;
            if (choice == "1") {
                cout << "Unesite novo ime: ";
                cin >> ime;
                korisnik[i].setime(ime);
                cout << "\n Ime uspješno izmijenjeno!\n\n";
            } else if (choice == "2") {
                cout << " Unesite novo prezime: ";
                cin >> prezime;
                korisnik[i].setprezime(prezime);
                cout << "\n Prezime uspješno izmijenjeno!\n\n";
            }  else {
                cout << "\n Pogrešan izbor!\n\n";
            }
            cout << "Pritisnite bilo koji taster da nastavite . . .";
            _getch();
            main();
       }
    }
    }
void prikaziPomoc() {
    system("CLS");
    cout << "=====================\n";
    cout << "       POMOĆ\n";
    cout << "=====================\n";
    cout << "Opcija [1]: Dodaj mi korisnika - omogućava dodavanje novog korisnika.\n";
    cout << "Opcija [2]: Uredi mi korisnika - omogućava uređivanje podataka postojećeg korisnika.\n";
    cout << "Opcija [3]: Obriši mi korisnika - omogućava brisanje korisnika iz baze podataka.\n";
    cout << "Opcija [4]: Pregledaj mi sve korisnike - prikazuje sve korisnike u sustavu.\n";
    cout << "Opcija [5]: Nazad na glavni meni - vraća se na glavni izbornik.\n";
    cout << "Opcija [6]: Izlaz - zatvara program.\n";
    cout << "Opcija [7]: Pretraži korisnike - omogućava pretraživanje korisnika po određenim kriterijima.\n";
    cout << "Opcija [8]: Pomoć - prikazuje ovu pomoć.\n";
    cout << "=====================\n";
}
//AddUser funkcija


void AddRadnika(int nesto){
    string ime, prezime, jmbg, tekuci, spol;

    cout<<"DODAJ RADNIKA\n\n";
    if(nesto<10){
        cout<<"- Ime: ";
        cin>>ime;

        cout<<"- Prezime: ";
        cin>>prezime;

        cout<<"- Spol: ";  // Dodajte dvotačku nakon "Spol"
        cin>>spol;

        while(jmbg.length() != 13) {
            cout<<"- Unesite JMBG: ";
            cin>>jmbg;

            if(jmbg.length() != 13) {
                cout<<"JMBG mora imati 13 cifara"<<endl;
            }
        }

        while(tekuci.length() != 16) {
            cout<<"- Unesite Tekuci_racun: ";
            cin>>tekuci;

            if(tekuci.length() != 16) {
                cout<<"Tekuci_racun mora imati 16 cifara"<<endl;
            }
        }

        radnik[nesto].setName(ime);
        radnik[nesto].setForname(prezime);
        radnik[nesto].setJMBG(jmbg);
        radnik[nesto].setSpol(spol);
        radnik[nesto].setTekuci(tekuci);

        increment(nesto); // pozivanje funkcije za povecanje brojaca

        cout<<"\n RADNIK USPJESNO DODAN!\n\nPritisnite bilo koji taster da nastavite . . .";
        _getch();
        main();
    }
    else{
        cout<<"DOSEGLI STE MAKSIMALNI BROJ KORISNIKA KOJI SE MOGU DODATI!\n\nPritisnite bilo koji taster da nastavite . . .";
        _getch();
        main();
    }
}


void EditRadnika(int nesto) {
    system("CLS");
    string editjmbg, choice;
    string jmbg, ime, prezime, tekuci;
    cout << "\n Uredi radnika \n\n\a" << endl;
    if (nesto == 0) {
        cout << "Nema Radnika za uredivanja! \n\n Pritisnite bilo koji taster da nastavite . . .";
        _getch();
        main();
    }
    cout << "Unesite JMBG radnika kojeg želite urediti: ";
    cin >> editjmbg;
    for (int i = 0; i < nesto; i++) {
        if (radnik[i].getJMBG() == editjmbg) {
            cout << "\nRADNIK PRONADJEN\n\n";
            cout << "Želite li izmijeniti:\n[1] Ime\n[2] Prezime\n[3] Tekuci\n\nUnesite izbor: ";
            cin >> choice;
            if (choice == "1") {
                cout << "Unesite novo ime: ";
                cin >> ime;
                radnik[i].setName(ime);
                cout << "\nIme uspješno izmijenjeno!\n\n";
            } else if (choice == "2") {
                cout << "Unesite novo prezime: ";
                cin >> prezime;
                radnik[i].setForname(prezime);
                cout << "\nPrezime uspješno izmijenjeno!\n\n";
            } else if (choice == "3") {
                cout << "Unesite novi tekuci: ";
                cin >> tekuci;
                radnik[i].setTekuci(tekuci);
                cout << "\nTekuci uspješno izmijenjen!\n\n";
            } else {
                cout << "\nPogrešan izbor!\n\n";
            }
            cout << "Pritisnite bilo koji taster da nastavite . . .";
            _getch();
            main();
        }
    }
}
void ViewRadnika(int nesto) {
    cout << "POGLEDAJTE SVE RADNIKE\n\n";

    if (nesto == 0) {
        cout << "Trenutno nema dodanih radnika.\n\n Pritisnite bilo koji taster da nastavite... ";
        _getch();
        return;
    }

    // Zaglavlje tabele
    cout << setw(15) << "JMBG" << setw(15) << "Ime" << setw(15) << "Prezime" << setw(15) << "Spol" << setw(15)<< "Tekuci_racun" << setw(20) << "Državljanstvo" << endl;

    for (int i = 0; i < nesto; i++) {
        // Podaci o radniku
        cout << setw(15) << radnik[i].getJMBG()
             << setw(15) << radnik[i].getName()
             << setw(15) << radnik[i].getForname()
             << setw(15) << radnik[i].getSpol()
             << setw(15) << radnik[i].getTekuci()
             << setw(20) << "N/A" << endl;  // Državljanstvo nije dostupno za radnike

        // Opcije transakcija za trenutnog radnika
    }

    cout << " \n Pritisnite bilo koji taster da nastavite . . .";
    _getch();
    main();  // Pretpostavka: Nakon prikaza radnika, vraćate se u glavni meni
}


void DeleteRadnika(int nesto){
string jmbg;
int izbo;
cout<< "Izbrisi radnika \n\n";
if(nesto==0){
    	cout<<"NEMA RADNIKA ZA BRISANJE!\n\nPritisnite bilo koji taster da nastavite . . .";
		_getch();
		main();
	}
cout<<"Unesite nam JMBG: ";
cin>>jmbg;
for(int i=0;i<nesto; i++){
    if(radnik[i].getJMBG()==jmbg){
        cout<<"\n RADNIK PRONADJEN \n\n";
        cout<<"Želite li izbrisati?\n[1]Da\n[2]Ne\n\nUnesite izbor: ";
        cin>>izbo;
        if(izbo == 1){
            radnik[i].setName("");
            radnik[i].setForname("");
            radnik[i].setJMBG("");
            for(int a=i;a<nesto;a++){

					radnik[a] = radnik[a+1];
				}
				radnik[9].setName("");
				radnik[9].setForname("");
				radnik[9].setJMBG("");

				decrment(nesto);
				cout<<"\n RADNIKA USPJEŠNO OBRISAN!\n\nPritisnite bilo koji taster da nastavite . . .";
				_getch();
				main();
			}
			else{
				main();
			}
		}
	}
	cout<<"\n RADNIK NIJE PRONAĐEN!\n\nPritisnite bilo koji taster da nastavite . . .";
	_getch();
	main();

}

void prikaziPomocRadnika() {
    system("CLS");
    cout << "=====================\n";
    cout << "       POMOĆ\n";
    cout << "=====================\n";
    cout << "Opcija [1]: Dodaj mi radnika - omogućava dodavanje novog radnika.\n";
    cout << "Opcija [2]: Uredi mi radnika - omogućava uređivanje podataka postojećeg radnika.\n";
    cout << "Opcija [3]: Obriši mi radnika - omogućava brisanje radnika iz baze podataka.\n";
    cout << "Opcija [4]: Pregledaj mi sve radnike - prikazuje sve korisnike u sustavu.\n";
    cout << "Opcija [5]: Nazad na glavni meni - vraća se na glavni izbornik.\n";
    cout << "Opcija [6]: Izlaz - zatvara program.\n";
    cout << "Opcija [7]: Pretraži radnike - omogućava pretraživanje radnika po određenim kriterijima.\n";
    cout << "Opcija [8]: Pomoć - prikazuje ovu pomoć.\n";
    cout << "=====================\n";
}





/*
Ukratko, ova funkcija ispisuje poruku zahvale korisniku i odmah završava program sa statusom izlaza 1.
Ako želimo promeniti ponašanje programa prilikom izlaska,
možemo promjeniti vrijednost argumenta u _exit ili koristiti return umesto _exit u glavnoj funkciji main.
*/
void quit(){
cout<<"Hvala Vam sto ste koristili nas program \n\a";
_exit(1);
}





