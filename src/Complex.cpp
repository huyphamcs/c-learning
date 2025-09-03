#include<math.h>
#include<iostream>
using namespace std;
const double PI = 3.141592653589793238463;

class Complex
{
private:
    double real;
    double img;

public:
    Complex() {}
    Complex(double real, double img)
    {
        this->real = real;
        this->img = img;
    }
    double getReal()
    {
        return real;
    }
    double getImg()
    {
        return img;
    }
    void setReal(double real)
    {
        this->real = real;
    }
    void setImg(double img)
    {
        this->img = img;
    }
    Complex operator+(const Complex &other)
    {
        return Complex(real + other.real, img + other.img);
    }
    Complex operator-(const Complex &other)
    {
        return Complex(real - other.real, img - other.img);
    }
    Complex operator*(const Complex &other)
    {
        return Complex(real * other.real - img * other.img, real * other.img + img * other.real);
    }
    Complex operator/(const Complex &other)
    {
        return Complex((real * other.real + img * other.img) / (other.real * other.real + other.img * other.img), (img * other.real - real * other.img) / (other.real * other.real + other.img * other.img));
    }
    double complexModule()
    {
        return sqrt(real * real + img * img);
    }
    double argumentAsRad()
    {
        return atan(img / real);
    }
    double argumentAsDeg()
    {
        return argumentAsRad() * (180.0 / PI);
    }
    Complex conjugate()
    {
        return Complex(real, img * (-1.0));
    }
    void print()
    {
        cout << real << (img > 0 ? " + " : " - ") << (img > 0 ? img : -img) << "i" << endl;
    }
};