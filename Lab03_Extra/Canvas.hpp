#pragma once


class Canvas {
  public:
    // contructor will call the clear method
    Canvas(int lines, int columns);
    ~Canvas();
    Canvas(const Canvas&) = delete;
    Canvas& operator=(const Canvas&) = delete;
    // set the character at the position x and y to value
    void set_pixel(int x, int y, char value);
    
    // tuples of x, y, value
    void set_pixels(int count, ...);

    void clear();
    void print() const;
  private:
    char** _pBuffer;
    int _width;
    int _height;
};
