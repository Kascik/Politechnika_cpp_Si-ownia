//
// Created by tomas on 8.11.2026.
//
#include <iostream>

using namespace std;

class Client {
private:
    int id;
    string name;
    string surname;
    string date_of_experience;
    string type;
public:
    Client(int id, string name, string surname, string date_of_experience, string type) {
        this->id = id;
        this->name = name;
        this->surname = surname;
        this->date_of_experience = date_of_experience;
        this->type = type;
    }
    void show() {
        cout << name << " " << surname << " " << date_of_experience << "" << type << endl;
    }
};

class Trainer {
private:
    int id;
    string name;
    string surname;

public:
    Trainer(int id, string name, string surname) {
        this->id = id;
        this->name = name;
        this->surname = surname;
    }
    void show() {
        cout << name << " " << surname << " " << id << endl;
    }
};


class Employee {
private:
    int id;
    string name;
    string surname;
    string position;

public:
    Employee(int id, string name, string surname, string position) {
        this->id = id;
        this->name = name;
        this->surname = surname;
        this->position = position;
    }

    void show() {
        cout << name << " " << surname << " " << position << endl;
    }
};


int main() {
    Client devclient(1, "clname", "clsurname", "cldate", "cltype");
    devclient.show();
    Trainer devtrainer(1, "trname", "trsurname");
    devtrainer.show();
    Employee devemployee(1, "emname", "emsurname", "emposition");
    devemployee.show();
}
