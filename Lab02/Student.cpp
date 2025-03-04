#include "Student.h"


bool Student::gradeInBounds(float num) noexcept{
    return num >= 0.0f && num <= 10.0f;
}


float Student::englishGrade() const noexcept{
    return _english;
}

float Student::averageGrade() const noexcept{
    return (_english + _history + _math) / 3.0f;
}

float Student::historyGrade() const noexcept{
    return _history;
}

float Student::mathGrade() const noexcept{
    return _math;
}

std::string Student::name() const noexcept{
    return _name;
}

void Student::setEnglishGrade(float num) noexcept{
    if(gradeInBounds(num))
        _english = num;
}


void Student::setName(std::string name) noexcept{
    _name = name;
}

void Student::setMathGrade(float num) noexcept{
    if(gradeInBounds(num))
        _math = num;
}


void Student::setHistoryGrade(float num) noexcept{
    if(gradeInBounds(num))
        _history = num;
}
