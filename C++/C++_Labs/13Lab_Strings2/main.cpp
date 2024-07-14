#include<iostream>


using namespace std;
string manupStr(string haystack,string needle,string replacement){

    int position = haystack.find(needle);

    while(position != string::npos){
        haystack.replace(position,needle.length(),replacement);
        position = haystack.find(needle);
    }

    return haystack;
}
int main(){
    string haystack , needle , replacement;
    string finalstr ; 
    cout << "Enter the source string: " << endl ;
    getline(cin , haystack);

    cout << "Enter the string to find string: " << endl ;
    getline(cin , needle);

    cout << "Enter the replacement string: " << endl ;
    getline(cin , replacement);

    finalstr = manupStr(haystack,needle,replacement);
    cout << finalstr << endl;

}