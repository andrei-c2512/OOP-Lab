#include "MovieSeries.hpp"
#include <iostream>

void MovieSeries::init() noexcept{
    count = 0;
    for(int i = 0 ; i < movieCapacity ; i++)
        movieList[i] = nullptr;
}


void MovieSeries::add(Movie* movie) noexcept{
    if(count == movieCapacity){
        std::cout << "Movie series is at full capacity\n";
        return;
    }

    movieList[count] = movie;
    count++;
}

void MovieSeries::print() const noexcept{
    for(int i = 0 ; i < count ; i++){
        movieList[i]->print();
    }
}

void MovieSeries::sort() noexcept
{
    bool go = false;
    do{
        go = false;
        for(int i = 0 ; i < count - 1 ; i++)
        {
            if(movieList[i]->age() < movieList[i + 1]->age())
            {
                std::swap(movieList[i] , movieList[i + 1]);
                go = true;
            }
        }
    }while(go);
}

