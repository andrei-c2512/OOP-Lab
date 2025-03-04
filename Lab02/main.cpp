#include "NumberList.h"
#include <iostream>

int main(){
    NumberList list;
    list.Init();
    int testNumbers[] = { 3 , 5 , 10 , 2 , 58, 300 };
    for(int nr  :  testNumbers)
        list.Add(nr);
    std::cout << "Test 1 before sorting:\n";

    list.Print();
    list.Sort();
    std::cout << "Test 1 after sorting:\n";
    list.Print();
    
    list.Init();
    int testNumbers2[] = { 10 , 9 , 8 , 7 , 6 ,5 , 4 , 3 , 2, 1 };

    for(int nr : testNumbers2)
        list.Add(nr);
    std::cout << "Test 2 before sorting:\n";
    list.Print();
    list.Sort();
    std::cout << "Test 2 after sorting:\n";
    list.Print();
    
    return 0;
}
