#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct TodoItem {
    string task;
    bool completed;
};

int main() 
{
    int n;
    int count = 0;
    TodoItem tasks[100];
    while(true)
    {
        cout<<"\n1. Add a task"<<endl;
        cout<<"2. View tasks"<<endl;
        cout<<"3. Mark task as completed"<<endl;
        cout<<"4. Remove tasks"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>n;
        if(cin.fail()){
            cout<<"Invalid choice. Please try again."<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch(n){
            case 1:
                if (count < 100) {
                    cout << "Enter the task: ";
                    getline(cin, tasks[count].task);
                    tasks[count].completed = false;
                    count++;
                    cout << "Task " << count << " added" << endl;
                } else {
                    cout << "Task list is full." << endl;
                }
                break;
            case 2:
                if(count == 0){
                    cout<<"No tasks added yet."<<endl;
                    break;
                }
                cout<<"Tasks: ";
                for(int i=0; i<count; i++)
                {   
                    string s=tasks[i].task;
                    cout<<"\t"<<i+1<<". "<<s<<"\t";
                    if(tasks[i].completed){
                        cout<<"(Completed)";
                    }
                    else{
                        cout<<"(Pending)";
                    }
                    cout<<endl;
                }
                break;
            case 3:
                int taskNum;
                cout<<"Enter the task number to mark as completed: ";
                cin>>taskNum;
                if(taskNum > 0 && taskNum <= count)
                {
                    tasks[taskNum-1].completed = true;
                    cout<<"Task marked as completed."<<endl;
                } else {
                    cout<<"Invalid task number."<<endl;
                }
                break;
            case 4:
                int taskNum1;
                cout<<"Enter the task number to remove: ";
                cin>>taskNum1;
                
                if(taskNum1 > 0 && taskNum <= count)
                {
                    if(!tasks[taskNum1-1].completed)
                    {
                        cout<<"Task is not completed. Cannot remove."<<endl;
                        break;
                    }
                    for(int i=(taskNum1-1); i<count-1; i++){
                        tasks[i] = tasks[i+1];
                    }
                    count--;
                    cout<<"Task "<<count<<" removed."<<endl;
                } 
                else 
                {
                    cout<<"Invalid task number."<<endl;
                }
                break;
            case 5:
                return 0;
            default:
                cout<<"Invalid choice. Please try again."<<endl;
        }

    }
    return 0;
}