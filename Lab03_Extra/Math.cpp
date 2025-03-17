#include "Math.h"
#include <stdarg.h>
#include <cstring>
#include <algorithm>



int Math::Add(int x , int y) { return x + y; }
int Math::Add(int x , int y , int z) { return x + y + z; }
int Math::Add(double x , double y) { return int(x + y); }
int Math::Add(double x , double y , double z) { return int(x + y + z); }
int Math::Mul(int x , int y) { return x * y; }
int Math::Mul(int x , int y , int z) { return x * y * z; }
int Math::Mul(double x , double y , double z) { return int(x * y * z); }  
int Math::Mul(double x , double y) { return int(x * y); } 
int Math::Add(int count, ...)
{
    int sum = 0;
    va_list args;
    va_start(args , count);
    for(int i = 0 ; i < count ; i++)
        sum += va_arg(args , int);
    va_end(args);
    
    return sum;
}
char* Math::Add(const char* s1 , const char* s2){
    if(s1 == nullptr || s2 == nullptr) return nullptr;

    size_t max = strlen(s1) , min = strlen(s2);
    const char* maxString = s1 , *minString = s2;
    if(max < min){
        std::swap(maxString , minString);
        std::swap(max , min);
    }
    char* newString = new char[std::max(strlen(s1), strlen(s2))];
    size_t i = 0;
    for( ; i < min ; i++)
        newString[i] = s1[i] + s2[i];

    for( ; i < max ; i++)
        newString[i] = maxString[i];
    return newString;
}

    
    
    
