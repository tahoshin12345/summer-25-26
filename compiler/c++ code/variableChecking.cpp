#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void uniqueString(string s)
{
    for(int i=0;i<s.size();i++)
    {
        for(int j=0;j<s.size();j++)
        {
            if(s[i]==s[j])
            {
                s[j]=s[j+1];
            }
        }
    }
}
int main()
{
    fstream f("fileHandling.cpp");
    string s,opt[] = {"+", "-", "*", "/", "%", "++", "--"};
    string key[]= {
    "alignas", "alignof", "and", "and_eq", "asm", "atomic_cancel",
    "atomic_commit", "atomic_noexcept", "auto", "bitand", "bitor",
    "bool", "break", "case", "catch", "char", "char8_t", "char16_t",
    "char32_t", "class", "compl", "concept", "const", "consteval",
    "constexpr", "constinit", "const_cast", "continue", "co_await",
    "co_return", "co_yield", "decltype", "default", "delete", "do",
    "double", "dynamic_cast", "else", "enum", "explicit", "export",
    "extern", "false", "float", "for", "friend", "goto", "if","include"
    "inline", "int", "long", "mutable", "namespace", "new", "noexcept",
    "not", "not_eq", "nullptr", "operator", "or", "or_eq", "private",
    "protected", "public", "reflexpr", "register", "reinterpret_cast",
    "requires", "return", "short", "signed", "sizeof", "static", "std"
    "static_assert", "static_cast", "struct", "switch", "synchronized",
    "template", "this", "thread_local", "throw", "true", "try",
    "typedef", "typeid", "typename", "union", "unsigned", "using",
    "virtual", "void", "volatile", "wchar_t", "while", "xor", "xor_eq", ";","."
};

    int s1=sizeof(opt)/sizeof(opt[0]),s2=sizeof(key)/sizeof(key[0]);
    int varcount,keywordcount,operatorcount;
    varcount=operatorcount=keywordcount=0;
    while(f>>s)
    {
        cout<<s<<" ";
        for (const string& op : opt) {
            if (s == op) {
                operatorcount++;
            }
        }
        for (const string& k : key) {
            if (s == k) {
                keywordcount++;
            }
    }


}
cout<<endl<<endl<<"total operator : "<<operatorcount<<endl;
    cout<<"total keyword : "<<keywordcount;
}
