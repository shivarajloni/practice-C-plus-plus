#include<iostream>

using namespace std;

string replacePi(string s)
{ 
    if (s.length() == 0 || s.length() == 1)
        return s;
    if (s[0] == 'p' && s[1] == 'i')
    {
        string smallOutput = replacePi(s.substr(2));    

        return "3.14" + smallOutput;
    }
    else
    {
        string smallOutput = replacePi(s.substr(1));
        return s[0] + smallOutput;
    }
}
 
int main()
{
    string s = "pipppiiipi";
      
    string result = replacePi(s);
     
    cout << result << endl;
 
    return 0;
}