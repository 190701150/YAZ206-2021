#include <iostream>
#include "university.h"
Course::Course(std::string syllabus, int numberOfHomeworks, int numberOfProjects, double homeworkPercentage, double projectPercentage, double midtermPercentage, double finalPercentage)
{
    this->syllabus = syllabus;
    this->numberOfHomeworks = numberOfHomeworks;
    this->numberOfProjects = numberOfProjects;
    this->homeworkPercentage = homeworkPercentage;
    this->projectPercentage = projectPercentage;
    this->midtermPercentage = midtermPercentage;
    this->finalPercentage = finalPercentage;
}

void Course::setSemester(Semester semester)
{
    this->semester = semester;
}
void Course::setPreCourses(std::vector<Course> courses)
{
    this->prerequisiteCourses = courses;
}
void Course::setId(std::string id)
{
    this->id;
}

std::string Course::getId()
{
    return this->id;
}

Semester Course::getSemester()
{
    return this->semester;
}

void Course::printCourse()
{
    std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    std::cout << "+ Syllabus: " << syllabus << std::endl;
    std::cout << "+ Number of homerworks: " << numberOfHomeworks << std::endl;
    std::cout << "+ Number of projects: " << numberOfProjects << std::endl;
    std::cout << "+ Homework %: " << homeworkPercentage << std::endl;
    std::cout << "+ Project %: " << projectPercentage << std::endl;
    std::cout << "+ Midterm %: " << midtermPercentage << std::endl;
    std::cout << "+ Final %: " << finalPercentage << std::endl;
    std::cout << "+ Semester: " << semesterToStr(this->semester) << std::endl;
    std::cout << "++++++++++++++++++++++++++++++++++++++++++" << std::endl;
}

std::string semesterToStr(Semester semester)
{
    if (semester == Semester::FALL)
    {
        return "Fall";
    }
    else if (semester == Semester::SPRING)
    {
        return "Spring";
    }
    else if (semester == Semester::SUMMER)
    {
        return "Summer";
    }
}