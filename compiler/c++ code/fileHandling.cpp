#include <iostream>
#include <fstream>

using namespace std;

int main()
{
   fstream f("newText.txt");
   string s;
   while(f>>s)
   {
       cout<<s<<endl;
   }

}
