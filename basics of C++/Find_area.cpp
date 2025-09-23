#include<iostream>
using namespace std;

float circle_area(float radius){
    float area = 3.14 * radius * radius ;
    return area; 
}

int main(){
    float radius ;
    cout << " enter the radius of circle: ";
    cin >> radius;
    cout << "Area of circle with radius " << radius << " is :" << circle_area(radius) << endl;

}