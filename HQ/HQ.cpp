#include <iostream>
#include <cmath>
#include <cstdint>

class Power 
{
public:
	void Set(const float a, const float b)
	{
		_a = a;
		_b = b;
	}

	void Calculete() 
	{
		std::cout <<"Число :" << _a <<" в степени :"<< _b << " = " << pow(_a, _b) << std::endl;
	}
	

private:
	float _a;
	float _b;
};
//2. Написать класс с именем RGBA, который содержит 4 переменные-члена типа std::uint8_t: m_red, m_green, m_blue и m_alpha (#include cstdint для доступа к этому типу). 
// Задать 0 в качестве значения по умолчанию для m_red, m_green, m_blue и 255 для m_alpha. Создать конструктор со списком инициализации членов, 
//который позволит пользователю передавать значения для m_red, m_blue, m_green и m_alpha. Написать функцию print(), которая будет выводить значения переменных-членов.

class RGBA
{
public:

	RGBA(uint8_t red = 0 , uint8_t green = 0 , uint8_t blue= 0, uint8_t alpha= 255) :m_red(red),m_green(green), m_blue(blue), m_alpha(alpha)
	{

	}

	void print()
	{
		std::cout << " R " << static_cast<int>(m_red) << std::endl;
		std::cout << " G " << static_cast<int>(m_green) << std::endl;
		std::cout << " B " << static_cast<int>(m_blue) << std::endl;
		std::cout << " A " << static_cast<int>(m_alpha) << std::endl;

	}

private:
	uint8_t m_red;
	uint8_t m_green;
	uint8_t m_blue;
	uint8_t m_alpha;
};

/*3 .Написать класс, который реализует функциональность стека. Класс Stack должен иметь:
• private-массив целых чисел длиной 10;

• private целочисленное значение для отслеживания длины стека;

• public-метод с именем reset(), который будет сбрасывать длину и все значения элементов на 0;

• public-метод с именем push(), который будет добавлять значение в стек. push() должен возвращать значение false, если массив уже заполнен, и true в противном случае;

• public-метод с именем pop() для вытягивания и возврата значения из стека. Если в стеке нет значений, то должно выводиться предупреждение;

• public-метод с именем print(), который будет выводить все значения стека.*/
class Stack 
{
public:
	void reset()
	{
		for (size_t i = 0; i < size; i++)
		{
			m_Arry[i] = 0;
		}
		elem = 0;
	}
	bool push(int out)
	{
		if (elem < size)
		{
			m_Arry[elem] = out;
			elem++;
			return true;
		}
		else
		{
			return false;
		}
	}
	int pop()
	{
		if (elem > 0 )
		{
			elem--;
			int element = m_Arry[elem];
				return element;
		}
		else
		{
			std::cout << " Нет значений в массиве " << std::endl;
			return 0;
		}
	}
	void print()
	{
		std::cout << " ( ";
		for (size_t i = 0; i < elem; i++)
		{
			std::cout << " " << m_Arry[i];
		}
		std::cout << " ) " << std::endl;
	}

private:
	const static size_t size{ 10 };
	int m_Arry[size]{};
	size_t elem{ 0 };
};


int main (){
	setlocale(LC_ALL, "rus");
	std::cout << "Первое задание :" << std::endl;
	Power task;
	task.Set(5, 5);
	task.Calculete();
	std::cout << std::endl;
	std::cout << "Второе задание :" << std::endl;
	RGBA task2(1, 3, 4, 8);
	task2.print();
	std::cout << "Третие  задание :" << std::endl;
	Stack stack;
	stack.reset();
	stack.print();

	stack.push(3);
	stack.push(7);
	stack.push(5);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();
	stack.print();

	return 0;
}