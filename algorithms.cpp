#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
#include <cmath>


using namespace std;

class Student {

    private:
    int id;
    string firstName;
    string lastName;

    public:
    int getId() const { return id; }
    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }

    Student(int id, string fn, string ln): id(id), firstName(fn), lastName(ln) {}

    bool operator< (const Student &s) const { return this->getId() < s.getId(); }

};


bool descendingById(Student s1, Student s2) {

    return s1.getId() > s2.getId();

}

bool descendingByLastName(Student s1, Student s2) {

    return s1.getLastName() > s2.getLastName();

}


void printStudentName(Student s) {

    cout << s.getFirstName() <<  " " << s.getLastName() << endl;

}


double integrate(double start, double end, function<double(double)> f) {

    int numIntervals = 10000;
    double result = 0;
    double deltaX = (end-start) / numIntervals;
    double xLeft = start;

    for (int i=0; i<numIntervals; i++) {
        double nextArea = deltaX * ((f(xLeft) + f(xLeft+ deltaX)) / 2);
        result += nextArea;
        xLeft += deltaX;
    }

    return result;

}


int main() 
{

    vector<Student> testStudents;
    testStudents.push_back( Student(10, "Bienve", "Velez"));
    testStudents.push_back( Student(65, "Joshua", "Cruz"));
    testStudents.push_back( Student(32, "Amanda", "Vazquez"));
    testStudents.push_back( Student(65, "Joshua", "Vazquez"));
    testStudents.push_back( Student(43, "Alejandra", "Munoz"));
    testStudents.push_back( Student(54, "Theo", "Puig"));
    testStudents.push_back( Student(65, "Joshua", "Cruz"));
    testStudents.push_back( Student(65, "Joshua", "Cruz"));
    testStudents.push_back( Student(76, "Rey", "Cotto"));


    // Sort by < operator
    sort(testStudents.begin(), testStudents.end());

    // Sort descendingly by Student ID: named function op
    sort(testStudents.begin(), testStudents.end(), descendingById);

    // Sort descendingly by student last name: named function op
    sort(testStudents.begin(),testStudents.end(), descendingByLastName);

    // Sort descendingly by student last name: lambda expression op
    sort(testStudents.begin(), testStudents.end(), [](Student s1, Student s2) { return s1.getLastName() > s2.getLastName(); });

    // Print every student name: named function op
    cout << "For each output:" << endl;
    for_each(testStudents.begin(),  testStudents.end(),[](Student s){ cout << s.getFirstName()  << endl;});

    // Print every student first name: lambda expression op

    // Find first student with a given characteristic: lambda expression op
    vector<Student>::iterator pos = find_if(testStudents.begin(),testStudents.end(),[](Student s){ return s.getFirstName()[0] == 'A';});
    cout << "First student starting with  A is: " << pos->getFirstName() << endl;
    // Find second student with a given characteristic: lambda expression op
    vector<Student>::iterator pos2 = find_if(pos+1,testStudents.end(),[](Student s){ return s.getFirstName()[0] == 'A';});

    cout << "Integral of x^2 from  0 to 2 = " << integrate(1, 3, [](double x) { return exp(x * x); })
         << endl;
}
