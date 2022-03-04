// Problem: https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118817/offering/1382241

#include <iostream>
using namespace std;

class Car {
    public:
    int noOfGear;
    string color;

    Car(int noOfGear, string color) 
    {
        this -> noOfGear = noOfGear;
        this -> color = color;
    }
    void printCarInfo() 
    {
        cout << "noOfGear: " << this -> noOfGear << endl;
        cout << "color: " << this -> color << endl;
    }

};

class RaceCar: public Car 
{
    public: int maxSpeed;

    RaceCar(int noOfGear, string color, int maxSpeed): Car(noOfGear, color) 
    {

        this -> maxSpeed = maxSpeed;
    }

    void printRaceCarInfo() 
    {
        printCarInfo();
        cout << "maxSpeed: " << this -> maxSpeed;
    }
};


int main() {
    int noOfGear, maxSpeed;
    string color;
    cin >> noOfGear >> color >> maxSpeed;
    RaceCar raceCar(noOfGear, color, maxSpeed);
    raceCar.printRaceCarInfo();
    return 0;
}
