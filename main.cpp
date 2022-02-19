#include "Stack.hpp"
#include <iostream>


int main(int argc, const char * argv[]) {
    
    MyStack<int> stack;
    char input;
    int choice;
    
    do {
        input = ' ';
        choice = 0;
        cout << BOLD << "*** Stack Management Menu ***)" << RESET << endl;
        cout << endl;
        
        cout << "\t1 → Push New Element To Top Of Stack" << endl;
        cout << "\t2 → Pop Top Element In Stack" << endl;
        cout << "\t3 → Print All Elements In Stack" << endl;
        cout << "\t4 → Get Stack Size" << endl;
        cout << "\t5 → Check if Empty" << endl;
        cout << RED << "\t6 → Quit" << RESET << endl;
        cout << endl;
        
        cout << "Enter a choice: ";
        cin >> choice;
        cin.ignore();
        cout << endl;
                
        try {
            switch(choice) {
                case 1:
                    cout << "Enter data for New Element: ";
                    cin >> choice;
                    cin.ignore();
                    cout << endl;
                    cout << BOLD << "Pushing...\n" << RESET << endl;
                    stack.push(choice);
                    break;
                case 2:
                    cout << BOLD << "Popping...\n" << RESET << endl;
                    stack.pop();
                    cout << endl;
                    break;
                case 3:
                    for(unsigned int i = 0; i < stack.size(); i++) {
                        cout << stack.getElement(i) << endl;
                    }
                    cout << endl;
                    break;
                case 4:
                    cout << BOLD << "Current Stack Size: " << stack.size() << RESET << endl;
                    cout << endl;
                    break;
                case 5:
                    if(stack.isEmpty()) {
                        cout << "\nStack is empty!" << endl;
                    }
                    else {
                        cout << "\nStack contains elememnts" << endl;
                    }
                    break;
                case 6:
                    cout << "\nQuitting..." << endl;
                    break;
                default:
                    throw runtime_error("<Invalid input>\n\n");
                    break;
            }
        }
        catch(const runtime_error &excpt) {
            cout << BOLD << RED << endl << endl;
            cout << "ERROR: " << excpt.what() << RESET;
        }
    }while(choice != 6);
    
    return 0;
}
