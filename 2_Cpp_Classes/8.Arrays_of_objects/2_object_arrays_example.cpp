/*
 This is the first object array example.
 We declare one class named student that holds all the student information.]
 We create later and array of that object and then with differnt initialization techniques that will be demostrated in
 the following examples we can invoke different Constructors.
*/
#include <iostream>
using namespace std;

class Student
{
  private:
    int student_id;
    float grade;

  public:
    // Constructors:
    // 1.Default
    Student() : Student(0, 0.0f)
    {
    }
    // 2.One parameter constructor:
    Student(int id) : Student(id, 0.0f)
    {
    }
    // 3.Two parameter constructor. We declare here and for variety we define after main.
    Student(int id, float grd);
    // Mutators:
    void set_id(int id) // Inlize initialization for speed
    {
        student_id = id;
    }
    void set_grade(float grd) // Inlize initialization for speed
    {
        grade = grd;
    }
    // Accessors:
    int get_id(void)
    {
        return student_id;
    }
    float get_grade(void)
    {
        return grade;
    }
};

int main(void)
{
    // Create the array:
    const int STUDENT_POPULATION = 50;
    Student s[STUDENT_POPULATION];
    for (int i = 0; i < STUDENT_POPULATION; i++)
        cout << "ID: " << s[i].get_id() << "\tGrade: " << s[i].get_grade() << endl;
    return 0;
}

// Functions-Constructors, go here:
// Two parameter constructor definition:
Student::Student(int id, float grd) : student_id(id), grade(grd) // Inline definition for speed.
{
}
