#include "engine.h"

int main()
{
    buffer screen(20, 20);
    screen.line({ 0,0 }, { 4,4 });
    screen.line({ 4,4 }, { 8,0 });
    screen.line({ 8,0 }, { 12,4 });
    screen.wait();
}