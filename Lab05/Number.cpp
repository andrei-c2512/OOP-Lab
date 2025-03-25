#include "Number.hpp"
#include <assert.h>
#include <string.h>
#include <iostream>

Number::Number(const char * value, int base){
    
}
Number::~Number()
{
    if(_pNumStr)
        delete [] _pNumStr;
    _pNumStr = nullptr;
}


Number::Number(const Number& num){  
    if(_pNumStr)
        delete [] _pNumStr;
    _pNumStr = nullptr;

    strcpy(_pNumStr , num._pNumStr);
    _size = num._size;    
    _capacity = num._capacity;
}
Number& Number::operator=(const Number& num){ 
    if(_pNumStr)
        delete [] _pNumStr;
    _pNumStr = nullptr;

    strcpy(_pNumStr , num._pNumStr);
    _size = num._size;    
    _capacity = num._capacity;
    return *this;
} 
Number::Number(Number&& num){ 
    if(_pNumStr)
        delete [] _pNumStr;
    _pNumStr = nullptr;
    _pNumStr = num._pNumStr;

    num._pNumStr = nullptr;
    _size = std::move(num._size);
    _capacity = std::move(num._capacity);
}

void Number::toBaseTen(){
    int exponent = 1;
    
   char* newNum =  
    for(int i = 0; i < _size ; i--){
        if(       
    }
}

Number& Number::operator=(Number&& num) noexcept{
    if(_pNumStr)
        delete [] _pNumStr;
    _pNumStr = nullptr;
    _pNumStr = num._pNumStr;

    num._pNumStr = nullptr;
    _size = std::move(num._size);
    _capacity = std::move(num._capacity);

    return *this;
}

void Number::SwitchBase(int newBase){

}
void Number::Print() const{
    std::cout << _pNumStr << '\n';
}
int  Number::GetDigitsCount() const{
    return _size;
}
int  Number::GetBase() const{
    return _base;
}

bool Number::operator>(const Number& num) const{
    if(_size > num._size)
        return true;
    else if(_size < num._size)
        return false;
    return ==operator(num);

}
bool Number::operator<(const Number& num) const{

}
bool Number::operator>=(const Number& num) const{

}
bool Number::operator<=(const Number& num) const{

}
bool Number::operator==(const Number& num) const{
    return false;
}
