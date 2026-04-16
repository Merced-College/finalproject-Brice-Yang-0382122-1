// Enemy.h
#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include <vector>
using namespace std;

class Enemy {
private:
    string name;
    string description;
    vector<string> actions;  // Vector to store multiple actions

public:
    Enemy(string name, string description, vector<string> actions);
    void setName(const string& newName);
    void setDescription(const string& newDescription);
    void setActions(const vector<string>& newActions);
    string getName() const;
    string getDescription() const;
    vector<string> getActions() const;
    string toString() const;
};

#endif
