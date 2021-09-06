#ifndef engine_h
#define engine_h

struct point
{
    int x;
    int y;
};

struct buffer
{
private:
    char** data;
    int width;
    int height;
public:
    buffer(const int, const int);
    void plot(const int, const int, const char);
    void line(const point, const point);
    void render();
    void clear();
    void wait();
    ~buffer();
};

#endif
