#include<bits/stdc++.h>
using namespace std;    
void radixSort(vector<int>&v){
    
}
void display(vector<int>&v){
    
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
}
int main(){
    freopen("output.txt","w",stdout);
    vector<int>arr =  {-50, -20, 0, 10, 5, 3, 2, 1, 4, 100, 200, 150};
    cout<<"Before Sorting : "<<endl;
    display(arr);
    // Radix Sort implementation goes here
    cout<<"After Sorting : "<<endl;
    display(arr);
}