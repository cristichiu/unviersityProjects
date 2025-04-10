import password_manager as manager
from getpass import getpass
def main():
    print("""
    1. Login
    2. Register
    """)
    opt = input("Alege optiunea: ")
    key = 0
    if opt == "1":
        login = manager.login()
        key = login[1]
        manager.user_username = login[0]
    if opt == "2":
        register = manager.register()
        key = register[1]
        manager.user_username = register[0]
    else:
        print("Optiune invalida.")

    while True:
        print("""
        1. Adauga parola
        2. Afiseaza parola
        3. Afiseaza parolele
        4. Iesire
        """)
        opt = input("Alege optiune: ")
        if opt == "1":
            site = input("Site: ")
            username = input("Username: ")
            password = getpass("Parola: ")
            manager.save_password(site, username, password, key)
        if opt == "2":
            site = input("Site: ")
            manager.get_password(site, key)
        if opt == "3":
            manager.show_passwords()
        if opt == "4":
            break

        else:
            print("Optiune invalida.")
main()
