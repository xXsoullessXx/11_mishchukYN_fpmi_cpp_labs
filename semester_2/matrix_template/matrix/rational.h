// rational.h

#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <numeric>
#include <cassert>

class Rational {
private:
    void Normalize() {
        int gcd = std::gcd(std::abs(num), denom);
        num /= gcd;
        denom /= gcd;
    }
public:
    Rational(int n = 0, int d = 1): num(n), denom(d) {
        assert(d > 0);
        Normalize();
    }
    Rational(const Rational& other): num(other.num), denom(other.denom) {}

    int GetNumerator() const {
        return num;
    }

    int GetDenominator() const {
        return denom;
    }
    
    Rational& operator=(const Rational& other) {
        num = other.num;
        denom = other.denom;
        return *this;
    }

    Rational& operator+=(const Rational& other) {
        // gcd(a, b) * lcm(a, b) = a * b 
        int gcd = std::gcd(denom, other.denom);
        int lcm = denom * other.denom / gcd;
        int res_num = num * lcm / denom + other.num * lcm / other.denom;
        
        num = res_num;
        denom = lcm;
        Normalize();
        return *this;
    }

    Rational& operator-=(const Rational& other) { 
        int gcd = std::gcd(denom, other.denom);
        int lcm = denom * other.denom / gcd;
        int res_num = num * lcm / denom - other.num * lcm / other.denom;
        
        num = res_num;
        denom = lcm;
        Normalize();
        return *this;
    }

    Rational& operator*=(const Rational& other) {
        num *= other.num;
        denom *= other.denom;
        Normalize();
        return *this;
    }
    
    Rational& operator/=(const Rational& other) {
        int other_sign = other.num > 0 ? 1 : -1;
        *this *= Rational(other_sign * other.denom, std::abs(other.num));
        Normalize();
        return *this;
    }

    Rational& operator++() { //prefix
        *this += 1;
        Normalize();
        return *this;
    }

    Rational operator++(int) { //postfix
        Rational copy = *this;
        *this += 1;
        Normalize();
        return copy;
    }

    bool operator<(const Rational& other) const {
        int denoms_gcd = std::gcd(denom, other.denom);
        int denoms_lcm = denom * other.denom / denoms_gcd;
        return num * denoms_lcm / denom < other.num * denoms_lcm / other.denom;
    }

    bool operator==(const Rational& other) const {
        return num == other.num && denom == other.denom;
    }

    bool operator!=(const Rational& other) const {
        return !(*this == other);
    }

    bool operator>(const Rational& other) const {
        return !(*this < other) && !(*this == other);
    }

    bool operator<=(const Rational& other) const {
        return !(*this > other);
    }

    bool operator>=(const Rational& other) const {
        return !(*this < other);
    }

    Rational operator-() {
        return Rational(-num, denom);
    }

    //operator double() const {
    //    return static_cast<double>(num) / denom;
    //}

    // operator int() const {
    //     return static_cast<int>(num / denom);
    // }

private:
    int num = 0;
    int denom = 0;
};

Rational operator+(const Rational& lhs, const Rational& rhs) {
    Rational sum = lhs;
    sum += rhs;
    return sum;
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
    Rational diff = lhs;
    diff -= rhs;
    return diff;
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
     Rational mul = lhs;
     mul *= rhs;
     return mul;
}

 Rational operator/(const Rational& lhs, const Rational& rhs) {
      Rational quotient = lhs;
      quotient /= rhs;
      return quotient;
}

std::ostream& operator<<(std::ostream& out, const Rational& frac) {
    if (frac.GetDenominator() == 1u) {
        out << frac.GetNumerator();
    } else {
        out << frac.GetNumerator() << '/' << frac.GetDenominator();
    }
    return out;
}

std::istream& operator>>(std::istream& in, Rational& frac) {
    int num;
    int denom;
    in >> num >> denom;
    frac = Rational(num, denom);
    return in;
}



#endif // RATIONAL_H

