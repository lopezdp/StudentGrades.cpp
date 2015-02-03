//
//  main.cpp
//  Student Grades App
//
//  Created by David P. Lopez on 1/19/15.
//  Copyright (c) 2015 David P. Lopez. All rights reserved.
//

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_QUIZZES = 10;
const int MAX_ASSIGNMENTS = 10;
const int MAX_STUDENTS = 10;

//data structure that holds info about students and their grades
struct StudentInfo
{
    //int numStudents;
    string studentName;
    
    int numQuizzes;
    int quizGrades[MAX_QUIZZES];
    
    int numAssignments;
    int assignmentGrades[MAX_ASSIGNMENTS];
    
    int midtermExam;
    int finalExam;
    
    
};

//function prototypes
void getInfo(StudentInfo [], int, int, int);
double computeAverage(StudentInfo[], int);
char determineLetterGrade(double);
void displayGradebook(StudentInfo[], int);


int main()
{
    // insert code here...
    
    StudentInfo student; //defines a structure variable
    int numStudents;
    int numQuizzes,
        numAssignments;
    
    StudentInfo sArray[MAX_STUDENTS] ;//defines a structure array
    
    cout << "How many students are in the class? ";
    cin >> numStudents;
    
    //Prompt the user for number of quizzes & assignments
    cout << "How many Quizzes? ";
    cin >> numQuizzes;
    
    cout << "How many assignments? ";
    cin >> numAssignments;
    cout << endl;
    
    cin.ignore();
    cin.sync();
    
    getInfo(sArray, numStudents, numQuizzes, numAssignments);
    
    displayGradebook(sArray, numStudents);

    return 0;
}


void getInfo(StudentInfo s[], int numStudents, int numQuizzes, int numAssignments)
{
     // Prompt User for number of students
    
    
    // Prompt User for Quiz & assignment Grades
    for (int i = 0; i < numStudents; i++)
    {
        // Prompt User for Student Names
        cout << "Please Enter Student Name: " << i + 1 << ". ";
        // Assign name string to array s.studentname[i]
        getline(cin, s[i].studentName);
        
        for(int k = 0; k < numQuizzes; k++)
        {
            cout << "ENTER Quiz #" << k + 1 << ". " << s[i].studentName << "'s Grade Earned: ";
            cin >> s[i].quizGrades[k]; //flip ask student first then quiz
        }
        
        for(int h = 0; h < numAssignments; h++)
        {
            cout << "ENTER Assignment #" << h + 1 << ". " << s[i].studentName << "'s Grade Earned: ";
            cin >> s[i].assignmentGrades[h];
        }
        
        cout << endl;
        
        // Prompt User for MTE
        cout << "ENTER the MTE score" << i + 1 << ". " << s[i].studentName << "'s Grade Earned: ";
        cin >> s[i].midtermExam;
    
        // Prompt User for FE
        cout << "ENTER the FE score" << i + 1 << ". " << s[i].studentName << "'s Grade Earned: ";
        cin >> s[i].finalExam;
        
        cin.ignore();
        cin.sync();
        
        cout << endl;
        cout << endl;
    }
}


double computeAverage(StudentInfo s, int num)
{
    double totalAvgGrade = 0.0;
    int totalQuizGrades=0;
    int totalAssGrades=0;
    int avgQuizGrades;
    int avgAssGrades;

        for(int i = 0; i < num; i++)
        {
            totalQuizGrades += s.quizGrades[i];
        }
        
        for(int i = 0; i < num; i++)
        {
            totalAssGrades += s.assignmentGrades[i];
        }
    
        avgQuizGrades = static_cast<double>(totalQuizGrades)/num;
        avgAssGrades = static_cast<double>(totalAssGrades)/num;
        
        totalAvgGrade = (avgQuizGrades + avgAssGrades + s.midtermExam + s.finalExam)/4.0;
        
        totalQuizGrades = 0;
        totalAssGrades = 0;
        
    
    return totalAvgGrade;
}


char determineLetterGrade(double aScore)
{
    if(aScore >= 90)
    {
        return 'A';
    }
    else if(aScore >= 80)
    {
        return 'B';
    }
    else if(aScore >= 70)
    {
        return 'C';
    }
    else if(aScore >= 60)
    {
        return 'D';
    }
    else
        return 'F';
}


void displayGradebook(StudentInfo myStudents[], int numS)
{
    double tempAvg;
    for (int i=0; i < numS; i++)
    {
        tempAvg = computeAverage(myStudents[i], numS);
        cout << myStudents[i].studentName << "  " << tempAvg << "  " << determineLetterGrade(tempAvg) << endl;
    }
}
