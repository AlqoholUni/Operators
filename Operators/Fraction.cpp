#include <iostream>
#include <string>

using namespace std;

// This class stores a fraction's numerator and denominator
class Fraction
{
	int numerator;
	int denominator;
public:
	Fraction(): numerator(0), denominator(0) { }
	// Empty constructor required because no arg constructor called in main for f3
	Fraction(int a, int b)
	{
		numerator = a;
		denominator = b;
	}

	int getNumerator() const { return numerator; }
	int getDenominator() const { return denominator; }
	void setNumerator(int x) { numerator = x; }
	void setDenominator(int y) { denominator = y; }

	Fraction operator +(Fraction& f) const;
	Fraction operator *(Fraction& f) const;
	bool operator >(Fraction& f) const;
};

Fraction Fraction::operator+(Fraction& f) const
{
	Fraction f3;
	auto num3 = (numerator * f.getDenominator()) + (f.getNumerator() * denominator);
	auto den3 = denominator * f.getDenominator();
	f3 = Fraction(num3, den3);
	return f3;
}

Fraction Fraction::operator*(Fraction& f) const
{
	Fraction f3;
	f3 = Fraction(numerator * f.getNumerator(), denominator * f.getDenominator());
	return f3;
}

bool Fraction::operator>(Fraction& f) const 
{
	auto f1 = float(numerator) / float(denominator);
	auto f2 = float(f.getNumerator()) / float(f.getDenominator());
	return f1 > f2 ? true : false;
}

// The following two functions are 'global functions',
// ie not a member of a class - not an OO approach but common C-like approach.
// Assumes inputs are valid (no input error checking).
int readNum(string str)
{
	int fslash = str.find('/'); // Finds index of '/' symbol in string
	auto val = str.substr(0, fslash); // Extracts numerator as a string
	auto value = atoi(val.c_str()); // Converts numerator to an int
	return value;
};

int readDen(string str)
{
	int fslash = str.find('/');
	int end = str.length(); // Length of input string
	auto val = str.substr(fslash + 1, end); // Extracts denominator as a string
	auto value = atoi(val.c_str());  // Converts denominator to an int
	return value;
};

int main()
{
	string fraction1;
	string fraction2;
	cout << "This program processes a fraction entered at the keyboard using syntax 'a/b'." << endl;
	cout << "Enter fraction 1:";
	cin >> fraction1;
	auto num = readNum(fraction1);
	auto den = readDen(fraction1);
	Fraction f1(num, den);   // Create the first fraction object
	
	cout << "Enter fraction 2:";
	cin >> fraction2;
	auto num2 = readNum(fraction2);
	auto den2 = readDen(fraction2);
	Fraction f2(num2, den2);

	auto test = f1 > f2;
	//auto f3 = f1 * f2;

	cout << "Fraction1 is " << f1.getNumerator() << "/" << f1.getDenominator() << endl;
	cout << "Fraction2 is " << f2.getNumerator() << "/" << f2.getDenominator() << endl;
	cout << "Fraction1 > Fraction2 = " << test << endl;
	system("pause");

	return 0;
}