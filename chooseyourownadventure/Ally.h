// Ally.h
#ifndef ALLY_H
#define ALLY_H

#include <string>
#include <vector>
using namespace std;

class Ally {
private:
    string name;
    string description;
    vector<string> actions;  // Vector to store multiple actions

public:
    Ally(string name, string description, vector<string> actions);
    void setName(const string& newName);
    void setDescription(const string& newDescription);
    void setActions(const vector<string>& newActions);
    string getName() const;
    string getDescription() const;
    vector<string> getActions() const;
    string toString() const;
};

#endif
