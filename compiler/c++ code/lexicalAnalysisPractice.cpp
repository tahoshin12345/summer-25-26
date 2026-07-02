#include <bits/stdc++.h>
using namespace std;
int main(){
    char ch;
    string currentToken="";
    int tokenId=0;

    string k={"=-*/%^"};


    map<string,int> simbleTable;
    while(cin.get(ch)){
        if(isalnum(ch)){
            currentToken+=ch;
        }
        else{
            if(!currentToken.empty()){
                if(isdigit(currentToken[0])){
                        cout<<"<"<<currentToken<<"> ";
                }
                else{
                    if(simbleTable.find(currentToken)==simbleTable.end()){
                        simbleTable[currentToken]=++tokenId;

                    }
                    cout<<"<id,"<<simbleTable[currentToken]<<"> ";
                }
               currentToken="";
            }
            for(int i=0;i<k.length();i++){
                if(ch==k[i]){
                    cout<<"<"<<ch<<"> ";
                }
            }
        }

    }
}
