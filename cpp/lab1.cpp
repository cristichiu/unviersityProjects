#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

class AbstractBase {
public:
    virtual void read() = 0;
    virtual void show() = 0;
    virtual int getElForSort() = 0;
    virtual string getElForFind() = 0;
    virtual string getElForDelete() = 0;
    virtual ~AbstractBase() {}
};

class Aeroport : public AbstractBase {
private: 
    string companyName;
    string date;
protected:
    string countryName;
    int raceNumber;
public:
    Aeroport(): companyName(""), date(""), countryName(""), raceNumber(0) {}
    Aeroport(string company, string data, string country, int courses): companyName(move(company)), date(move(data)), countryName(move(country)), raceNumber(courses) {}
    ~Aeroport() {}

    void read() override {
        setCompanyName();
        setDate();
        setCountryName();
        setRaceNumber();
    }
    void show() override {
        cout<<endl<<"=============================="<<endl<<"Nume companie: "<<getCompanyName()<<endl<<"Data infiintarii: "<<getDate()<<endl<<"Numele tarii: "<<getCountryName()<<endl<<"Numarul de curse: "<<getRaceNumber()<<endl<<"=============================="<<endl<<endl;
    }

    int getRaceNumber() const { return raceNumber; }
    const string& getCountryName() const { return countryName; }
    const string& getCompanyName() const { return companyName; }
    const string& getDate() const { return date; }

    string setCompanyName() { cout<<"Nume companie: "; cin>>companyName; return getCompanyName(); }
    string setDate() { cout<<"Data infiintarii: "; cin>>date; return getDate(); }
    string setCountryName() { cout<<"Numele tarii: "; cin>>countryName; return getCountryName(); }
    int setRaceNumber() { 
        cout<<"Numarul de curse: ";
        while(!(cin>>raceNumber)) { cout<<"Trebuie sa fie cifra (int): "; cin.clear(); cin.ignore(1000, '\n'); }
        return getRaceNumber();
    }
};

class Owner : virtual public Aeroport {
private:
    string x1; int x2;
protected:
    int x3;
public:
    Owner(): Aeroport(), x1(""), x2(0), x3(0) {}
    Owner(string company, string data, string country, int courses, string x1P, int x2P, int x3P): Aeroport(move(company), move(data), move(country), courses), x1(move(x1P)), x2(x2P), x3(x3P) {}
    ~Owner() {}
    void read() override {
        Aeroport::read();
        setOwnerX1();
        setOwnerX2();
        setOwnerX3();
    }
    void show() override {
        Aeroport::show();
        cout<<"x1: "<<getOwnerX1()<<endl<<"x2: "<<getOwnerX2()<<endl<<"x3: "<<getOwnerX3()<<endl<<"=============================="<<endl<<endl;
    }
    string setOwnerX1() { cout<<"x1 (string): "; cin>>x1; return getOwnerX1(); }
    int setOwnerX2() {
        cout<<"x2 (int): ";
        while(!(cin>>x2)) { cout<<"Trebuie sa fie cifra (int): "; cin.clear(); cin.ignore(1000, '\n'); }
        return getOwnerX2();
    }
    int setOwnerX3() {
        cout<<"x3 (int): ";
        while(!(cin>>x3)) { cout<<"Trebuie sa fie cifra (int): "; cin.clear(); cin.ignore(1000, '\n'); }
        return getOwnerX3();
    }

    const string& getOwnerX1() const { return x1; }
    int getOwnerX2() const { return x2; }
    int getOwnerX3() const { return x3; }
};

class TimeZone : virtual public Aeroport {
private:
    string y1; int y2;
protected:
    int y3;
public:
    TimeZone(): Aeroport(), y1(""), y2(0) {}
    TimeZone(string company, string data, string country, int courses, string y1P, int y2P, int y3P): Aeroport(move(company), move(data), move(country), courses), y1(move(y1P)), y2(y2P), y3(y3P) {}
    ~TimeZone() {}
    void read() override {
        Aeroport::read();
        setTimeZoneY1();
        setTimeZoneY2();
        setTimeZoneY3();
    }
    void show() override {
        Aeroport::show();
        cout<<"y1: "<<getTimeZoneY1()<<endl<<"y2: "<<getTimeZoneY2()<<endl<<"y3: "<<getTimeZoneY3()<<endl<<"=============================="<<endl<<endl;
    }
    string setTimeZoneY1() { cout<<"Y1 (string): "; cin>>y1; return getTimeZoneY1(); }
    int setTimeZoneY2() {
        cout<<"Y2 (int): ";
        while(!(cin>>y2)) { cout<<"Trebuie sa fie cifra (int): "; cin.clear(); cin.ignore(1000, '\n'); }
        return getTimeZoneY2();
    }
    int setTimeZoneY3() {
        cout<<"Y3 (int): ";
        while(!(cin>>y3)) { cout<<"Trebuie sa fie cifra (int): "; cin.clear(); cin.ignore(1000, '\n'); }
        return getTimeZoneY3();
    }

    const string& getTimeZoneY1() const { return y1; }
    int getTimeZoneY2() const { return y2; }
    int getTimeZoneY3() const { return y3; }
};

class General : virtual public Owner, virtual public TimeZone {
private:
    int z1;
public:
    General(): Owner(), TimeZone(), z1(0) {}
    General(string a, string b, string c, int d, string e, int f, string g, string h, int i): Owner(move(a), move(b), move(c), d, move(e), f), TimeZone(move(a), move(b), move(c), d, move(g), h), z1(i) {} 
    void show() override {
        Owner::show();
        TimeZone::show();
        cout<<"z1: "<<getGeneralZ1()<<endl<<"=============================="<<endl<<endl;
    }
    void read() override {
        Owner::read();
        TimeZone::read();
        setGeneralZ1();
    }
    int setGeneralZ1() {
        cout<<"Z1 (int): ";
        while(!(cin>>z1)) { cout<<"Trebuie sa fie cifra (int): "; cin.clear(); cin.ignore(1000, '\n'); }
        return getGeneralZ1();
    }
    int getGeneralZ1() const { return z1; }
};

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif 
}
void pause(string m) { cout<<endl<<m; cin.ignore(); cin.get(); }

int readAeroporturi(string& msg, vector<Aeroport>& arps) {
    for(int i=0; i<arps.size(); i++) {
        cout<<i+1<<". Citire aeroport."<<endl;
        arps[i].read();
    }
    msg = "Aeroporturi modificate cu succes. ";
    return 200;
}

int modifyByIndex(string& msg, vector<Aeroport>& arps) {
    int i; cout<<"Scrie pozitia aeroportului pe care vrei sa-l modifici: "; cin>>i;
    if(cin.fail()) { msg = "Pozitia trebuie sa fie o cifra. "; cin.clear(); cin.ignore(1000, '\n'); return 22; }
    if(i<1 || i>arps.size()) {
        msg = "Nu exista asa aeroport. ";
        return 404;
    }
    arps[i-1].read();
    msg = "Aeroport modificat cu succes. ";
    return 200;
}

int showAeroporturi(string& msg, vector<Aeroport>& arps) {
    for(int i=0; i<arps.size(); i++) arps[i].show();
    pause("Press enter to continue.");
    return 0;
}

int sortAeroporturi(string& msg, vector<Aeroport>& arps) {
    sort(arps.begin(), arps.end(), [](const Aeroport& a1, const Aeroport& a2) { return a1.getRaceNumber() < a2.getRaceNumber(); });
    msg = "S-a sortat cu succes. ";
    return 200;
}

int findByCountry(string& msg, vector<Aeroport>& arps) {
    string search; cout<<"Scrie ce tara cauti (q for exit): "; cin>>search;
    if(search == "q") return 0;
    int showed = 0;
    for(int i=0; i<arps.size(); i++)
        if(arps[i].getCountryName() == search) { arps[i].show(); showed = 1; }
    if(!showed) { msg = "Nu s-a gasit niciun aeroport cu tara " + search + ". "; return 404; }
    pause("Press enter to continue.");
    return 0;
}

int addByIndex(string& msg, vector<Aeroport>& arps) {
    int k; cout<<"Scrie pe ce pozitie vrei sa pui noul element: "; cin>>k;
    if(cin.fail()) { msg = "Pozitia trebuie sa fie o cifra. "; cin.clear(); cin.ignore(1000, '\n'); return 22; }
    if(k<1 || k>arps.size()+1) { msg = "Array-ul nu are asa pozitie disponibila. "; return 34; }
    Aeroport arp;
    arp.read();
    arps.insert(arps.begin() + k-1, move(arp));
    msg = "Aeroport adaugat cu succes. ";
    return 200;
}

int deleteByCompany(string& msg, vector<Aeroport>& arps) {
    string k; cout<<"Scrie numele companiei care sa fie sterse (q for exit): "; cin>>k;
    if(k == "q") return 0;
    int deleted = 0;
    for(int i=0; i<arps.size(); i++) if(arps[i].getCompanyName() == k) { arps.erase(arps.begin() + i); deleted = 1; }
    if(deleted) { msg = "Aeroportul " + k + " a fost sters cu succes. "; return 200; } 
    else { msg = "Aeroportul " + k + " nu a fost gasit ca sa fie sters. "; return 404; }
}

int readOwners(string& msg, vector<Owner>& owners) {
    for(int i=0; i<owners.size(); i++) {
        cout<<i+1<<". Citire Owner."<<endl;
        owners[i].read();
    }
    msg = "Owneri modificati cu succes. ";
    return 200;
}

int showOwners(string& msg, vector<Owner>& owners) {
    for(int i=0; i<owners.size(); i++) owners[i].show();
    pause("Press enter to continue.");
    return 0;
}

int sortOwners(string& msg, vector<Owner>& owners) {
    sort(owners.begin(), owners.end(), [](const Owner& a1, const Owner& a2) { return a1.getOwnerX2() < a2.getOwnerX2(); });
    msg = "S-a sortat cu succes. ";
    return 200;
}

int findByOwnerX1(string& msg, vector<Owner>& owners) {
    string search; cout<<"Scrie ce nume cauti (q for exit): "; cin>>search;
    if(search == "q") return 0;
    int showed = 0;
    for(int i=0; i<owners.size(); i++)
        if(owners[i].getOwnerX1() == search) { owners[i].show(); showed = 1; }
    if(!showed) { msg = "Nu s-a gasit niciun owner cu numele " + search + ". "; return 404; }
    pause("Press enter to continue.");
    return 0;
}

int modifyOwnerByIndex(string& msg, vector<Owner>& owners) {
    int i; cout<<"Scrie pozitia aeroportului pe care vrei sa-l modifici: "; cin>>i;
    if(cin.fail()) { msg = "Pozitia trebuie sa fie o cifra. "; cin.clear(); cin.ignore(1000, '\n'); return 22; }
    if(i<1 || i>owners.size()) {
        msg = "Nu exista asa aeroport. ";
        return 404;
    }
    owners[i-1].read();
    msg = "Aeroport modificat cu succes. ";
    return 200;
}

int deleteOwnerByX1(string& msg, vector<Owner>& owners) {
    string k; cout<<"Scrie numele care sa fie sterse (q for exit): "; cin>>k;
    if(k == "q") return 0;
    int deleted = 0;
    for(int i=0; i<owners.size(); i++) if(owners[i].getOwnerX1() == k) { owners.erase(owners.begin() + i); deleted = 1; }
    if(deleted) { msg = "Aeroportul ownerului " + k + " a fost sters cu succes. "; return 200; } 
    else { msg = "Aeroportul ownerului " + k + " nu a fost gasit ca sa fie sters. "; return 404; }
}

int readTimeZones(string& msg, vector<TimeZone>& timezones) {
    for(int i=0; i<timezones.size(); i++) {
        cout<<i+1<<". Citire timezone."<<endl;
        timezones[i].read();
    }
    msg = "Timezone modificati cu succes. ";
    return 200;
}

int showTimeZones(string& msg, vector<TimeZone>& timezones) {
    for(int i=0; i<timezones.size(); i++) timezones[i].show();
    pause("Press enter to continue.");
    return 0;
}

int sortTimeZone(string& msg, vector<TimeZone>& timezones) {
    sort(timezones.begin(), timezones.end(), [](const TimeZone& a1, const TimeZone& a2) { return a1.getTimeZoneY2() < a2.getTimeZoneY2(); });
    msg = "S-a sortat cu succes. ";
    return 200;
}

int findTimeZoneByY1(string& msg, vector<TimeZone>& timezones) {
    string search; cout<<"Scrie ce oras cauti (q for exit): "; cin>>search;
    if(search == "q") return 0;
    int showed = 0;
    for(int i=0; i<timezones.size(); i++)
        if(timezones[i].getTimeZoneY1() == search) { timezones[i].show(); showed = 1; }
    if(!showed) { msg = "Nu s-a gasit niciun oras cu numele " + search + ". "; return 404; }
    pause("Press enter to continue.");
    return 0;
}

int modifyTimeZoneByIndex(string& msg, vector<TimeZone>& timezones) {
    int i; cout<<"Scrie pozitia aeroportului pe care vrei sa-l modifici: "; cin>>i;
    if(cin.fail()) { msg = "Pozitia trebuie sa fie o cifra. "; cin.clear(); cin.ignore(1000, '\n'); return 22; }
    if(i<1 || i>timezones.size()) {
        msg = "Nu exista asa aeroport. ";
        return 404;
    }
    timezones[i-1].read();
    msg = "Aeroport modificat cu succes. ";
    return 200;
}

int deleteTimeZoneByY1(string& msg, vector<TimeZone>& timezones) {
    string k; cout<<"Scrie numele orasului care sa fie sterse (q for exit): "; cin>>k;
    if(k == "q") return 0;
    int deleted = 0;
    for(int i=0; i<timezones.size(); i++) if(timezones[i].getTimeZoneY1() == k) { timezones.erase(timezones.begin() + i); deleted = 1; }
    if(deleted) { msg = "Aeroportul orasului " + k + " a fost sters cu succes. "; return 200; } 
    else { msg = "Aeroportul orasului " + k + " nu a fost gasit ca sa fie sters. "; return 404; }
}

int choseOption(string menuTipe, string menu, int &status, string &msg, int max) {
    clearScreen();
    cout<<menuTipe<<endl;
    cout<<menu<<msg;
    if(status) cout<<"(status: "<<status<<") ";
    cout<<"Alege optiunea: ";
    int option;
    while(!(cin>>option)) { cout<<"Trebuie sa fie cifra (int): "; cin.clear(); cin.ignore(1000, '\n'); }
    while(option <= 0 || option > max) { cout<<"Optiunea poate fi intre 1 si "<<max<<": "; cin>>option; }
    return option;
}

void showMenu1(int &status, string &msg, vector<Aeroport> &aeroporturi, int &menuSelected) {
    static int (*menu[7])(string &, vector<Aeroport> &) = { readAeroporturi, showAeroporturi, sortAeroporturi, findByCountry, addByIndex, deleteByCompany, modifyByIndex };
    int option = choseOption("Aeroport", "------------------------------------------------\n1. Modifica-le pe toate.\n2. Afisare aeroporturi.\n3. Sorteaza dupa nr. de curse.\n4. Cauta aeropoarte dupa tara.\n5. Citire aeroport nou pe pozitie specifica.\n6. Stergere aeroport dupa numele companiei.\n7. Modifica dupa pozitie.\n8. Editeaza meniul de owner\n9. Editeaza meniul de timezone\n10. exit\n------------------------------------------------\n", status, msg, 10);
    if(option == 8) { menuSelected = 1; return; }
    if(option == 9) { menuSelected = 2; return; }
    if(option == 10) { menuSelected = 10; return; } // exit
    if(status) { status = 0; msg = ""; }
    status = menu[option-1](msg, aeroporturi);
}

void showMenu2(int &status, string &msg, vector<Owner> &owners, int &menuSelected) {
    static int (*menu[6])(string &, vector<Owner> &) = { readOwners, showOwners, sortOwners, findByOwnerX1, modifyOwnerByIndex, deleteOwnerByX1 };
    int option = choseOption("Owner", "------------------------------------------------\n1. Modifica-le pe toate.\n2. Afisare owners.\n3. Sorteaza dupa x2.\n4. Cauta aeropoarte dupa x1.\n5. Modifica dupa pozitie.\n6. Stergere aeroport dupa x1.\n7. Inapoi la meniul principal\n------------------------------------------------\n", status, msg, 7);
    if(option == 7) { menuSelected = 0; return; }
    if(status) { status = 0; msg = ""; }
    status = menu[option-1](msg, owners);
}

void showMenu3(int &status, string &msg, vector<TimeZone> &timezones, int &menuSelected) {
    static int (*menu[7])(string &, vector<TimeZone> &) = { readTimeZones, showTimeZones, sortTimeZone, findTimeZoneByY1, modifyTimeZoneByIndex, deleteTimeZoneByY1 };
    int option = choseOption("TimeZone", "------------------------------------------------\n1. Modifica-le pe toate.\n2. Afisare timezone.\n3. Sorteaza dupa y2.\n4. Cauta aeropoarte dupa y1.\n5. Modifica dupa pozitie.\n6. Stergere aeroport dupa y1.\n7. Inapoi la meniul principal\n------------------------------------------------\n", status, msg, 7);
    if(option == 7) { menuSelected = 0; return; }
    if(status) { status = 0; msg = ""; }
    status = menu[option-1](msg, timezones);
}

int main() {
    srand(time(0));
    string msg = ""; int status = 0;
    vector<Aeroport> aeroporturi;
    vector<Owner> owners;
    vector<TimeZone> timeZones;

    //autogenerare
    int autoGenerate;
    cout<<"Cate aeropoarte sa se genereze automat?: ";
    while(!(cin>>autoGenerate)) { cout<<"Trebuie sa fie cifra (int): "; cin.clear(); cin.ignore(1000, '\n'); }
    for(int i=1; i<=autoGenerate; i++) {
        int year = rand() % 75;
        Aeroport arp("company"+to_string(i), to_string(rand() % 30 + 1) + "/" + to_string(rand() % 11 + 1) + "/" + to_string(year + 1950), "country"+to_string(i), (rand() % 200 + 165) * (75 - year));
        Owner own(arp.getCompanyName(), arp.getDate(), arp.getCountryName(), arp.getRaceNumber(), "x1"+to_string(i), i, rand() % 100);
        TimeZone tmz(arp.getCompanyName(), arp.getDate(), arp.getCountryName(), arp.getRaceNumber(), "y1"+to_string(i), i, rand() % 100);
        aeroporturi.push_back(move(arp));
        owners.push_back(move(own));
        timeZones.push_back(move(tmz));
    }

    //meniu
    status = 200; msg = "Am adaugat " + to_string(autoGenerate) + " aeroporturi. ";
    int menuSelected = 0;
    while(1) {
        switch(menuSelected) {
            case 0: { showMenu1(status, msg, aeroporturi, menuSelected); break; }
            case 1: { showMenu2(status, msg, owners, menuSelected); break; }
            case 2: { showMenu3(status, msg, timeZones, menuSelected); break; }
            default: break;
        }
        if(menuSelected == 10) break;
    }

    return 0;
}
