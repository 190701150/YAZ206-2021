#include <string>
#include <vector>
#pragma once

enum Semester
{
    FALL,
    SPRING,
    SUMMER
};

class Course
{
private:
    Semester semester;
    std::string name;
    std::string id;
    std::vector<Course> prerequisiteCourses;
    std::string syllabus;
    int numberOfHomeworks;
    int numberOfProjects;
    double homeworkPercentage;
    double projectPercentage;
    double midtermPercentage;
    double finalPercentage;

    std::string getId();
    std::string getId();

public:
    Course::Course(std::string syllabus, int numberOfHomeworks, int numberOfProjects, double homeworkPercentage, double projectPercentage, double midtermPercentage, double finalPercentage);

    void setSemester(Semester semester);
    void setPreCourses(std::vector<Course> courses);
    void setId(std::string id);
    void printCourse();
    std::string getId();
    std::string getName();
    std::vector<Course> getPrerequisiteCourses();
    Semester getSemester();
};

enum Grade
{
    FRESHMAN,
    SOPHOMORE,
    JUNIOR,
    SENIOR
};

class UniversityMember
{
};

class Student : UniversityMember
{
private:
    std::string fullName;
    std::string id;
    std::string startingDate;
    Grade grade;
    std::vector<Course> coursesTaken;
    std::vector<Course> coursesCompleted;
    double GPA;

public:
    Student();

    std::vector<Course> &getFailedCourses();
    Grade getGrade();
    double getGPA();

    void printTranscript();
    void print();
};

class Department
{
private:
    std::string departmentName;
    std::string facultyName;
    std::vector<Course> coursesOffered;
    std::vector<Instructor> facultyMembers;
    std::vector<Student> students;

public:
    void addCourse(Course &course);
    void addFacultyMember(Instructor &member);
    void removeFacultyMember(Instructor &member);

    std::vector<Course> getCoursesByPrerequisite(bool withPrerequisite);
    std::vector<Course> getCoursesByFacultyMember(Instructor &instructor);

    void printCourseByFacultyMember(Instructor &instructor);
    void printNameOfTheCourses();
    void printStudents();
    void printCoursesOffered();
    void printFacultyMembers();
    void print();

    std::vector<Instructor> &getFacultyMembers();
};

class Instructor : UniversityMember
{
private:
    std::string fullName;
    std::string id;
    std::string startingDate;
    Department department;
    bool isFulltime;
    int numberOfJournalPapers;
    int numberofConferencePapers;
    std::vector<Course> coursesOffered;
    std::string laboratory;

public:
    void setCourseContent(Course &course, Semester semester, std::string id, std::vector<Course> preCourses);
    void increaseJournalPapers();
    void increaseConferencePapers();
    void addCourse(Course &course);
    void removeCourse(Course &course);
    bool checkCourseGiven(Course &course);

    std::vector<Course> getCourseBySemester(Semester semester);
    std::vector<Course> getCourseByDepartment(Department department);

    void printCoursesOffered();
    void print();

    std::string getId();
    std::string getFullName();

    bool getIsFulltime();
};

class Faculty
{
private:
    std::vector<Department> departments;

public:
    int getNumberOfDepts();
    int getTotalFacultyMembersCount();
    int getFulltimeFacultyMembersCount();
    int getAdjunctimeFacultyMembersCount();

    void addDepartment(Department &department);
    void addFacultyMember(Department &department, Instructor &member);
    void removeFacultyMember(Department &department, Instructor &member);

    void printCoursesOffered();
    void printFacultyMembers();
    void printStudents();
    void print();
};
