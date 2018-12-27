#include<iostream>
#include<windows.h>
using namespace std;

const char * TITLE = "Game[TV]+";

int main(){
    HWND h_wnd = FindWindowA(0, (TITLE));
    DWORD pid = 0;
    DWORD addr = 0x10020970;
    char  username[100];
//    if(!h_wnd){
//        cout << TITLE << " not exists!" << endl;
//    } else {
//        cout << TITLE << " found!!" << endl;

        cout << "PID? ";
        cin >> pid;
        GetWindowThreadProcessId(h_wnd, &pid);
        if(!pid){
            cout << "Can't get process_id!" << endl;
        } else {
            cout << "OK, PID -> " << pid << endl;
            HANDLE p_handle = OpenProcess(PROCESS_VM_READ, 0, pid);
            if(!p_handle){
                cout << "Can't get process handle!" << endl;
            } else {
                cout << "Get process handle SUCCESS!" << endl;
                ReadProcessMemory(p_handle, (void*)addr, &username, sizeof(username), 0);
                cout << username << endl;
            }
//        }
    }
    return 0;
}
