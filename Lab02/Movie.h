#pragma once

class Movie{
public:
   Movie(const char* name , int releaseYear , double IMDBScore , int minutes);
   void setName(const char* name) noexcept;
   void setReleaseYear(int year) noexcept;
   void setLength(int minutes) noexcept;
   void setIMDBScore(double score) noexcept;
   
   const char* name() const noexcept;
   double IMDBScore() const noexcept; 
   int releaseYear() const noexcept;
   int length() const noexcept;
   int age() const noexcept;
private:
    char _name[256];
    int _releaseYear;
    double _IMDBScore;
    int _length; 
};
