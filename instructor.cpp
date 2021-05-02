#include <iostream>
#include "university.h"

void Instructor::setCourseContent(Course &course, Semester semester, std::string id, std::vector<Course> preCourses)
{
    course.setSemester(semester);
    course.setId(id);
    course.setPreCourses(preCourses);
}
void Instructor::increaseJournalPapers()
{
    this->numberOfJournalPapers++;
}
void Instructor::increaseConferencePapers()
{
    this->numberofConferencePapers++;
}
void Instructor::addCourse(Course &course)
{
    this->coursesOffered.push_back(course);
}
void Instructor::removeCourse(Course &course)
{
    std::vector<Course>::iterator position;
    for (auto ite = coursesOffered.begin(); ite != coursesOffered.end(); ite++)
    {
        if (ite->getId() == course.getId())
        {
            position = ite;
        }
    }
    this->coursesOffered.erase(position);
}
bool Instructor::checkCourseGiven(Course &course)
{

    for (auto ite = coursesOffered.begin(); ite != coursesOffered.end(); ite++)
    {
        if (ite->getId() == course.getId())
        {
            return true;
        }
    }
    return false;
}

std::vector<Course> Instructor::getCourseBySemester(Semester semester)
{
    std::vector<Course> newCourses = std::vector<Course>();
    for (auto ite = coursesOffered.begin(); ite != coursesOffered.end(); ite++)
    {
        if (ite->getSemester() == semester)
        {
            newCourses.push_back(*ite);
        }
    }

    return newCourses;
}

std::vector<Course> Instructor::getCourseByDepartment(Department department)
{
}

void Instructor::printCoursesOffered()
{
    std::cout << "########### Course Names ###########" << std::endl;
    for (auto ite = coursesOffered.begin(); ite != coursesOffered.end(); ite++)
    {
        std::cout << ite->getName() << std::endl;
    }

    std::cout << std::endl;
}

std::string Instructor::getId()
{
    return this->id;
}
std::string Instructor::getFullName()
{
    return this->fullName;
}

void Instructor::print()
{
}
