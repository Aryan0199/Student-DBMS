#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
class student{
public:
    char first_name[10];
    char last_name[10];
    char course[20];
    char section[5];
}a;
int main() {
    FILE *fp, *ft;
    int choice;
    char another;
    char xlast_name[10];
    int x;
    cin >> x;
    while (x) {
        cout << "\t\t====== STUDENT DATABASE SYSTEM ======";
        cout << "\n\n                                          ";
        cout << "\n\n";
        cout << "\n \t\t\t 1. Add    Records";
        cout << "\n \t\t\t 2. List   Records";
        cout << "\n \t\t\t 3. Modify Records";
        cout << "\n \t\t\t 4. Delete Records";
        cout << "\n \t\t\t 5. Exit   Program";
        cout << "\n\n";
        cout << "\t\t\t Select Your Choice :=> ";
        fflush(stdin);
        cin >> choice;
        switch (choice) {
            case 1:
                another = 'y';
                while (another == 'y') {
                    system("cls");
                    cout << "Enter first name: ";
                    fflush(stdin);
                    cin >> a.first_name;
                    cout << "Enter last name: ";
                    fflush(stdin);
                    cin >> a.last_name;
                    cout << "Enter course name: ";
                    fflush(stdin);
                    cin >> a.course;
                    cout << "Enter section: ";
                    fflush(stdin);
                    cin >> a.section;
                    fp = fopen("database.txt", "a");
                    fwrite(&a, sizeof(a), 1, fp);
                    fclose(fp);
                    cout << "To add another record press y";
                    fflush(stdin);
                    another = getchar();
                }
                break;
            case 2:
                system("cls");
                fp = fopen("database.txt", "r");
                rewind(fp);
                cout << "\t\t******Records in the Database*******\n";
                printf(" ");
                printf("\n");
                printf("\t\t\t\t");
                printf("\t\t\t\t");
                printf("\n");
                printf("\t\t\t\t");
                printf("\n");
                while (fread(&a, sizeof(a), 1, fp) == 1) {
                    cout << "\tFull Name      :" << a.first_name << " " << a.last_name << endl;
                    cout << "\tCourse Name      :" << a.course << endl;
                    cout << "\tSection      :" << a.section << endl;
                    printf("\n\n\n");
                }
                fclose(fp);
                system("pause");
                fflush(stdin);
                break;
            case 3:
                system("cls");
                another = 'y';
                fp = fopen("database.txt", "r+");
                rewind(fp);
                while (another == 'y') {
                    cout << "Enter the last name: ";
                    fflush(stdin);
                    cin >> xlast_name;
                    while (fread(&a, sizeof(a), 1, fp) == 1) {
                        if (strcmp(xlast_name, a.last_name) == 0) {
                            cout << "Enter new first name: ";
                            fflush(stdin);
                            cin >> a.first_name;
                            cout << "Enter new last name: ";
                            fflush(stdin);
                            cin >> a.last_name;
                            cout << "Enter new course: ";
                            fflush(stdin);
                            cin >> a.course;
                            cout << "Enter new section: ";
                            fflush(stdin);
                            cin >> a.section;
                            fseek(fp, -sizeof(a), SEEK_CUR);
                            fwrite(&a, sizeof(a), 1, fp);
                            break;
                        }
                    }

                    cout << "\n  To Modify Another Record press y\n";
                    fflush(stdin);
                    another = getchar();
                }
                fclose(fp);
                break;
            case 4:
                system("cls");
                another = 'y';
                while (another == 'y') {
                    fp = fopen("database.txt", "r+");
                    ft = fopen("temp.txt", "w");
                    cout << "Enter last name: ";
                    cin >> xlast_name;
                    rewind(fp);
                    while (fread(&a, sizeof(a), 1, fp) == 1) {
                        if (strcmp(a.last_name, xlast_name) != 0) {
                            fwrite(&a, sizeof(a), 1, ft);
                        }
                    }
                    fclose(fp);
                    fclose(ft);
                    remove("database.txt");
                    rename("temp.txt", "database.txt");
                    cout << "Succesfully deleted\n";
                    cout << "To remove  another record press y";
                    fflush(stdin);
                    another = getchar();
                }
                break;
            case 5:
                exit(0);

        }
    }
    return 0;
}
