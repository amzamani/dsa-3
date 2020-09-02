#include<iostream>
#include<string>
using namespace std;
int main()
{
     string str;
     string str2; 
  
    cout << "Please enter the 1st string: \n"; 
    getline(cin, str);
    // char c = str[0];
    // cout<<c<<endl;

    cout << "Please enter the 2nd string : \n"; 
    getline(cin, str2);
    cout<<"combined string :";
    cout<<str+str2;
    cout<<endl;


}