#pragma once

#include "Movie.h"


class MovieSeries{
public:
    void init() noexcept;
    void add(Movie* movie) noexcept;
    void sort() noexcept;
    void print() const noexcept; 
    static constexpr int movieCapacity = 16;
private:
    Movie* movieList[movieCapacity];
    int count;
};
