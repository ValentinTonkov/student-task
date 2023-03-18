#include <iostream>

using namespace std;

/*
 * definition of class Student
 * */
class Student {

    /* Private section. Private members are not visible outside the class definition.
     * For example, if an object is created in int main() function with Student student1
     * than the private fields could not be accessed there:
     * student1.age = 15; is not valid in int main()
     * An important concept of the OOP is encapsulation. It restricts direct access to some
     * components of an object.
     * In this example, there are private fields and public methods get/set
     * */
private:
    int age;
    string fn;
    string name;


    /* public section. The public members are visible outside the class
     * if the fields in the private section were declared here, than they
     * would have been accessed from outside the class definition, for example
     * from int main(), but this is not recommended
     * */
public:

    //this method prints the info for the object
    void printInfo() {
        cout << name << ", " << age << ", fn: " << fn << endl;
    }

    //get method for age - it returns the value of the private field age
    int getAge() {
        return age;
    }


    /*
     * this is a public method that sets value of the private field age
     * validations could be added, for example - check if the parameter age value is
     * greater than 0 and less than 120
     * */
    void setAge(int age) {
        /*
         * the parameter age shadows the field age of the class, so "age = age" is not
         * valid. The pointer "this" could be used to call the current object and to access
         * the field age.
         * Value of the field age could be set by the following ways (use one the following):
         * */
        Student::age = age;
        //or
        this->age = age;

        /*another way is to rename the name of the parameter age. Than the
         * definition of the function will look like this:
         *
         * void setAge(int newAge){
         *      age = newAge;
         * }
         * */
    }

    //get method for the field fn.
    const string &getFn() const {
        return fn;
    }

    void setFn(const string &fn) {
        Student::fn = fn;
    }

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        Student::name = name;
    }

    void enterStudentInfo(){
        cout<< "Enter name: ";
        getline(cin, name);

        cout << "years: ";
        cin >> age;
        cin.ignore(100, '\n');

        cout << "fn: ";
        getline(cin, fn);
    }
};

int main() {
    //creating 3 Student objects
    Student s1, s2, s3;

    //using the setAge method to set value of the private field age
    s1.setAge(14);
    //using getAge method
    cout <<"s1.getAge()  =  "<< s1.getAge()<<endl;

    s1.setName("Name1");
    s1.setFn("123231");


    /*
     * this is not valid, because the fields age name and fn are private
    s1.age = 13;
    s1.name = "Name1";
    s1.fn = "12312321";

    s2.age = 24;
    s2.name = "Name2";
    s2.fn = "123f12321";
     */


    //array of objects
    Student students[3];

    students[0] = s1;
    students[1] = s2;
    students[2] = s3;

    //cout<<students[0].name<<endl;

    //inserting data from command line
    for (int i = 0; i < 3; ++i) {
        cout << "Student number " << i + 1 << endl << "Enter name: ";
        string name;
        getline(cin, name);
        students[i].setName(name);

        cout << "years: ";
        int age;
        cin >> age;
        students[i].setAge(age);
        cin.ignore(100, '\n');

        cout << "fn: ";
        string fn;
        getline(cin, fn);
        students[i].setFn(fn);
    }

    //printing students info
    for (int i = 0; i < 3; i++){
        students[i].printInfo();
    }



    //inserting data from command line,  using the enterStudentInfo method:
    for (int i = 0; i < 3; ++i) {
        students[i].enterStudentInfo();
    }


    //printing students info
    for (int i = 0; i < 3; i++){
        students[i].printInfo();
    }

    return 0;
}
