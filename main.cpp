#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "Course.hpp"

using namespace std;

/*
 * print schedule - outputs course schedule to the screen
 * @param - add any new parameters you need
 */
void printSchedule(vector<Course> c)
{
    //TODO implement your print using the copy algorithm, 2 iterators, and an ostream_iterator
    copy(c.begin(), c.end() ,ostream_iterator<Course>(std::cout)); //destination of copy is cout with " " in between
}

int main () {
    vector<Course> c;
    //TODO read from courses.txt
    ifstream f{"../courses.txt"};
    if (!f.is_open()) {
        cerr << "Unable to open file" << endl;
        exit(1);
    } else {
        string course;
        char cour;
        int courEnum;
        unsigned int start;
        unsigned int finish;
        while (f >> course >> cour >> start >> finish) {
            //TODO store data in an STL container
            switch (cour) {
                case 'M':
                    courEnum = 0;
                    break;
                case 'T':
                    courEnum = 1;
                    break;
                case 'W':
                    courEnum = 2;
                    break;
                case 'R':
                    courEnum = 3;
                    break;
                case 'F':
                    courEnum = 4;
                    break;
            }
            c.push_back(Course(course, static_cast<Course::dayOfWeek>(courEnum), start, finish));
        }
    }
    //TODO sort your STL container with the sort algorithm
    sort(c.begin(), c.end());
    //TODO implement code to determine schedule conflicts
    for(auto it1 = c.begin(); it1 < c.end() - 1; it1++)  {
        for(auto it2 = it1 + 1; it2 < c.end(); it2++) {
            if(*it1 == *it2) {
                //TODO print out schedule conflicts
                cout << "CONFLICT\n"
                     << *it1 << *it2 << endl;
            }
        }
    }
    //TODO print out schedule
    printSchedule(c);
    return 0;
}