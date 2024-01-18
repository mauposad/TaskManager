/*Console baseed task management system written in C++
Author: Mauricio Posadas
Date Started: January 15th 2024

Current Status: 
    Basic functions (except AddTask) are working properly. Same with the running program. 
    For PriorityVector have upper and lower limit when inputting. Reorganize any time new task is inserted

TO-DO: Figure out how to take in sentences on AddTask Function.
       Make PriorityBoard based on priority level.
       (Stack, Queue, Array, or another vector?)

Additional Things to implement:   
    1. On markStatus can prompt user if they would like to remove instead of immediately removing
   
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
    
    Task(string &newTask, int &np)
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
             << "\nCompleted? No\n" << endl;
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
    vector<Task> priorityList; // vector for now. 
    
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
             << "\n5. Change Priority Level"
             << "\n6. Exit\n" << endl;
    }
    void run() 
    {
        int choice;
        do
        {
            cout << "Which action would you like to complete?" << endl;
            menu();
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
                    markStatus();
                    break;
                case 4:
                    printTaskBoard();
                    break;
                case 5:
                    markPriority();
                    break;
                case 6: //exit
                    break;
                default:
                    cout << "Invalid choice. Try again" << endl;
                    break;
            } 
        } while (choice!=6);
        
       

        
    }
    void printTaskBoard()
    {
        int num = 0;
        for(auto item : taskBoard) // number the tasks being outputted
        {
            cout << num << ". ";
            item.printTaskInfo();
            num++;
        }
    }
    void addTask() // still needs work
    {
        string tempTask;
        int tempPriority;
        cout << "You would like to create a new task. Please enter task description" <<  endl;
        cin >> tempTask;
        cout << "Now enter priority level. All in one line (1 to 3. 1 being the utmost priority)" << endl;
        cin >> tempPriority;
        Task temp(tempTask, tempPriority); // initializes task manager
        taskBoard.push_back(temp); // pushes task onto task manager vector
    }
    void removeTask()
    {
        int back, temp;
        back = taskBoard.size()-1;
        cout << "Please list the task you would like to remove by entering task number\n" << endl;
        printTaskBoard();
        cin >> temp;
        swap(taskBoard[temp], taskBoard[back]); // move Task to back of vector
        taskBoard.pop_back(); // pop Task out of vector
    }
    void removeTask(int temp) // removing task without user input
    {
        int back;
        back = taskBoard.size()-1;
        swap(taskBoard[temp], taskBoard[back]); // move Task to back of vector
        taskBoard.pop_back(); // pop Task out of vector
    }
    void markPriority() //changing Priority level
    {
        int tempPriority, temp;
        cout << "Please list the task you would like to change its priority level by entering task number" << endl;
        printTaskBoard();
        cin >> temp;
        cout << "Enter new priority level (1 to 3. 1 being utmost priority)" << endl;
        cin  >> tempPriority;
        taskBoard.at(temp).changePriority(tempPriority); // changing priority 
    }
    void markStatus() // changing status to completed then removing
    {
        int temp;
        cout << "Which Task have you completed?\n" << endl;
        printTaskBoard();
        cout << "Please enter number of task you have completed? " << endl;
        cin >> temp;
        taskBoard.at(temp).changeStatus();
        cout << "Task will now be removed from Task Board" << endl;
        removeTask(temp);
    }
};


int main()
{
    Console ToDoList;
    ToDoList.run();

    return 0;
}