// Brice Yang
// Yen Her
// 3/17/2026
// CPSC-25-12703

#include <fstream>
#include <sstream>
#include "LinkedList.h"
#include "Enemy.h"

void introduction() { 
    cout << "Welcome to the Castle Adventure!\n";
    cout << "You will navigate through various rooms in the castle, encountering challenges and making decisions that will determine your path.\n";
    cout << "Choose your actions wisely. Let's start your journey!\n\n";
}

int main() {
    LinkedList castleRooms;
    ifstream file("rooms.csv");
    string line;
    

    // Reading rooms from the CSV file
    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            string name, description, actionsStr, item;
            vector<string> actions;

            getline(ss, name, ',');
            getline(ss, description, ',');
            getline(ss, actionsStr, ',');
            getline(ss, item);

            stringstream actionStream(actionsStr);
            string action;
            while (getline(actionStream, action, ';')) {
                actions.push_back(action);
            }

            Room newRoom(name, description, actions, item);
            castleRooms.addRoom(newRoom);
        }
        file.close();
    } else {
        cout << "Unable to open file" << endl;
        return 1;
    }

    // Introduction
    introduction();

    int enemyIndex = 0;
    int currentLine = 0;

    // Interaction with rooms
    auto current = castleRooms.getHead();
    while (current != nullptr) { // Runs while 'current' does not point to a null object
        cout << current->room.toString() << endl;

        // Display actions for the current room
        int actionNum = 1;
        for (const auto& action : current->room.getActions()) {
            cout << actionNum++ << ". " << action << endl;
        }

        // User chooses an action
        int choice;
        cout << "Choose an action (1-" << current->room.getActions().size() << "): ";
        cin >> choice;

        // Process choice
        if (choice < 1 || choice > current->room.getActions().size()) {
            cout << "Invalid choice. Try again.\n"; // Declares after an invalid input by the User.
        } 
        else {
            cout << "You chose: " << current->room.getActions()[choice - 1] << endl;

            // OPTION 3: Player chooses to fight Enemy
            if (choice == 3) {

                ifstream enemyFile("enemies.csv");
                if (enemyFile.is_open()) {
                    string line;
                    bool found = false;
                    while (getline(enemyFile, line)) {
                        if (currentLine == enemyIndex) {
                            stringstream ss(line);
                            string name, description, actionsStr;
                            vector<string> actions;

                            getline(ss, name, ',');
                            getline(ss, description, ',');
                            getline(ss, actionsStr);

                            stringstream actionStream(actionsStr);
                            string action;
                            while (getline(actionStream, action, ';')) {
                                actions.push_back(action);
                            }

                            Enemy enemy(name, description, actions);
                            cout << enemy.toString() << endl;
                            found = true;
                            break;
                        }
                        currentLine++;
                    }
                    enemyFile.close();
                    enemyIndex++; // changes enemy. No loop
                } else {
                    cout << "Unable to open enemies.csv" << endl;
                }
                
                //Add combat dialogue, combat mechanics, and consequences of combat here.

                // pushes into next room, may remove
                current = current->next;
            }

            // OPTION 4: Assumes 'Leave the room' is the last action
            if (choice == current->room.getActions().size()) {  
                enemyIndex++;
                currentLine++;
                current = current->next;  // Move to next room
            }
            
        }

    }

    // Runs when the game ends
    cout << "You have reached the end of your adventure.\n";
    return 0;
}
