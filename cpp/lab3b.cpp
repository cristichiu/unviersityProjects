#include <iostream>
using namespace std;

class Complex {
    private:
    float real, imaginary;
    public:
    Complex(): real(0), imaginary(0) {}
    Complex(float r, float i): real(r), imaginary(i) {}
    Complex(const Complex &original): real(original.real), imaginary(original.imaginary) {}
    friend istream& operator>>(istream& input, Complex& c);
    friend ostream& operator<<(ostream& output, const Complex& c);

    float setReal() {
        cout<<"Partea reala: ";
        while(!(cin>>real)) { cout<<"Partea reala trebuie sa fie de tip float: "; cin.clear(); cin.ignore(1000, '\n'); }
        return real;
    }
    float setImaginary() {
        cout<<"Partea imaginara: ";
        while(!(cin>>imaginary)) { cout<<"Partea imaginara trebuie sa fie de tip float: "; cin.clear(); cin.ignore(1000, '\n'); }
        return imaginary;
    }
    float getReal() const { return real; }
    float getImaginary() const { return imaginary; }

    friend Complex &operator*=(Complex &first, const Complex &second);
    friend Complex operator++(Complex& c, int);
    friend Complex& operator++(Complex& c);
    friend bool operator==(const Complex& first, const Complex& second);
    friend Complex operator+(int x, const Complex& c);
    friend Complex operator+(const Complex& c, int x);
    Complex &operator=(const Complex &other) {
        if (this != &other) {
            real = other.real;
            imaginary = other.imaginary;
        }
        return *this;
    }

    void display() const { cout << real << " + " << imaginary << "i" << endl; }
};

istream& operator>>(istream& input, Complex& c) {
    cout<<"Partea reala: ";
    while(!(input>>c.real)) { cout<<"Partea reala trebuie sa fie de tip float: "; input.clear(); input.ignore(1000, '\n'); }
    cout<<"Partea imaginara: ";
    while(!(input>>c.imaginary)) { cout<<"Partea imaginara trebuie sa fie de tip float: "; input.clear(); input.ignore(1000, '\n'); }
    return input;
}

ostream& operator<<(ostream& output, const Complex& c) {
    output<<c.real<<" + "<<c.imaginary<<"i";
    return output;
}

Complex& operator*=(Complex& first, const Complex& second) {
    float newReal = first.real * second.real - first.imaginary * second.imaginary;
    float newImaginary = first.real * second.imaginary + first.imaginary * second.real;
    first.real = newReal;
    first.imaginary = newImaginary;
    return first;
}

Complex operator++(Complex& c, int) {
    Complex temp = c;
    c.real += 1;
    return temp;
}

Complex& operator++(Complex& c) {
    c.real += 1;
    return c;
}

bool operator==(const Complex& first, const Complex& second) {
    return (first.real == second.real && first.imaginary == second.imaginary);
}

Complex operator+(const Complex& c, int x) {
    return Complex(c.real + x, c.imaginary);
}

Complex operator+(int x, const Complex& c) {
    return Complex(c.real + x, c.imaginary);
}

int main() {
    Complex c1, c2;
    cin>>c1>>c2;
    cout<<c1<<endl<<c2<<endl;

    c1 *= c2;
    cout<<c1<<endl;

    Complex c3 = c1++;
    cout<<c1<<endl<<c3<<endl;

    ++c1;
    cout<<c1<<endl;

    Complex c4(3, 4), c5(3, 4);
    cout << "c4 == c5: " << (c4 == c5 ? "True" : "False") << endl;

    Complex c6 = c1 + 5;
    cout<<c6<<endl;

    Complex c7 = 5 + c1;
    cout<<c7<<endl;

    Complex c8;
    c8 = c1;
    cout<<c8<<endl;

    return 0;
}
