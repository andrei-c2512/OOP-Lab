#include "Canvas.h"
#include <cmath>
#include <iostream>

Canvas::Canvas(int width0 , int height0)
    :width(width0), height(height0)
{
    pixelBuffer = new char*[height];
    for(int y = 0 ; y < height ; y++){
        pixelBuffer[y] = new char[width];
        for(int x = 0 ; x < width ; x++)
           pixelBuffer[y][x] = ' '; 
    }

}

void Canvas::Clear(){
    for(int y = 0 ; y < height ; y++){
        for(int x = 0 ; x < width ; x++)
            pixelBuffer[y][x] = ' ';
    }
}

void Canvas::Print(){
    for(int y = 0 ; y < height ; y++)
        std::cout << pixelBuffer[y] << '\n';
}

void Canvas::FillRect(int left , int top , int right , int bottom, char ch)
{
    for( ; top < bottom ; top++){
        for( ; left < right ; left++)
            pixelBuffer[top][left] = ch;
    }
}

void Canvas::DrawRect(int left , int top , int right , int bottom , char ch)
{
    //top and bottom lines
    for(int l = left ; l < right ; l++)
    {
        pixelBuffer[top][l] = ch;
        pixelBuffer[bottom][l] = ch;
    }
    //bottom and top
    for(int t = top ; t < bottom ; t++)
    {
        pixelBuffer[t][left] = ch;
        pixelBuffer[t][right] = ch;
    }
}

float Canvas::distance(int x1 , int y1 , int x2 , int y2){
    return sqrt( pow(x1 - x2 , 2) + pow(y1 - y2, 2));    
}

void Canvas::FillCircle(int x , int y , int ray , char ch)
{
   for(int bufY = y - ray ; bufY < y + ray ; bufY++){
      for(int bufX = x - ray ; bufX < x + ray ; bufX++){
          int distanceFromCenter = (int)distance(x , y , bufX , bufY);
          if(distanceFromCenter <= ray)
              pixelBuffer[bufY][bufX] = ch;
      } 
    }
}

void Canvas::DrawCircle(int x , int y , int ray , char ch)
{
   for(int bufY = y - ray ; bufY < y + ray ; bufY++){
      for(int bufX = x - ray ; bufX < x + ray ; bufX++){
          int distanceFromCenter = (int)distance(x , y , bufX , bufY);
          if(distanceFromCenter <= ray && distanceFromCenter >= ray - 2)
              pixelBuffer[bufY][bufX] = ch;
      } 
   }
}

void Canvas::SetPoint(int x , int y , char ch){
    pixelBuffer[y][x] = ch;
}

void Canvas::DrawLine(int x1 , int y1 , int x2 , int y2 , char ch){
    float slope = float(y2 - y1) / float(x2 - x1);
    if(!(slope >= -1.0f && slope <= 1.0f))
    {
        slope = float(x2 - x1)/ (y2 - y1);
        float x = float(x1) + slope;
        for(int y = y1 ; y < y2 ; y++){
            pixelBuffer[y][(int)x] = ch; 
            x += slope;
        }
    }
    else{
        float y = y1;
        for(int x = x1 ; x < x2 ; x++){
            pixelBuffer[(int)y][x] = ch;
            y += slope;
        }
    }

}
