
#include <iostream>
#include "university.h"

int Faculty::getNumberOfDepts()
{
    return this->departments.size();
}
int Faculty::getTotalFacultyMembersCount()
{
    int total = 0;
    for (int i = 0; i < this->departments.size(); i++)
    {
        for (int j = 0; j < this->departments[i].getFacultyMembers().size(); j++)
        {
            total++;
        }
    }

    return total;
}
int Faculty::getFulltimeFacultyMembersCount()
{
    int total = 0;
    for (int i = 0; i < this->departments.size(); i++)
    {
        for (int j = 0; j < this->departments[i].getFacultyMembers().size(); j++)
        {
            if (departments[i].getFacultyMembers()[j].getIsFulltime())
            {
                total++;
            }
        }
    }

    return total;
}
int Faculty::getAdjunctimeFacultyMembersCount()
{
}

void Faculty::addDepartment(Department &department)
{
    this->departments.push_back(department);
}
void Faculty::addFacultyMember(Department &department, Instructor &member)
{
    department.addFacultyMember(member);
}
void Faculty::removeFacultyMember(Department &department, Instructor &member)
{
    department.removeFacultyMember(member);
}

void Faculty::printCoursesOffered()
{
    for (int i = 0; i < this->departments.size(); i++)
    {
        this->departments[i].printCoursesOffered();
    }
}
void Faculty::printFacultyMembers()
{
    for (int i = 0; i < this->departments.size(); i++)
    {
        this->departments[i].printFacultyMembers();
    }
}
void Faculty::printStudents()
{
    for (int i = 0; i < this->departments.size(); i++)
    {
        this->departments[i].printStudents();
    }
}
void Faculty::print()
{
}
