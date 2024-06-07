#include <iostream>
#include <ctime>

using namespace std;

bool isTheYearALeapYear(int year) //isLeapYear(int year)
{
    if (year % 400 == 0)
        return true;
    if ((year % 4 == 0) && (year % 100 != 0))
        return true;
    return false;
}

int howManyDaysAMonthHasFromTheGivenDate(int year, int month, int day) //how many days a month has from the given date; ileDniMaMiesiacZPodanejDaty
{
    int daysInTheMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //dniWMiesiacu

    if (year < 2000 || month < 1 || month > 12 || day < 1 || day > 31)
        return 0;

    if (isTheYearALeapYear(year) && month == 2) //czyRokJestPrzestepny
        daysInTheMonth[month - 1]++;

    return daysInTheMonth[month - 1];
}

bool isTheDateCorrect(int year, int month, int day) //czyDataJestPoprawna
{
    int numberOfDays = howManyDaysAMonthHasFromTheGivenDate(year, month, day);
    if (numberOfDays == 0) return false;

    return day <= numberOfDays;
}

int howManyDaysTheCurrentMonthHas() //ileDniMaBiezacyMiesiac
{
    time_t timeNow = time(0); //czasTeraz
    tm* now = localtime(&timeNow);

    int year = now->tm_year + 1900;
    int month = now->tm_mon + 1;
    int day = now->tm_mday;

    return howManyDaysAMonthHasFromTheGivenDate(year, month, day);
}

struct Date
{
    int year;
    int month;
    int day;
};

Date stringToDateConversion(string dateString) //konwersjaNaDate
{
    Date date;
    date.year = stoi(dateString.substr(0, 4));
    date.month = stoi(dateString.substr(5, 2));
    date.day = stoi(dateString.substr(8, 2));
    return date;
}

int compareDates(string date1, string date2) //porownajDate
{
    Date d1 = stringToDateConversion(date1);
    Date d2 = stringToDateConversion(date2);

    // Porownanie lat
    if (d1.year < d2.year) return -1;
    if (d1.year > d2.year) return 1;

    // Porownanie miesiecy
    if (d1.month < d2.month) return -1;
    if (d1.month > d2.month) return 1;

    // Porownanie dni
    if (d1.day < d2.day) return -1;
    if (d1.day > d2.day) return 1;

    // Daty sa rowne
    return 0;
}

int main()
{
    cout << howManyDaysTheCurrentMonthHas();
    return 0;
}
