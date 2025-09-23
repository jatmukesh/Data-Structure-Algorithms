#include<iostream>
#include<numeric>
using namespace std;

bool isPossibleSolution(int book_pages[], int N, int M, int sol ){  // predicate function
    int pageSum =0 ;
    int c = 1;
    for(int i =0; i < N; i++){
        if(book_pages[i] > sol)   return false;
        else if(pageSum + book_pages[i] > sol){
            c++;
            pageSum = book_pages[i];
            if(c>M ){
                return false;
            }
        } 
        else {
            pageSum+=book_pages[i];
        }
    }
    return true;

}

int Find_pages(int book_pages[], int N ,int M ){
    if( M > N )     return -1;
    int start = 0;
    int end = accumulate(book_pages, book_pages+N, 0);
    int ans =-1;
    
    while(start <= end){
        int mid = start + (end-start)/2;
        if(isPossibleSolution(book_pages,N,M,mid)){         //predicate function
            ans = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }

    return ans;
}


int main(){
    
    int book_pages[] = { 12,34,67,90 };
    int N = 4, M = 2;
    int ans = Find_pages(book_pages,N,M);
    cout << " the answer is : " << ans;

}