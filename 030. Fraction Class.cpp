// Problem: https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118817/offering/1381816

#include<iostream>

#include<algorithm>

using namespace std;

class Fraction {

    public:
    int num, den; // Numerator and Denominator
    
    Fraction(int n, int d)
    {
        this->num = n;
        this->den = d;
    }
    
    void add(Fraction f)
    {
        this->num = this->num * f.den + this->den * f.num;
        this->den = this->den * f.den;
        this->simplify();
    }
    
    void multiply(Fraction f)
    {
        this->num = this->num * f.num;
        this->den = this->den * f.den;
        this->simplify();
    }
    
    void simplify()
    {
        int gcd = __gcd(this->num,this->den);
        this->num /= gcd;
        this->den /= gcd;
    }

};

int main() {

    int n1, d1; // Numerator and Denominator of first Fraction
    cin >> n1 >> d1;
    Fraction f1(n1,d1);
    
    int q; // Number of Queries
    cin >> q;
    for(int i=0; i<q; i++)
    {
        int c; // Choice
        int n2, d2; // Numerator and Denominator of first Fraction
        cin >> c >> n2 >> d2;
        Fraction f2(n2,d2);
        if(c == 1)
        {
            f1.add(f2);
            cout << f1.num << "/" << f1.den << endl;
        }
        else if(c == 2)
        {
            f1.multiply(f2);
            cout << f1.num << "/" << f1.den << endl;
        }
        else
        {
            continue;
        }
    }

    return 0;
}
