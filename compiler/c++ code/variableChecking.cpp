#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
    fstream f("rion.txt");
    string s;
    while(f>>s)
    {
        cout<<s<<endl;
    }
}
