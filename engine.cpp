#include <iostream>
#include <chrono>
#include <thread>
#include "engine.h"

void buffer::wait()
{
    using namespace std::this_thread;
    using namespace std::chrono_literals;
    using std::chrono::system_clock;
    sleep_for(1s);
    system("TERM=xterm-256color;clear");
}

buffer::buffer(const int W, const int H)
{
    this->width = W;
    this->height = H;

    this->data = new char* [H];
    for (int i = 0; i < H; ++i)
        this->data[i] = new char[W];
    
    clear();
}

void buffer::plot(const int x, const int y, const char c)
{
    data[y][x] = c;
}

void buffer::line(const point start, const point end)
{
    
    if (start.x == end.x)
    {
        int starty, endy;
        if (start.y < end.y)
        {
            starty = start.y;
            endy = end.y;
        }
        else
        {
            starty = end.y;
            endy = start.y;
        }
        for (int y = starty; y <= endy; y++)
        {
            plot(start.x, y, '#');
        }
        return;
    }
    
    int deltax = end.x - start.x;
    int deltay = end.y - start.y;
    double delta_error = (double)deltay / deltax;
    if (delta_error < 0) delta_error = -delta_error;
    double error = 0;
    int y = start.y;
    for (int x = start.x; x <= end.x; ++x)
    {
        plot(x, y, '#');
        error += delta_error;
        if (error >= 0.5)
        {
            if (deltay > 0) ++y;
            else --y;
            --error;
        }
    }
}

void buffer::render()
{
    for (int i = 0; i < this->height; ++i)
    {
        for (int j = 0; j < this->width; ++j)
        {
            std::cout << this->data[i][j];
        }
        std::cout << std::endl;
    }
}

buffer::~buffer()
{
    for (int i = 0; i < this->height; ++i)
        delete[] this->data[i];
    delete[] this->data;
}

void buffer::clear()
{
    for (int i = 0; i < this->height; ++i)
    {
        for (int j = 0; j < this->width; ++j)
        {
            this->data[i][j] = ' ';
        }
    }
}
