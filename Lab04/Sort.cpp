#include <random>
#include "Sort.hpp"
#include <stdarg.h>
#include <string.h>
#include <iostream>
#include <stack>

std::random_device rd;
std::mt19937 rng(rd());

Sort::Sort(int min , int max, size_t size)
    :_size(size)
{
    std::cout << "List constructed with random elements\n";
    _pList = new int[size];
    std::uniform_int_distribution<int> range(min , max);

    for(int i = 0 ; i < size ; i++)
        _pList[i] = range(rng);
}

Sort::Sort(std::initializer_list<int> list){
    std::cout << "List constructed with initialiser list\n";
    _pList = new int[list.size()];
    int* ptrToList = _pList;
    for(auto b = list.begin() ; b != list.end() ; ++b){
        *ptrToList = *b;
        ptrToList++;
    }
    _size = list.size();
}

Sort::Sort(int* list , size_t size)
    :_pList(list) , _size(size)
{}
Sort::Sort(int count , ...)
    :_size(count)
{
    std::cout << "Constructor with variadic arguments\n";
    _pList = new int[count];

    va_list args;
    va_start(args, count);
    
    for(int i = 0 ; i < _size ; i++)
        _pList[i] = va_arg(args, int);

    va_end(args); 
}
Sort::Sort(char* string){
    std::cout << "Constructor by string\n";
    _size = 0;
    for(int i = 0 ; i < strlen(string); i++){
        _size += (size_t)(string[i] == ',');
    }    
    _pList = new int[_size];

    char* number = strtok(string , ",");
    int i = 0;
    while(number != nullptr){
        _pList[i] = atoi(number);
        number = strtok(nullptr , ",");
        i++;  
    }
}

std::function<bool(int , int)> Sort::comparisonOp(bool ascendent){
    if(ascendent){
        return [](int lhs , int rhs) { return lhs < rhs; };
    }
    else 
        return  [](int lhs , int rhs) { return lhs > rhs; };
}

void Sort::InsertSort(bool ascendent){ 
    auto cmp = comparisonOp(ascendent);
    std::cout << _size << '\n';
    for(int i = 0 ; i < _size ; i++){
        int tmp = _pList[i];
        int j = i - 1;
        while(j >= 0 && cmp(tmp, _pList[j]))
        {
            _pList[j + 1] = _pList[j];
            j--;
        }
        j++;
        _pList[j] = tmp;
    }
}
void Sort::QuickSort(bool ascendent){
    auto cmp = comparisonOp(ascendent);
    std::stack<std::pair<int , int>> intervalStack;
    intervalStack.emplace(0 , _size - 1);

    while(intervalStack.size()){
        auto interval = intervalStack.top();
        intervalStack.pop();
        int left = interval.first , right = interval.second;
        int pivot = (left + right) / 2;
        std::swap(_pList[pivot] , _pList[right]);
        right--;
        while(left <= right){
            while(right >= interval.first && cmp(_pList[interval.second],_pList[right]))
                right--;
            while(left <= interval.second  && !cmp(_pList[interval.second] , _pList[left]))
                left++;    
            if(left < right)
                std::swap(_pList[left] , _pList[right]);
        }
        std::swap(_pList[left] , _pList[interval.second]);
        if(left - 1 - interval.first > 1)
            intervalStack.emplace(interval.first , left - 1);
        if(interval.second - (left + 1) > 1)
            intervalStack.emplace(left + 1 , interval.second);
        
    }
}
void Sort::BubbleSort(bool ascendent){
    if(_size < 2) return;
    auto cmp = comparisonOp(ascendent);
    bool go = false;
    do{
      go = false;
      for(int i = 0 ; i < _size - 1; i++)
      {
            if(cmp(_pList[i] , _pList[i + 1])){
                go = true;
                std::swap(_pList[i] , _pList[i + 1]);
            }
      }
    }while(go); 
}
void Sort::Print() const{
    for(int i = 0 ; i < _size ; i++){
        std::cout << _pList[i] << ' ';
    }
    std::cout << '\n';
}
int  Sort::GetElementsCount() const { return _size; }
int  Sort::GetElementFromIndex(int index) const { return _pList[index]; }
