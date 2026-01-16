#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main(int argc, char *argv[])
{
    // Level 1: Parent creates Child1
    int pid1 = fork();
    
    if (pid1 < 0) {
        cerr << "Fork failed at level 1" << endl;
        exit(1);
    }
    else if (pid1 == 0) {
        // Child1 process - becomes parent to Child2
        int pid2 = fork();
        
        if (pid2 < 0) {
            cerr << "Fork failed at level 2" << endl;
            exit(1);
        }
        else if (pid2 == 0) {
            // Child2 process - becomes parent to Child3
            int pid3 = fork();
            
            if (pid3 < 0) {
                cerr << "Fork failed at level 3" << endl;
                exit(1);
            }
            else if (pid3 == 0) {
                // Child3 process - becomes parent to Child4
                int pid4 = fork();
                
                if (pid4 < 0) {
                    cerr << "Fork failed at level 4" << endl;
                    exit(1);
                }
                else if (pid4 == 0) {
                    // Child4 process (last child) - prints first
                    int child4_pid = getpid();
                    cout << "Child4 (Last Child) PID: " << child4_pid << endl;
                    exit(0);
                }
                else {
                    // Child3 acts as parent, waits for Child4
                    wait(NULL);
                    int child3_pid = getpid();
                    cout << "Child3 PID: " << child3_pid << endl;
                    exit(0);
                }
            }
            else {
                // Child2 acts as parent, waits for Child3
                wait(NULL);
                int child2_pid = getpid();
                cout << "Child2 PID: " << child2_pid << endl;
                exit(0);
            }
        }
        else {
            // Child1 acts as parent, waits for Child2
            wait(NULL);
            int child1_pid = getpid();
            cout << "Child1 PID: " << child1_pid << endl;
            exit(0);
        }
    }
    else {
        // Main Parent waits for Child1
        wait(NULL);
        int parent_pid = getpid();
        cout << "Main Parent PID: " << parent_pid << endl;
        exit(0);
    }
    
    return 0;
}
