//
// Created by Michael on 06.10.2020.
//
/*Класс ФОТОГРАФ.
Данные: имя, фамилия, пол, год рождения, год начала деятельности, рейтинг.
Создать 2 фотографов в куче и одного в стеке. Данные первых двух заполнить с
помощью сеттеров, а третий проинициализировать с помощью конструктора с
параметрами. В главной функции проимитировать три фотосессии и голосование
зрителей по их результатам (нарастить рейтинг каждого фотографа на случайное число
из диапазона 0.0..1.0; если количество проголосовавших людей меньше 10, то не
наращивать рейтинг). Вывести список фотографов в порядке убывания суммарного
рейтинга.*/
#ifndef LABTWOCPP_PHOTOGRAPHER_H
#define LABTWOCPP_PHOTOGRAPHER_H
#include <iostream>

class Photographer {
public:
    Photographer();
    Photographer(std::string firstName, std::string lastName, std::string gender, double rating, int yearOfBirth, int yearOfCareerStart);
    std::string getFirstName();
    std::string getLastName();
    std::string getGender();
    double getRating();
    int getYearOfBirth();
    int getYearOfCareerStart();
    void setFirstName(const std::string &firstName);
    void setLastName(const std::string &lastName);
    void setGender(const std::string &gender);
    void setRating(double rating);
    void setYearOfBirth(int yearOfBirth);
    void setYearOfCareerStart(int yearOfCareerStart);
    virtual ~Photographer();
    void serialize(const std::string& filename);
    void deserialize(const std::string&filename);
    void takeSomePictures();
    bool operator <(const Photographer & photographerObj) const;
    static void sortByRating(Photographer *photographers[], int size = totalPhotographers);
    friend std::ostream& operator<< (std::ostream &out, const Photographer &photographer);
private:
    std::string firstName;
    std::string lastName;
    std::string gender;
    double rating;
    int yearOfBirth;
    int yearOfCareerStart;
    static int totalPhotographers;
};


#endif LABTWOCPP_PHOTOGRAPHER_H
