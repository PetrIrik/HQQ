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
		std::cout << " Студент № " << get_countC() << std::endl;
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



int main (){
	setlocale(LC_ALL, "rus");
	Student grisha("Гриша", "Мужчина", 21, 69, 2022);
	grisha.PrintInfStudent();
	
	Student Petr("Петр", "Мужчина", 24, 75, 2022);
	Petr.PrintInfStudent();

	Student Anna("Анна", " Женщина ", 20, 59, 2022);
	Anna.PrintInfStudent();
	
	return 0;
}