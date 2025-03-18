#pragma once
#include <functional>
#include <initializer_list>

class Sort
{
public:
    Sort(int min , int max , size_t count);
    Sort(int* list , size_t size);
    Sort(std::initializer_list<int> list);
    Sort(int count , ...);
    Sort(char* string);
    void InsertSort(bool ascendent=false);
    void QuickSort(bool ascendent=false);
    void BubbleSort(bool ascendent=false);
    void Print() const;
    int  GetElementsCount() const;
    int  GetElementFromIndex(int index) const;
private:
    static std::function<bool(int , int)> comparisonOp(bool ascendent);    
private:
    int* _pList;
    size_t _size;
};
