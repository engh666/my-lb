class Point //класс точка
{
    int x,y; //координаты
public:
    Point(int _x,int _y) //конструктор принает координаты
    {
        x = _x;
        y = _y;
    }
    void setX(int _x) //устпновить х
    {
        x = _x;
    }
    void setY(int _y) //установить у
    {
        y = _y;
    }
    int getX() //возращает х
    {
        return x;
    }
    int getY() //возращает у
    {
        return y;
    }
};

class Line //класс линия
{
    Point[2]; //масив из двух точек
public:
    Line(int x1,int y1,int x2,int y2) //конструктор принимает координаты двух точек
    {
        Point[0] = Point(x1,y1); //записываем в массив точек
        Point[1] = Point(x2,y2);
    }
    void setX(int x,int n) //установить х
    {
        if(n == 0 || n == 1) //что бы не выйти за границы массива
        {
            Point[n].setX(x);
        }
    }
    void setY(int y,int n) //установить у
    {
        if(n == 0 || n == 1)
        {
            Point[n].setY(y);
        }
    }
    void getX(int n) //вернуть х
    {
        if(n == 0 || n == 1)
        {
            Point[n].getX();
        }
    }
    void getY(int n) //вернуть у
    {
        if(n == 0 || n == 1)
        {
            Point[n].getY();
        }
    }
};

class Paralelogram //класс паралелограм
{
    Line[4]; //это массив из 4х линий
public:
    Paralelogram(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4) //принимает 4 точки
    {
        Line[0] = Line(x1,y1,x2,y2); //записываем в массив
        Line[1] = Line(x2,y2,x3,y3);
        Line[2] = Line(x3,y3,x4,y4);
        Line[3] = Line(x4,y4,x1,y1);
    }
    void setX(int x,int n) //устанавливаем х
    {
        if(n == 0) //меняем в друх линиях
        {
            Line[0].setX(x,0);
            Line[3].setX(x,1);
        }
        else if(n == 1)
        {
            Line[0].setX(x,1);
            Line[1].setX(x,0);
        }
        else if(n == 2)
        {
            Line[1].setX(x,1);
            Line[2].setX(x,0);
        }
        else if(n == 3)
        {
            Line[2].setX(x,1);
            Line[3].setX(x,0);
        }
    }
    void setY(int y,int n)
    {
        if(n == 0)
        {
            Line[0].setY(y,0);
            Line[3].setY(y,1);
        }
        else if(n == 1)
        {
            Line[0].setY(y,1);
            Line[1].setY(y,0);
        }
        else if(n == 2)
        {
            Line[1].setY(y,1);
            Line[2].setY(y,0);
        }
        else if(n == 3)
        {
            Line[2].setY(y,1);
            Line[3].setY(y,0);
        }
    }
    int getX(int n) //получаем х
    {
        if(n>=0 && n<4)
            return Line[n].getX(0);
    }
    int getY(int n) //получаем у
    {
        if(n>=0 && n<4)
            return Line[n].getY(0);
    }
};
