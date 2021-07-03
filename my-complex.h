#ifndef __COMPLEX__
#define __COMPLEX__

#include <iostream>
#include <cmath>
class ostream;
class complex;
// complex& __doapl(complex* ths, const complex& r);

class complex
{
public:
    complex(double r=0, double i=0):re(r), im(i){}
    complex& operator+=(const complex&);
    // ostream& operator << (ostream& os, const complex&);
    double real() const { return re; }
    double imag() const { return im; }
    
private:
    double re, im;
    friend complex& __doapl(complex*, const complex&);
};

inline complex& 
__doapl(complex* ths, const complex& r)
{
    ths->re += r.re;
    ths->im += r.im;
    return *ths;
}

inline complex& 
complex::operator+= (const complex& r)
{
    return __doapl(this, r);
}

inline complex
operator + (const complex& x, const complex& y)
{
    return complex(x.real()+y.real(), x.imag()+y.imag());
}

inline complex
operator + (const complex& x, double y)
{
    return complex(x.real()+y, x.imag());
}

inline complex
operator + (double x, const complex& y)
{
    return complex(x+y.real(), y.imag());
}

inline bool
operator == (const complex& x, const complex& y)
{
    return x.real()==y.real() && x.imag()==y.imag();
}

inline complex
conj (const complex&x)
{
    return complex(x.real(), -x.imag());
}

ostream&
operator << (ostream& os, const complex& x)
{
    return os << '(' << x.real() << ',' << x.imag() << ')';
}



#endif