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
#ifndef LABTWOCPP_MATRIX_H
#define LABTWOCPP_MATRIX_H
#include <iostream>

class Matrix {
    public:
        Matrix();
        Matrix(int rows, int columns, double (*function)(int, int));
        ~Matrix();

        int getRows();
        int getColumns();

        double at(int i, int j);
        void setAt(int i, int j, double val);

        void operator++();
        void operator++(int);
        void operator--();
        void operator--(int);

        void printFormatted();
        friend std::ostream& operator<< (std::ostream &out, const Matrix &matrix);
    private:
        int rows;
        int columns;
        double** array;
};

#endif LABTWOCPP_MATRIX_H
