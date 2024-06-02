#include <iostream>

using namespace std;

// Abstract class STUDENT
class STUDENT {
private:
    int rollno;

protected:
    STUDENT(int r) : rollno(r) {}
    void show() const {
        cout << "Roll No: " << rollno << endl;
    }
};

// Abstract class TEACHER
class TEACHER {
private:
    int tcode;

protected:
    TEACHER(int t) : tcode(t) {}
    void show() const {
        cout << "Teacher Code: " << tcode << endl;
    }
};

// Derived class COURSE
class COURSE : public STUDENT, public TEACHER {
private:
    int ccode;

public:
    COURSE(int r, int t, int c) : STUDENT(r), TEACHER(t), ccode(c) {}
    void show() const {
        STUDENT::show();
        TEACHER::show();
        cout << "Course Code: " << ccode << endl;
    }
};

int main() {
    // Creating an object of type COURSE
    COURSE course(101, 202, 303);

    // Displaying data members of all the classes
    course.show();

    return 0;
}