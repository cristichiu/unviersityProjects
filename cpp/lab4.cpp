#include <iostream>
#include <stdexcept> // Pentru std::invalid_argument
using namespace std;

// Clasa-șablon Complex
template <typename T>
class Complex {
private:
    T real, imaginary;
public:
    // Constructori
    Complex() : real(0), imaginary(0) {}
    Complex(T r, T i) : real(r), imaginary(i) {}
    Complex(const Complex &original) : real(original.real), imaginary(original.imaginary) {}

    // Destructor
    ~Complex() {}

    // Operatori de citire și afișare (declarații)
    friend istream& operator>> <>(istream& input, Complex<T>& c);
    friend ostream& operator<< <>(ostream& output, const Complex<T>& c);

    // Setters și getters
    void setReal(T r) { real = r; }
    void setImaginary(T i) { imaginary = i; }
    T getReal() const { return real; }
    T getImaginary() const { return imaginary; }

    // Operator *=
    Complex& operator*=(const Complex& other) {
        T newReal = real * other.real - imaginary * other.imaginary;
        T newImaginary = real * other.imaginary + imaginary * other.real;
        real = newReal;
        imaginary = newImaginary;
        return *this;
    }

    // Operator ++ (postfixat)
    Complex operator++(int) {
        Complex temp = *this;
        real += 1;
        return temp;
    }

    // Operator ++ (prefixat)
    Complex& operator++() {
        real += 1;
        return *this;
    }

    // Operator ==
    bool operator==(const Complex& other) const {
        return (real == other.real && imaginary == other.imaginary);
    }

    // Operator +
    Complex operator+(T x) const {
        return Complex(real + x, imaginary);
    }

    // Operator =
    Complex& operator=(const Complex& other) {
        if (this != &other) {
            real = other.real;
            imaginary = other.imaginary;
        }
        return *this;
    }

    // Afișare
    void display() const { cout << real << " + " << imaginary << "i" << endl; }
};

// Definirea operatorului >>
template <typename T>
istream& operator>>(istream& input, Complex<T>& c) {
    cout << "Partea reala: ";
    while (!(input >> c.real)) {
        cout << "Partea reala trebuie sa fie de tip numeric: ";
        input.clear();
        input.ignore(1000, '\n');
    }
    cout << "Partea imaginara: ";
    while (!(input >> c.imaginary)) {
        cout << "Partea imaginara trebuie sa fie de tip numeric: ";
        input.clear();
        input.ignore(1000, '\n');
    }
    return input;
}

// Definirea operatorului <<
template <typename T>
ostream& operator<<(ostream& output, const Complex<T>& c) {
    output << c.real << " + " << c.imaginary << "i";
    return output;
}

// Funcția-șablon externă pentru a aduna două numere complexe
template <typename T>
Complex<T> addComplexNumbers(const Complex<T>& c1, const Complex<T>& c2) {
    try {
        return Complex<T>(c1.getReal() + c2.getReal(), c1.getImaginary() + c2.getImaginary());
    } catch (const exception& e) {
        cerr << "Eroare la adunarea numerelor complexe: " << e.what() << endl;
        throw;
    }
}

// Supraîncărcarea operatorului + pentru int + Complex
template <typename T>
Complex<T> operator+(T x, const Complex<T>& c) {
    return Complex<T>(c.getReal() + x, c.getImaginary());
}

int main() {
    try {
        // Exemplu cu Complex<float>
        Complex<float> c1, c2;
        cout << "Introduceti primul numar complex:\n";
        cin >> c1;
        cout << "Introduceti al doilea numar complex:\n";
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

        // Comparație
        Complex<float> c4(3.0f, 4.0f), c5(3.0f, 4.0f);
        cout << "c4 == c5: " << (c4 == c5 ? "True" : "False") << endl;

        // Adunare cu întreg
        Complex<float> c6 = c1 + 5;
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

    } catch (const exception& e) {
        cerr << "Eroare in program: " << e.what() << endl;
    }

    return 0;
}
