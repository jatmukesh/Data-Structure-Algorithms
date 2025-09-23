#include<iostream>
using namespace std;

void change_to( double celsius){
    double kelvin = celsius + 273.15;
    double fahrenheit = celsius*1.80 + 32.00;

    cout << "Temperature in kelvin : " << kelvin << endl ;
    cout << "Temperature in Fahrenheit : " << fahrenheit << endl ;
}

int main(){

    int celsius ;
   
    cout << " Enter temperature in celsius: ";
    cin >> celsius ;
    change_to( celsius );

}