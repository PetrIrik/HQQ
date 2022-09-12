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
	
	virtual float area() = 0;
}; 
class Parallelogram:Figure
{
public:
	

private:

};

class Cilrcle
{
public:
	

private:

};





int main (){

	return 0;
}