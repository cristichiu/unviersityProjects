#include <iostream>

#include <string>

#include <vector>

#include <algorithm>

#include <ctime>

#include <cstdlib>

using namespace std;

class Aeroport {
  private: string companyName;
  string date;
  protected: string countryName;
  int raceNumber;
  public: Aeroport(): companyName(""),
  date(""),
  countryName(""),
  raceNumber(0) {}
  Aeroport(string company, string data, string country, int courses): companyName(move(company)),
  date(move(data)),
  countryName(move(country)),
  raceNumber(move(courses)) {}
  ~Aeroport() {}

  void readAeroport() {
    setCompanyName([]() {
      string temp;
      cout << "Nume companie: ";
      cin >> temp;
      return temp;
    }());
    setDate([]() {
      string temp;
      cout << "Data infiintarii: ";
      cin >> temp;
      return temp;
    }());
    setCountryName([]() {
      string temp;
      cout << "Numele tarii: ";
      cin >> temp;
      return temp;
    }());
    setRaceNumber([]() {
      int temp;
      vrfRaceNum: // verify if input is int
        cout << "Numarul de curse: ";
      cin >> temp;
      if (cin.fail()) {
        cout << "Nu ai introdus un numar, mai incearca o data" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        goto vrfRaceNum;
      }
      return temp;
    }());
  }
  void showAeroport() {
    cout << endl << "==============================" << endl << "Nume companie: " << getCompanyName() << endl << "Data infiintarii: " << getDate() << endl << "Numele tarii: " << getCountryName() << endl << "Numarul de curse: " << getRaceNumber() << endl << "==============================" << endl << endl;
  }

  int getRaceNumber() const {
    return raceNumber;
  }
  string getCountryName() const {
    return countryName;
  }
  string getCompanyName() const {
    return companyName;
  }
  string getDate() const {
    return date;
  }

  string setCompanyName(string company) {
    companyName = move(company);
    return getCompanyName();
  }
  string setDate(string data) {
    date = move(data);
    return getDate();
  }
  string setCountryName(string country) {
    countryName = move(country);
    return getCountryName();
  }
  int setRaceNumber(int courses) {
    raceNumber = move(courses);
    return getRaceNumber();
  }
};

class Owner: public Aeroport {
  private: string name;int age;
  public: Owner(): Aeroport(),
  name(""),
  age(0) {}
  Owner(string company, string data, string country, int courses, string nameP, int ageP): Aeroport(company, data, country, courses),
  name(move(nameP)),
  age(move(ageP)) {}
  ~Owner() {}
  void readOwner() {
    readAeroport();
    setOwnerName([]() {
      string temp;
      cout << "Nume owner: ";
      cin >> temp;
      return temp;
    }());
    setOwnerAge([]() {
      int temp;
      vrfOwnerAge: // verify if input is int
        cout << "Varsta owner: ";
      cin >> temp;
      if (cin.fail()) {
        cout << "Nu ai introdus un numar, mai incearca o data" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        goto vrfOwnerAge;
      }
      return temp;
    }());
  }
  void showOwner() {
    showAeroport();
    cout << "Nume owner: " << getOwnerName() << endl << "Age owner: " << getOwnerAge() << endl << "==============================" << endl << endl;
  }
  string setOwnerName(string nameP) {
    name = move(nameP);
    return getOwnerName();
  }
  int setOwnerAge(int ageP) {
    age = move(ageP);
    return getOwnerAge();
  }

  string getOwnerName() const {
    return name;
  }
  int getOwnerAge() const {
    return age;
  }
};

class TimeZone: public Aeroport {
  private: string city;int timeZone;
  public: TimeZone(): Aeroport(),
  city(""),
  timeZone(0) {}
  TimeZone(string company, string data, string country, int courses, string cityP, int timeZoneP): Aeroport(company, data, country, courses),
  city(move(cityP)),
  timeZone(move(timeZoneP)) {}
  ~TimeZone() {}
  void readTimeZone() {
    readAeroport();
    setCity([]() {
      string temp;
      cout << "Numele orasului in timezone: ";
      cin >> temp;
      return temp;
    }());
    setTimeZone([]() {
      int temp;
      vrfTimeZone: // verify if input is int
        cout << "timezone: ";
      cin >> temp;
      if (cin.fail()) {
        cout << "Nu ai introdus un numar, mai incearca o data" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        goto vrfTimeZone;
      }
      return temp;
    }());
  }
  void showTime() {
    showAeroport();
    cout << "Nume city: " << getCity() << endl << "Timezone: " << getTimeZone() << endl << "==============================" << endl << endl;
  }
  string setCity(string cityP) {
    city = move(cityP);
    return getCity();
  }
  int setTimeZone(int timeZoneP) {
    timeZone = move(timeZoneP);
    return getTimeZone();
  }

  string getCity() const {
    return city;
  }
  int getTimeZone() const {
    return timeZone;
  }
};

void clearScreen() {
  #ifdef _WIN32
  system("cls");
  #else
  system("clear");
  #endif
}
void pause(string m) {
  cout << endl << m;
  cin.ignore();
  cin.get();
}

void readAeroporturi(int & status, string & msg, vector < Aeroport > & arps) {
  for (int i = 0; i < arps.size(); i++) {
    cout << i + 1 << ". Citire aeroport." << endl;
    arps[i].readAeroport();
  }
  status = 200;
  msg = "Aeroporturi modificate cu succes. ";
}

void modifyByIndex(int & status, string & msg, vector < Aeroport > & arps) {
  int i;
  cout << "Scrie pozitia aeroportului pe care vrei sa-l modifici: ";
  cin >> i;
  if (cin.fail()) {
    status = 22;
    msg = "Pozitia trebuie sa fie o cifra. ";
    cin.clear();
    cin.ignore(1000, '\n');
    return;
  }
  if (i < 1 || i > arps.size()) {
    status = 404;
    msg = "Nu exista asa aeroport. ";
    return;
  }
  arps[i - 1].readAeroport();
  status = 200;
  msg = "Aeroport modificat cu succes. ";
}

void showAeroporturi(int & status, string & msg, vector < Aeroport > & arps) {
  for (int i = 0; i < arps.size(); i++) arps[i].showAeroport();
  pause("Press enter to continue.");
}

void sortAeroporturi(int & status, string & msg, vector < Aeroport > & arps) {
  sort(arps.begin(), arps.end(), [](const Aeroport & a1,
    const Aeroport & a2) {
    return a1.getRaceNumber() < a2.getRaceNumber();
  });
  status = 200;
  msg = "S-a sortat cu succes. ";
}

void findByCountry(int & status, string & msg, vector < Aeroport > & arps) {
  string search;
  cout << "Scrie ce tara cauti (q for exit): ";
  cin >> search;
  if (search == "q") return;
  int showed = 0;
  for (int i = 0; i < arps.size(); i++)
    if (arps[i].getCountryName() == search) {
      arps[i].showAeroport();
      showed = 1;
    }
  if (!showed) {
    status = 404;
    msg = "Nu s-a gasit niciun aeroport cu tara " + search + ". ";
    return;
  }
  pause("Press enter to continue.");
}

void addByIndex(int & status, string & msg, vector < Aeroport > & arps) {
  int k;
  cout << "Scrie pe ce pozitie vrei sa pui noul element: ";
  cin >> k;
  if (cin.fail()) {
    status = 22;
    msg = "Pozitia trebuie sa fie o cifra. ";
    cin.clear();
    cin.ignore(1000, '\n');
    return;
  }
  if (k < 1 || k > arps.size() + 1) {
    status = 34;
    msg = "Array-ul nu are asa pozitie disponibila. ";
    return;
  }
  Aeroport arp;
  arp.readAeroport();
  arps.insert(arps.begin() + k - 1, arp);
  status = 200;
  msg = "Aeroport adaugat cu succes. ";
}

void deleteByCompany(int & status, string & msg, vector < Aeroport > & arps) {
  string k;
  cout << "Scrie numele companiei care sa fie sterse (q for exit): ";
  cin >> k;
  if (k == "q") return;
  int deleted = 0;
  for (int i = 0; i < arps.size(); i++)
    if (arps[i].getCompanyName() == k) {
      arps.erase(arps.begin() + i);
      deleted = 1;
    }
  if (deleted) {
    status = 200;
    msg = "Aeroportul " + k + " a fost sters cu succes. ";
  } else {
    status = 404;
    msg = "Aeroportul " + k + " nu a fost gasit ca sa fie sters. ";
  }
}

void readOwners(int & status, string & msg, vector < Owner > & owners) {
  for (int i = 0; i < owners.size(); i++) {
    cout << i + 1 << ". Citire Owner." << endl;
    owners[i].readOwner();
  }
  status = 200;
  msg = "Owneri modificati cu succes. ";
}

void showOwners(int & status, string & msg, vector < Owner > & owners) {
  for (int i = 0; i < owners.size(); i++) owners[i].showOwner();
  pause("Press enter to continue.");
}

void sortOwners(int & status, string & msg, vector < Owner > & owners) {
  sort(owners.begin(), owners.end(), [](const Owner & a1,
    const Owner & a2) {
    return a1.getOwnerAge() < a2.getOwnerAge();
  });
  status = 200;
  msg = "S-a sortat cu succes. ";
}

void findByOwnerName(int & status, string & msg, vector < Owner > & owners) {
  string search;
  cout << "Scrie ce nume cauti (q for exit): ";
  cin >> search;
  if (search == "q") return;
  int showed = 0;
  for (int i = 0; i < owners.size(); i++)
    if (owners[i].getOwnerName() == search) {
      owners[i].showOwner();
      showed = 1;
    }
  if (!showed) {
    status = 404;
    msg = "Nu s-a gasit niciun owner cu numele " + search + ". ";
    return;
  }
  pause("Press enter to continue.");
}

void modifyOwnerByIndex(int & status, string & msg, vector < Owner > & owners) {
  int i;
  cout << "Scrie pozitia aeroportului pe care vrei sa-l modifici: ";
  cin >> i;
  if (cin.fail()) {
    status = 22;
    msg = "Pozitia trebuie sa fie o cifra. ";
    cin.clear();
    cin.ignore(1000, '\n');
    return;
  }
  if (i < 1 || i > owners.size()) {
    status = 404;
    msg = "Nu exista asa aeroport. ";
    return;
  }
  owners[i - 1].readOwner();
  status = 200;
  msg = "Aeroport modificat cu succes. ";
}

void deleteOwnerByName(int & status, string & msg, vector < Owner > & owners) {
  string k;
  cout << "Scrie numele care sa fie sterse (q for exit): ";
  cin >> k;
  if (k == "q") return;
  int deleted = 0;
  for (int i = 0; i < owners.size(); i++)
    if (owners[i].getOwnerName() == k) {
      owners.erase(owners.begin() + i);
      deleted = 1;
    }
  if (deleted) {
    status = 200;
    msg = "Aeroportul ownerului " + k + " a fost sters cu succes. ";
  } else {
    status = 404;
    msg = "Aeroportul ownerului " + k + " nu a fost gasit ca sa fie sters. ";
  }
}

void readTimeZones(int & status, string & msg, vector < TimeZone > & timezones) {
  for (int i = 0; i < timezones.size(); i++) {
    cout << i + 1 << ". Citire timezone." << endl;
    timezones[i].readTimeZone();
  }
  status = 200;
  msg = "Timezone modificati cu succes. ";
}

void showTimeZones(int & status, string & msg, vector < TimeZone > & timezones) {
  for (int i = 0; i < timezones.size(); i++) timezones[i].showTime();
  pause("Press enter to continue.");
}

void sortTimeZone(int & status, string & msg, vector < TimeZone > & timezones) {
  sort(timezones.begin(), timezones.end(), [](const TimeZone & a1,
    const TimeZone & a2) {
    return a1.getTimeZone() < a2.getTimeZone();
  });
  status = 200;
  msg = "S-a sortat cu succes. ";
}

void findByCity(int & status, string & msg, vector < TimeZone > & timezones) {
  string search;
  cout << "Scrie ce oras cauti (q for exit): ";
  cin >> search;
  if (search == "q") return;
  int showed = 0;
  for (int i = 0; i < timezones.size(); i++)
    if (timezones[i].getCity() == search) {
      timezones[i].showTime();
      showed = 1;
    }
  if (!showed) {
    status = 404;
    msg = "Nu s-a gasit niciun oras cu numele " + search + ". ";
    return;
  }
  pause("Press enter to continue.");
}

void modifyTimeZoneByIndex(int & status, string & msg, vector < TimeZone > & timezones) {
  int i;
  cout << "Scrie pozitia aeroportului pe care vrei sa-l modifici: ";
  cin >> i;
  if (cin.fail()) {
    status = 22;
    msg = "Pozitia trebuie sa fie o cifra. ";
    cin.clear();
    cin.ignore(1000, '\n');
    return;
  }
  if (i < 1 || i > timezones.size()) {
    status = 404;
    msg = "Nu exista asa aeroport. ";
    return;
  }
  timezones[i - 1].readTimeZone();
  status = 200;
  msg = "Aeroport modificat cu succes. ";
}

void deleteTimeZoneByCity(int & status, string & msg, vector < TimeZone > & timezones) {
  string k;
  cout << "Scrie numele orasului care sa fie sterse (q for exit): ";
  cin >> k;
  if (k == "q") return;
  int deleted = 0;
  for (int i = 0; i < timezones.size(); i++)
    if (timezones[i].getCity() == k) {
      timezones.erase(timezones.begin() + i);
      deleted = 1;
    }
  if (deleted) {
    status = 200;
    msg = "Aeroportul orasului " + k + " a fost sters cu succes. ";
  } else {
    status = 404;
    msg = "Aeroportul orasului " + k + " nu a fost gasit ca sa fie sters. ";
  }
}

void showMenu1(void( * menu[])(int & , string & , vector < Aeroport > & ), int & status, string & msg, vector < Aeroport > & aeroporturi, int & menuSelected) {
  vrfOptionNum1: // verify if input is int
    clearScreen();
  cout << "Aeroport" << endl;
  cout << "------------------------------------------------\n1. Modifica-le pe toate.\n2. Afisare aeroporturi.\n3. Sorteaza dupa nr. de curse.\n4. Cauta aeropoarte dupa tara.\n5. Citire aeroport nou pe pozitie specifica.\n6. Stergere aeroport dupa numele companiei.\n7. Modifica dupa pozitie.\n8. Editeaza meniul de owner\n9. Editeaza meniul de timezone\n10. exit\n------------------------------------------------\n" << msg;
  if (status) cout << "(status: " << status << ") ";
  cout << "Alege optiunea: ";
  int option;cin >> option;
  if (cin.fail()) {
    status = 22;
    msg = "Optiunea nu poate fi altceva decat cifre. ";
    cin.clear();
    cin.ignore(1000, '\n');
    goto vrfOptionNum1;
  } // fail
  if (option <= 0 || option > 10) {
    status = 404;
    msg = "Optiunea poate fi intre 1 si 10. ";
    goto vrfOptionNum1;
  } // fail
  if (option == 8) {
    menuSelected = 1;
    return;
  }
  if (option == 9) {
    menuSelected = 2;
    return;
  }
  if (option == 10) {
    menuSelected = 10;
    return;
  } // exit
  if (status) {
    status = 0;
    msg = "";
  }
  menu[option - 1](status, msg, aeroporturi);
}

void showMenu2(void( * menu[])(int & , string & , vector < Owner > & ), int & status, string & msg, vector < Owner > & owners, int & menuSelected) {
  vrfOptionNum2: clearScreen();
  cout << "Owner" << endl;
  cout << "------------------------------------------------\n1. Modifica-le pe toate.\n2. Afisare owners.\n3. Sorteaza dupa varsta.\n4. Cauta aeropoarte dupa nume la owner.\n5. Modifica dupa pozitie.\n6. Stergere aeroport dupa numele ownerului.\n7. Inapoi la meniul principal\n------------------------------------------------\n" << msg;
  if (status) cout << "(status: " << status << ") ";
  cout << "Alege optiunea: ";
  int option;cin >> option;
  if (cin.fail()) {
    status = 22;
    msg = "Optiunea nu poate fi altceva decat cifre. ";
    cin.clear();
    cin.ignore(1000, '\n');
    goto vrfOptionNum2;
  } // fail
  if (option <= 0 || option > 7) {
    status = 404;
    msg = "Optiunea poate fi intre 1 si 7. ";
    goto vrfOptionNum2;
  } // fail
  if (option == 7) {
    menuSelected = 0;
    return;
  }
  if (status) {
    status = 0;
    msg = "";
  }
  menu[option - 1](status, msg, owners);
}

void showMenu3(void( * menu[])(int & , string & , vector < TimeZone > & ), int & status, string & msg, vector < TimeZone > & timezones, int & menuSelected) {
  vrfOptionNum3: clearScreen();
  cout << "TimeZone" << endl;
  cout << "------------------------------------------------\n1. Modifica-le pe toate.\n2. Afisare timezone.\n3. Sorteaza dupa timezone.\n4. Cauta aeropoarte dupa orasul la timezone.\n5. Modifica dupa pozitie.\n6. Stergere aeroport dupa numele orasului din timezone.\n7. Inapoi la meniul principal\n------------------------------------------------\n" << msg;
  if (status) cout << "(status: " << status << ") ";
  cout << "Alege optiunea: ";
  int option;cin >> option;
  if (cin.fail()) {
    status = 22;
    msg = "Optiunea nu poate fi altceva decat cifre. ";
    cin.clear();
    cin.ignore(1000, '\n');
    goto vrfOptionNum3;
  } // fail
  if (option <= 0 || option > 7) {
    status = 404;
    msg = "Optiunea poate fi intre 1 si 7. ";
    goto vrfOptionNum3;
  } // fail
  if (option == 7) {
    menuSelected = 0;
    return;
  }
  if (status) {
    status = 0;
    msg = "";
  }
  menu[option - 1](status, msg, timezones);
}

int main() {
  srand(time(0));
  string msg = "";
  int status = 0;
  vector < Aeroport > aeroporturi;
  vector < Owner > owners;
  vector < TimeZone > timeZones;
  int autoGenerate;
  vrfAutoGenerate:
    cout << "Cate aeropoarte sa se genereze automat?: ";
  cin >> autoGenerate;
  if (cin.fail()) {
    cout << "Trebuie sa fie cifra." << endl;
    cin.clear();
    cin.ignore(1000, '\n');
    goto vrfAutoGenerate;
  }
  for (int i = 1; i <= autoGenerate; i++) {
    int year = rand() % 75;
    Aeroport arp("company" + to_string(i), to_string(rand() % 30 + 1) + "/" + to_string(rand() % 11 + 1) + "/" + to_string(year + 1950), "country" + to_string(i), (rand() % 200 + 165) * (75 - year));
    Owner own(arp.getCompanyName(), arp.getDate(), arp.getCountryName(), arp.getRaceNumber(), "name" + to_string(i), rand() % 70 + 20);
    TimeZone tmz(arp.getCompanyName(), arp.getDate(), arp.getCountryName(), arp.getRaceNumber(), "city" + to_string(i), i - 5);
    aeroporturi.push_back(arp);
    owners.push_back(own);
    timeZones.push_back(tmz);
  }
  status = 200;
  msg = "Am adaugat " + to_string(autoGenerate) + " aeroporturi. ";
  void( * menu1[7])(int & , string & , vector < Aeroport > & ) = {
    readAeroporturi,
    showAeroporturi,
    sortAeroporturi,
    findByCountry,
    addByIndex,
    deleteByCompany,
    modifyByIndex
  };
  void( * menu2[6])(int & , string & , vector < Owner > & ) = {
    readOwners,
    showOwners,
    sortOwners,
    findByOwnerName,
    modifyOwnerByIndex,
    deleteOwnerByName
  };
  void( * menu3[7])(int & , string & , vector < TimeZone > & ) = {
    readTimeZones,
    showTimeZones,
    sortTimeZone,
    findByCity,
    modifyTimeZoneByIndex,
    deleteTimeZoneByCity
  };
  int menuSelected = 0;
  while (1) {
    switch (menuSelected) {
    case 0: {
      showMenu1(menu1, status, msg, aeroporturi, menuSelected);
      break;
    }
    case 1: {
      showMenu2(menu2, status, msg, owners, menuSelected);
      break;
    }
    case 2: {
      showMenu3(menu3, status, msg, timeZones, menuSelected);
      break;
    }
    default:
      break;
    }
    if (menuSelected == 10) break;
  }
  return 0;
}
