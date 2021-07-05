#include <cstdint>
#include <iostream>

/*
Создать абстрактный класс Figure (фигура). Его наследниками являются классы
Parallelogram (параллелограмм) и Circle (круг). Класс Parallelogram — базовый
для классов Rectangle (прямоугольник), Square (квадрат), Rhombus (ромб). Для
всех классов создать конструкторы. Для класса Figure добавить чисто виртуальную
функцию area() (площадь). Во всех остальных классах переопределить эту функцию,
исходя из геометрических формул нахождения площади.


 */
class Figure
{
protected:
    double m_a;

public:
    Figure(double a)
        : m_a(a)
    {
    }

    virtual int area() = 0;
};
class Parallelogram : public Figure
{
protected:
    double m_b;

public:
    Parallelogram(double b, double a)
        : Figure(a)
        , m_b(b){};
    int area() override { return m_a * m_b; }
};
class Circle : public Figure
{
    double m_p = 3.14;

public:
    Circle(double r)
        : Figure(r){};
    int area() override { return m_a * m_p; };
};

class Rectangle : public Parallelogram
{
public:
    Rectangle(double b, double a)
        : Parallelogram(b, a){};
    int area() override { return m_a * m_b; }
};

class Square : public Parallelogram
{
public:
    Square(double b, double a)
        : Parallelogram(b, a){};
    int area() override { return m_a * m_b; }
};
class Rhombus : public Parallelogram
{
public:
    Rhombus(double b, double a)
        : Parallelogram(b, a){};
    int area() override { return m_a * m_b; }
};

void task1()
{
    Parallelogram a(3, 6);
    Circle        b(3.3);
    Rectangle     c(7, 4);
    Square        d(5, 5);
    Rhombus       f(3, 9);
    std::cout << "Parallelogram " << a.area() << " area " << std::endl;
    std::cout << "Circle " << b.area() << " area " << std::endl;
    std::cout << "Rectangle " << c.area() << " area " << std::endl;
    std::cout << "Square " << d.area() << " area " << std::endl;
    std::cout << "Rhombus " << f.area() << " area " << std::endl;
}

/*
Создать класс Car (автомобиль) с полями company (компания) и model (модель).
Классы-наследники: PassengerCar (легковой автомобиль) и Bus (автобус). От этих
классов наследует класс Minivan (минивэн). Создать конструкторы для каждого из
классов, чтобы они выводили данные о классах. Создать объекты для каждого из
классов и посмотреть, в какой последовательности выполняются конструкторы.
Обратить внимание на проблему «алмаз смерти». Примечание: если использовать
виртуальный базовый класс, то объект самого "верхнего" базового класса создает
самый "дочерний" класс.


 */

class Car
{
protected:
    std::string m_company, m_model;

public:
    Car(std::string company, std::string model)
        : m_company(company)
        , m_model(model){};
    virtual void print()
    {
        std::cout << "Class Car"
                  << " " << m_company << " " << m_model << std::endl;
    };
};
class PassengerCar : public virtual Car
{
public:
    PassengerCar(std::string company, std::string model)
        : Car(company, model){};
    void print() override
    {
        std::cout << "Class PassengerCar"
                  << " " << m_company << " " << m_model << std::endl;
    };
};
class Bus : public virtual Car
{
public:
    Bus(std::string company, std::string model)
        : Car(company, model){};
    void print() override
    {
        std::cout << "Class Bus"
                  << " " << m_company << " " << m_model << std::endl;
    };
};
class Minivan : public PassengerCar, public Bus
{
public:
    Minivan(std::string company, std::string model)
        : PassengerCar(company, model)
        , Bus(company, model)
        , Car(company, model){};
    void print() override
    {
        std::cout << "Class Minivan"
                  << " " << m_company << " " << m_model << std::endl;
    }
};

void task2()
{
    Car          aa("Mercedes-Benz", "V-Class");
    PassengerCar a("Mercedes-Benz", "V-Class");
    Bus          b("Mercedes-Benz", "V-Class");
    Minivan      c("Mercedes-Benz", "V-Class");
    aa.print();
    a.print();
    b.print();
    c.print();
}
/*
Создать класс: Fraction (дробь). Дробь имеет числитель и знаменатель (например,
3/7 или 9/2). Предусмотреть, чтобы знаменатель не был равен 0.
Перегрузить:
* математические бинарные операторы (+, -, *, /) для выполнения действий с
дробями
* унарный оператор (-)
* логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).
Примечание: Поскольку операторы < и >=, > и <= — это логические
противоположности, попробуйте перегрузить один через другой. Продемонстрировать
использование перегруженных операторов.

 */

class Fraction
{
    int m_numerator, m_denominator;

public:
    Fraction(int numerator, int denominator)
    {
        if (denominator != 0)
        {
            m_numerator   = numerator;
            m_denominator = denominator;
        }
        else
            throw std::runtime_error("ERROR! Denominator can't be 0");
    }

    friend Fraction operator+(const Fraction& d1, const Fraction& d2);
    friend Fraction operator-(const Fraction& d1, const Fraction& d2);
    friend Fraction operator*(const Fraction& d1, const Fraction& d2);
    friend Fraction operator/(const Fraction& d1, const Fraction& d2);
    friend bool     operator>(const Fraction& d1, const Fraction& d2);
    friend bool     operator>=(const Fraction& d1, const Fraction& d2);
    friend bool     operator<(const Fraction& d1, const Fraction& d2);
    friend bool     operator<=(const Fraction& d1, const Fraction& d2);
    friend bool     operator!=(const Fraction& d1, const Fraction& d2);
    friend bool     operator==(const Fraction& d1, const Fraction& d2);
    Fraction operator-() const { return Fraction(-m_numerator, m_denominator); }
    void print() { std::cout << m_numerator << "/" << m_denominator << " "; }
    int  getNumerator() { return m_numerator; }
    int  getDenominator() { return m_denominator; }
};
Fraction operator+(const Fraction& d1, const Fraction& d2)
{
    return Fraction(
        (d1.m_numerator * d2.m_denominator + d2.m_numerator * d1.m_denominator),
        d1.m_denominator * d2.m_denominator);
}
Fraction operator-(const Fraction& d1, const Fraction& d2)
{
    return Fraction(
        (d1.m_numerator * d2.m_denominator - d2.m_numerator * d1.m_denominator),
        d1.m_denominator * d2.m_denominator);
}

Fraction operator*(const Fraction& d1, const Fraction& d2)
{
    return Fraction(d1.m_numerator * d2.m_numerator,
                    d1.m_denominator * d2.m_denominator);
}

Fraction operator/(const Fraction& d1, const Fraction& d2)
{
    return Fraction(d1.m_numerator * d2.m_denominator,
                    d1.m_denominator * d2.m_numerator);
}

bool operator>(const Fraction& d1, const Fraction& d2)
{
    return ((d1.m_numerator / d1.m_denominator) >
            (d2.m_numerator / d2.m_denominator));
}

bool operator>=(const Fraction& d1, const Fraction& d2)
{
    return ((d1.m_numerator / d1.m_denominator) >=
            (d2.m_numerator / d2.m_denominator));
}

bool operator<(const Fraction& d1, const Fraction& d2)
{
    return !((d1.m_numerator / d1.m_denominator) >=
             (d2.m_numerator / d2.m_denominator));
}

bool operator<=(const Fraction& d1, const Fraction& d2)
{
    return !((d1.m_numerator / d1.m_denominator) >
             (d2.m_numerator / d2.m_denominator));
}
bool operator!=(const Fraction& d1, const Fraction& d2)
{
    return !((d1.m_numerator / d1.m_denominator) ==
             (d2.m_numerator / d2.m_denominator));
}
bool operator==(const Fraction& d1, const Fraction& d2)
{
    return ((d1.m_numerator / d1.m_denominator) ==
            (d2.m_numerator / d2.m_denominator));
}

void task3()
{
    Fraction a(1, 2);
    Fraction b(1, 3);
    Fraction Sum  = a + b;
    Fraction Sub  = a - b;
    Fraction Div  = a / b;
    Fraction Mult = a * b;
    Fraction Unar = -a;
    bool     w1   = a == b;
    bool     w2   = a != b;
    bool     w3   = a < b;
    bool     w4   = a > b;
    bool     w5   = a <= b;
    bool     w6   = a >= b;

    Sum.print();
    Sub.print();
    Div.print();
    Mult.print();
    Unar.print();
}

/*
Создать класс Card, описывающий карту в игре БлэкДжек. У этого класса должно
быть три поля: масть, значение карты и положение карты (вверх лицом или
рубашкой). Сделать поля масть и значение карты типом перечисления (enum).
Положение карты - тип bool. Также в этом классе должно быть два метода: метод
Flip(), который переворачивает карту, т.е. если она была рубашкой вверх, то он
ее поворачивает лицом вверх, и наоборот. метод GetValue(), который возвращает
значение карты, пока можно считать, что туз = 1.

 */

class Card
{
public:
    enum SUIT
    {
        HEART,
        CLUB,
        DIAMOND,
        SPADE
    };
    enum VALUE
    {
        ACE   = 1,
        TWO   = 2,
        THREE = 3,
        FOUR  = 4,
        FIVE  = 5,
        SIX   = 6,
        SEVEN = 7,
        EIGHT = 8,
        NINE  = 9,
        TEN   = 10,
        JACK  = 10,
        QUEN  = 10,
        KING  = 10
    };

private:
    SUIT  m_suit;
    VALUE m_value;
    bool  m_position;

public:
    Card(SUIT s = CLUB, VALUE v = ACE, bool position = 0)
        : m_suit(s)
        , m_value(v)
        , m_position(position)
    {
    }

    bool Flip() { m_position = !(m_position); }

    int GetValue()
    {
        int value = 0;
        if (m_position)
        {
            value = m_value;
        }

        return value;
    }
};

int main(int argc, char** args)
{
    task1();
    task2();
    task3();
}
