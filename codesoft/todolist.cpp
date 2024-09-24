#include<bits/stdc++.h>
using namespace std;

void addTask(map<int, string>& myTask, map<int, int>& mymap, int& key) {
    int question;
    string val;
    do {
        cin.ignore();
        cout << "Enter Your Task Details : ";
        getline(cin, val);
        myTask.insert({key, val});
        mymap.insert({key, 0});
        key++;
        cout << "Do you want to add more Task? (1=Yes / 0=No) : ";
        cin >> question;
    } while(question);
}

void viewTasks(const map<int, string>& myTask, const map<int, int>& mymap) {
    cout << endl;
    if (myTask.empty()) {
        cout << "No tasks available." << endl;
    } else {
        for (auto x : myTask) {
            if (mymap.at(x.first) == 1) {
                cout << "Task-" << x.first << " : " << x.second << endl;
            } else if (mymap.at(x.first) == 0) {
                cout << "Task-" << x.first << " : " << x.second << " ---> [Pending]" << endl;
            }
        }
    }
}

void deleteTask(map<int, string>& myTask, map<int, int>& mymap) {
    int delete_key;
    cout << "\nEnter the task number which one you want to remove/delete : ";
    cin >> delete_key;
    
    if (myTask.find(delete_key) != myTask.end()) {
        myTask.erase(delete_key);
        mymap.erase(delete_key);
        cout << "\nTask-" << delete_key << " deleted/removed successfully...!" << endl;
    } else {
        cout << "\nTask not found!" << endl;
    }
}

void markTaskCompleted(map<int, string>& myTask, map<int, int>& mymap) {
    int edit_key;
    cout << "\nEnter the task number which one you want to mark as completed : ";
    cin >> edit_key;
    
    if (myTask.find(edit_key) != myTask.end()) {
        myTask[edit_key] = myTask.at(edit_key) + " ---> [Completed]";
        mymap[edit_key] = 1;
        cout << "\nTask-" << edit_key << " marked as completed successfully...!" << endl;
    } else {
        cout << "Invalid Task Number...!" << endl;
    }
}

int main() {
    int key = 1, choice;
    map<int, string> myTask;
    map<int, int> mymap;
    
    while (true) {
        cout << "\n------------------------- TO-DO LIST -------------------------\n";
        cout << "What you want to do? --->\n";
        cout << "1.>>> Add Task >>>\n";
        cout << "2.>>> View Task >>>\n";
        cout << "3.>>> Remove Task >>>\n";
        cout << "4.>>> Mark Task as Completed >>>\n";
        cout << "5.>>> Exit >>>\n";
        cout << "\nSelect your choice : ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                addTask(myTask, mymap, key);
                break;
            case 2:
                viewTasks(myTask, mymap);
                break;
            case 3:
                deleteTask(myTask, mymap);
                break;
            case 4:
                markTaskCompleted(myTask, mymap);
                break;
            case 5:
                cout << "\nThank you for using My To-Do List Application...!\n";
                return 0;
            default:
                cout << "Invalid choice...! Please try again...\n";
                break;
        }
    }
    
    return 0;
}

