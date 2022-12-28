#include <iostream>
#include <map>
#include <string>

int main() {
    typedef std::map<std::string, int> mapType;
    mapType populationMap;
    int num, popnum;
    std::string sname, state;

    std::cout << "How many states you want to enter: "; std::cin >> num;
    for(int i = 0; i < num; i++) {
        std::cout << "\nEnter State name: "; std::cin >> sname;
        std::cout << "Enter Population: "; std::cin >> popnum;
        populationMap.insert(std::pair<std::string, int>(sname, popnum)); 
    }

    mapType::iterator iter; char choice;
    do {
        std::cout << "\nEnter the name of the state: "; std::cin >> state;
        iter = populationMap.find(state);
        if(iter != populationMap.end()) {
            std::cout << state <<"'s populations is " << iter -> second << " million\n";
            std::cout << "Continue? [y/n]: "; std::cin >> choice;
        } else { 
            std::cout << "Key is not in populationMap" << '\n';
            std::cout << "\nContinue? [y/n]: "; std::cin >> choice;
        }
    } while(choice == 'y');
    return 0;
}