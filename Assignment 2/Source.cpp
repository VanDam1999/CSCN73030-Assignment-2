#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

//#define PRE_RELEASE

struct STUDENT_DATA {
	std::string firstname;
	std::string lastname;
	std::string email;
};

std::vector<STUDENT_DATA> students;

int main() { 

	// PRE-RELEASE MODE SORUCE CODE
	#ifdef PRE_RELEASE
		cout << "You are currently running the pre-release source code \n" << endl;
		
		// Open the StudentData_Email.txt file
		std::ifstream file("StudentData_Emails.txt");
	#else 
		cout << "You are currently running the standard source code \n" << endl;

		// Open the StudentData.txt file
		std::ifstream file("StudentData.txt");
	#endif;

	std::string str;
	
	// Read each line from the txt file.
	while (std::getline(file, str)) {
		
		std::istringstream new_str(str);

		std::string new_string;
		std::vector<std::string> new_strings;

		// Break the string from the file into a vector where there is a comma
		while (std::getline(new_str, new_string, ',')) {
			new_strings.push_back(new_string);
		}

		// Create an object and store the vector data into it
		STUDENT_DATA student;
		student.firstname = new_strings[0];
		student.lastname = new_strings[1];

		#ifdef PRE_RELEASE 
			student.email = new_strings[2];
		#endif;

		// Push the object into a vector object of the same type
		students.push_back(student);
	}

	// DEBUG MODE TESTING
	#ifdef _DEBUG
		#ifdef PRE_RELEASE
			for (int i = 0; i < students.size(); i++) {
				cout << students.at(i).firstname << "," << students.at(i).lastname << ", " << students.at(i).email << endl;
			}
		#else 
			for (int i = 0; i < students.size(); i++) {
				cout << students.at(i).firstname << "," << students.at(i).lastname << endl;
			}
		#endif;
	#endif 

	return 1;
}