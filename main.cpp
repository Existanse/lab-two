#include <iostream>
#include <algorithm>
#include "Photographer.h"
#include "Fraction.h"
#include "Vector.h"
#include "Matrix.h"


void taskOne();
void taskTwo();
void taskThree();

int main() {
    taskOne();
    taskTwo();
    taskThree();
    return 0;
}
#pragma region Task One
//Преобразование: 2D → 1D. Двумерный массив 4х4 вещественных чисел необходимо
//        выложить в один ряд по элементам слева направо и снизу вверх.
//Инициализация: заполнить массив числами x[i][j] = √(i + j + 1).
//Вывод на экран: каждый элемент одномерного массива вывести с точностью четыре
//знака после запятой; каждый элемент двумерного массива – с точностью два знака.
double getElement(int i, int j){
    return sqrt(i+j+1);
}
void taskOne(){
    std::cout<< "-------------------- TASK ONE --------------------" << std::endl;
    auto* m = new Matrix(4, 4, getElement);
    std::cout<<"Nonformatted using '<<'\n"<<*m<<std::endl;
    std::cout<<"Formatted:"<<std::endl;
    m->printFormatted();
    std::cout<<"=>"<<std::endl;
    auto* v = new Vector(*m);
    v->printFormatted();
    std::cout<<"Nonformatted using '<<'\n"<<*v<<std::endl;
    std::cout<<"\nElement at index [2] is: "<<(*v)[2]<<std::endl;
    (*v)++;
    std::cout<<"\nVector incremented:\n"<<*v<<std::endl;
}
#pragma endregion
#pragma region Task Two
/*Написать класс Fraction для представления обыкновенных дробей (как отношения двух целых чисел x/y).
 Перегрузить операторы +, -, *, / для дробей. 
 Реализовать метод void reduce() для сокращения дроби, а также статические методы:
 int gcd(int n, int m)
функция для нахождения наибольшего общего делителя чисел n и m;
 void printAsFraction(double decimal_fraction)
 void printAsFraction(char* decimal_fraction)
перегруженные методы вывода десятичной дроби в виде обыкновенной 
(например, при значении decimal_fraction = 0.43 на экране должно вывестись 43/100, при 0.25 – 1/4 и т.д.).
Также реализовать в виде статического члена класса счетчик всех созданных на данный момент в программе экземпляров дробей.
Продемонстрировать работу созданного класса. Создать несколько объектов дробей. 
Произвести операции сложения, вычитания, умножения и деления дробей. Вывести на экран результаты. 
Показать также результаты работы статических методов класса.*/
void taskTwo(){
    std::cout<< "-------------------- TASK TWO --------------------" << std::endl;
    Fraction fr0 = Fraction(6, 10);
    std::cout << "First fraction: "<<fr0 << std::endl;
    fr0.reduce();
    std::cout << "First fraction(reduced): "<<fr0 << std::endl;
    Fraction fr1 = Fraction(2, 4);
    std::cout << "Second fraction: "<<fr1 << std::endl;
    fr1.reduce();
    std::cout << "Second fraction(reduced): "<<fr1 << std::endl;
    Fraction fr2 = fr0+fr1;
    std::cout << "Sum of the two fractions: "<<fr2 << std::endl;
    fr2.reduce();
    std::cout << "Sum of the two fractions(reduced): "<<fr2 << std::endl;
    Fraction fr3 = fr0-fr1;
    std::cout << "Difference of the two fractions: "<<fr3 << std::endl;
    fr3.reduce();
    std::cout << "Difference of the two fractions(reduced): "<<fr3 << std::endl;
    Fraction fr4 = fr0*fr1;
    std::cout << "Product of the two fractions: "<<fr4 << std::endl;
    fr4.reduce();
    std::cout << "Product of the two fractions(reduced): "<<fr4 << std::endl;
    Fraction fr5 = fr0/fr1;
    std::cout << "Quotient of the two fractions: "<<fr5 << std::endl;
    fr5.reduce();
    std::cout << "Quotient of the two fractions(reduced): "<<fr5 << std::endl;
    std::cout << "Total fractions: " << Fraction::getTotalFractions() << std::endl;
    Fraction::printAsFraction(0.43);
    Fraction::printAsFraction("0.25");
}
#pragma endregion
#pragma region Task Three
void taskThree(){
    /*
    Написать собственный класс, в соответствии с вариантом. 
    Продемонстрировать в коде инкапсуляцию данных, применение конструкторов без параметров и с параметрами для инициализации данных.
    Класс должен содержать метод serialize() для сохранения данных класса в файл и метод deserialize() 
    для чтения данных класса из файла по умолчанию в текущей директории,
    а также перегруженные методы serialize(const std::string& filename) 
    и deserialize(const std::string& filename) для работы с файлом с указанным в параметре именем.
    Класс ФОТОГРАФ.
    Данные: имя, фамилия, пол, год рождения, год начала деятельности, рейтинг.
    Создать 2 фотографов в куче и одного в стеке. Данные первых двух заполнить с помощью сеттеров, 
    а третий проинициализировать с помощью конструктора с параметрами. 
    В главной функции проимитировать три фотосессии и голосование зрителей по их результатам 
    (нарастить рейтинг каждого фотографа на случайное число из диапазона 0.0..1.0;
    если количество проголосовавших людей меньше 10, то не наращивать рейтинг). 
    Вывести список фотографов в порядке убывания суммарного рейтинга.
    */
    std::cout<< "-------------------- TASK THREE --------------------" << std::endl;
    auto* ph0 = new Photographer();
    auto* ph1 = new Photographer();
    Photographer ph2 = Photographer("Nadezhda", "Krupskaya", "F", 4, 1869, 1903);

    ph0->setFirstName("Alexander");
    ph0->setLastName("Pushkin");
    ph0->setGender("M");
    ph0->setRating(4.1);
    ph0->setYearOfBirth(1799);
    ph0->setYearOfCareerStart(1813);

    ph1->setFirstName("Leo");
    ph1->setLastName("Tolstoy");
    ph1->setGender("M");
    ph1->setRating(3.5);
    ph1->setYearOfBirth(1828);
    ph1->setYearOfCareerStart(1847);

    std::cout<<*ph0<<std::endl;
    std::cout<<*ph1<<std::endl;
    std::cout<<ph2<<std::endl;

    std::cout<< "---SIMULATING TAKING PICTURES---" << std::endl;

    ph0->takeSomePictures();
    ph1->takeSomePictures();
    ph2.takeSomePictures();

    std::cout<<*ph0<<std::endl;
    std::cout<<*ph1<<std::endl;
    std::cout<<ph2<<std::endl;
    std::cout<< "---SORTED BY RATING---" << std::endl;

    Photographer *phArray[] = {ph0, ph1, &ph2};
    Photographer::sortByRating(phArray);
    std::cout<<*ph0<<std::endl;
    std::cout<<*ph1<<std::endl;
    std::cout<<ph2<<std::endl;

    ph0->serialize(ph0->getLastName()+".txt");
    std::cout << "Photographer "<< ph0->getFirstName()<<" "<< ph0->getLastName()<< " saved to file " << ph0->getLastName() << ".txt." <<std::endl;

    std::cout<< "---LOADED FROM FILE santa.txt---" << std::endl;
    ph0->deserialize("santa.txt");
    std::cout<<*ph0<<std::endl;
}
#pragma endregion