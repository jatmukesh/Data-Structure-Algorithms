#include<iostream>
#include<vector>

using namespace std;

int main(){
        // syntax -> vector<type> vectorName

    vector<string> cars = {"volvo", "Mazda", "BMW", "Roll Royce" };
    
    // Print vector elements using auto keyword 
    // 'auto' directly identifies the datatype of the vector array and then runs similar to for loop
    for (auto i : cars) {  // it assigns value of all the elements in 'cars' to 'i' that is a temporary or loop variable 
        cout << i << " ";
    }
    cout << endl;
    // Get the first element
    cout << cars.front() << endl;

    // Get the last element
    cout << cars.back() << endl;

    
    // Get the second element
    cout << cars.at(1)<< endl;

    // Get the third element
    cout << cars.at(2)<< endl;
     
    // Get the pointer to the first and last  element  -> vectorName.begin() and vectorName.end()
    cars.erase(cars.begin()+1) ;
    for(auto i : cars)
     cout  << i<< " ";
    
    cout << endl;
    cout << cars.max_size();
     
}