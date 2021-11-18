// Labb3, Datum.cpp – definitioner av icke-triviala medlemsfunktioner

#include <iostream>
#include <string>
#include "Datum.h"

// Initialisera statisk medlem
// (första elementet används inte i denna lösning!)
const std::array<unsigned int, 13> Datum::ANT_DAGAR_PER_MAANAD = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const std::array<std::string, 13> Datum::NAMES = {"", "Januari", "Februari", "Mars", "April", "Maj", "Juni", "Juli", "Augusti", "September", "Oktober", "November", "December"};

Datum::Datum() { set_date(2000, 1, 1); }

// Konstruktor
Datum::Datum(int year, int month, int day)
{
    set_date(year, month, day);
}

void Datum::set_date(const int &yy, const int &mm, const int &dd)
{
    // Glöm inte att kontrollera inmatade värden, annars "exception"
    if (yy > 2100 || yy < 2000)
    {
        std::invalid_argument("Året måste vara mellan >= 2000 och <= 2100");
    }
    if (mm > 12 || mm < 1)
    {
        std::invalid_argument("Månaden måste vara >= 1 och <= 12");
    }
    int daysInMonth = ANT_DAGAR_PER_MAANAD[mm];
    bool isLeap = is_skott_aar(yy);

    if (isLeap && mm == 2)
    {
        if (dd < 1 || dd > daysInMonth + 1)
        {
            std::invalid_argument("Dagen stämmer inte med år och månad");
        }
    }
    else if (dd < 1 || dd > daysInMonth)
    {
        std::invalid_argument("Dagen stämmer inte med år och månad");
    }

    year = yy;
    month = mm;
    day = dd;
}

// Denna medlemsfunktion är tänkt att lägga till 1 dag till befintligt datum.
// Om sista dagen i månaden, så byt månad.
// Om skottår, så ta hänsyn till att februari(månad 2) har 29 dagar.
// Om sista dagen på året, så byt år.
void Datum::step_one_day()
{
    // Dagen är inte sista dagen i månaden!
    if (!end_of_month(day))
        ++day;
    else if (month < 12)
    {
        ++month;
        day = 1;
    }
    else
    {
        ++year;
        month = 1;
        day = 1;
    }
}

// Returnera true om yy(year) är skottår!
bool Datum::is_skott_aar(int yy)
{
    if (yy % 400 == 0 ||
        (yy % 100 != 0 && yy % 4 == 0))
        return true;
    else
        return false;
}

// Är det sista dagen (dd) i månaden?
bool Datum::end_of_month(int dd) const
{
    if (month == 2 && is_skott_aar(year))
        return dd == 29;
    else
        return dd == ANT_DAGAR_PER_MAANAD[month];
}

const Datum Datum::operator+(const int& dd){
    for(int i = 0; i < dd; i++){
        step_one_day;
    }
    return *this;
}

const Datum Datum::operator+=(const int& dd){
    for(int i = 0; i < dd; i++){
        step_one_day;
    }
    return *this;
}


const void Datum::operator++()
{
    step_one_day();
}
const void Datum::operator++(int dummy)
{
        step_one_day();
}

// operator<<
std::ostream &operator<<(std::ostream &output, const Datum &d)
{
    output << d.day << ' ' << d.NAMES[d.month] << ' '  << d.year;
    return output;
}

Datum operator+(const Datum& date){
    
    //date.step_one_day;
}

const bool Datum::operator<(const Datum &other)
{
    if (year > other.year)
    {
        return false;
    }
    if (year < other.year)
    {
        return true;
    }
    if (month > other.month)
    {
        return false;
    }
    if (month < other.month)
    {
        return true;
    }
    if (day > other.day)
    {
        return false;
    }
    if (day <= other.day)
    {
        return true;
    }
}
const bool Datum::operator<=(const Datum &other)
{
    if (year <= other.year)
    {
        return true;
    }
    if (year > other.year)
    {
        return false;
    }
    if (month <= other.month)
    {
        return true;
    }
    if (month > other.month)
    {
        return false;
    }
    if (day <= other.day)
    {
        return true;
    }
    if (day > other.day)
    {
        return false;
    }
}
const bool Datum::operator>(const Datum &other)
{
    if (year > other.year)
    {
        return true;
    }
    if (year < other.year)
    {
        return false;
    }
    if (month > other.month)
    {
        return true;
    }
    if (month < other.month)
    {
        return false;
    }
    if (day > other.day)
    {
        return true;
    }
    if (day <= other.day)
    {
        return false;
    }
}
const bool Datum::operator>=(const Datum &other)
{
    if (year >= other.year)
    {
        return true;
    }
    if (year < other.year)
    {
        return false;
    }
    if (month >= other.month)
    {
        return true;
    }
    if (month < other.month)
    {
        return false;
    }
    if (day >= other.day)
    {
        return true;
    }
    if (day < other.day)
    {
        return false;
    }
}

const bool Datum::operator==(const Datum &other)
{
    if (year == other.year && month == other.month && day == other.day)
    {
        return true;
    }
    return false;
}
const bool Datum::operator!=(const Datum &other)
{
    if (year == other.year && month == other.month && day == other.day)
    {
        return false;
    }
    return true;
}