// Labb3, Datum.h – klassdefinition

#ifndef DATUM_H
#define DATUM_H

#include <array>
#include <iostream>

class Datum
{
    friend std::ostream &operator<<(std::ostream &, const Datum &);


    unsigned int year;
    unsigned int month;
    unsigned int day;

    // Deklaration av statisk privat medlem, "ant_dagar per månad"
    static const std::array<unsigned int, 13> ANT_DAGAR_PER_MAANAD;
    static const std::array<std::string, 13> NAMES;

    //OBS. funktionen "step_one_day()" bör vara PRIVATE


public:
    Datum();
    Datum(int, int, int);
    void set_date(const int& yy, const int& mm, const int& dd); // set year, month, day
    const bool operator<(const Datum &other);
    const bool operator<=(const Datum &other);
    const bool operator>(const Datum &other);
    const bool operator>=(const Datum &other);
    const bool operator==(const Datum &other);
    const bool operator!=(const Datum &other);
    const void operator++();
    const void operator++(int dummy);
    const Datum operator+(const int& dd);
    const Datum operator+=(const int& dd);
    
    void step_one_day(); // Öka datum med en dag

    //friend int operator+(const Datum &date);

    static bool is_skott_aar(int); // Är det skottår?
    bool end_of_month(int) const;  // Är dagen den sista i månaden?
};

// Datum operator+(int num, const Datum& date){
//     for(int i = 0; i < num; i++){
//         //date.step_one_day;
//     }
// }

#endif
