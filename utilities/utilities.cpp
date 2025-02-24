#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <vector>

#include "../includes/constants.h"
#include "../includes/utilities.h"
using namespace std;

/***
 * Clears allStudentData, Opens file, For each line; parses name, midterm1,midterm2 and an
 * optional finalgrade (if present in file)from that line. Puts this info into a studentData struct,
 * adds this struct to allstudentData vector.
 * NOTE:
 * Ignore empty lines
 * Non empty lines will contain 4 or 5 values to be parsed.
 * the default param separator_char is defined in the header file declaration of readFile ONLY, it is not in the readFile definition.
 * @param file - where student data is stored
 * @param allstudentData - a vector that holds the student data info after it has been read from file
 * @param separator_char - the character that separates each bit of data in a line of student data
 * @return COULD_NOT_OPEN_FILE
 *         SUCCESS
 */
int readFile(std::string &file, std::vector<KP::studentData> &allstudentData, char separator_char=KP::SEPERATOR_CHAR ){
	ifstream myInputfile;
	myInputfile.open(file.c_str());	//could open with  flags myfile.open(MYFILE, ios::in)
													//note the .c_str() call on MYFILE
	if (!myInputfile.is_open())
		return COULD_NOT_OPEN_FILE;

		//read and count the data
	std::string line;
	while (!myInputfile.eof()) {				//exits when reach end of file
		getline(myInputfile, line);				//gets a line up to '/n' char
		cout<<line;
	}

	myInputfile.close();
	return SUCCESS;

}

/***
 * Iterates over all students in vector, and averages midterm1 and midterm2 to get the finalgrade
 * @param allstudentData
 * @return VECTOR_CONTAINS_NO_STUDENTS
 *         SUCCESS
 */
int calculateFinalGrade(std::vector<KP::studentData> &allstudentData){
	return SUCCESS;

}
//void extractFailingStudents(double failgrade = FAILGRADE);

/***
 * Opens file, serializes data from allstudentData to file, closes file
 * the default param seperator_char is defined in the header file ONLY
 * @param file - where student data is stored
 * @param allstudentData - a vector that holds student data info that will be written to file
 * @param separator_char - the character that separates each bit of data in a line of student data
 * @return VECTOR_CONTAINS_NO_STUDENTS
 *         COULD_NOT_OPEN_FILE
 *         SUCCESS
 */
int writeFile(std::string &file, std::vector<KP::studentData> &allstudentData, char separator_char=KP::SEPERATOR_CHAR ){
	ofstream myOutputfile;
	myOutputfile.open(file.c_str());	//could open with  flags myfile.open(MYFILE, ios::out)
											//note the .c_str() call on MYFILE
	if (!myOutputfile.is_open())
		return COULD_NOT_OPEN_FILE;

	myOutputfile << "Data for a file.\n";

		//delicate, what if exception is thrown after file is opened
		//but before next line?
		//never close the file, resource leak, and some systems
		//limit number file handles open,
	myOutputfile.close();
	return SUCCESS;

}

//sorts studentdata based on SORT_TYPE
/***
 *
 * @param allstudentData - a vector that holds student data info that will be written to file
 * @param st - how to sort the vector
 * @return VECTOR_CONTAINS_NO_STUDENTS
 *         SUCCESS
 */
int sortStudentData(std::vector<KP::studentData> &allstudentData,KP::SORT_TYPE st){
	return SUCCESS;

}


//if you are debugging the file must be in the project parent directory
std::string DoubleToString(double Number) {
	std::ostringstream ss;
	ss << Number;
	return ss.str();
}

//if myString does not contain a string rep of number returns 0
//if int not large enough has undefined behaviour, 
//this is a very fragile function
//ex. string a="3";
//    int i = stringToInt(a.c_str()); //i contains 3
//    a="s";
//    i = stringToInt(a.c_str()); //i receives 0
int stringToInt(const char *myString) {
	return atoi(myString);
}

//if myString does not contain a string rep of number returns 0
//this is a very fragile function
//ex. string b="4.5";
//    double d = stringToDouble(b.c_str()); //d receives 4.5
double stringToDouble(const char *myString) {
	return atof(myString);
}

