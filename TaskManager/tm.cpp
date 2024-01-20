/*Console baseed task management system written in C++
Author: Mauricio Posadas
Date Started: January 15th 2024

Current Status: 
    Need to modify all basic functions to also work priorityBoard.
    Run needs to be modified to only take in numbers. Glitches out when taking in letters

TO-DO: Modify all basic functions to also work for priorityBoard (doubly linked list)
       Prompt if they want unorganized or organized when printing taskBoard.

Additional Things to implement:   
    1. On markStatus can prompt user if they would like to remove instead of immediately removing
    2. Implement markPriority. remove from list then reimplement in correct place? 
    3. Could also just show tasks of utmost importance till they are completed then show remaining tasks
    4. Maybe just one data structure? instead of one unorganized vector and one organized list
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
    int getPriority()
    {
        return priorityLevel;
    }
};

class Console
{
    
    vector<Task> taskBoard; // stores ALL tasks 
    list<Task> priorityBoard; // orders task by priority level
    
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
    void run() // modify to only take numbers and nothing else. 
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
                case 5: //FIXME
                    //markPriority();
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
        cin >> tempTask;// modify to take in sentences
        cout << "Now enter priority level. All in one line (1 to 3. 1 being the utmost priority)" << endl;
        cin >> tempPriority; // change so only takes numbers one through 3
        Task temp(tempTask, tempPriority); // initializes task manager
        taskBoard.push_back(temp); // pushes task onto task manager vector
        organizePriority(temp);
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
    void organizePriority(Task temp) // NEEDS TO BE CHECKED
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


/* FOR LATER USE
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