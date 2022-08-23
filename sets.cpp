#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

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

    bool operator<(Student s2) const { return this->id < s2.id; }

};

int countUnique(const vector<Student> &students)
{
    set<Student> mySet;
    for (Student s : students) {
        mySet.insert(s);
    }
    return  mySet.size();

}

int main() {

    vector<Student> testStudents;
    testStudents.push_back( Student(10, "Bienve", "Velez"));
    testStudents.push_back( Student(65, "Joshua", "Cruz"));
    testStudents.push_back( Student(32, "Amanda", "Vazquez"));
    testStudents.push_back( Student(32, "Amanda", "Davis"));
    testStudents.push_back( Student(65, "Joshua", "Vazquez"));
    testStudents.push_back( Student(43, "Alejandra", "Munoz"));
    testStudents.push_back( Student(54, "Fatima", "Puig"));
    testStudents.push_back( Student(54, "Fatima", "Puig"));
    testStudents.push_back( Student(65, "Joshua", "Cruz"));
    testStudents.push_back( Student(65, "Joshua", "Cruz"));
    testStudents.push_back( Student(76, "Rey", "Cotto"));

    cout << "Count of Vector Students: " << testStudents.size() << endl;
    cout << "Count of Unique Students: " << countUnique(testStudents) << endl;

    // set<Student> A;
    // A.insert( Student(10, "Bienve", "Velez"));
    // A.insert( Student(65, "Joshua", "Cruz"));
    // A.insert( Student(32, "Amanda", "Vazquez"));
    // A.insert( Student(32, "Amanda", "Davis"));
    // A.insert( Student(65, "Joshua", "Vazquez"));

    // set<Student> B; 
    // B.insert( Student(43, "Alejandra", "Munoz"));
    // B.insert( Student(54, "Fatima", "Puig"));
    // B.insert( Student(54, "Fatima", "Puig"));
    // B.insert( Student(65, "Joshua", "Cruz"));
    // B.insert( Student(65, "Joshua", "Cruz"));
    // B.insert( Student(76, "Rey", "Cotto"));

    // set<Student> C;
    // set_intersection(A.begin(), A.end(), B.begin(), B.end(), C.begin());

}
