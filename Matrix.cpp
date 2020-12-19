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
#include <iostream>
#include "Matrix.h"

Matrix::Matrix(){

}
Matrix::Matrix(int _rows, int _columns, double (*function)(int, int)){
  
    rows = _rows;
    columns = _columns;
    array = new double*[rows];
    for (int i = 0; i < rows; i++)
	{
		*(array + i) = new double[columns];
	}
    for(int i = 0; i < rows; i++){
        for(int j = 0; j< columns; j++){
            array[i][j] = function(i,j);
        }
    }
}
Matrix::~Matrix(){
for (size_t i = 0; i < rows; ++i)
	{
		delete[] * (array + i);
	}
	delete[] array;
}

int Matrix::getRows(){
    return rows;
}
int Matrix::getColumns(){
    return columns;
}

double Matrix::at(int i, int j){
    return (*(*(array + i) + j));
}
void Matrix::setAt(int i, int j, double val){
    array[i][j] = val;
}
void Matrix::printFormatted(){
    printf("[");
    for(int i = 0; i<rows; i++){
        for(int j = 0;j<columns;j++){
            if(i!=0 || j>0)
                printf(" ");
            printf(" %.2f", (*(*(array + i) + j)));
        }
        if(i!=rows-1)
         printf("\n");
    }
    printf(" ]\n");
}

std::ostream &operator<<(std::ostream &out, const Matrix &matrix) {
    out<<"[";
    for(int i = 0; i<matrix.rows; i++){
        for(int j = 0;j<matrix.columns;j++){
            if(i!=0 || j>0)
                out<<" ";
            out<< *(*(matrix.array + i) + j);
        }
        if(i!=matrix.rows-1)
            out<<"\n";
    }
    out<<" ]\n";
    return out;
}
void Matrix::operator++(){
    for(int i =0; i< rows; i++){
        for(int j =0; j< columns; j++){
            ++array[i][j];
        }
    }
}
void Matrix:: operator++(int)
{
    for(int i =0; i< rows; i++){
        for(int j =0; j< columns; j++){
            (*(*(array + i) + j))++;
        }
    }
}
void Matrix:: operator--()
{
    for(int i =0; i< rows; i++){
        for(int j =0; j< columns; j++){
            --array[i][j];
        }
    }
}
void Matrix:: operator--(int)
{
    for(int i =0; i< rows; i++){
        for(int j =0; j< columns; j++){
            (*(*(array + i) + j))--;
        }
    }
}
