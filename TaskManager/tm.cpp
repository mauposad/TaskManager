/*Console baseed task management system written in C++
Author: Mauricio Posadas
Date Started: January 15th 2024

Current Status: Creating classes as well as variables/ functions for different classes
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Task 
{
    string taskDescription;
    int priorityLevel;
    bool completed;
    
    public:
    
    Task(string newTask, int np, bool status)
    {
        taskDescription = newTask;
        priorityLevel = np;
        completed = status;
    }

    void printTaskInfo()
    {   
        cout << "Task Info" << endl;
        cout << "Task Description: " << taskDescription
             << "\nPriority Level: " << priorityLevel
             << "\nCompleted? " << completed << endl;
    }

    void changePriority(int newPriority) // Potential Problems as variable is private
    {
        priorityLevel = newPriority;
    }
    void changeStatus(bool newStatus) // Potential Problems as variable is private
    {
        completed = newStatus;
    }
};

class Console
{
    
    vector<Task> taskBoard; // stores ALL tasks
    //stack or array to store priority on tasks
    public:
    Console() // constructor
    {}
    void menu() // do while loop to show menu and choose number
    {
        cout << "\nTask Manager. Actions below"
             << "\n1. Add Task"
             << "\n2. Remove Task"
             << "\n3. Mark Task as Completed"
             << "\n4. View Tasks"
             << "\n5. Exit" << endl;
    }
    void runConsole()
    {
        int choice;
        cout << "Which action would you like to complete?" << endl;
        cin >> choice;
        switch(choice) 
        {
            case 1:
                //addTask();
                break;
            case 2: 
                removeTask();
                break;
            case 3:
                //mark tasks as completed
                break;
            case 4:
                // print all tasks
                break;
            case 5:
                //exit
                break;
        }

        
    }
    void addTask(Task newTask)
    {

        
    }
    void removeTask(){}
    void markPriority(){}



};


int main()
{


    return 0;
}