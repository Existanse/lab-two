//
// Created by Michael on 14.10.2020.
//
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
#ifndef LABTWOCPP_FRACTION_H
#define LABTWOCPP_FRACTION_H
#include <iostream>

class Fraction {
    public:
        Fraction();
        Fraction(int x, int y);
        void setX(int x);
        void setY(int y);
        int getX();
        int getY();

        Fraction operator+(const Fraction& term);
        Fraction operator-(const Fraction& subtrahend);
        Fraction operator*(const Fraction& factor);
        Fraction operator/(const Fraction& divisor);

        ~Fraction();
        void printFraction();
        void reduce();
        static int getTotalFractions();
        static int gcd(int a, int b);
        static int lcm(int a, int b);
        static void printAsFraction(char* decimal_fraction);
        static void printAsFraction(double decimal_fraction);

        friend std::ostream& operator<< (std::ostream &out, const Fraction &fraction);
    private:
        int x;
        int y;
        static int totalFractions;
};

#endif LABTWOCPP_FRACTION_H
