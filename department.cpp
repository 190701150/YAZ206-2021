#include <iostream>
#include "university.h"

void Department::addCourse(Course &course)
{
    this->coursesOffered.push_back(course);
}
void Department::addFacultyMember(Instructor &member)
{
    this->facultyMembers.push_back(member);
}
void Department::removeFacultyMember(Instructor &member)
{
    std::vector<Instructor>::iterator position;
    for (auto ite = facultyMembers.begin(); ite != facultyMembers.end(); ite++)
    {
        if (ite->getId() == member.getId())
        {
            position = ite;
        }
    }
    this->facultyMembers.erase(position);
}
void Department::printCourseByFacultyMember(Instructor &member)
{
    std::cout << "########### Courses by " << member.getFullName() << "###########" << std::endl;
    for (auto ite = coursesOffered.begin(); ite != coursesOffered.end(); ite++)
    {
        if (ite->getId() == member.getId())
        {
            ite->printCourse();
        }
    }
}
void Department::printNameOfTheCourses()
{
    std::cout << "########### Course Names ###########" << std::endl;
    for (auto ite = coursesOffered.begin(); ite != coursesOffered.end(); ite++)
    {
        std::cout << ite->getName() << std::endl;
    }

    std::cout << std::endl;
}
void Department::printStudents()
{
    std::cout << "########### Students ###########" << std::endl;
    for (auto ite = students.begin(); ite != students.end(); ite++)
    {
        ite->print();
    }
}

std::vector<Course> Department::getCoursesByPrerequisite(bool withPrerequisite)
{
    std::vector<Course> newCourses = std::vector<Course>();
    for (auto ite = coursesOffered.begin(); ite != coursesOffered.end(); ite++)
    {
        if ((ite->getPrerequisiteCourses().size() != 0) == withPrerequisite)
        {
            newCourses.push_back(*ite);
        }
    }

    return newCourses;
}

std::vector<Instructor> &Department::getFacultyMembers()
{
    return facultyMembers;
}

void Department::printCoursesOffered()
{
    for (int i = 0; i < coursesOffered.size(); i++)
    {
        coursesOffered[i].printCourse();
    }
}

void Department::printCoursesOffered()
{
    for (int i = 0; i < coursesOffered.size(); i++)
    {
        facultyMembers[i].print();
    }
}