#include "Canvas.hpp"
#include <sstream>
#include <iostream>
#include <cstdarg>

Canvas::Canvas(int height , int width)
    :_width(width) , _height(height)
{
    _pBuffer = new char*[height];
    for(int i = 0 ; i < height ; i++)
    {
       _pBuffer[i] = new char[width];
       for(int j = 0 ; j < width ; j++)
          _pBuffer[i][j] = ' '; 
    }
}

Canvas::~Canvas()
{
    for(int y = 0 ; y < _height ; y++)
        delete [] _pBuffer[y];
    delete [] _pBuffer;
    _pBuffer = nullptr;
}
void Canvas::print() const{
    std::cout << "Height : " << _height << "\n Width : " << _width << '\n';
    for(int y = 0 ; y < _height ; y++)
    {
        for(int x = 0 ; x <_width ; x++)
        {
            std::cout << _pBuffer[y][x];
        }    
        std::cout << '\n';
    }
}

void Canvas::clear(){
    for(int y = 0 ; y < _height ; y++)
    {
        for(int x = 0 ; x < _width ; x++)
            _pBuffer[y][x] = ' ';
    }
}
void Canvas::set_pixel(int x, int y, char value){
    _pBuffer[x][y] = value;
}
// tuples of x, y, value
void Canvas::set_pixels(int count, ...){
    va_list args; 
    va_start(args , count);
    
    for(int i = 0 ; i < count ; i++)
    {
        int x = va_arg(args , int);
        int y = va_arg(args , int);
        char val = (char)va_arg(args, int);
        set_pixel(x , y , val);
    }
    va_end(args);
}


