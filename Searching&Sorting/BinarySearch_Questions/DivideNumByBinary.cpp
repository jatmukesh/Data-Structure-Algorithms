#include<iostream>
using namespace std;

int GetQuotient(int divisor , int dividend){
    int s = 0;
    int e = dividend;
    int mid = s + (e-s)/2;
    int ans = -1;

    while( s <= e){
        if(divisor*mid == dividend)
            return mid ;
        else if(divisor*mid < dividend){
            ans = mid ;
            s = mid+1;
            }
        else
            e = mid-1;
        mid = s + (e-s)/2;
    }
     return ans;
}

int main(){
    int divisor,dividend;
    cout << "enter divisior:";
    cin >> divisor ;
    cout << "enter dividend :";
    cin >> dividend;
    int ans = GetQuotient( abs(divisor), abs(dividend));
    
    if( (divisor > 0 && dividend < 0 )|| (divisor < 0 && dividend > 0 ) )
    ans = -ans;
    cout << "Final ans is : " << ans << endl;
}