#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

#define FILE_NAME "data.txt"

void menu() {
    int choice;
    while(1) {
        printf("\n====== Student Management System ======\n");
        printf("1. Add Student\n");
        printf("2. Show Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: addStudent(); break;
            case 2: showStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: exit(0);
            default: printf("Invalid Choice!\n");
        }
    }
}

void addStudent() {
    Student s;
    FILE *fp = fopen(FILE_NAME, "a");

    printf("\nEnter ID: "); scanf("%d",&s.id);
    printf("Enter Name: "); getchar(); fgets(s.name,50,stdin);
    s.name[strcspn(s.name,"\n")] = 0;
    printf("Enter Age: "); scanf("%d",&s.age);
    printf("Enter GPA: "); scanf("%f",&s.gpa);

    fprintf(fp,"%d,%s,%d,%.2f\n",s.id,s.name,s.age,s.gpa);
    fclose(fp);

    printf("Student Added Successfully!\n");
}

void showStudents() {
    FILE *fp = fopen(FILE_NAME,"r");
    if(!fp){ printf("\nNo Data Found!\n"); return; }

    Student s;
    printf("\n--- Student List ---\n");
    while(fscanf(fp,"%d,%49[^,],%d,%f\n",&s.id,s.name,&s.age,&s.gpa)==4){
        printf("ID:%d | Name:%s | Age:%d | GPA:%.2f\n",s.id,s.name,s.age,s.gpa);
    }

    fclose(fp);
}

void searchStudent() {
    FILE *fp = fopen(FILE_NAME,"r");
    if(!fp){ printf("\nNo Data Found!\n"); return; }

    int id,found=0;
    Student s;
    printf("\nEnter ID to Search: "); scanf("%d",&id);

    while(fscanf(fp,"%d,%49[^,],%d,%f\n",&s.id,s.name,&s.age,&s.gpa)==4){
        if(s.id == id){
            printf("\n--- Student Found ---\n");
            printf("ID:%d | Name:%s | Age:%d | GPA:%.2f\n",s.id,s.name,s.age,s.gpa);
            found=1;
            break;
        }
    }
    fclose(fp);

    if(!found) printf("Student Not Found!\n");
}

void deleteStudent() {
    FILE *fp=fopen(FILE_NAME,"r");
    if(!fp){ printf("\nNo Data Found!\n"); return; }

    int id,found=0;
    Student s;
    FILE *temp=fopen("temp.txt","w");

    printf("\nEnter ID to Delete: "); scanf("%d",&id);

    while(fscanf(fp,"%d,%49[^,],%d,%f\n",&s.id,s.name,&s.age,&s.gpa)==4){
        if(s.id != id) fprintf(temp,"%d,%s,%d,%.2f\n",s.id,s.name,s.age,s.gpa);
        else found=1;
    }

    fclose(fp); fclose(temp);
    remove(FILE_NAME);
    rename("temp.txt",FILE_NAME);

    if(found) printf("Student Deleted Successfully!\n");
    else printf("Student Not Found!\n");
}

void loadFromFile() {
    FILE *fp = fopen(FILE_NAME,"a");
    fclose(fp);
}
