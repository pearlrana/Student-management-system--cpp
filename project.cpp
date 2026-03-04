#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Student {
private:
    int id;
    string name;
    float marks;

public:
    Student(int i, string n, float m) {
        id = i;
        name = n;
        marks = m;
    }

    int getId() { return id; }
    float getMarks() { return marks; }

    void updateDetails(string n, float m) {
        name = n;
        marks = m;
    }

    void display() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
        cout << "---------------------" << endl;
    }

    // Save format
    string toFile() {
        return to_string(id) + " " + name + " " + to_string(marks);
    }
};

class StudentManager {
private:
    vector<Student> students;

public:
    void addStudent() {
        int id;
        string name;
        float marks;

        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Marks: ";
        cin >> marks;

        students.push_back(Student(id, name, marks));
        cout << "Student added successfully!\n";
    }

    void displayAll() {
        if (students.empty()) {
            cout << "No students available.\n";
            return;
        }

        for (auto &s : students) {
            s.display();
        }
    }

    void searchStudent() {
        int id;
        cout << "Enter ID to search: ";
        cin >> id;

        for (auto &s : students) {
            if (s.getId() == id) {
                cout << "Student Found:\n";
                s.display();
                return;
            }
        }

        cout << "Student not found.\n";
    }

    void deleteStudent() {
        int id;
        cout << "Enter ID to delete: ";
        cin >> id;

        for (int i = 0; i < students.size(); i++) {
            if (students[i].getId() == id) {
                students.erase(students.begin() + i);
                cout << "Student deleted successfully!\n";
                return;
            }
        }

        cout << "Student not found.\n";
    }

    void updateStudent() {
        int id;
        cout << "Enter ID to update: ";
        cin >> id;

        for (auto &s : students) {
            if (s.getId() == id) {
                string name;
                float marks;
                cout << "Enter new name: ";
                cin >> name;
                cout << "Enter new marks: ";
                cin >> marks;

                s.updateDetails(name, marks);
                cout << "Student updated successfully!\n";
                return;
            }
        }

        cout << "Student not found.\n";
    }

    void calculateAverage() {
        if (students.empty()) {
            cout << "No data available.\n";
            return;
        }

        float sum = 0;
        for (auto &s : students) {
            sum += s.getMarks();
        }

        cout << "Average Marks: " << (sum / students.size()) << endl;
    }

    void saveToFile() {
        ofstream file("students.txt");

        for (auto &s : students) {
            file << s.toFile() << endl;
        }

        file.close();
        cout << "Data saved to file.\n";
    }

    void loadFromFile() {
        ifstream file("students.txt");
        int id;
        string name;
        float marks;

        while (file >> id >> name >> marks) {
            students.push_back(Student(id, name, marks));
        }

        file.close();
    }
};

int main() {
    StudentManager manager;
    manager.loadFromFile(); // load previous data

    int choice;

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Update Student\n";
        cout << "6. Calculate Average Marks\n";
        cout << "7. Save to File\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: manager.addStudent(); break;
            case 2: manager.displayAll(); break;
            case 3: manager.searchStudent(); break;
            case 4: manager.deleteStudent(); break;
            case 5: manager.updateStudent(); break;
            case 6: manager.calculateAverage(); break;
            case 7: manager.saveToFile(); break;
            case 8: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice\n";
        }

    } while (choice != 8);

    return 0;
}