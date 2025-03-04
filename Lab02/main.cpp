#include "NumberList.h"
#include <iostream>
#include "Student.h"
#include "Utility.h"

void numberListClassExample(){
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

}

void studentClassExample(){
    Student s1;
    Student s2;

    //s1 init
    s1.setName("Andrei");
    s1.setMathGrade(7.0f);
    s1.setEnglishGrade(10.0f);
    s1.setHistoryGrade(9.0f);

    //s2 init
    s2.setName("Mihnea");
    s2.setMathGrade(5.0f);
    s2.setEnglishGrade(10.0f);
    s2.setHistoryGrade(10.0f);
    
    std::cout << "Comparing " << s1.name() << " to " << s2.name() << "'s History Grades\n";
    std::cout << Utility::compareHistoryGrade(s1 , s2) << '\n';
    
    std::cout << "Comparing " << s1.name() << " to " << s2.name() << "'s names\n";
    std::cout << Utility::compareName(s1 , s2) << '\n';

    std::cout << "Comparing " << s1.name() << " to " << s2.name() << "'s Math Grades\n";
    std::cout <<    Utility::compareMathGrade(s1 , s2) << '\n';
    
    std::cout << "Comparing " << s1.name() << " to " << s2.name() << "'s Average Grades\n";
    std::cout << Utility::compareAverage(s1 , s2) << '\n';

    
    std::cout << "Comparing " << s1.name() << " to " << s2.name() << "'s English Grades\n";
    std::cout << Utility::compareEnglishGrade(s1 , s2) << '\n';


}
int main(){
    numberListClassExample();
    studentClassExample(); 
    return 0;
}
