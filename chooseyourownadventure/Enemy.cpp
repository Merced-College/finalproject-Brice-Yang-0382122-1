// Enemy.cpp 
#include "Enemy.h"

Enemy::Enemy(string name, string description, vector<string> actions)
    : name(name), description(description), actions(actions){}

void Enemy::setName(const string& newName) { name = newName; }
void Enemy::setDescription(const string& newDescription) { description = newDescription; }
void Enemy::setActions(const vector<string>& newActions) { actions = newActions; }
string Enemy::getName() const { return name; }
string Enemy::getDescription() const { return description; }
vector<string> Enemy::getActions() const { return actions; }
string Enemy::toString() const {
    string info = "Enemy: " + name + "\nDescription: " + description + "\nActions:\n";
    for (const auto& action : actions) {
        info += "- " + action + "\n";
    }
    return info;
}
