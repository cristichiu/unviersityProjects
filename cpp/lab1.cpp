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
    virtual int getRaceNumber() const = 0;
    virtual string getCountryName() const = 0;
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

    virtual void read() override {
        setCompanyName();
        setDate();
        setCountryName();
        setRaceNumber();
    }
    virtual void show() override {
        cout<<endl<<"=============================="<<endl<<"Nume companie: "<<getCompanyName()<<endl<<"Data infiintarii: "<<getDate()<<endl<<"Numele tarii: "<<getCountryName()<<endl<<"Numarul de curse: "<<getRaceNumber()<<endl<<"=============================="<<endl<<endl;
    }

    virtual int getRaceNumber() const override { return raceNumber; }
    virtual string getCountryName() const override { return countryName; }
    const string& getCompanyName() const { return companyName; }
    const string& getDate() const { return date; }

    string setCompanyName() { cout<<"Nume companie: "; cin>>companyName; return getCompanyName(); }
    string setDate() { cout<<"Data infiintarii: "; cin>>date; return getDate(); }
    string setCountryName() { cout<<"Numele tarii: "; cin>>countryName; return getCountryName(); }
    int setRaceNumber() { 
        cout<<"Numarul de curse: ";
        while(!(cin>>raceNumber) || raceNumber <= 0) { cout<<"Trebuie sa fie cifra (int): "; cin.clear(); cin.ignore(1000, '\n'); }
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
    virtual void read() override {
        Aeroport::read();
        setOwnerX1();
        setOwnerX2();
        setOwnerX3();
    }
    virtual void show() override {
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
    virtual int getRaceNumber() const override { return Aeroport::getRaceNumber(); }
    virtual string getCountryName() const override { return Aeroport::getCountryName(); }
};

class TimeZone : virtual public Aeroport {
private:
    string y1; int y2;
protected:
    int y3;
public:
    TimeZone(): Aeroport(), y1(""), y2(0), y3(0) {}
    TimeZone(string company, string data, string country, int courses, string y1P, int y2P, int y3P): Aeroport(move(company), move(data), move(country), courses), y1(move(y1P)), y2(y2P), y3(y3P) {}
    ~TimeZone() {}
    virtual void read() override {
        Aeroport::read();
        setTimeZoneY1();
        setTimeZoneY2();
        setTimeZoneY3();
    }
    virtual void show() override {
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
    virtual int getRaceNumber() const override { return Aeroport::getRaceNumber(); }
    virtual string getCountryName() const override { return Aeroport::getCountryName(); }
};

class General : virtual public Owner, virtual public TimeZone {
private:
    int z1;
public:
    General(): Owner(), TimeZone(), z1(0) {}
    General(string a, string b, string c, int d, string e, int f1, int f2, string g, int h1, int h2, int i): Owner(move(a), move(b), move(c), d, move(e), f1, f2), TimeZone(move(a), move(b), move(c), d, move(g), h1, h2), z1(i) {} 
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
    int getRaceNumber() const override { return Aeroport::getRaceNumber(); }
    virtual string getCountryName() const override { return Aeroport::getCountryName(); }
};

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif 
}
void pause(string m) { cout<<endl<<m; cin.ignore(); cin.get(); }

int readObjects(string& msg, vector<AbstractBase*>& objects) {
    for(int i=0; i<objects.size(); i++) {
        cout<<i+1<<". Citire obiect."<<endl;
        objects[i]->read();
    }
    msg = "Obiecte modificate cu succes. ";
    return 200;
}

int showObjects(string& msg, vector<AbstractBase*>& objects) {
    for(int i=0; i<objects.size(); i++) objects[i]->show();
    pause("Press enter to continue.");
    return 0;
}

int sortObjects(string& msg, vector<AbstractBase*>& objects) {
    sort(objects.begin(), objects.end(), [](const AbstractBase* a1, const AbstractBase* a2) { return a1->getRaceNumber() < a2->getRaceNumber(); });
    msg = "S-a sortat cu succes. ";
    return 200;
}

int findObjects(string& msg, vector<AbstractBase*>& objects) {
    string search; cout<<"Scrie ce tara cauti (q for exit): "; cin>>search;
    if(search == "q") return 0;
    int showed = 0;
    for(int i=0; i<objects.size(); i++)
        if(objects[i]->getCountryName() == search) { objects[i]->show(); showed = 1; }
    if(!showed) { msg = "Nu s-a gasit niciun aeroport cu tara " + search + ". "; return 404; }
    pause("Press enter to continue.");
    return 0;
}

int modifyObjects(string& msg, vector<AbstractBase*>& objects) {
    int i; cout<<"Scrie pozitia aeroportului pe care vrei sa-l modifici: "; cin>>i;
    if(cin.fail()) { msg = "Pozitia trebuie sa fie o cifra. "; cin.clear(); cin.ignore(1000, '\n'); return 22; }
    if(i<1 || i>objects.size()) {
        msg = "Nu exista asa aeroport. ";
        return 404;
    }
    objects[i-1]->read();
    msg = "Aeroport modificat cu succes. ";
    return 200;
}

int deleteObjects(string& msg, vector<AbstractBase*>& objects) {
    string k; cout<<"Scrie numele companiei care sa fie sterse (q for exit): "; cin>>k;
    if(k == "q") return 0;
    int deleted = 0;
    for(int i=0; i<objects.size(); i++) if(objects[i]->getCountryName() == k) { objects.erase(objects.begin() + i); deleted = 1; }
    if(deleted) { msg = "Aeroportul " + k + " a fost sters cu succes. "; return 200; } 
    else { msg = "Aeroportul " + k + " nu a fost gasit ca sa fie sters. "; return 404; }
}

int showMenu(int &status, string &msg, vector<AbstractBase*>& objects) {
    static int (*menu[7])(string &, vector<AbstractBase*>&) = { readObjects, showObjects, sortObjects, findObjects, modifyObjects, deleteObjects };
    clearScreen();
    cout<<"------------------------------------------------\n1. Citeste obiectele.\n2. Afiseaza obiectele.\n3. Sorteaza dupa nr. de curse.\n4. Cauta dupa tara.\n5. Citire aeroport nou pe pozitie specifica.\n6. Stergere dupa tara.\n7. exit\n------------------------------------------------\n"<<msg;
    if(status) cout<<"(status: "<<status<<") ";
    cout<<"Alege optiunea: ";
    int option;
    while(!(cin>>option)) { cout<<"Trebuie sa fie cifra (int): "; cin.clear(); cin.ignore(1000, '\n'); }
    while(option <= 0 || option > 7) { cout<<"Optiunea poate fi intre 1 si 10: "; cin>>option; }
    if(option == 7) return 0;
    if(status) { status = 0; msg = ""; }
    status = menu[option-1](msg, objects);
    return 1;
}

int main() {
    srand(time(0));
    string msg = ""; int status = 0;
    
    int n;
    cout<<"Cate elemenete vrei sa adaugi: ";
    while(!(cin>>n)) { cout<<"Trebuie sa fie cifra (int): "; cin.clear(); cin.ignore(1000, '\n'); }
    vector<AbstractBase*> objects;
    for(int i=0; i<n; i++) {
        int tip;
        cout<<"Ce tip sa fie elementul "<<i+1<<" (1: Aeroport, 2: Owner, 3: TimeZone, 4: General): ";
        while(!(cin>>tip)) { cout<<"Trebuie sa fie cifra (int): "; cin.clear(); cin.ignore(1000, '\n'); }
        switch(tip) {
            case 1: { objects.push_back(new Aeroport()); break; }
            case 2: { objects.push_back(new Owner()); break; }
            case 3: { objects.push_back(new TimeZone()); break; }
            case 4: { objects.push_back(new General()); break; }
            default: { cout<<"Tip invalid: "; i--; break; }
        }
    }

    while(showMenu(status, msg, objects));

    return 0;
}
