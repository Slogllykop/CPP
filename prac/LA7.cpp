#include <iostream>
#include <map>
#include <string>
#include <utility>
using namespace std;

int main() {
    typedef map<string, int> mapType;
    mapType populationMap;
    int i;
    int num;
    string sname;
    int popnum;

    cout<<"How many states you want to enter :: ";
    cin>>num;

    for(i=0;i<num;i++) {
        cout<<"Enter State name :: ";
        cin>>sname;
        cout<<"Enter Population :: ";
        cin>>popnum;
        cout<<"-----------------------------"<<endl; 
        populationMap.insert(pair<string, int>(sname, popnum)); 
    } 

    mapType::iterator iter = --populationMap.end();
    cout << "Size of populationMap :: " << populationMap.size() << '\n';

    for (iter = populationMap.begin(); iter != populationMap.end(); ++iter) {
        cout << iter->first <<": " << iter->second << " million\n";
        cout<<"-----------------------------"<<endl;
    }
    
    string state;
    cout<<"Enter the name of the state :: "<<endl;
    cin>>state;

    iter = populationMap.find(state);
    if( iter != populationMap.end() )
    cout << state <<"'s populations is " << iter->second << " million\n";
    else
    cout << "Key is not in populationMap" << '\n';
    
    populationMap.clear();
    return 0;
}