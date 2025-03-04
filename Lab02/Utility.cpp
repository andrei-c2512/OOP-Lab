#include "Utility.h"
#include <cstring>

int Utility::cmpNum(float lhs , float rhs){
   if(lhs > rhs)
      return 1;
   else if(lhs == rhs)
      return 0;
   else 
      return -1;
}
    
int Utility::compareAverage(const Student& s1 , const Student& s2){
   float lhs = s1.averageGrade();
   float rhs = s2.averageGrade();
   return cmpNum(lhs , rhs);
} 


int Utility::compareMathGrade(const Student& s1 , const Student& s2){
   float lhs = s1.mathGrade();
   float rhs = s2.mathGrade();
   return cmpNum(lhs , rhs);
} 

int Utility::compareEnglishGrade(const Student& s1 , const Student& s2){
    float lhs = s1.englishGrade();
    float rhs = s2.englishGrade();

    return cmpNum(lhs , rhs);
}

int Utility::compareHistoryGrade(const Student& s1, const Student& s2){
    float lhs = s1.historyGrade();
    float rhs = s2.historyGrade();
    return cmpNum(lhs , rhs);
}

int Utility::compareName(const Student& s1 , const Student& s2){
    return strcmp(s1.name().data()  , s2.name().data());
}
