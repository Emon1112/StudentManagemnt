#ifndef STUDENT_H
#define STUDENT_H

typedef struct {
    int id;
    char name[50];
    int age;
    float gpa;
} Student;

void menu();
void addStudent();
void showStudents();
void searchStudent();
void deleteStudent();
void loadFromFile();

#endif
