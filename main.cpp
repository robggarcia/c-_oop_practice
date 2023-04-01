#include <iostream>
using std::string;

// implementing a contract for an abstract class
class AbstractEmployee
{
    virtual void AskForPromotion() = 0;
};

// employee class is inhereting from our abstract class
class Employee : AbstractEmployee
{
    // access modifiers: public, private (default), protected
private:
    string Company;
    int Age;

protected:
    string Name;

public:
    // getters and setters can access private properties
    void setName(string name)
    {
        Name = name;
    }
    string getName()
    {
        return Name;
    }
    void setCompany(string company)
    {
        Company = company;
    }
    string getCompany()
    {
        return Company;
    }
    void setAge(int age)
    {
        // change only applied if age is 18 or older
        if (age >= 18)
            Age = age;
    }
    int getAge()
    {
        return Age;
    }

    void IntroduceYourself()
    {
        std::cout << "Name - " << Name << std::endl;
        std::cout << "Company - " << Company << std::endl;
        std::cout << "Age - " << Age << std::endl;
    }
    // constructor MUST be public
    Employee(string name, string company, int age)
    {
        Name = name;
        Company = company;
        Age = age;
    }
    void AskForPromotion()
    {
        if (Age > 30)
            std::cout << Name << " got promoted!" << std::endl;
        else
            std::cout << Name << " sorry, no promotion for you!" << std::endl;
    }
};

// the Developer class is a child class of the parent class Employee and inherits all properties
// inheritence is PRIVATE by default unless we make it PUBLIC
class Developer : public Employee
{
public:
    string FavProgrammingLanguage;

    Developer(string name, string company, int age, string favLang)
        : Employee(name, company, age) // send these properties to our parent class constructor
    {
        // the only new properties that need to be initialized
        FavProgrammingLanguage = favLang;
    }
    void FixBug()
    {
        // because the Employee class properties are private, we must use methods
        // unless we make the properties PROTECTED! <-- derived classes can access these
        std::cout << Name << " fixed a bug using " << FavProgrammingLanguage << "!" << std::endl;
    }
};

class Teacher : public Employee
{
public:
    string Subject;
    void PrepareLesson()
    {
        std::cout << Name << " is preparing a " << Subject << " lesson." << std::endl;
    }
    Teacher(string name, string company, int age, string subject)
        : Employee(name, company, age)
    {
        Subject = subject;
    }
};

int main()
{
    Employee employee1 = Employee("Rob", "CCS", 35);
    employee1.IntroduceYourself();

    Employee employee2 = Employee("Sarah", "Amazon", 25);
    employee2.IntroduceYourself();

    employee1.setAge(15);
    std::cout << employee1.getName() << " is " << employee1.getAge() << " years old." << std::endl;

    employee1.AskForPromotion();
    employee2.AskForPromotion();

    Developer dev = Developer("Mario", "Google", 25, "C++");
    dev.FixBug();
    dev.AskForPromotion();

    Teacher teach = Teacher("Luigi", "School District of Philadelphia", 32, "Physics");
    teach.PrepareLesson();
    teach.AskForPromotion();

    return 0;
}