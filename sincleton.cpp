#include <iostream>
using namespace std;

class Man {
    static Man* man;
    string name;
    Man(string name) {
        this->name = name;
    }
public:
    string getName() {
        return name;
    }
    static Man* get(string name) {
        if (man == nullptr) {
            man = new Man(name);
        }
        return man;
    }
};

Man* Man::man = nullptr;

int main()
{
    Man* man1 = Man::get("Karl");
    Man* man2 = Man::get("Leon");
    cout << man1<<endl;
    cout << man2<<endl;
    cout << man1->getName() << endl;
    cout << man2->getName() << endl;
    
}
