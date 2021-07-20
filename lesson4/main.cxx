#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>
/*
Добавить в контейнерный класс, который был написан в этом уроке, методы:
для удаления последнего элемента массива (аналог функции pop_back() в векторах)
для удаления первого элемента массива (аналог pop_front() в векторах)
для сортировки массива
для вывода на экран элементов.

 */

class ArrayInt
{
private:
    int  m_length;
    int* m_data;

public:
    ArrayInt()
        : m_length(0)
        , m_data(nullptr)
    {
    }

    ArrayInt(int length)
        : m_length(length)
    {
        assert(length >= 0);

        if (length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
    }
    void erase()
    {
        delete[] m_data;

        m_data   = nullptr;
        m_length = 0;
    }
    int  getLength() { return m_length; }
    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }
    void resize(int newLength)
    {

        if (newLength == m_length)
            return;

        if (newLength <= 0)
        {
            erase();
            return;
        }

        int* data = new int[newLength];

        if (m_length > 0)
        {
            int elementsToCopy = (newLength > m_length) ? m_length : newLength;

            for (int index = 0; index < elementsToCopy; ++index)
                data[index] = m_data[index];
        }

        delete[] m_data;

        m_data   = data;
        m_length = newLength;
    }
    void insertBefore(int value, int index)
    {

        assert(index >= 0 && index <= m_length);

        int* data = new int[m_length + 1];

        for (int before = 0; before < index; ++before)
            data[before] = m_data[before];

        data[index] = value;

        for (int after = index; after < m_length; ++after)
            data[after + 1] = m_data[after];

        delete[] m_data;
        m_data = data;
        ++m_length;
    }
    void push_back(int value) { insertBefore(value, m_length); }

    ~ArrayInt() { delete[] m_data; }

    // задание

    void fillarray()
    {
        for (int i = 0; i < m_length; ++i)
        {
            m_data[i] = m_length - i + 1;
        }
    }
    //для удаления последнего элемента массива (аналог функции pop_back() в
    //векторах)

    void pop_back()
    {
        m_data[m_length - 1] = 0;
        --m_length;
    }
    //для удаления первого элемента массива (аналог pop_front() в векторах)
    void pop_front()
    {
        for (int i = 0; i < m_length; ++i)
        {
            m_data[i] = m_data[i + 1];
        }

        m_data[m_length - 1] = 0;
        --m_length;
    }
    //для сортировки массива

    void sorting()
    {
        for (int i = 0; i < m_length - 1; ++i)
        {
            int temp = m_data[i];
            for (int j = i + 1; j < m_length; ++j)
            {
                if (m_data[j] < m_data[i])
                    temp = m_data[j];
                m_data[j] = m_data[i];
                m_data[i] = temp;
            }
        }
    }
    //для вывода на экран элементов.

    void print()
    {
        std::cout << "{ ";
        for (int i = 0; i < m_length; ++i)
        {
            std::cout << m_data[i] << " ";
        }
        std::cout << " }" << std::endl;
    }
};

/*
 Дан вектор чисел, требуется выяснить, сколько среди них различных. Постараться
 использовать максимально быстрый алгоритм.

 */

void printVector(const std::vector<int>& a)
{
    std::cout << "The length is: " << a.size() << '\n';

    for (int i = 0; i < a.size(); i++)
        std::cout << a.at(i) << ' ';

    std::cout << std::endl;
}

/*Реализовать класс Hand, который представляет собой коллекцию карт. В классе
будет одно поле: вектор указателей карт (удобно использовать вектор, т.к. это по
сути динамический массив, а тип его элементов должен быть - указатель на объекты
класса Card). Также в классе Hand должно быть 3 метода: метод Add, который
добавляет в коллекцию карт новую карту, соответственно он принимает в качестве
параметра указатель на новую карту метод Clear, который очищает руку от карт
метод GetValue, который возвращает сумму очков карт руки (здесь предусмотреть
возможность того, что туз может быть равен 11).
*/
int main(int argc, char** args) {}
