#include<iostream>
#include<string>
using namespace std;
int main()
{
     string str;
     string str2; 
  
    cout << "Please enter the string: \n"; 
    getline(cin, str);
    // char c = str[0];
    // cout<<c<<endl;

    cout << "Please enter the substring to fetch : \n"; 
    getline(cin, str2);

    if(str.find(str2)>str.length())
    {
        cout<<"substring not found";
        cout<<endl;
    }
    else{

    cout<<"postition of substring is : \n";
    cout << str.find(str2) << endl;
    cout<<"length of substring is : \n";
    cout<<str2.length();
    cout<<endl;
    }


}