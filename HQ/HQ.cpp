#include <iostream>
#include <string>

/*1. Создать абстрактный класс Figure (фигура). Его наследниками являются классы Parallelogram (параллелограмм) и Circle (круг). 
Класс Parallelogram — базовый для классов Rectangle (прямоугольник),
Square (квадрат), Rhombus (ромб). Для всех классов создать конструкторы.
Для класса Figure добавить чисто виртуальную функцию area() (площадь).
Во всех остальных классах переопределить эту функцию, исходя из геометрических формул нахождения площади.*/

class Figure
{
public:
	
	Figure() {};

	virtual float area() = 0;
}; 

class Parallelogram:Figure
{
public:
	
	Parallelogram(float _longA , float heightH)
		: A(_longA), H(heightH) 
	{
	}

	float area() override
	{
		return (A * H);
	}

protected:

	float A, H;

};

class Circle:Figure
{
public:
	Circle(float rangeR)
		:R(rangeR)
	{
	}

	float area() override
	{
		return (3.14F * R * R);
	}
protected:

	float R;
};

class Rectangle:public Parallelogram
{
public:
	Rectangle(float _longA, float heightH)
		: Parallelogram(_longA, heightH) 
	{
	}

	float area() override
	{
		return ( A * H);
	}
};

class Square:Parallelogram
{
public:
	Square(float _longA)
		:Parallelogram(_longA, _longA)
	{
	}
	float area() override
	{
		return (A * A);
	}
};

class Rhombus:Parallelogram
{
public:
	Rhombus(float _longA, float heightH)
		: Parallelogram(_longA, heightH)
	{
	}
	
	float area () override
	{
		return (A * H);
	}
};

/*2. Создать класс Car (автомобиль) с полями company (компания) и model (модель). 
Классы-наследники: PassengerCar (легковой автомобиль) и Bus (автобус). От этих классов наследует класс Minivan (минивэн).
Создать конструкторы для каждого из классов, чтобы они выводили данные о классах. Создать объекты для каждого из классов и посмотреть, в какой последовательности выполняются конструкторы.
Обратить внимание на проблему «алмаз смерти».*/

class Car
{
public:
	Car() {};
	Car(std::string company, std::string model)
		:_Company(company),_Model(model)
	{
		std::cout << "Creating Object Car" << std::endl;
	}
	~Car()
	{
		std::cout << "Deleting Object Car" << std::endl;
	}
protected:
	std::string _Company;
	std::string _Model;
};

class PassengerCar:virtual public Car
{
public:
	PassengerCar(){}
	PassengerCar(std::string company,std::string modele)
		:Car(company,modele)
	{
		std::cout << "Creating Object Car - PassengerCar " << std::endl;
		std::cout << company << " " << modele << std::endl;
	}
	~PassengerCar()
	{
		std::cout << "Deleting Object PassengerCar" << std::endl;
	}

};

class Bus:virtual public Car
{
public:
	Bus(){}
	Bus(std::string company, std::string modele)
		:Car(company,modele)
	{
		std::cout << "Creating Object Car - Bus " << std::endl;
		std::cout << company << " " << modele << std::endl;
	}
	~Bus()
	{
		std::cout << "Deleting Object Bus" << std::endl;
	}

};

class Minivan:public PassengerCar, public Bus
{
public:
	Minivan(std::string company, std::string modele)
		:Car(company, modele)
	{
		std::cout << "Creating Object Car - Minivan " << std::endl;
		std::cout << company << " " << modele << std::endl;
	}
	~Minivan()
	{
		std::cout << "Deleting Object Minivan " << std::endl;
	}

};

/*3. Создать класс: Fraction (дробь). Дробь имеет числитель и знаменатель (например, 3/7 или 9/2). Предусмотреть, чтобы знаменатель не был равен 0. Перегрузить:
математические бинарные операторы (+, -, *, /) для выполнения действий с дробями
унарный оператор (-)
логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).

Примечание: Поскольку операторы < и >=, > и <= — это логические противоположности, попробуйте перегрузить один через другой.

Продемонстрировать использование перегруженных операторов.*/

class Fraction
{
public:
	Fraction(double numer, double denomin)
		:Numerator(numer), Denominator(denomin)
	{
		if (Denominator == 0)
		{
			Denominator = 0.0000001;
		}
	}
	friend Fraction operator+(const Fraction& a1, const Fraction& a2);
	friend Fraction operator-(const Fraction& a1, const Fraction& a2);
	friend Fraction operator*(const Fraction& a1, const Fraction& a2);
	friend Fraction operator/(const Fraction& a1, const Fraction& a2);
	friend Fraction operator-(const Fraction& a1);
	friend std::ostream& operator<<(std::ostream&, const Fraction& fraction);

	void setDenominator(double denomin)
	{
		if (denomin == 0)
		{
			denomin = 0.0000001;
		}
		else
		{
			Denominator = denomin;
		}
	}

	void setNumerator(double numer)
	{
		Numerator = numer;
	}

	double getNumerator()
	{
		return Numerator;
	}
	double getDenominator()
	{
		return Denominator;
	}

private:
	double Numerator, Denominator;
};

Fraction operator+(const Fraction& a1, const Fraction& a2)
{
	return Fraction(a1.Numerator * a2.Denominator + a2.Numerator*a1.Denominator,a1.Denominator*a2.Denominator);
}

Fraction operator-(const Fraction& a1, const Fraction& a2)
{
	return Fraction(a1.Numerator * a2.Denominator - a2.Numerator * a1.Denominator, a1.Denominator * a2.Denominator);
}
Fraction operator*(const Fraction& a1, const Fraction& a2)
{
	return Fraction(a1.Numerator*a2.Numerator,a1.Denominator*a2.Denominator);
}
Fraction operator/(const Fraction& a1, const Fraction& a2)
{
	return Fraction(a1.Numerator*a2.Denominator,a1.Denominator*a2.Numerator);
}
Fraction operator-(const Fraction& a1)
{
	return Fraction(-a1.Numerator,-a1.Denominator);
}
bool operator==(Fraction& a1, Fraction& a2)
{
	if ((a1.getNumerator()== a2.getNumerator())&&(a1.getDenominator()==a2.getDenominator()))
	{
		return true;
	}
	else 
	{
		return false;
	}
}
bool operator!=(Fraction& a1, Fraction& a2)
{
	if (a1 == a2)
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool operator>(Fraction& a1, Fraction& a2)
{
	if ((a1.getNumerator() / a1.getDenominator()) > (a2.getNumerator() / a2.getDenominator()))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator<(Fraction & a1, Fraction & a2)
{
	if ((a1.getNumerator() / a1.getDenominator()) < (a2.getNumerator() / a2.getDenominator()))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator<=(Fraction& a1, Fraction& a2)
{
	if (!(a1 > a2))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator>=(Fraction& a1, Fraction& a2)
{
	if (!(a1 < a2))
	{
		return true;
	}
	else
	{
		return false;
	}
}
std::ostream& operator<<(std::ostream& out, const Fraction& fraction)
{
	out << fraction.Numerator << "/" << fraction.Denominator;
	return out;

}
//=========================================================================================================================
/*4 Создать класс Card, описывающий карту в игре БлэкДжек. У этого класса должно быть три поля: масть, значение карты и положение карты (вверх лицом или рубашкой). 
Сделать поля масть и значение карты типом перечисления (enum). Положение карты - тип bool. Также в этом классе должно быть два метода:
метод Flip(), который переворачивает карту, т.е. если она была рубашкой вверх, то он ее поворачивает лицом вверх, и наоборот.
метод GetValue(), который возвращает значение карты, пока можно считать, что туз = 1.*/

class Card
{
public:
	
	Card()

	{

	}
	void Flip()
	{
		shirt_top = !shirt_top;
	}

	value_en GetValue()
	{
		return Value;
	}
private:
	suit_en Suit;
	value_en Value;
	bool shirt_top;
};

enum suit_en
{
	CLUBS,
	DIAMONDS,
	HEARTS,
	SPADES
};

enum value_en
{
	ACE = 1,
	TWO = 2,
	THREE = 3,
	FOUR = 4,
	FIVE = 5,
	SIX = 6,
	SEVEN = 7,
	EIGHTH = 8,
	NINE = 9,
	TEN = 10,
	JACK = 10,
	QUEEN = 10,
	KING = 10,
};


int main ()
{
	setlocale(LC_ALL, "rus");
	//Task 1==============================================================
	float Parallelogram_long(4);
	float Prarllelogram_heiht(6.1F);
	Parallelogram paralleloram(Parallelogram_long, Prarllelogram_heiht);
	std::cout << paralleloram.area() << std::endl;

	float Cirle_renge(3.5);
	Circle circle(Cirle_renge);
	std::cout << circle.area() << std::endl;

	float rectangle_long(5);
	float rectangle_heiht(5);
	Rectangle rectangle(rectangle_long, rectangle_heiht);
	std::cout << rectangle.area() << std::endl;

	float Square_long(5);
	Square square(Square_long);
	std::cout << square.area() << std::endl;

	float Rhombus_long(3);
	float Rhombus_heiht(4);
	Rhombus rhombus(Rhombus_long, Rhombus_heiht);
	std::cout << rhombus.area() << std::endl;

	std::cout << std::endl;
	//Task 2=================================================================

	Car* car = new Car("Lada", "2110");
	std::cout << std::endl;
	PassengerCar* Pascar = new PassengerCar("Mazda", "3");
	std::cout << std::endl;
	Bus* bus = new Bus("НефАЗ", "5299");
	std::cout << std::endl;
	Minivan* miniv = new Minivan("Mitsubishi", "Delica");
	std::cout << std::endl;
	delete miniv;
	std::cout << std::endl;
	delete bus;
	std::cout << std::endl;
	delete Pascar;
	std::cout << std::endl;
	delete car;
	std::cout << std::endl;

	//Task 3=================================================================
	Fraction a1(3, 7);
	Fraction a2(9, 2);
	std::cout << (a1 + a2) << std::endl;
	std::cout << (a1 - a2) << std::endl;
	std::cout << (a1 * a2) << std::endl;
	std::cout << (a1 / a2) << std::endl;
	std::cout << (-a1) << std::endl;

	if (a1 == a2) std::cout << "Fraction 1 == Fraction 2" << std::endl;
	if (a1 != a2) std::cout << "Fraction 1 != Fraction 2" << std::endl;
	if (a1 > a2) std::cout << "Fraction 1 > Fraction 2" << std::endl;
	if (a1 <= a2) std::cout << "Fraction 1 <= Fraction 2" << std::endl;
	if (a1 < a2) std::cout << "Fraction 1 < Fraction 2" << std::endl;
	if (a1 >= a2) std::cout << "Fraction 1 >= Fraction 2" << std::endl;
	return 0;
}