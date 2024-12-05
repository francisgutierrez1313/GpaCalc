#include <iostream>
#include <string>
using namespace std;

// Function to convert letter grade to GPA points
// Handles lower and upper case
float letterGradeToPoints(const string& letterGrade) {
    if (letterGrade == "A" || letterGrade == "a") return 4.0;
    if (letterGrade == "A-" || letterGrade == "a-") return 3.7;
    if (letterGrade == "B+" || letterGrade == "b+") return 3.3;
    if (letterGrade == "B" || letterGrade == "b") return 3.0;
    if (letterGrade == "B-" || letterGrade == "b-") return 2.7;
    if (letterGrade == "C+" || letterGrade == "c+") return 2.3;
    if (letterGrade == "C" || letterGrade == "c") return 2.0;
    if (letterGrade == "C-" || letterGrade == "c-") return 1.7;
    if (letterGrade == "D+" || letterGrade == "d+") return 1.3;
    if (letterGrade == "D" || letterGrade == "d") return 1.0;
    if (letterGrade == "F" || letterGrade == "f") return 0.0;
    return -1.0; // Invalid grade
}

// Function to calculate the GPA
float calculateGPA(int* creditHours, float* grades, int numCourses) {
    float totalPoints = 0.0;
    int totalCredits = 0;
    for (int i = 0; i < numCourses; i++) {
        totalPoints += creditHours[i] * grades[i];
        totalCredits += creditHours[i];
    }
    return totalCredits == 0 ? 0.0 : totalPoints / totalCredits;
}

// Class for GPA Calculator
class GPACalculator {
private:
    string* courseNames; // Array to store course names
    int* creditHours;    // Array to store credit hours
    string* letterGrades; // Array to store letter grades
    float* grades;       // Array to store grade points
    int numCourses;      // Number of courses

public:
    // Constructor
    GPACalculator(int courses) {
        numCourses = courses;
        courseNames = new string[numCourses];
        creditHours = new int[numCourses];
        letterGrades = new string[numCourses];
        grades = new float[numCourses];
    }

    // Destructor
    ~GPACalculator() {
        delete[] courseNames;
        delete[] creditHours;
        delete[] letterGrades;
        delete[] grades;
    }

    // Function to get the user's course details
    void inputCourseDetails() {
        for (int i = 0; i < numCourses; i++) {
            cout << "Enter details for course " << (i + 1) << ":\n";
            cout << "Course Name: ";
            cin >> courseNames[i];
            cout << "Credit Hours: ";
            cin >> creditHours[i];

            // Loops until a valid grade is entered
            while (true) {
                cout << "Letter Grade (A, A-, B+, etc.): ";
                cin >> letterGrades[i];
                grades[i] = letterGradeToPoints(letterGrades[i]);
                if (grades[i] >= 0) {
                    break; // Exit loop if the grade is valid
                }
                cout << "Invalid letter grade entered. Please try again.\n";
            }
        }
    }

    // Function to calculate and display GPA
    void displayGPA() {
        float gpa = calculateGPA(creditHours, grades, numCourses);
        cout << "\nYour GPA is: " << gpa << endl;
    }

    // Function to display all course details
    void displayCourseDetails() {
        cout << "\nCourse Details:\n";
        for (int i = 0; i < numCourses; i++) {
            cout << "Course: " << courseNames[i]
                 << ", Credit Hours: " << creditHours[i]
                 << ", Letter Grade: " << letterGrades[i]
                 << ", Grade Points: " << grades[i] << endl;
        }
    }
};

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    // Create an object of GPACalculator
    GPACalculator gpaCalc(numCourses);

    // Input course details
    gpaCalc.inputCourseDetails();

    // Display all course details
    gpaCalc.displayCourseDetails();

    // Display GPA
    gpaCalc.displayGPA();

    return 0;
}
