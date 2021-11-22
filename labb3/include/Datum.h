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
    void step_one_day(); // Öka datum med en dag

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
    const Datum operator++();
    const Datum operator++(int dummy);
    const Datum operator+(int dd) const;
    const Datum operator+=(int dd);

    static bool is_skott_aar(int); // Är det skottår?
    bool end_of_month(int) const;  // Är dagen den sista i månaden?
};

inline const Datum operator+(int num, Datum date){
    return date + num;
}

#endif
