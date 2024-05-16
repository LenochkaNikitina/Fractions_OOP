#include <iostream>
using namespace std;

class Fraction {
    int Integer;
    int Numerator;
    int Denominator;

    int greatest_common_diviser(int a, int b) {
        if (a < b) {
            swap(a, b);
        }

        while (a % b != 0) {
            a = a % b;
            swap(a, b);
        }
       
        return abs(b);
    }

    int least_common_multiple(int a, int b) {

        return (a * b) / greatest_common_diviser(a, b);
    }

    void improper(Fraction& a) {
        bool is_negative = a.Integer < 0;

        a.Numerator += abs(a.Integer) * a.Denominator;
        a.Integer = 0;

        if (is_negative) {
            a.Numerator *= -1;
        }
    }

    void reduce(Fraction& a) {
        int Greatest_common_diviser = greatest_common_diviser(a.Numerator, a.Denominator);

        a.Numerator /= Greatest_common_diviser;
        a.Denominator /= Greatest_common_diviser;
    }

    void to_proper(Fraction& a) {
        a.Integer = a.Numerator / a.Denominator;
        a.Numerator = a.Numerator % a.Denominator;
        if (a.Numerator < 0) a.Numerator *= -1;
    }

    void inverse_fraction(Fraction& a) {
        int temp = a.Numerator;
        a.Numerator = a.Denominator;
        a.Denominator = temp;
    }

   
public:
    Fraction(){}
    Fraction(int Int, int Num, int Denom) {
        Integer = Int;
        Numerator = Num;
        Denominator = Denom;
    }

    Fraction fraction_sum(Fraction& a) {
        Fraction temp_first{ Integer, Numerator, Denominator };
        Fraction temp_second = a;

        improper(temp_first);
        improper(temp_second);

        int Common_denominator = least_common_multiple(a.Denominator, Denominator);

        temp_first.Numerator *= Common_denominator / Denominator;
        temp_first.Denominator = Common_denominator;

        temp_second.Numerator *= Common_denominator / a.Denominator;
        temp_second.Denominator = Common_denominator;

        temp_first.Numerator += temp_second.Numerator;
               
        reduce(temp_first);

        to_proper(temp_first);

        return temp_first;
    }

    Fraction fraction_substr(Fraction& a) {
        Fraction temp_first{ Integer, Numerator, Denominator };
        Fraction temp_second = a;

        improper(temp_first);
        improper(temp_second);

        int Common_denominator = least_common_multiple(a.Denominator, Denominator);

        temp_first.Numerator *= Common_denominator / Denominator;
        temp_first.Denominator = Common_denominator;

        temp_second.Numerator *= Common_denominator / a.Denominator;
        temp_second.Denominator = Common_denominator;

        temp_first.Numerator -= temp_second.Numerator;

        reduce(temp_first);

        to_proper(temp_first);

        return temp_first;
    }

    Fraction fraction_multiplication(Fraction b) {
        improper(b);
        Fraction a{ Integer, Numerator, Denominator };
        improper(a);

        a.Numerator *= b.Numerator;
        a.Denominator *= b.Denominator;

        reduce(a);
        to_proper(a);

        return a;
    }

    Fraction fraction_division(Fraction b) {
        //Fraction a{ Integer, Numerator, Denominator };
        
        improper(b);
        //improper(a);

        inverse_fraction(b);

        b = fraction_multiplication(b);

        return b;
    }

    void print() {
        cout << Integer << ' ' << Numerator << '/' << Denominator << endl;
    }
};

int main() {
    setlocale(0, "rus");

    Fraction First(0, 5, 9);
    Fraction Second(1, 6, 8);
    Fraction Result;

    Result = First.fraction_sum(Second);
    Result.print();

    Result = First.fraction_substr(Second);
    Result.print();

    Result = First.fraction_multiplication(Second);
    Result.print();

    Result = First.fraction_division(Second);
    Result.print();

    return 0;
}

