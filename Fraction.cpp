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

#include "Fraction.h"
#include <iostream>

int Fraction::totalFractions = 0;
Fraction::Fraction() {
    totalFractions++;
}

Fraction::Fraction(int _x, int _y) {
    x = _x;
    y = _y;
    totalFractions++;
}
int Fraction::getX(){
    return x;
}
int Fraction::getY(){
    return y;
}
void Fraction::setX(int _x){
    x = _x;
}
void Fraction::setY(int _y){
    y = _y;
}
Fraction Fraction:: operator+(const Fraction& term){
    Fraction output;
    if(y==term.y){
        output.setX(x+term.x);
        output.setY(y);
    }else{
        output.setY(lcm(y, term.y));
        output.setX((x*output.y/y)+(term.x*output.y/term.y));
    } 
    return output;
}
Fraction Fraction:: operator-(const Fraction& subtrahend){
    Fraction output;
    if(y==subtrahend.y){
        output.setX(x-subtrahend.x);
        output.setY(y);
    }else{
        output.setY(lcm(y, subtrahend.y));
        output.setX((x*output.y/y)-(subtrahend.x*output.y/subtrahend.y));
    } 
    return output;
}
Fraction Fraction:: operator*(const Fraction& factor){
    Fraction output;
    output.setX(x*factor.x);
    output.setY(y*factor.y);
    return output;
}
Fraction Fraction:: operator/(const Fraction& divisor){
    Fraction output;
    output.setX(x*divisor.y);
    output.setY(y*divisor.x);
    return output;
}
void Fraction::reduce(){
    int divider = gcd(x,y);
    x = x/divider;
    y = y/divider;
}
Fraction::~Fraction() {

}
void Fraction::printFraction(){
    std::cout<<x<<"/"<<y<<std::endl;
}
int Fraction::getTotalFractions(){
    return totalFractions;
}
int Fraction::gcd(int a, int b){
    if(a == 0)
        return b;
    if(b == 0)
        return a;
    if(a == b)
        return a;
    if(a%2==0)
        if(b%2==0)
            return 2*gcd(a/2, b/2);
        else 
            return gcd(a/2, b);
    else 
        if(b%2 == 0)
            return gcd(a, b/2);
        else   
            if(a>b)
                return gcd((a-b)/2, b);
            else    
                return gcd((b-a)/2, a);
}
int Fraction::lcm(int a, int b){
    int numerator = a*b;
    if (numerator<0)
        a = -a;
    int divisor = gcd(a,b);
    return (numerator/divisor);
} 
void Fraction::printAsFraction(char* decimal_fraction){
     int length = std::strlen(decimal_fraction);
    int powerOfTen = 0;
    int decimalPoint = INT_MAX;
    int lastNonZero = 0;
    for(int i = 0; i<length;i++){
        if(decimal_fraction[i]=='.')
            decimalPoint = i;
        if(i>decimalPoint){
            if(decimal_fraction[i]!='0')
                lastNonZero = i;
        }
    }
    powerOfTen = lastNonZero-decimalPoint;
    char* numerator = new char[powerOfTen];
    int index = 0;
    for(int i = decimalPoint+1; i<=lastNonZero; i++){
        numerator[index] = decimal_fraction[i];
        index++;
    }
    int denominator = pow(10, powerOfTen);
    Fraction result = Fraction(atoi(numerator), denominator);
    result.reduce();
    result.printFraction();
}
void Fraction::printAsFraction(double decimal_fraction){
    std::string str = std::to_string(decimal_fraction);
    const char* cstr = str.c_str();
    int length = std::strlen(cstr);
    int powerOfTen = 0;
    int decimalPoint = INT_MAX;
    int lastNonZero = 0;
    for(int i = 0; i<length;i++){
        if(cstr[i]=='.')
            decimalPoint = i;
        if(i>decimalPoint){
            if(cstr[i]!='0')
                lastNonZero = i;
        }
    }
    powerOfTen = lastNonZero-decimalPoint;
    char* numerator = new char[powerOfTen];
    int index = 0;
    for(int i = decimalPoint+1; i<=lastNonZero; i++){
        numerator[index] = cstr[i];
        index++;
    }
    int denominator = pow(10, powerOfTen);
    Fraction result = Fraction(atoi(numerator), denominator);
    result.reduce();
    result.printFraction();
}

std::ostream &operator<<(std::ostream &out, const Fraction &fraction) {
    out<<fraction.x<<"/"<<fraction.y;
    return out;
}
