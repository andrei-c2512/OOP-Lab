#include "NumberList.h"
#include <iostream>


void NumberList::Init()
{
    count = 0;
    for(int i = 0 ; i < 10 ; i++)
        numbers[i] = 0;

}


bool NumberList::Add(int x){
    if(count == 10)
        return false;
    numbers[count] = x;
    count++;

    return true;
}

void NumberList::Sort(){
   bool go = false;
   do{
      go = false;
      for(int i = 0; i < count - 1 ; i++)
      {
         if(numbers[i] > numbers[i + 1])
         {
            std::swap(numbers[i] , numbers[i + 1]);
            go = true; 
         }
      }
    }while(go);
}

void NumberList::Print(){
    for(int i = 0 ; i < count ; i++)
        std::cout << numbers[i] << ' ';
    std::cout << '\n';
}
