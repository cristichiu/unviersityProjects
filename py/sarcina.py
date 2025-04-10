def division():
    a = input("primul numar: ")
    b = input("al 2-lea numar: ")
    try:
        c = int(a)/int(b)
    except ValueError:
        print("Una din cifre nu este numar.")
    except ZeroDivisionError:
        print("S-a incercat impartirea la 0.")
    except TypeError:
        print("Operatia nu este posibila din alte motive.")
    else:
        print("Operatia completata cu succes.")
division()
