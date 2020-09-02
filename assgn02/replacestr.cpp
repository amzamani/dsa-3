#include<iostream>
#include<string>
using namespace std;
int main()
{
     string str;
     string str2; 
     string str3;
  
    cout << "Please enter the string: \n"; 
    getline(cin, str);
    // char c = str[0];
    // cout<<c<<endl;

    cout << "Please enter the substring to replace : \n"; 
    getline(cin, str2);
    if(str.find(str2)>str.length())
    {
        cout<<"substring not found";
        cout<<endl;
    }
    else{

    int pos = str.find(str2);
    int pos_last = str2.length();

    cout <<"Please enter the substring to replace with : \n";
    getline(cin,str3);
    
    cout<<pos<<endl;
    cout<<pos_last<<endl;

    str.replace(pos,pos_last,str3);

    cout<<endl;
    cout<<str;
    cout<<endl;
    }



}