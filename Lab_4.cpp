

#include "pch.h"
#include <iostream>
#include <exception>
#include <fstream>
using namespace std;

class Rational
{
public:
		
	Rational() {
		 numerator = 0;
		 denominator = 1;
		 sign = 1;
	};

	Rational(int x) {
		numerator = x;
		denominator = 1;
		sign = 1;
		if (numerator < 0) {
			numerator *= -1;
			sign = -1;
		}
		
	};
	Rational(int x,int y) {
		if (y == 0) {
			throw out_of_range("Знаменатель не может равняться нулю!");
		}

		 numerator = x;
		 denominator = y;
		
		 sign = 1;
		
		 if (numerator < 0 ) {
			 numerator *= -1;
			 sign = -1;
		 }
		 if (denominator < 0) {
			 denominator *= -1;
			 sign = -1;
		 }
		 Getmixednum();
		};
		

	~Rational() {
		
	};

	
	friend ostream & operator<<(ostream& stream, Rational&ratio) {
		if (ratio.sign ==-1) {
			stream << '-';
		}
				
		stream << ratio.numerator << "/" << ratio.denominator<<" " ;
				
		return stream;
	}

	friend istream & operator>>(istream&stream, Rational&ratio) {

		stream >> ratio.numerator >> ratio.denominator;
		return stream;
	}

	void Getmixednum() {
		
		reduction();
		}
	
	
	void reduction() {

		if (numerator != 0) {
			int d = denominator;
			int n = numerator;
						
			while (n != d)
			{
				if (n > d)
					n -= d;
				else d -= n;
			}
			int nod = n;
			if (nod != 1) {

				numerator /= nod;
				denominator /= nod;
			}
		}
	}

	   	  
	bool operator==(const Rational & other)
	{
		if ((numerator != other.numerator || denominator != other.denominator))
		{
			
			return false;
		}
		else {
			
			return true;
		}
	}

	bool operator!=(const Rational & other)
	{
		return !(this->operator==(other));
		
	}
	   

	bool operator >(Rational  other)//////Сравнение(больше)
	{
		
		if (double(this->numerator/this->denominator) > double(other.numerator/other.denominator)) {
			
			return true;
		}
		if (double(this->numerator / this->denominator) == double(other.numerator / other.denominator)) {

			return false;
		}
			return false;
		}
	
	bool operator <(Rational  other)//////Сравнение(меньше)
	{

		if (double(this->numerator / this->denominator) < double(other.numerator / other.denominator)) {

			return true;
		}
		if (double(this->numerator / this->denominator) == double(other.numerator / other.denominator)) {

			return false;
		}
		return false;
	}

	bool operator >=(Rational  other)//////Сравнение(больше или равно)
	{
		
		if ((this->operator==(other)) && !(this->operator>(other))) {
			return true;
		}
		else if 
			(!(this->operator==(other)) && (this->operator>(other))){
			return true;
		}
		return false;
				
	}

	bool operator <=(Rational  other)//////Сравнение(меньше или равно)
	{

		if ((this->operator==(other)) && !(this->operator<(other))) {
			return true;
		}
		else if
			(!(this->operator==(other)) && (this->operator<(other))) {
			return true;
		}
		return false;
	}

	Rational operator +=(const Rational & other) {

		
		this->numerator = (numerator*other.denominator + other.numerator*denominator);
		this->denominator = (denominator*other.denominator);
		this->Getmixednum();
		return *this;

}
	Rational operator +(const Rational & other) {
				
		return (this->operator+=(other));

	}
	Rational operator -=(const Rational & other) {


		this->numerator = (numerator*other.denominator - other.numerator*denominator);
		if (this->numerator < 0) {

			this->numerator*=-1;
			this->sign = -1;
		}
		this->denominator = (denominator*other.denominator);
		this->Getmixednum();
		return *this;

	}
	
	Rational operator -(const Rational & other) {
				
		return(this->operator-=(other));
	}

	Rational operator *=(const Rational & other) {


		this->numerator = (numerator* other.numerator);
		if (this->numerator < 0) {

			this->numerator *= -1;
			this->sign = -1;
		}
		this->denominator = (denominator*other.denominator);
		this->Getmixednum();
		return *this;

	}
	
	Rational operator *(const Rational & other) {
		return (this->operator*=(other));
	}
	
	Rational operator /=(const Rational & other) {


		this->numerator = (numerator* other.denominator);
		if (this->numerator < 0) {

			this->numerator *= -1;
			this->sign = -1;
		}
		this->denominator = (denominator*other.numerator);
		this->Getmixednum();
		return *this;

	}
	
	Rational operator /(const Rational & other) {
	
		return (this->operator/=(other));
	}

	Rational operator -() {

		return Rational(numerator*=-1,denominator);

	}

	Rational operator ++() {
		numerator++;
		denominator++;
		Getmixednum();
		return *this;
	}
	
	Rational operator ++(int) {
		
		Rational previous(*this);
		numerator++;
		denominator++;
		Getmixednum();
		return previous;
	}

	Rational operator --() {
		numerator--;
		denominator--;
		Getmixednum();
		return *this;
	}

	Rational operator --(int) {
		Rational previous(*this);
		numerator--;
		
		denominator--;
		if (this->denominator == 0) {
			this->denominator = 1;
		}
		Getmixednum();
		return previous;
	}

	Rational Getreversenum() {//Обратное
				
		int n;
		n = numerator;
		this->numerator = denominator;
		this->denominator = n;
		return *this;

	}
	
	Rational Getrealnumber() {//вещественное
		
		double result = (double(numerator) / double(denominator));
		cout << "Вещественное число : " << result << endl;
		return result;
		
	}
	
	Rational Getwholenumber() {
		double result = (double(numerator) / double(denominator));
		cout << "Целое число : " << result << endl;
		return result;
	}

	

private:
	
	int numerator;//числитель
	int denominator;//знаменатель
	int sign;//знак
};



int main()
{
	setlocale(LC_ALL, "ru");
		
	try                                      //Если знаменталь равен нулю.
	{
		Rational a(18,34);
		Rational c(18,3);

		cout << a << endl;
		cout << c << endl;
	
	
			
	//cin >> a;   //ввод
	//cout << a;

		//Сравнение на

	//bool g = a == c;    //равенство
	//cout << g << endl;

	//bool l = a != c;    //неравенство
	//cout << l << endl;
	
	//bool p = a > c;      //больше
	//cout << p <<endl;

	//bool t = a >= c;     //больше или равно
	//cout << t << endl;
	
	//bool y = a < c;      //меньше
	//cout << y << endl;

	//bool t1 = a <= c;		//меньше или равно
	//cout << t1 << endl;

		//арифметические бинарные операторы 

	//a += c;				// +=
	//cout<< a<<endl;

	//Rational res;			// +
	//res = a + c;
	//cout << res << endl;
	
	
	//a -= c;				// -=
	//cout << a << endl;
	
	//Rational result;		// -
	//result = a - c;
	//cout << result << endl;
	
	//a *= c;				// *=	
	//cout << a << endl;

	//Rational res1;		// *
	//res1 = a * c;
	//cout << res1<<endl;

	/*a /= c;				// /=
	cout << a << endl;*/

	//Rational res2;			// /
	//res2 = a / c;
	//cout << res2 << endl;
	
	//cout << -a;             //(унарный минус)

	//cout << ++a;			//Инкремент префиксный
	
	//Rational b=a++;	     //Инкремент постфиксный
	//cout << "->переменной присвоено значение a:" << b <<endl;
	//cout << "Новое значение a: " << a <<endl;
	
		
	//Декремент постфиксный
	//Rational w=c--;	    
	//cout << "->переменной присвоено значение c:" << w <<endl;
	//cout << "Новое значение c: " << c <<endl;
	
	//-a;						//Унарный минус
	//cout << a << endl;

	//++c;						//Инкремент префиксный
	//cout << c << endl;
	
	//--a;						//Декремент префиксный
	//cout << a << endl;

	

	//c.Getwholenumber(); //Получение целого числа
		
	//a.Getrealnumber();	//Получение вещественного числа
	
	
	//a.Getreversenum();						//Получение обратного числа
	//cout << a << endl;
	
		
	}
	catch (const std::exception&)
	{
		cout << "Знаменатель не может равняться нулю" << endl;
	}
	system("pause");
}

