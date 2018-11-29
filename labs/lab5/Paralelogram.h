class Point //����� �����
{
    int x,y; //����������
public:
    Point(int _x,int _y) //����������� ������� ����������
    {
        x = _x;
        y = _y;
    }
    void setX(int _x) //���������� �
    {
        x = _x;
    }
    void setY(int _y) //���������� �
    {
        y = _y;
    }
    int getX() //��������� �
    {
        return x;
    }
    int getY() //��������� �
    {
        return y;
    }
};

class Line //����� �����
{
    Point[2]; //����� �� ���� �����
public:
    Line(int x1,int y1,int x2,int y2) //����������� ��������� ���������� ���� �����
    {
        Point[0] = Point(x1,y1); //���������� � ������ �����
        Point[1] = Point(x2,y2);
    }
    void setX(int x,int n) //���������� �
    {
        if(n == 0 || n == 1) //��� �� �� ����� �� ������� �������
        {
            Point[n].setX(x);
        }
    }
    void setY(int y,int n) //���������� �
    {
        if(n == 0 || n == 1)
        {
            Point[n].setY(y);
        }
    }
    void getX(int n) //������� �
    {
        if(n == 0 || n == 1)
        {
            Point[n].getX();
        }
    }
    void getY(int n) //������� �
    {
        if(n == 0 || n == 1)
        {
            Point[n].getY();
        }
    }
};

class Paralelogram //����� ������������
{
    Line[4]; //��� ������ �� 4� �����
public:
    Paralelogram(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4) //��������� 4 �����
    {
        Line[0] = Line(x1,y1,x2,y2); //���������� � ������
        Line[1] = Line(x2,y2,x3,y3);
        Line[2] = Line(x3,y3,x4,y4);
        Line[3] = Line(x4,y4,x1,y1);
    }
    void setX(int x,int n) //������������� �
    {
        if(n == 0) //������ � ���� ������
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
    int getX(int n) //�������� �
    {
        if(n>=0 && n<4)
            return Line[n].getX(0);
    }
    int getY(int n) //�������� �
    {
        if(n>=0 && n<4)
            return Line[n].getY(0);
    }
};
