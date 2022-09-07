#include <iostream>
#include <string>
/*1. Создать класс Person (человек) с полями: имя, возраст, пол и вес. 
Определить методы переназначения имени, изменения возраста и веса. Создать производный класс Student (студент), имеющий поле года обучения. 
Определить методы переназначения и увеличения этого значения.
Создать счетчик количества созданных студентов. В функции main() создать несколько (не больше трёх) студентов. Вывести информацию о них.*/

class Person
{
public:
	Person() = default;

	Person( const std::string &name, const std::string &gander , const size_t &age, const size_t &weight )
		: m_name(name), m_gender(gander), m_age(age), m_weight(weight)
	{

	}
	std::string getName() const { return m_name; }
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
		_countC++;
	}
	~Student()
	{
		_countC--;
	}
	size_t year() 
	{
		m_StudYear++;
	}
	void SetyearOS(const size_t _year_os)
	{
		m_StudYear = _year_os;
	}

	const int get_countC() const { return _countC; }


private:
	size_t m_StudYear;
	static int _countC;
};

int Student::_countC = 0;



int main (){
	setlocale(LC_ALL, "rus");
	Student grisha("Гриша", "Мужчина", 21, 74, 2022);
	
	return 0;
}