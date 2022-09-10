﻿#include <iostream>
#include <string>
/*1. Создать класс Person (человек) с полями: имя, возраст, пол и вес. 
Определить методы переназначения имени, изменения возраста и веса. Создать производный класс Student (студент), имеющий поле года обучения. 
Определить методы переназначения и увеличения этого значения.
Создать счетчик количества созданных студентов. В функции main() создать несколько (не больше трёх) студентов. Вывести информацию о них.*/

class Person
{
public:
	Person() = default;

	Person( const std::string &name, const std::string &gander , const size_t age, const size_t weight )
		: m_name(name), m_gender(gander), m_age(age), m_weight(weight)
	{

	}
	std::string getName() const { return m_name; }
	std::string getGender() const { return m_gender;  }
	size_t getAge() const { return m_age; }
	size_t getWeight() const { return m_weight; }

private:
	std::string m_name;
	std::string m_gender;
	size_t m_age;
	size_t m_weight;
};
class Student:Person
{
public:
	
	Student(const std::string &name, const  std::string &gander,const size_t age,const size_t weight,const size_t yearos)
		: Person (name, gander, age, weight) , m_StudYear(yearos)
	{
		_countS++;
	}
// yearos - "year of study" - год обучения .
	~Student()
	{
		_countS--;
	}
	size_t year_increase()// увеличение года 
	{
		m_StudYear++;
	}

	void SetyearOS(const size_t _year_os)// Присваивание года 
	{
		m_StudYear = _year_os;
	}


	const int get_countC() const { return _countS; }
	const size_t getStudy_year() const { return m_StudYear; }

	void PrintInfStudent() 
	{
		std::cout << " Имя = " << getName() << std::endl;
		std::cout << " Пол = " << getGender() << std::endl;
		std::cout << " Возраст = " << getAge() << std::endl;
		std::cout << " Год обучения = " << getStudy_year() << std::endl;
		
		std::cout << std::endl;
	}
private:
	size_t m_StudYear;
	static int _countS;// счетчик студенто 
	
};

int Student::_countS = 0;

/*2. Создать классы Apple (яблоко) и Banana (банан), которые наследуют класс Fruit (фрукт).
У Fruit есть две переменные-члена: name (имя) и color (цвет). Добавить новый класс GrannySmith, который наследует класс Apple.*/

class Fruit
{
public:

	Fruit() = default; 

	Fruit(const std::string name, const std::string color)
		: f_name(name), f_color(color)
	{

	}

	std::string  getName() const { return f_name;  }
	std::string  getColor() const { return f_color; }
	
	
private:
	std::string f_name;
	std::string f_color;
};

class Apple:public Fruit
{
public:
	Apple(const std::string color , const std::string name = "")
		: Fruit(name + "apple", color)
	{
	}

private:
	
};

class Banana:public Fruit
{
public:
	Banana() : Fruit(" banana ", " yellow ")
	{
	}
private:

};

class GrannySmith:public Apple
{
public:
	GrannySmith() : Apple( " green ", " Granny Smith ")
	{
	}

private:

};

/*3. Изучить правила игры в Blackjack. Подумать, как написать данную игру на С++, используя объектно-ориентированное программирование. 
Сколько будет классов в программе? Какие классы будут базовыми, а какие производными? Продумать реализацию игры с помощью классов и
записать результаты в виде комментария в основном файле сдаваемой работы.*/

class Game //условия игры 
{
public:
	

private:

};

enum list_deck
{
	_2, _3, _4, _5, _6, _7, _8, _9, _10,
	A = 1,
	J, Q, K,
};

enum class Suit
{
	clubs ,	    //♣️
	diamonds,	//♦️
	hearts,		//♥️
	spades,		//♠️
};


class Hand //рука в которые 
{
public:
	

private:

};





class Deck:Hand // карты в руке 
{
public:
	
private:

};

class Players // описания играков от()-до() , их слоты , и поинты из игру и которые им выдал дилер 
{

};

class Player:Players // сам игрок 
{

};

class Computre // компьютер 
{

};






int main (){
	setlocale(LC_ALL, "rus");
	Student grisha("Гриша", "Мужчина", 21, 69, 2022);
	grisha.PrintInfStudent();
	
	Student Petr("Петр", "Мужчина", 24, 75, 2022);
	Petr.PrintInfStudent();

	Student Anna("Анна", " Женщина ", 20, 59, 2022);
	Anna.PrintInfStudent();
	std::cout << std::endl;

	Apple a(" red ");
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";


	return 0;
}