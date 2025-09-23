#include<iostream>
using namespace std;

int main(){
    
// butterfly pattern

int m = 5 ;

for(int i = 0; i < 2*m; i++){
    int condition = i < m ? i : (m + (m - i - 1));
    int spaces = i < m ? 2*(m - condition - 1) : (i - condition -1);
    for( int j = 0; j < 2*m; j++){
        if(j <= condition ){
            cout << "* ";
        }
        else if(spaces > 0){
            cout << "  ";
            spaces--;
        }
        else{
            cout << "* ";
        }
    }
    cout << endl;
}
}