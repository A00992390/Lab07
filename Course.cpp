#include "Course.hpp"

using namespace std;

Course::Course (string title, dayOfWeek day, unsigned int start_time, unsigned int finish_time) : title (title), day (day), start_time (start_time), finish_time (finish_time)
{
}
Course::Course (const Course & m) : title (m.title), day (m.day), start_time (m.start_time), finish_time (m.finish_time)
{
}

Course & Course::operator =(const Course & m) {
    //TODO: assign a course to a new course using const_cast
    swap(title, (const_cast<Course &> (m)).title);
    swap(day, (const_cast<Course &> (m)).day);
    swap(start_time, (const_cast<Course &> (m)).start_time);
    swap(finish_time, (const_cast<Course &> (m)).finish_time);
    return *this;
}
bool Course::operator == (const Course & m) const {
    //TODO: checking if courses are equal based on the title, day, starttime and finishtime
    if(title == m.title && day == m.day && start_time == m.start_time && finish_time == m.finish_time)
        return true;
    return false;
}

bool Course::operator < (const Course & m) const
{
    //TODO: to compare two Courses based on the tile
    if(day != m.day)
        return day < m.day;
    else {
        if(start_time != m.start_time)
            return start_time < m.start_time;
        else
            return finish_time < m.finish_time;
    }
}

ostream & operator << (ostream &os, const Course & m)
{
    char dateLetter;
    //TODO: print course details in "title day starttime endtime" format
    switch(m.day) {
        case 0:
            dateLetter = 'M';
            break;
        case 1:
            dateLetter = 'T';
            break;
        case 2:
            dateLetter = 'W';
            break;
        case 3:
            dateLetter = 'R';
            break;
        case 4:
            dateLetter = 'F';
            break;
        case 5:
            dateLetter = 'S';
            break;
        case 6:
            dateLetter = 'U';
            break;

    }
    os << m.title << " " << dateLetter << " " << m.start_time << " " << m.finish_time << endl;
    return os;
}