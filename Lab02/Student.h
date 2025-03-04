#pragma once
#include <string>

class Student{
public:
    Student() = default;
    std::string name() const noexcept;
    float mathGrade() const noexcept;
    float englishGrade() const noexcept;
    float historyGrade() const noexcept;

    float averageGrade() const noexcept;

    void setMathGrade(float num) noexcept;
    void setEnglishGrade(float num) noexcept;
    void setHistoryGrade(float num) noexcept;
    void setName(std::string num) noexcept;
private:
    static bool gradeInBounds(float num) noexcept;
private:
    std::string _name;
    float _math;
    float _english;
    float _history;
};

