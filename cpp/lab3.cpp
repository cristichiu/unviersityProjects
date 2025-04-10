#include <iostream>
using namespace std;

template <class T>
class Complex {
    private:
    T real, imaginary;
    public:
    Complex(): real(0), imaginary(0) {}
    Complex(T r, T i): real(r), imaginary(i) {}
    Complex(const Complex<T> &original): real(original.real), imaginary(original.imaginary) {}
    ~Complex() {}

    void setReal(istream& input) {
        while(true) {
            try {
                cout<<"Partea reala: ";
                if(!(input>>real)) {
                    input.clear();
                    input.ignore(1000, '\n');
                    throw "type error.";
                }
                break;
            } catch (const char* n) {
                cout<<n<<endl;
            }
        }
    }
    void setImaginary(istream& input) {
        while(true) {
            try {
                cout<<"Partea imaginara: ";
                if(!(input>>imaginary)) {
                    input.clear();
                    input.ignore(1000, '\n');
                    throw "type error.";
                }
                break;
            } catch (const char* n) {
                cout<<n<<endl;
            }
        }
    }

    T getReal() const { return real; }
    T getImaginary() const { return imaginary; }

    Complex<T> &operator*=(const Complex<T> &other) {
        T newReal = real * other.real - imaginary * other.imaginary;
        T newImaginary = real * other.imaginary + imaginary * other.real;
        real = newReal;
        imaginary = newImaginary;
        return *this;
    }
    Complex<T> operator++(int) {
        Complex<T> temp = *this;
        real += 1;
        return temp;
    }
    Complex<T>& operator++() {
        real += 1;
        return *this;
    }
    bool operator==(const Complex<T> &other) const {
        return (real == other.real && imaginary == other.imaginary);
    }
    Complex<T> operator+(T x) const {
        return Complex<T>(real + x, imaginary);
    }
    Complex<T> &operator=(const Complex<T> &other) {
        if (this != &other) {
            real = other.real;
            imaginary = other.imaginary;
        }
        return *this;
    }
};

template <class T>
istream& operator>>(istream& input, Complex<T>& c) {
    c.setReal(input);
    c.setImaginary(input);
    return input;
}

template <class T>
ostream& operator<<(ostream& output, const Complex<T>& c) {
    output<<c.getReal()<<" + "<<c.getImaginary()<<"i";
    return output;
}

template <class T>
Complex<T> operator+(int x, const Complex<T>& c) {
    return Complex<T>(c.getReal() + x, c.getImaginary());
}

template <class T>
Complex<T> addComplexNumbers(const Complex<T>& c1, const Complex<T>& c2) {
    try {
        return Complex<T>(c1.getReal() + c2.getReal(), c1.getImaginary() + c2.getImaginary());
    } catch (const exception& e) {
        cerr << "Eroare la adunarea numerelor complexe: " << e.what() << endl;
        throw;
    }
}

template <class T>
Complex<T> addComplexToInt(const Complex<T>& c1, T n) {
    try {
        return Complex<T>(c1.getReal() + n, c1.getImaginary());
    } catch (const exception& e) {
        cerr << "Eroare la adunarea unui numar complex cu un alt numar: "<<e.what()<<endl;
        throw;
    }
}

int main() {
    try {
        // Exemplu cu Complex<float>
        Complex<float> c1, c2;
        cout << "Introduceti primul numar complex float:\n";
        cin >> c1;
        cout << "Introduceti al doilea numar complex float:\n";
        cin >> c2;

        cout << "Numerele introduse sunt:\n";
        cout << "c1: " << c1 << endl;
        cout << "c2: " << c2 << endl;

        // Înmulțire
        c1 *= c2;
        cout << "Rezultatul inmultirii c1 *= c2: " << c1 << endl;

        // Incrementare postfixată și prefixată
        Complex<float> c3 = c1++;
        cout << "c1 dupa incrementare postfixata: " << c1 << endl;
        cout << "Valoarea lui c3 (c1++): " << c3 << endl;

        ++c1;
        cout << "c1 dupa incrementare prefixata: " << c1 << endl;

        // Comparație cu complex int
        Complex<int> c4, c5(3, 4);
        cout<<"Citire c4 tip int: "<<endl;
        cin>>c4;
        cout << "c4 == c5: " << (c4 == c5 ? "True" : "False") << endl;

        // Adunare cu întreg
        Complex<int> c6 = c4 + 5;
        cout << "c1 + 5: " << c6 << endl;

        Complex<float> c7 = 5 + c1;
        cout << "5 + c1: " << c7 << endl;

        // Atribuire
        Complex<float> c8;
        c8 = c1;
        cout << "c8 = c1: " << c8 << endl;

        // Folosirea funcției-șablon addComplexNumbers
        Complex<float> c9 = addComplexNumbers(c1, c2);
        cout << "Rezultatul adunarii c1 si c2 (folosind functia-sablon): " << c9 << endl;
        Complex<int> c10 = addComplexToInt(c4, 15);
        cout<<"Rezultatul adunarii lui c4 cu 15 (folosind o functie shablon): " << c10<< endl;

    } catch (const exception& e) {
        cerr << "Eroare in program: " << e.what() << endl;
    }
    return 0;
}
