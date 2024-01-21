/*Console based task management system written in C++
Author: Mauricio Posadas
Date Started: January 15th 2024

Current Status: 
   removeTask gives segFault (lines 167 and 176)
   addTask only takes in a single word description along with priority glitches out when non number values are inputted

TO-DO: Fix segFault on removeTask. Problem could also be with while statement or possibly use of erase function
      

Additional Things to implement:   
    1. On markStatus can prompt user if they would like to remove instead of immediately removing
    2. Implement markPriority. remove from list then reimplement in correct place? 
    3. Could also just show tasks of utmost importance till they are completed then show remaining tasks
    
*/

#include <iostream>
#include <string>
#include <vector>
#include <list>


using namespace std;

class Task 
{
    string taskDescription;
    int priorityLevel;
    bool completed;
    int taskNum;
    
    public:
    
    Task(string &newTask, int &np)
    {
        taskDescription = newTask;
        priorityLevel = np;
        completed = false;
        taskNum = 0;
    }

    void printTaskInfo()
    {   
        cout << taskNum << ". Task Info\n"
             << "Task Description: " << taskDescription
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
    void changeTaskNum(int newNum)
    {
        taskNum = newNum;
    }
    string getDescription()
    {
        return taskDescription;
    }
    int getPriority()
    {
        return priorityLevel;
    }
    int getTaskNum()
    {
        return taskNum;
    }
};

class Console
{
    
    list<Task> priorityBoard; // stores all tasks and orders task by priority level
    
    public:
    Console() // constructor
    {}
    void menu() 
    {
        cout << "\nTask Manager. Actions below"
             << "\n1. Add Task"
             << "\n2. Remove Task"
             << "\n3. Mark Task as Completed"
             << "\n4. View Tasks"
             << "\n5. Exit\n" << endl;
    }
    void run() 
    {
        int choice;
        do
        {
            cout << "Which action would you like to complete?" << endl;
            menu();
            cin >> choice; // modify to only take in numbers
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
                case 5: //exit
                    break;
                default:
                    cout << "Invalid choice. Try again" << endl;
                    break;
            } 
        } while (choice!=5);
        
       

        
    }
    void printTaskBoard() 
    {
        int num = 1;
        for(auto item : priorityBoard) // number the tasks being outputted
        {
            item.changeTaskNum(num);
            item.printTaskInfo();
            num++;
        }

    }
    void addTask() // still needs work on getLine function
    {
        string tempTask;
        int tempPriority = 0;
        cout << "You would like to create a new task. Please enter task description" <<  endl;
        cin >> tempTask; // not taking in full phrases only single words. 
        while((tempPriority>3) || (tempPriority<1))
        {
            cout << "Now enter priority level. All in one line (1 - 3. 1 being the utmost priority)" << endl;
            cin >> tempPriority; // still crashes when inputting non number characters
        }
        Task temp(tempTask, tempPriority); // initializes task to be added
        organizePriority(temp);
    }
    void removeTask() // erase function causing segFault
    {
        int temp;
        cout << "Please list the task you would like to remove by entering task number\n" << endl;
        printTaskBoard();
        cin >> temp;
        auto it = priorityBoard.begin();
        while((it != priorityBoard.end()) && (it->getTaskNum()!=temp))
        {
            it++;
        }
        //priorityBoard.erase(it);
    }
    void removeTask(int temp) // removing task without user input
    {
        auto it = priorityBoard.begin();
        while((it != priorityBoard.end()) && (it->getTaskNum()!=temp))
        {
            it++;
        }
        //priorityBoard.erase(it);
    }
    void markStatus()
    {
        int temp;
        cout << "Which Task have you completed?\n" << endl;
        printTaskBoard();
        cout << "Please enter number of task you have completed? " << endl;
        cin >> temp;
         for(auto item : priorityBoard) // number the tasks being outputted
        {
            if(item.getTaskNum() == temp)
            {
                item.changeStatus();
                break; // breaking out of for loop to avoid unnecesary iterations
            }
        }
        
        cout << "Task will now be removed from Task Board" << endl;
        removeTask(temp);
    }
    void organizePriority(Task temp)
    {
        if(temp.getPriority() == 3)
        {
            priorityBoard.push_back(temp);
        }
        else if(temp.getPriority()==2)
        {
            auto it = priorityBoard.begin(); // creating valid iterator
            while((it != priorityBoard.end()) && ((it->getPriority()<temp.getPriority()))) // iterate through till correct value is found
            {
                it++;// if not found iterate one more
            }
            priorityBoard.insert(it,temp);// when found insert

        }
        else if(temp.getPriority() == 1)
        {
            priorityBoard.push_front(temp); 
        }

    }
};


int main()
{
    Console ToDoList;
    ToDoList.run();

    return 0;
}


/* FOR LATER USE MARK PRIORITY
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

*/