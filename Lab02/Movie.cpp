#include "Movie.h"
#include <cstring>

double Movie::IMDBScore() const noexcept { return _IMDBScore; } 
int Movie::length() const noexcept { return _length; }
int Movie::releaseYear() const noexcept{ return _releaseYear; } 
const char* Movie::name() const noexcept { return _name; } 
int Movie::age() const noexcept { return 2025 - _releaseYear; } 

void Movie::setName(const char* name) noexcept{
    if(strlen(name) > 255)
        return;
    strcpy(_name , name);    
}

void Movie::setLength(int minutes) noexcept {
    _length = minutes;
}

void Movie::setReleaseYear(int year) noexcept {
    _releaseYear = year;
}

void Movie::setIMDBScore(double score) noexcept {
    if( score >= 0.0 && score <= 10.0)
        _IMDBScore = score;
}


