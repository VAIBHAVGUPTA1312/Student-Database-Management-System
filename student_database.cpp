#include <bits/stdc++.h>
using namespace std;

class Student
{
private:
    string name;
    string roll_num;
    int age;
    string gender;
    int application_no;

public:
    Student(string in_name = "John Doe", string in_roll_num = "xxx",
            int in_age = 0, string in_gender = "Not Specified", int app_no = 0)
        : name(in_name), roll_num(in_roll_num), age(in_age), gender(in_gender), application_no(app_no) {}

    void show_data() const
    {
        cout << "| " << left << setw(15) << name.substr(0, 15)
             << "| " << setw(10) << roll_num.substr(0, 10)
             << "| " << setw(3) << age
             << " | " << setw(10) << gender.substr(0, 10)
             << "| " << setw(5) << application_no << " |" << endl;
    }

    void update_data(string new_name, string new_roll_num, int new_age, string new_gender)
    {
        name = new_name;
        roll_num = new_roll_num;
        age = new_age;
        gender = new_gender;
    }

    int get_application_no() const { return application_no; }
};

vector<Student> student_database;

void create_student(int app_no)
{
    string name, roll_num, gender;
    int age;

    cout << "App No. " << app_no << " - Enter the name of the Student (Max 15 characters): ";
    cin.ignore();
    getline(cin, name);
    cout << "App No. " << app_no << " - Enter the roll number of the Student (Max 10 characters): ";
    cin >> roll_num;
    cout << "App No. " << app_no << " - Enter the age of the Student (Max 3 digits): ";
    cin >> age;
    cout << "App No. " << app_no << " - Enter the gender of the Student (Max 10 characters): ";
    cin >> gender;
    cout << endl;

    student_database.push_back(Student(name, roll_num, age, gender, app_no));
}

void read_student(int app_no)
{
    for (const auto &student : student_database)
    {
        if (student.get_application_no() == app_no)
        {
            cout << "\n+----------------+-----------+-----+-----------+-------+\n";
            cout << "| " << left << setw(15) << "Name"
                 << "| " << setw(10) << "Roll No"
                 << "| " << setw(3) << "Age"
                 << " | " << setw(10) << "Gender"
                 << "| " << setw(5) << "App No" << "|\n";
            cout << "+----------------+-----------+-----+-----------+-------+\n";
            student.show_data();
            cout << "+----------------+-----------+-----+-----------+-------+\n";
            return;
        }
    }
    cout << "Student with application no " << app_no << " not found.\n";
}

void update_student(int app_no)
{
    for (auto &student : student_database)
    {
        if (student.get_application_no() == app_no)
        {
            string name, roll_num, gender;
            int age;

            cout << "Enter updated name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter updated roll number: ";
            cin >> roll_num;
            cout << "Enter updated age: ";
            cin >> age;
            cout << "Enter updated gender: ";
            cin >> gender;

            student.update_data(name, roll_num, age, gender);
            cout << "Student data updated successfully.\n";
            return;
        }
    }
    cout << "Student with application no " << app_no << " not found.\n";
}

void delete_student(int app_no)
{
    auto it = find_if(student_database.begin(), student_database.end(),
                      [app_no](const Student &student)
                      {
                          return student.get_application_no() == app_no;
                      });

    if (it != student_database.end())
    {
        student_database.erase(it);
        cout << "Student with application no " << app_no << " deleted successfully.\n";
    }
    else
    {
        cout << "Student with application no " << app_no << " not found.\n";
    }
}

void display_database()
{
    if (student_database.empty())
    {
        cout << "No students found in the database.\n";
        return;
    }

    cout << "\n+----------------+-----------+-----+-----------+-------+\n";
    cout << "| " << left << setw(15) << "Name"
         << "| " << setw(10) << "Roll No"
         << "| " << setw(3) << "Age"
         << " | " << setw(10) << "Gender"
         << "| " << setw(5) << "App No" << "|\n";
    cout << "+----------------+-----------+-----+-----------+-------+\n";

    for (const auto &student : student_database)
    {
        student.show_data();
    }
    cout << "+----------------+-----------+-----+-----------+-------+\n";
}

void add_students()
{
    int num_students;
    cout << "Enter the number of students to add: ";
    cin >> num_students;

    for (int i = 1; i <= num_students; i++)
    {
        create_student(i);
    }
}

int main()
{
    int choice;
    while (true)
    {
        cout << "\n1. Add Students\n2. Display Database\n3. Read Student\n4. Update Student\n"
             << "5. Delete Student\n6. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            add_students();
            break;
        case 2:
            display_database();
            break;
        case 3:
        {
            int app_no;
            cout << "Enter application number to view: ";
            cin >> app_no;
            read_student(app_no);
            break;
        }
        case 4:
        {
            int app_no;
            cout << "Enter application number to update: ";
            cin >> app_no;
            update_student(app_no);
            break;
        }
        case 5:
        {
            int app_no;
            cout << "Enter application number to delete: ";
            cin >> app_no;
            delete_student(app_no);
            break;
        }
        case 6:
            cout << "Exiting the program.\n";
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
}
