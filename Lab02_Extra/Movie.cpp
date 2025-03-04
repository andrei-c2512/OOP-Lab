#include "Movie.h"
#include <cstring>
#include <iostream>

double Movie::score() const noexcept { return _IMDBScore; } 
int Movie::length() const noexcept { return _length; }
int Movie::year() const noexcept{ return _releaseYear; } 
const char* Movie::name() const noexcept { return _name; } 
int Movie::age() const noexcept { return 2025 - _releaseYear; } 

void Movie::set_name(const char* name) noexcept{
    if(strlen(name) > 255)
        return;
    strcpy(_name , name);    
}

void Movie::set_length(int minutes) noexcept {
    _length = minutes;
}

void Movie::set_year(int year) noexcept {
    _releaseYear = year;
}

void Movie::set_score(double score) noexcept {
    if( score >= 0.0 && score <= 10.0)
        _IMDBScore = score;
}


void Movie::print() const noexcept{
    std::cout << "Name : " << _name << '\n';
    std::cout << "Score : " << _IMDBScore << '\n';
    std::cout << "Year : " << _releaseYear << '\n';
    std::cout << "Duration : " << _length << " minutes\n";

    int movieAge = age();
    if(movieAge == 0)
        std::cout << "Has been out for less than a year\n";
    else if(movieAge == 1)
        std::cout << "Has been out for a year\n";
    else 
        std::cout << "Has been out for " << movieAge << " years\n";
    std::cout << '\n';
}
