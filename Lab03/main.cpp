#include "Math.h"
#include <random>
#include <iostream>
#include <string_view>
#include <cstring>
#include "Canvas.h"

std::random_device rd;
std::mt19937 rng(rd());

template<typename lhs , typename rhs>
void printPair(lhs left , rhs right){
    std::cout << left << " : " << right << '\n';
}

void printLn(std::string_view text){
    std::cout << text << '\n';
}
void integerExample(){
    printLn("Integer example");
    printLn("Generating 3 random integers a , b and c");
    std::uniform_int_distribution<int> varRange(0 ,100);
    std::uniform_int_distribution<int> variadicRange(5 , 10);


    int a = varRange(rng) , b = varRange(rng) , c = varRange(rng);

    printPair("a", a);
    printPair("b" , b);
    printPair("c" , c);
    printPair("a+b" , Math::Add(a, b));
    printPair("a+b+c" , Math::Add(a , b , c));
    printPair("a*b", Math::Mul(a,b));
    printPair("a*b*c", Math::Mul(a,b,c)); 

    printPair("Variadic example with 5 arguments: 10 + 5 + 2 + 3 + 10" , Math::Add(5, 10 , 2 , 3, 5 , 10));
}

void realExample(){
    printLn("Real numbers example");
    printLn("Generating 3 random doubles a, b and c");
    std::uniform_real_distribution<double> varRange(0.0 , 100.0);
    
    double a = varRange(rng) , b = varRange(rng) , c = varRange(rng);
    
    printPair("a" , a);
    printPair("b" ,b);
    printPair("c", c);
    printPair("a+b" , Math::Add(a, b));
    printPair("a+b+c" ,Math::Add(a, b , c));
    printPair("a*b" , Math::Mul(a , b));
    printPair("a*b*c" , Math::Mul(a,b,c));
}

void stringExample(){
    printLn("String example");
    printLn("Example 1 with 2 valid arguments");
    const char string1[] = "Andrei are bani";
    const char string2[] = "Andrei nu mai are bani fiindca i-a furat colegul de camera";
    char* result1 = Math::Add(string1 , string2);
   
    printPair("Left side argument" , string1);
    printPair("Right side argument" , string2); 
    printLn(std::string_view(result1 , strlen(result1)));
    delete [] result1;
    printLn("Example 2 with one invalid argument");

    char* result2 = Math::Add(nullptr , "ceva");
    std::cout << result2 << '\n';
}

void canvasExample(){
    Canvas canvas(100 , 80);
    canvas.DrawCircle(30 , 30 , 10 , '@');
    canvas.DrawLine(10 , 10, 50 , 60 , '*');
    canvas.DrawRect(10 , 10 , 60 , 60, '&');
    canvas.Print();
}
int main(){
    //integerExample();
    //realExample(); 
    //stringExample();
    canvasExample();

    return 0;
}
