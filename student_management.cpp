#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Maximum number of students
const int MAX = 100;

// Structure to store student details
struct Student {
    int rollNo;
    string name;
    string branch;
    float marks;
};

Student students[MAX];
int totalStudents = 0;

// Function to check duplicate roll number
int findRoll(int roll) {
    for (int i = 0; i < totalStudents; i++) {
        if (students[i].rollNo == roll)
            return i;
    }
    return -1;
}

// 1. Add Student
void addStudent() {
    if (totalStudents == MAX) {
        cout << "\nRecord storage is full!\n";
        return;
    }

    int roll;
    cout << "\nEnter Roll Number: ";
    cin >> roll;

    // Check duplicate roll number
    if (findRoll(roll) != -1) {
        cout << "Roll number already exists!\n";
        return;
    }

    students[totalStudents].rollNo = roll;

    cout << "Enter Name: ";
    getline(cin >> ws, students[totalStudents].name);

    cout << "Enter Branch: ";
    getline(cin, students[totalStudents].branch);

    cout << "Enter Marks (0-100): ";
    cin >> students[totalStudents].marks;

    if (students[totalStudents].marks < 0 ||
        students[totalStudents].marks > 100) {
        cout << "Invalid marks! Record not added.\n";
        return;
    }

    totalStudents++;
    cout << "\nStudent added successfully!\n";
}

// 2. Display All Students
void displayStudents() {
    if (totalStudents == 0) {
        cout << "\nNo student records found!\n";
        return;
    }

    cout << "\n";
    cout << left << setw(12) << "Roll No"
         << setw(22) << "Name"
         << setw(15) << "Branch"
         << setw(10) << "Marks" << endl;

    cout << "-----------------------------------------------------------\n";

    for (int i = 0; i < totalStudents; i++) {
        cout << left << setw(12) << students[i].rollNo
             << setw(22) << students[i].name
             << setw(15) << students[i].branch
             << setw(10) << students[i].marks << endl;
    }
}

// 3. Search Student by Roll Number
void searchByRoll() {
    int roll;
    cout << "\nEnter Roll Number to search: ";
    cin >> roll;

    int index = findRoll(roll);

    if (index == -1) {
        cout << "Student record not found!\n";
    } else {
        cout << "\nStudent Found!\n";
        cout << "Roll Number: " << students[index].rollNo << endl;
        cout << "Name: " << students[index].name << endl;
        cout << "Branch: " << students[index].branch << endl;
        cout << "Marks: " << students[index].marks << endl;
    }
}

// 4. Search Student by Name
void searchByName() {
    string name;
    bool found = false;

    cout << "\nEnter Student Name: ";
    getline(cin >> ws, name);

    for (int i = 0; i < totalStudents; i++) {
        if (students[i].name == name) {
            cout << "\nStudent Found!\n";
            cout << "Roll Number: " << students[i].rollNo << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Branch: " << students[i].branch << endl;
            cout << "Marks: " << students[i].marks << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Student record not found!\n";
}

// 5. Update Student Record
void updateStudent() {
    int roll;
    cout << "\nEnter Roll Number to update: ";
    cin >> roll;

    int index = findRoll(roll);

    if (index == -1) {
        cout << "Student not found!\n";
        return;
    }

    int choice;

    cout << "\nWhat do you want to update?";
    cout << "\n1. Name";
    cout << "\n2. Branch";
    cout << "\n3. Marks";
    cout << "\nEnter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Enter New Name: ";
            getline(cin >> ws, students[index].name);
            cout << "Name updated successfully!\n";
            break;

        case 2:
            cout << "Enter New Branch: ";
            getline(cin >> ws, students[index].branch);
            cout << "Branch updated successfully!\n";
            break;

        case 3: {
            float newMarks;
            cout << "Enter New Marks: ";
            cin >> newMarks;

            if (newMarks < 0 || newMarks > 100) {
                cout << "Invalid marks! Update cancelled.\n";
                return;
            }

            students[index].marks = newMarks;
            cout << "Marks updated successfully!\n";
            break;
        }

        default:
            cout << "Invalid choice!\n";
    }
}

// 6. Delete Student Record
void deleteStudent() {
    int roll;
    cout << "\nEnter Roll Number to delete: ";
    cin >> roll;

    int index = findRoll(roll);

    if (index == -1) {
        cout << "Student not found!\n";
        return;
    }

    // Shift remaining records to the left
    for (int i = index; i < totalStudents - 1; i++) {
        students[i] = students[i + 1];
    }

    totalStudents--;
    cout << "Student deleted successfully!\n";
}

// 7. Bubble Sort by Roll Number
void sortByRoll() {
    for (int i = 0; i < totalStudents - 1; i++) {
        for (int j = 0; j < totalStudents - i - 1; j++) {
            if (students[j].rollNo > students[j + 1].rollNo) {
                swap(students[j], students[j + 1]);
            }
        }
    }

    cout << "\nRecords sorted by Roll Number!\n";
    displayStudents();
}

// 8. Insertion Sort by Name
void sortByName() {
    for (int i = 1; i < totalStudents; i++) {
        Student key = students[i];
        int j = i - 1;

        while (j >= 0 && students[j].name > key.name) {
            students[j + 1] = students[j];
            j--;
        }

        students[j + 1] = key;
    }

    cout << "\nRecords sorted by Name!\n";
    displayStudents();
}

// 9. Selection Sort by Marks (Descending)
void sortByMarks() {
    for (int i = 0; i < totalStudents - 1; i++) {
        int maxIndex = i;

        for (int j = i + 1; j < totalStudents; j++) {
            if (students[j].marks > students[maxIndex].marks) {
                maxIndex = j;
            }
        }

        swap(students[i], students[maxIndex]);
    }

    cout << "\nRecords sorted by Marks (Highest First)!\n";
    displayStudents();
}

// 10. Rank List / Topper
void rankList() {
    if (totalStudents == 0) {
        cout << "\nNo student records available!\n";
        return;
    }

    // Sort marks in descending order
    sortByMarks();

    cout << "\n========== STUDENT RANK LIST ==========\n";

    for (int i = 0; i < totalStudents; i++) {
        cout << "Rank " << i + 1
             << " : " << students[i].name
             << " | Marks: " << students[i].marks << endl;
    }

    cout << "\nTopper: " << students[0].name
         << " (" << students[0].marks << " marks)\n";
}

// 11. Branch-wise Report
void branchReport() {
    string branch;
    int count = 0;
    float sum = 0;

    cout << "\nEnter Branch Name: ";
    getline(cin >> ws, branch);

    cout << "\nStudents in " << branch << " branch:\n";

    for (int i = 0; i < totalStudents; i++) {
        if (students[i].branch == branch) {
            cout << students[i].rollNo << " - "
                 << students[i].name << " - "
                 << students[i].marks << endl;

            sum += students[i].marks;
            count++;
        }
    }

    if (count == 0) {
        cout << "No students found in this branch!\n";
    } else {
        cout << "Total Students: " << count << endl;
        cout << "Average Marks: " << sum / count << endl;
    }
}

// 12. Student-wise Report
void studentReport() {
    int roll;

    cout << "\nEnter Roll Number: ";
    cin >> roll;

    int index = findRoll(roll);

    if (index == -1) {
        cout << "Student record not found!\n";
        return;
    }

    cout << "\n========== STUDENT REPORT ==========\n";

    cout << "Roll Number: " << students[index].rollNo << endl;
    cout << "Name: " << students[index].name << endl;
    cout << "Branch: " << students[index].branch << endl;
    cout << "Marks: " << students[index].marks << endl;

    cout << "====================================\n";
}

// Main Function
int main() {
    int choice;

    do {
        cout << "\n\n====================================";
        cout << "\n   STUDENT RECORD MANAGEMENT SYSTEM";
        cout << "\n====================================";

        cout << "\n1. Add Student";
        cout << "\n2. Display All Students";
        cout << "\n3. Search by Roll Number";
        cout << "\n4. Search by Name";
        cout << "\n5. Update Student Record";
        cout << "\n6. Delete Student Record";
        cout << "\n7. Sort by Roll Number";
        cout << "\n8. Sort by Name";
        cout << "\n9. Sort by Marks";
        cout << "\n10. Generate Rank List / Topper";
        cout << "\n11. Branch-wise Report";
        cout << "\n12. Student-wise Report";
        cout << "\n0. Exit";

        cout << "\n\nEnter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchByRoll(); break;
            case 4: searchByName(); break;
            case 5: updateStudent(); break;
            case 6: deleteStudent(); break;
            case 7: sortByRoll(); break;
            case 8: sortByName(); break;
            case 9: sortByMarks(); break;
            case 10: rankList(); break;
            case 11: branchReport(); break;
            case 12: studentReport(); break;
            case 0:
                cout << "\nThank you for using the system!\n";
                break;
            default:
                cout << "\nInvalid Choice! Try Again.\n";
        }

    } while (choice != 0);

    return 0;
}
