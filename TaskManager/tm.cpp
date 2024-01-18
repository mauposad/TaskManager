/*Console baseed task management system written in C++
Author: Mauricio Posadas
Date Started: January 15th 2024

Current Status: 
    Completed Task functions (printTaskInfo, changePriority, changeStatus)
    Completed Console functions (printTaskBoard, addTask, menu, markPriority, removeTask)

TO-DO: xxxx

Additional Things to implement:   
    1. Better algorithm for markPriority & removeTask (currently has bad run time)
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Task 
{
    string taskDescription;
    int priorityLevel;
    bool completed;
    
    public:
    
    Task(string newTask, int np)
    {
        taskDescription = newTask;
        priorityLevel = np;
        completed = false;
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
    void changeStatus() // Potential Problems as variable is private
    {
        completed = true;
    }
    string getDescription()
    {
        return taskDescription;
    }
};

class Console
{
    
    vector<Task> taskBoard; // stores ALL tasks
    
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
    void actions() // not completed
    {
        int choice;
        cout << "Which action would you like to complete?" << endl;
        cin >> choice;
        switch(choice) 
        {
            case 1:
                addTask();
                break;
            case 2: 
                removeTask();
                break;
            case 3:
                //mark tasks as completed
                break;
            case 4:
                printTaskBoard();
                break;
            case 5: //exit
                break;
            default:
                cout << "Invalid choice. Try again" << endl;
                break;
        }

        
    }
    void printTaskBoard()
    {
        for(auto item : taskBoard) // watch for bounds errors
        {
            item.printTaskInfo();
        }
    }
    void addTask()
    {
        string input, tempTask, tempPriority;
        cout << "You would like to create a new task. Please enter the following info\n"
             << "Task description followed by priority level. All in one line (1 to 3. 1 being utmost priority)" << endl;
        getline(cin, input);
        stringstream iss(input);
        iss >> tempTask >> tempPriority;
        Task temp(tempTask, stoi(tempPriority)); // initializes task manager
        taskBoard.push_back(temp); // pushes task onto task manager vector
    }
    void removeTask()
    {
        int back;
        back = taskBoard.size()-1;
        string temp;
        cout << "Please list the task you would like to remove by listing the task description\n" << endl;
        printTaskBoard();
        cin >> temp;
        for(size_t i = 0; i<taskBoard.size(); i++) 
        {
            if(taskBoard.at(i).getDescription() == temp)
            {
                swap(taskBoard[i], taskBoard[back]);
                taskBoard.pop_back();
            }
        }
    }
    void markPriority()
    {
        string temp;
        int tempPriority;
        cout << "Please list the task you would like to change its priority level by listing task description\n" << endl;
        printTaskBoard();
        cin >> temp;
        cout << "Enter new priority level (1 to 3. 1 being utmost priority)" << endl;
        cin  >> tempPriority;
        for(auto item : taskBoard) // bad runTime
        {
            if(item.getDescription() == temp)
            {
                item.changePriority(tempPriority);
            }
        }
    }
};


int main()
{


    return 0;
}