#include "Sort.hpp"
#include <iostream>

void printLn(const char* str){
    std::cout << str << '\n';
}
int main(){
    Sort list1 = { 10 , 24 , 41 , 512 , 1231 , 1231};
    char str[] = "10,23,41,54,100,1,4,3,2";
    Sort list2(str);
    Sort list3(3 , 10 , 20);
    
    printLn("List1");
    list1.Print();
    printLn("List2");
    list2.Print();
    printLn("List3");
    list3.Print();
    
    printLn("List1 descending insertion sort");
    list1.InsertSort(false);
    list1.Print();
    printLn("List1 ascending insertion sort");
    list1.InsertSort(true);
    list1.Print();


    printLn("List2 descending quick sort");
    list2.QuickSort(false);
    list2.Print();
    printLn("List2 ascending quick sort");
    list2.QuickSort(true);
    list2.Print();

    printLn("List3 descending bubble sort");
    list3.BubbleSort(false);
    list3.Print();
    printLn("LIst3 ascending bubble sort");
    list3.BubbleSort(true);
    list3.Print();
}
