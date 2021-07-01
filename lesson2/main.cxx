#include <cstdint>
#include <iostream>

/*
Создать класс Person (человек) с полями: имя, возраст, пол и вес. Определить
методы переназначения имени, изменения возраста и веса. Создать производный
класс Student (студент), имеющий поле года обучения. Определить методы
переназначения и увеличения этого значения. Создать счетчик количества созданных
студентов. В функции main() создать несколько студентов. По запросу вывести
определенного человека.


 */
class Person

{
protected:
    std::string m_name, m_sex;
    int         m_old, m_weigh;

public:
    Person(std::string name, std::string sex, int old, int weigh)
        : m_name(name)
        , m_sex(sex)
        , m_old(old)
        , m_weigh(weigh)
    {
    }
    void rename(std::string name) { m_name = name; }
    void reold(int old) { m_old = old; }
    void reweigh(int weigh) { m_weigh = weigh; }
};

class Student : public Person
{
    int        m_curs, num;
    static int count;

public:
    Student(std::string name, std::string sex, int old, int weigh, int curs)
        : Person(name, sex, old, weigh)
        , m_curs(curs)
    {
        count++;
        num = count;
    }
    void setCurs(int curs) { m_curs = curs; }
    void countCurs(int curs) { m_curs += curs; }
    void printStudent() const
    {
        std::cout << "Number: " << num << std::endl
                  << "Student: " << m_name << std::endl
                  << "Old: " << m_old << std::endl
                  << "Sex: " << m_sex << std::endl
                  << "Weigth: " << m_weigh << std::endl
                  << "Curs: " << m_curs << std::endl
                  << std::endl;
    }
};
int  Student::count = 0;
void task1()
{

    Student Anna("Anna", "Woman", 21, 52, 5);
    Student Henru("Henru", "Man", 31, 64, 2);
    Student Jan("Jan", "Man", 17, 55, 1);

    Jan.printStudent();
}
/*
Создать классы Apple (яблоко) и Banana (банан), которые наследуют класс Fruit
(фрукт). У Fruit есть две переменные-члена: name (имя) и color (цвет). Добавить
новый класс GrannySmith, который наследует класс Apple. int main()
{
    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;
}


Код, приведенный выше, должен давать следующий результат:

      My apple is red.
My banana is yellow.
My Granny Smith apple is green.



 */
class Fruit
{
    std::string m_name, m_color;

public:
    Fruit(std::string name, std::string color)
        : m_name(name)
        , m_color(color)
    {
    }
    std::string getName() { return m_name; }
    std::string getColor() { return m_color; }
};

class Apple : public Fruit
{
public:
    Apple(std::string color, std::string name = "apple")
        : Fruit(name, color)
    {
    }
};

class Banana : public Fruit
{
public:
    Banana()
        : Fruit("Banana", "yellow")
    {
    }
};

class GrannySmith : public Apple
{
public:
    GrannySmith()
        : Apple("green", "Granny Smith apple")
    {
    }
};

void task2()
{
    Apple       a("red");
    Banana      b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
}

int main(int argc, char** args)
{
    task1();
    task2();
}
/*
Изучить правила игры в Blackjack. Подумать, как написать данную игру на С++,
используя объектно-ориентированное программирование. Сколько будет классов в
программе? Какие классы будут базовыми, а какие производными? Продумать
реализацию игры с помощью классов и записать результаты.


пока что только прочел
https://ru.wikipedia.org/wiki/%D0%91%D0%BB%D1%8D%D0%BA%D0%B4%D0%B6%D0%B5%D0%BA
 */
