#include <cstdint>
#include <iostream>

/*
 Создать класс Power, который содержит два вещественных числа. Этот класс
 должен иметь две переменные-члена для хранения этих вещественных чисел. Еще
 создать два метода: один с именем set, который позволит присваивать значения
 переменным, второй — calculate, который будет выводить результат возведения
 первого числа в степень второго числа. Задать значения этих двух чисел по
 умолчанию.

 */
class Power
{
    int i1 = 0, i2 = 0;

public:
    void set(int t1, int t2)
    {
        i1 = t1;
        i2 = t2;
    }
    long pow(long a, long b)
    {
        if (b == 0)
        {
            return 1;
        }
        if (b % 2 == 0)
        {
            return pow(a * a, b / 2);
        }
        return a * pow(a, b - 1);
    }
    void calculate() { std::cout << pow(i1, i2) << std::endl; }
};

/*
Написать класс с именем RGBA, который содержит 4 переменные-члена типа
std::uint8_t: m_red, m_green, m_blue и m_alpha (#include cstdint для доступа к
этому типу). Задать 0 в качестве значения по умолчанию для m_red, m_green,
m_blue и 255 для m_alpha. Создать конструктор со списком инициализации членов,
который позволит пользователю передавать значения для m_red, m_blue, m_green и
m_alpha. Написать функцию print(), которая будет выводить значения
переменных-членов.
*/

class RGBA
{
    std::uint8_t m_red = 0, m_green = 0, m_blue = 0, m_alpha = 255;

public:
    RGBA(std::uint8_t red,
         std::uint8_t green,
         std::uint8_t blue,
         std::uint8_t alpha)
    {
        m_red   = red;
        m_green = green;
        m_blue  = blue;
        m_alpha = alpha;
    }
    void print()
    {
        std::cout << "red " << static_cast<int>(m_red) << " green "
                  << static_cast<int>(m_green) << " blue "
                  << static_cast<int>(m_blue) << " alpha "
                  << static_cast<int>(m_alpha) << std::endl;
    }
};

/*
Написать класс, который реализует функциональность стека. Класс Stack должен
иметь: private-массив целых чисел длиной 10; private целочисленное значение для
отслеживания длины стека; public-метод с именем reset(), который будет
сбрасывать длину и все значения элементов на 0; public-метод с именем push(),
который будет добавлять значение в стек. push() должен возвращать значение
false, если массив уже заполнен, и true в противном случае; public-метод с
именем pop() для вытягивания и возврата значения из стека. Если в стеке нет
значений, то должно выводиться предупреждение; public-метод с именем print(),
который будет выводить все значения стека. Код main(): int main()
{
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


Этот код должен выводить:
( )
( 3 7 5 )
( 3 7 )
( )

*/

class Stack
{
private:
    static const int size        = 10;
    int              array[size] = { 0 };
    int              top         = 0;

public:
    void reset()
    {
        for (int i = 0; i < size; ++i)
            array[i] = 0;
        top = 0;
    };
    bool push(int value)
    {
        if (top < size && top >= 0)
        {
            *(array + top++) = value;
            return true;
        }
        return false;
    };
    int pop()
    {
        // std::cerr << "top = " << top << std::endl;
        if (top == 0)
        {
            std::cout << "empty!\n";
            return std::numeric_limits<int>::min();
        }
        return *(array + --top);
    };

    void print()
    {
        std::cout << "(";
        for (int i = 0; i < top; ++i)
        {
            std::cout << array[i];
            if (i != top - 1)
                std::cout << ",";
        }
        std::cout << ")\n";
    };
};

int main(int argc, char** args)
{
    Power obj;
    obj.set(3, 4);
    obj.calculate();
    RGBA shader(1, 1, 1, 1);
    shader.print();

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
}
