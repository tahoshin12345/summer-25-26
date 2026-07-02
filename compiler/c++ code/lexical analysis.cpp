#include <iostream>
#include <string>
#include <map>
#include <cctype>

using namespace std;

int main() {
    char ch;
    string currentToken = "";
    map<string, int> symbolTable;
    int idCounter = 1;
    char c[]={"=-*/%^"};
    int sz=sizeof(c)/sizeof(c[0]);

    while (cin.get(ch)) {

        if (isalnum(ch)) {
            currentToken += ch;
        } else {

            if (!currentToken.empty()) {

                if (isdigit(currentToken[0])) {
                    cout << "<" << currentToken << ">";
                }

                else {
                    if (symbolTable.find(currentToken) == symbolTable.end()) {
                        symbolTable[currentToken] = idCounter++;
                    }
                    cout << "<id" << symbolTable[currentToken] << ">";
                }
                currentToken = "";
            }
            for(int i=0;i<sz;i++){
                if(ch==c[i]){
                    cout<<"<"<<ch<<">";
                }
            }
        }
    }
    return 0;
}
