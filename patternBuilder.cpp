#include <iostream>
#include <string>
using namespace std;

class Clerk {
private:
    friend class ClerkBuilder;
    string name;
    string phone;
    int cab;
public:
    Clerk() {};
    void work()
    {
        cout <<this << " : " << name << " clerk work in " << cab<<endl;
    }
};

class Programmer {
private:
    friend class ProgrammerBuilder;
    string name;
    string mail;
    int cab;
public:
    Programmer() {};
    void pragramm()
    {
        cout <<this<<" : "<< name << " programmer work in " << cab << endl;
    }
};

class Journal {
private:
    friend class JournalBuilder;
    string info;
public:
    Journal() {};
    string getInfo()
    {
        return info;
    }
};

class Builder {
public:
    virtual void setName(string) = 0;
    virtual void setCab(int) = 0;
    virtual void setContacts(string) = 0;
};

class ClerkBuilder : public Builder {
    
private:
    
    Clerk* clerk;
    string name;
    string phone;
    int cab;
public:
    ClerkBuilder() {}
    ~ClerkBuilder() {
        delete clerk;
    }
    ClerkBuilder(string name, string phone, int cab) {
        this->name = name;
        this->phone = phone;
        this->cab = cab;
    }
    void setName(string name) {
        this->name = name;
    }
    void setContacts(string phone) {
        this->phone = phone;
    }
    void setCab(int cab) {
        this->cab = cab;
    }
    Clerk* get() {
        clerk = new Clerk();
        clerk->name = name;
        clerk->phone = phone;
        clerk->cab = cab;
        return clerk;
    }
};

class ProgrammerBuilder : public Builder {

private:

    Programmer* programmer;
    string name;
    string mail;
    int cab;
public:
    ProgrammerBuilder() {}
    ~ProgrammerBuilder() {
        delete programmer;
    }
    ProgrammerBuilder(string name, string mail, int cab) {
        this->name = name;
        this->mail = mail;
        this->cab = cab;
    }
    void setName(string name) {
        this->name = name;
    }
    void setContacts(string mail) {
        this->mail = mail;
    }
    void setCab(int cab) {
        this->cab = cab;
    }
    Programmer* get() {
        programmer = new Programmer();
        programmer->name = name;
        programmer->mail = mail;
        programmer->cab = cab;
        return programmer;
    }
};

class JournalBuilder : public Builder {

private:
    Journal* journal;
    string data="";
public:
    JournalBuilder() {}
    ~JournalBuilder() {
        delete journal;
    }
    JournalBuilder(string name, string phone, int cab) {
        data += name;
        data += " | ";
        data += phone;
        data += " | ";
        data += to_string(cab);
    }
    void setName(string name) {
        data += name;
        data += " | ";
    }
    void setContacts(string phone) {
        data += phone;
        data += " | ";
    }
    void setCab(int cab) {
        data += to_string(cab);
    }
    Journal* get() {
        journal = new Journal();
        journal->info = data;
        return journal;
    }
};

class Director {
public:
    Director() {};
    ClerkBuilder* createClerk(string name, string contact, int cab) {
        ClerkBuilder* clerkBuilder = new ClerkBuilder();
        clerkBuilder->setName(name);
        clerkBuilder->setContacts(contact);
        clerkBuilder->setCab(cab);
        return clerkBuilder;
    }
    ProgrammerBuilder* createProgrammer(string name, string contact, int cab) {
        ProgrammerBuilder* programmerBuilder = new ProgrammerBuilder();
        programmerBuilder->setName(name);
        programmerBuilder->setContacts(contact);
        programmerBuilder->setCab(cab);
        return programmerBuilder;
    }
    JournalBuilder* createJournal(string name, string contact, int cab) {
        JournalBuilder* journalBuilder = new JournalBuilder();
        journalBuilder->setName(name);
        journalBuilder->setContacts(contact);
        journalBuilder->setCab(cab);
        return journalBuilder;
    }
};

int main()
{
    Director* director = new Director();
    ClerkBuilder* builder1 = director->createClerk("Clerk1", "89123123", 23);
    ProgrammerBuilder* builder2 = director->createProgrammer("Programmer1", "prog@mail.com", 1);
    JournalBuilder* builder3 = director->createJournal("Journal1", "qwer", 23);

    Clerk* clerk1 = builder1->get();
    Clerk* clerk2 = builder1->get();
    Clerk* clerk3 = builder1->get();
    Clerk* clerk4 = builder1->get();

    Programmer* prog1 = builder2->get();
    Programmer* prog2 = builder2->get();
    Programmer* prog3 = builder2->get();
    Programmer* prog4 = builder2->get();

    Journal* journal1 = builder3->get();
    Journal* journal2 = builder3->get();
    Journal* journal3 = builder3->get();
    Journal* journal4 = builder3->get();

    clerk1->work();
    clerk2->work();
    clerk3->work();
    clerk4->work();

    prog1->pragramm();
    prog2->pragramm();
    prog3->pragramm();
    prog4->pragramm();

    cout <<journal1<<" : "<< journal1->getInfo()<<endl;
    cout << journal2 << " : " << journal2->getInfo() << endl;
    cout << journal3 << " : " << journal3->getInfo() << endl;
    cout << journal4 << " : " << journal4->getInfo() << endl;




}
