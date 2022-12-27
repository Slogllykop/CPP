#include <iostream>
#include <fstream>
#include <string>

class Student {
    public:
        std::string name;
        int roll; float marks;

        void getdata() {
            std::cin.ignore();
            std::cout<<"Enter Name: "; getline(std::cin, name);
            std::cout<<"Enter Roll NO: "; std::cin>>roll;
            std::cout<<"Enter marks : "; std::cin>>marks;
            std::cout<<std::endl;
        }
};

int main() {
    int n;
    std::cout<<"Total Students: "; std::cin>>n;

    Student s[10];

    std::ofstream fout;
    fout.open("students.txt");

    int i = 0;
	while (fout && n) {
        s[i].getdata();
        fout << "Student " << ++i << std::endl;
        fout << "Name: " << s[--i].name << std::endl;
        fout << "Roll no.: " << s[i].roll << std::endl;
        fout << "Marks: " << s[i++].marks;
        if (n-- > 1) fout << "\n\n";
    }

	fout.close();

    std::string line;

    std::ifstream fin;
	fin.open("students.txt");

    std::cout << "FILE CONTENT BELOW\n";
    while (fin && getline(fin, line)) std::cout << line << "\n";

    fin.close();

    return 0;
}