#include <iostream>
#include <string>

using namespace std;

class Person {
    static int countPeople;

    protected:
        string name = "Person"+countPeople;
        int age = 0;

    public:
        Person(string n, int a) : name(n), age(a) {
            countPeople++;
        }
        virtual ~Person(){
            countPeople--;
        }

        virtual int getAge() { return age; }
        virtual void setAge(int a) { age = a; }

        virtual string getName() { return name; }
        virtual void setName(string n) { name = n; }
};
int Person::countPeople = 0;

class Worker: public Person {
    static int countWorker;

    protected:
        double salary = 10.0f;
        
    public:
        string address = "N/A";
        Worker(string n, int a, double s, string ad) : Person(n, a), salary(s), address(ad) {
            countWorker++;
        }
        virtual ~Worker(){
            countWorker--;
        }

        virtual void changeSalary(double new_salary){ salary = new_salary; }
        virtual double getSalary(){ return salary; }
};
int Worker::countWorker = 0;

    
class Manager: public Worker {
    static int countManager;
        
    protected:
        string department = "Humman Resource"; // department they lead
        
    public:
        Manager(string n, int a, double s, string ad, string dpt): Worker(n, a, s, ad), department(dpt){
            countManager++;
        }
        virtual ~Manager(){
            countManager--;
        }
        
        virtual void changeDept(string new_dept){ department = new_dept; }
        virtual string getDept(){ return department; }
};
int Manager::countManager = 0;

class CEO: public Manager {
    static int countCEO;

    protected:
        string company = "N/A";

    public:
        CEO(string n, int a, double s, string ad, string dpt, string cp): Manager(n, a, s, ad, dpt), company(cp){
            countCEO++;
        }
        ~CEO(){
            countCEO--;
        }

        virtual void changeCompany(string new_cp){ company = new_cp; }
        virtual string getCompany(){ return company; }
};
int CEO::countCEO = 0;

int main() {
    CEO ceo("Alice", 45, 150000, "New York", "Management", "TechCorp");

    cout << "CEO: " << ceo.getName() << ", Company: " << ceo.getCompany() << endl;
    
    return 0;
}