//
// Created by Michael on 15.10.2020.
//
/*Написать классы Vector и Matrix для хранения и обработки одномерных и
двумерных массивов, соответственно. Реализовать задание 2 лабораторной работы No1 с помощью созданных классов.
 Все функции оформить в виде методов классов.
В коде отразить следующее:
 Выделение и освобождение динамической памяти производить в конструкторах и деструкторах классов, соответственно.
 В классе Vector перегрузить оператор индексации []. В классе Matrix добавить методы T at(int i, int j) const и 
setAt(int i, int j, T val), которые позволяют получить и установить значение элемента массива с индексом [i][j],
 T – это тип элементов массива по варианту (int или double).
 Перегрузить операторы инкремента и декремента (как префиксного, так и постфиксного). 
Смысл инкремента / декремента всего массива заключается в инкременте / декременте каждого элемента массива.*/

//Преобразование: 2D → 1D. Двумерный массив 4х4 вещественных чисел необходимо
//        выложить в один ряд по элементам слева направо и снизу вверх.
//Инициализация: заполнить массив числами x[i][j] = √(i + j + 1).
//Вывод на экран: каждый элемент одномерного массива вывести с точностью четыре
//знака после запятой; каждый элемент двумерного массива – с точностью два знака.

#include "Vector.h"
#include "Matrix.h"
#include <iostream>

Vector::Vector(){
}
Vector::Vector(Matrix matrix){
    size = matrix.getColumns()*matrix.getRows();
    int index = 0;
    array = new double[size];
    for (int i = matrix.getRows()-1; i >= 0; i--) {
        for (int j = 0; j < matrix.getColumns(); j++) {
            *(array+index) = matrix.at(i,j);
            ++index;
        }
    }
}
Vector::~Vector(){
   delete[] array;
}

double Vector::operator[] (const int index){
    return (array[index]);
}
void Vector::operator++(){
    for(int i =0; i< size; i++){
        array[i]++;
    }
}
void Vector:: operator++(int)
{
	for (int i = 0; i < size; i++)
	{
		++(* (array + i));
	}
}
void Vector:: operator--()
{
	for (int i = 0; i < size; i++)
	{
        (*(array + i))--;
	}
}
void Vector:: operator--(int)
{
	for (int i = 0; i < size; i++)
	{
		--(* (array + i));
	}
}

std::ostream &operator<<(std::ostream &out, const Vector &vector) {
    out<<"[";
    for(int i =0; i< vector.size; i++){
        out<<*(vector.array+i);
        if(i!= vector.size-1)
            out<<" ";
    }
    out<<"]";
    return out;
}

void Vector::printFormatted(){
    printf("[");
    for(int i =0; i< size; i++){
        printf(" %.5g", *(array+i));
        if(i!= size-1)
            printf(" ");
    }
    std::cout<<" ]"<<std::endl;
}