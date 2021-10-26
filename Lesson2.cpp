// OOP_Lesson1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//



#include <iostream>
#include <fstream>
#include <locale>
#include <math.h>
#include <cstdint>

typedef std::uint16_t uInt;
typedef std::string string;

enum Sex
{
    MAN,
    WOMAN
};

//вывод перечисления, не очень красиво, можно сделать лучше)
inline const char* enumToString(Sex el)
{
    switch (el)
    {
    case MAN: return "Мужской";
    case WOMAN: return "Женский";
    default:
        return "";
    }
}

//Задание1
class Person
{
protected: //для того чтобы дочерний класс Student имел к ним доступ
    string m_name {""};
    uInt m_age{0};
    Sex m_sex{MAN};
    uInt m_weight{0};

public:
    //контрукторы
    Person() {}; //по умолчанию
    Person(string name, uInt age, Sex sex, uInt weight) : m_name(name), m_age(age), m_sex(sex), m_weight(weight) {};

    //деструктор
    ~Person(){};

    //функции члены 
    //сеттеры
    void setName(string name) { this->m_name = name; };
    void setAge(uInt age) { this->m_age = age; };
    void setWeight(uInt weight) { this->m_weight = weight; };

};

class Student : public Person
{
    int m_studyYear{0};

public:
    //контрукторы
    Student():Person() {}; //по умолчанию
    Student(string name, uInt age, Sex sex, uInt weight, int studyYear) : Person(name, age, sex, weight), m_studyYear(studyYear) {};//вызываем контруктор базового класса с необходимыми параметрами в списке инициализации

    //деструктор
    ~Student() {};

    //функции члены
    //сеттеры
    void setStudyYear(int studyYear) { this->m_studyYear = studyYear; };
    void incStudyYear() { this->m_studyYear ++; };

    //const-методы
    void printSelf() const 
    {
        std::cout << "Имя " << m_name << std::endl
            << "Возраст " << m_age << std::endl
            << "Пол " << enumToString(m_sex) << std::endl
            << "Вес " << m_weight << std::endl
            << "Год обучения " << m_studyYear << std::endl << "*************";
    };
};
//*********задание1

//Задание2
class Fruit
{
protected:
    string name;
    string color;

public:
    Fruit(string color = "", string name = "")
    {
        this->name = name;
        this->color = color;
    };

    ~Fruit() {};

    //реализуем через константные функции
    string getName() const
    {
        return name;
    };

    string getColor() const
    {
        return color;
    };
};

class Apple : public Fruit
{
public:
    Apple(string color = "", string name = "apple")
    {
        this->name = name;
        this->color = color;
    };
    ~Apple() {};

};

class Banana : public Fruit
{
public:
    Banana(string color = "yellow", string name = "banana")
    {
        this->name = name;
        this->color = color;
    };
    ~Banana() {};


};
 

class GrannySmith : public Apple
{
public:
    GrannySmith(string color = "green", string name = "Granny Smith")
    {
        this->name = name + " apple";
        this->color = color;
    };
    ~GrannySmith() {};

private:

};


//*********задание2
void Zadanie1()
{
    /*--------------------------------------------------
    Создать класс Person (человек) с полями: имя, возраст, пол и вес. Определить методы переназначения имени, изменения возраста и веса.
    Создать производный класс Student (студент), имеющий поле года обучения. Определить методы переназначения и увеличения этого значения.
    Создать счетчик количества созданных студентов. В функции main() создать несколько (не больше трёх) студентов. Вывести информацию о них.
    ----------------------------------------------------*/
    int counter{ 0 }; //счетчик студентов (не совсем поняла зачем он нужен, сделаю пока так)

    //1.
    Student st1("John", 20, MAN, 60, 2018);
    st1.printSelf();
    counter++;
   
    Student st2("Lesya", 25, WOMAN, 50, 2020);
    counter++;
    st2.printSelf();
    st2.incStudyYear();
    st2.printSelf();

   


};

void Zadanie2()
{
    /*--------------------------------------------------
    Создать классы Apple (яблоко) и Banana (банан), которые наследуют класс Fruit (фрукт). У Fruit есть две переменные-члена: name (имя) и color (цвет).
    Добавить новый класс GrannySmith, который наследует класс Apple.

    ----------------------------------------------------*/
    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    /* результат работы 
    My apple is red.
    My banana is yellow.
    My Granny Smith apple is green.
    */
  

};

void Zadanie3()
{
    /*--------------------------------------------------
    Изучить правила игры в Blackjack. Подумать, как написать данную игру на С++, используя объектно-ориентированное программирование.
    Сколько будет классов в программе? Какие классы будут базовыми, а какие производными? Продумать реализацию игры с помощью классов 
    и записать результаты в виде комментария в основном файле сдаваемой работы.
    ----------------------------------------------------*/
   
    /*Ну в первую очередь напрашивается добавление класса самой игры BlackJack, у которой будет публичный метод PlayGame(), CheckWin(), 
    * Я бы добавила класс Participant (участник), у которого будут методы SumCards(посчитать карты на руках), AddCard(взять карту), PrintSelf() (напечатать карты)
    * Возможно наследники класса Participant будут классы Player и Diller (но над этим надо подучать, стоит ли :))) )
    * Добавить Класс Deck (колода карт)
    */


};

void Zadanie4()
{
    /*--------------------------------------------------

     ----------------------------------------------------*/




};

void Zadanie5()
{
    /*--------------------------------------------------

     ----------------------------------------------------*/


};
int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "Введите номер задания цифрой" << std::endl;
    unsigned short nomerZadania;

    std::cin >> nomerZadania;

    switch (nomerZadania)
    {
    case 1:Zadanie1(); break;

    case 2:Zadanie2(); break;

    case 3:Zadanie3(); break;

    case 4:Zadanie4(); break;

    case 5:Zadanie5(); break;

    default: break;
    }


    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
