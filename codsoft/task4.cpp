#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

void addTask(vector<Task>& tasks, const string& description) {
    Task newTask;
    newTask.description = description;
    newTask.completed = false;
    tasks.push_back(newTask);
}

void viewTasks(const vector<Task>& tasks) {
    cout << "Tasks:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". ";
        if (tasks[i].completed) {
            cout << "[Completed] ";
        } else {
            cout << "[Pending] ";
        }
        cout << tasks[i].description << endl;
    }
}

void markCompleted(vector<Task>& tasks, size_t index) {
    if (index >= 0 && index < tasks.size()) {
        tasks[index].completed = true;
        cout << "Task marked as completed." << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}

void removeTask(vector<Task>& tasks, size_t index) {
    if (index >= 0 && index < tasks.size()) {
        tasks.erase(tasks.begin() + index);
        cout << "Task removed." << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}

int main() {
    vector<Task> tasks;
    int choice;
    string taskDescription;
    size_t index;

    while (true) {
        cout << "\n1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                cin.ignore(); // Ignore newline character from previous input
                getline(cin, taskDescription);
                addTask(tasks, taskDescription);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                viewTasks(tasks);
                cout << "Enter task index to mark as completed: ";
                cin >> index;
                markCompleted(tasks, index - 1); // Adjust index to match vector indexing
                break;
            case 4:
                viewTasks(tasks);
                cout << "Enter task index to remove: ";
                cin >> index;
                removeTask(tasks, index - 1); // Adjust index to match vector indexing
                break;
            case 5:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}
