#include<iostream>
#include<string>
#include <cctype>
#include<map>
using namespace std;
int main()
{
char ch;
string token="";
int id=0;
string s="+-*/%=";
map<string,int> st;
 while(cin.get(ch)){
    if(isalnum(ch)){
        token+=ch;
    }
    else{
        if(!token.empty()){
            if(isdigit(token[0])){
                cout<< "<"<<token<< ">";
            }
        else{
            if(st.find(token)==st.end()){
                st[token]=++id;
            }
            cout<<"<id"<<st[token]<<">";
        }
        token="";
        }
         for(int i=0;i<s.length();i++){
        if(ch==s[i]){
            cout<<"<"<<ch<<">";
        }

    }

    }
 }
}
