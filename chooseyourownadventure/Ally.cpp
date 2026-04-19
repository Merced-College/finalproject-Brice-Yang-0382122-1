// Ally.cpp 
#include "Ally.h"

Ally::Ally(string name, string description, vector<string> actions)
    : name(name), description(description), actions(actions){}

void Ally::setName(const string& newName) { name = newName; }
void Ally::setDescription(const string& newDescription) { description = newDescription; }
void Ally::setActions(const vector<string>& newActions) { actions = newActions; }
string Ally::getName() const { return name; }
string Ally::getDescription() const { return description; }
vector<string> Ally::getActions() const { return actions; }
string Ally::toString() const {
    string info = "Ally: " + name + "\nDescription: " + description + "\nActions:\n";
    for (const auto& action : actions) {
        info += "- " + action + "\n";
    }
    return info;
}
