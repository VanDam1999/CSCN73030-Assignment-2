#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct STUDENT_DATA {
	std::string firstname;
	std::string lastname;
};

std::vector<STUDENT_DATA> students;

int main() {
	std::ifstream file("StudentData.txt");
	std::string str{};
	while (std::getline(file, str)) {
		
		std::istringstream iss(str);

		std::string new_string;
		std::vector<std::string> new_strings;

		while (std::getline(iss, new_string, ',')) {
			new_strings.push_back(new_string);
		}

		STUDENT_DATA student;
		student.firstname = new_strings[0];
		student.lastname = new_strings[1];
		students.push_back(student);
	}




	return 1;
}