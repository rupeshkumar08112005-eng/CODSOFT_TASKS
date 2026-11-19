#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

struct Task {
    string description;
    bool completed;
};

void showTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "\nYour to-do list is empty.\n";
        return;
    }

    cout << "\n----------- YOUR TASKS -----------\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". [" << (tasks[i].completed ? "Completed" : "Pending")
             << "] " << tasks[i].description << "\n";
    }
}

int main() {
    vector<Task> tasks;
    int choice;

    do {
        cout << "\n====================================\n";
        cout << "             TO-DO LIST\n";
        cout << "====================================\n";
        cout << "1. Add task\n";
        cout << "2. View tasks\n";
        cout << "3. Mark task as completed\n";
        cout << "4. Delete task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Please enter a valid menu number.\n";
            return 1;
        }

        if (choice == 1) {
            string description;
            cout << "Enter task description: ";
            getline(cin >> ws, description);
            tasks.push_back({description, false});
            cout << "Task added successfully.\n";
        } else if (choice == 2) {
            showTasks(tasks);
        } else if (choice == 3) {
            showTasks(tasks);
            if (!tasks.empty()) {
                size_t taskNumber;
                cout << "Enter task number to mark completed: ";
                if (!(cin >> taskNumber) || taskNumber < 1 || taskNumber > tasks.size()) {
                    cout << "Invalid task number.\n";
                    return 1;
                }
                tasks[taskNumber - 1].completed = true;
                cout << "Task marked as completed.\n";
            }
        } else if (choice == 4) {
            showTasks(tasks);
            if (!tasks.empty()) {
                size_t taskNumber;
                cout << "Enter task number to delete: ";
                if (!(cin >> taskNumber) || taskNumber < 1 || taskNumber > tasks.size()) {
                    cout << "Invalid task number.\n";
                    return 1;
                }
                tasks.erase(tasks.begin() + static_cast<long long>(taskNumber - 1));
                cout << "Task deleted successfully.\n";
            }
        } else if (choice == 5) {
            cout << "Thank you for using the To-Do List.\n";
        } else {
            cout << "Invalid choice. Select 1 to 5.\n";
        }
    } while (choice != 5);

    return 0;
}
