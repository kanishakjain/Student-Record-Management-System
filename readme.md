# 🎓 Student Record Management System

A menu-driven **Student Record Management System** developed using C++. This project helps manage student information efficiently through basic Data Structures and Algorithms, including **Arrays, Linear Searching, and Sorting Algorithms**.

The system allows users to register students, store and manage their records, search for specific students, update or delete information, generate reports, and prepare student ranking lists.

---

## 📌 Project Overview

The Student Record Management System is a console-based application designed to simplify the management of student records.

It uses a fixed-size array to store student information and implements different searching and sorting techniques to perform operations efficiently.

### Project Details

| Attribute | Details |
|---|---|
| Project Name | Student Record Management System |
| Programming Language | C++ |
| Project Type | Console-Based Application |
| Maximum Students | 100 |
| Main Concepts | Arrays, Searching, Sorting |
| Searching Algorithm | Linear Search |
| Sorting Algorithms | Bubble Sort, Insertion Sort, Selection Sort |
| Compiler | GCC / MinGW |
| Interface | Menu-Driven Console Interface |

---

## ✨ Features

### 1. Student Registration and Record Storage

- Add new student records.
- Store student Roll Number, Name, Branch, and Marks.
- Validate duplicate roll numbers.
- Prevent registration when the maximum array capacity is reached.
- Validate marks within the range of 0–100.

### 2. Student Record Management

- Update existing student information.
- Update individual details without modifying the entire record:
  - Student Name
  - Branch
  - Marks
- Delete student records using their Roll Number.
- Automatically shift remaining records after deletion.

### 3. Display and Report Module

- Display all registered students in tabular format.
- Generate individual student reports using Roll Number.
- Generate branch-wise reports.
- Display the total number of students in a selected branch.
- Calculate the average marks of students belonging to a particular branch.

### 4. Searching Module

**Search by Roll Number**
- Uses Linear Search.
- Searches for a student using their unique Roll Number.
- Displays complete student details when found.

**Search by Name**
- Searches for students using their names.
- Displays matching student records.
- Handles cases where the student is not found.

### 5. Sorting and Ranking Module

The project implements three sorting algorithms:

| Sorting Algorithm | Sorting Criteria | Order |
|---|---|---|
| Bubble Sort | Roll Number | Ascending |
| Insertion Sort | Student Name | Alphabetical |
| Selection Sort | Marks | Descending |

Additional functionality:
- Generate a student rank list.
- Display students according to marks.
- Identify the topper based on the highest marks.

---

## 🧠 Data Structures and Algorithms Used

### 1. Arrays

An array of structures is used to store student records.

Each student contains four attributes:

```cpp
struct Student {
    int rollNo;
    string name;
    string branch;
    float marks;
};

Student students[100];
```

The array stores up to 100 student records.

### 2. Linear Search

Linear Search is used to find students by Roll Number and Name.

The algorithm checks each record sequentially until a matching student is found.

**Time Complexity:**
- Best Case: O(1)
- Average Case: O(n)
- Worst Case: O(n)

### 3. Bubble Sort

Bubble Sort is used to arrange student records according to Roll Number in ascending order.

It repeatedly compares adjacent elements and swaps them if they are in the wrong order.

**Time Complexity:**
- Best Case: O(n) with an optimized implementation
- Average Case: O(n²)
- Worst Case: O(n²)

*Note: The current implementation does not use an early-exit optimization, so its best-case complexity is also O(n²).*

### 4. Insertion Sort

Insertion Sort is used to arrange student names alphabetically.

It takes one element at a time and inserts it into its correct position in the sorted portion.

**Time Complexity:**
- Best Case: O(n)
- Average Case: O(n²)
- Worst Case: O(n²)

### 5. Selection Sort

Selection Sort is used to arrange students according to marks in descending order.

It finds the student with the highest marks and places that record at the beginning of the array.

**Time Complexity:**
- Best Case: O(n²)
- Average Case: O(n²)
- Worst Case: O(n²)

---

## 📂 Project Modules

| Module | Description |
|---|---|
| Student Registration | Adds new student records |
| Record Storage | Stores student details in an array |
| Display Module | Displays all student records |
| Searching Module | Searches by Roll Number and Name |
| Update Module | Updates individual student details |
| Delete Module | Removes student records |
| Sorting Module | Sorts records using three algorithms |
| Ranking Module | Generates rank list and identifies topper |
| Branch-wise Report | Displays students and average marks by branch |
| Student-wise Report | Displays an individual student's information |

---

## ⚙️ Technologies Used

- **C++** – Core programming language.
- **Arrays** – Student record storage.
- **Structures** – Organizing student information.
- **Functions** – Modular program implementation.
- **Loops and Conditional Statements** – Program control and iteration.
- **GCC / MinGW** – Compilation and execution.

---

## 💻 Installation and Setup

### Prerequisites

Make sure you have the following installed:

- GCC C++ Compiler (MinGW or MinGW-w64)
- Visual Studio Code (optional)
- Windows, Linux, or macOS

### Step 1: Clone the Repository

```bash
git clone https://github.com/kanishakjain/Student-Record-Management-System.git
```

### Step 2: Navigate to the Project Directory

```bash
cd Student-Record-Management-System
```

### Step 3: Compile the Program

Using GCC:

```bash
g++ student_management.cpp -o student_management
```

### Step 4: Run the Program

**Windows:**

```powershell
.\student_management.exe
```

**Linux / macOS:**

```bash
./student_management
```

---

## 🖥️ Application Menu

When you run the program, the following menu appears:

```text
====================================
   STUDENT RECORD MANAGEMENT SYSTEM
====================================

1. Add Student
2. Display All Students
3. Search by Roll Number
4. Search by Name
5. Update Student Record
6. Delete Student Record
7. Sort by Roll Number
8. Sort by Name
9. Sort by Marks
10. Generate Rank List / Topper
11. Branch-wise Report
12. Student-wise Report
0. Exit

Enter Your Choice:
```

Select an option by entering its corresponding number.

---

## 📊 Sample Student Record

The following is an illustrative example of student information:

| Roll No | Name | Branch | Marks |
|---|---|---|---|
| 101 | Rahul Sharma | CSE | 85 |
| 102 | Priya Singh | IT | 92 |
| 103 | Aman Verma | CSE | 78 |
| 104 | Neha Gupta | ECE | 95 |

### Example: Rank List

```text
========== STUDENT RANK LIST ==========

Rank 1 : Neha Gupta | Marks: 95
Rank 2 : Priya Singh | Marks: 92
Rank 3 : Rahul Sharma | Marks: 85
Rank 4 : Aman Verma | Marks: 78

Topper: Neha Gupta (95 marks)
```

---

## 📁 Project Structure

```text
Student-Record-Management-System/
│
├── student_management.cpp
│
└── README.md
```

---

## ⚠️ Limitations

- The system supports a maximum of 100 student records.
- Student records are stored in RAM using arrays.
- Records are not permanently saved.
- All records are lost when the program terminates.
- Searching by name requires an exact, case-sensitive match.
- The application provides a console-based interface rather than a graphical interface.

---

## 🚀 Future Enhancements

The following features can be added in future versions:

- File handling for permanent student record storage.
- Dynamic memory allocation to support more students.
- Graphical User Interface (GUI).
- Login and authentication system.
- Export student reports to CSV or PDF.
- Advanced searching and filtering options.
- Percentage and grade calculation.
- Improved ranking with equal-rank handling for students having the same marks.

---

## 🎯 Learning Outcomes

Through this project, we explored:

- Practical implementation of arrays in C++.
- Using structures to organize student information.
- Implementing Linear Search.
- Understanding and implementing Bubble Sort.
- Understanding and implementing Insertion Sort.
- Understanding and implementing Selection Sort.
- Developing modular programs using functions.
- Managing records through insertion, deletion, and updating.
- Applying Data Structures and Algorithms to a real-world problem.

---

## 👨‍💻 Contributors

**Project:** Student Record Management System

Developed as a college-level C++ project to demonstrate fundamental concepts of Data Structures and Algorithms.

---

## 📄 License

This project is available for educational and learning purposes. You are welcome to explore, modify, and improve it.

---

⭐ If you find this project useful, consider giving the repository a star!
