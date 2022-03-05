// Problem: https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118817/offering/1382256

#include<iostream>

using namespace std;

class Shape 
{
    public:
    string shapeType;

    Shape(string shapeType) 
    {
        this -> shapeType = shapeType;
    }

    void printMyType() 
    {
        cout << this -> shapeType << endl;
    }
};

class Square: public Shape 
{
    public:
    int length;

    Square(string shapeType, int length): Shape(shapeType) 
    {
        this -> length = length;
    }

    void printMyType() 
    {
        cout << this -> shapeType << endl;
    }

    int calculateArea() 
    {
        return this -> length * this -> length;
    }
};

class Rectangle: public Shape 
{
    public:
    int length;
    int breadth;

    Rectangle(string shapeType, int length, int breadth): Shape(shapeType) 
    {
        this -> length = length;
        this -> breadth = breadth;
    }

    void printMyType() 
    {
        cout << this -> shapeType << endl;
    }

    int calculateArea() 
    {
        return this -> length * this -> breadth;
    }
};

int main() 
{

    Square square("square", 5);
    square.printMyType();
    cout << square.calculateArea() << endl;

    Rectangle rectangle("rectangle", 5, 4);
    rectangle.printMyType();
    cout << rectangle.calculateArea() << endl;

}
