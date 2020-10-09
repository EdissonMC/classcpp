
#include <iostream>
#include <cctype>
#include "editorbuffer.h"

    void executeCommand(EditorBuffer & buffer,  std::string line); 
    void displayBuffer(EditorBuffer & buffer);
    void printHelpText();



    int main() {
    EditorBuffer editor_B ;

        while (true) {
            std::string cmd;


            std::cout <<"\n>";
            getline(std::cin,  cmd);

            if(cmd!= "") executeCommand( editor_B , cmd);
            //std::cout <<cmd;


        }

        return 0;
    }



/*
    Function: executeCommand
    Usage: executeCommand(buffer, line);
    ___________________________________
    Executes the command specified by line on the editor buffer

*/
    void executeCommand(EditorBuffer & buffer,  std::string line) {
    
        switch (toupper(line[0]))
        {
        case 'I':
                std::cout <<"you insert I\n";
                for(std::string::iterator it = line.begin()+1; it != line.end(); ++it) {
                //    std::cout << *it;
                    buffer.insertCharacter(*it);
                }
                displayBuffer(buffer);
            break;
        
        
        case 'D': 
                buffer.deleteCharacter();
                displayBuffer(buffer);
            break;

        case 'F': 
                buffer.moveCursorForward();
                displayBuffer(buffer);
            break;
        
        case 'B': 
                buffer.moveCursorBackward();
                displayBuffer(buffer);
            break;   

        case 'J': 
                buffer.moveCursorToStart();
                displayBuffer(buffer);
            break;    
        
        case 'E': 
                buffer.moveCursorToEnd();
                displayBuffer(buffer);
            break;    

        case 'H': 
                printHelpText();
            break;    
        
        case 'Q': 
                exit(0);
            break;    

        default:
            break;
        }
    }








/*
    Function : displayBuffer
    Usage: displayBuffer(buffer);
    ____________________________
    Display the state of the buffer including the position of the cursor

*/
    void displayBuffer(EditorBuffer & buffer) {
        std::string str = buffer.getText();
        
        for(int i= 0;  i< str.length(); i++) {
            std::cout << " " << str[i];
        }

        std::cout <<"\n";
        std::cout<< std::string (2* buffer.getCursor(), ' ') << "^" <<"\n";
    }




/*
    Function: printHelpText
    Usage: printHelpText();
    _______________________
    Display a message showing the legal commands
*/

    void printHelpText() {
        std::cout <<"Editor commands :" << "\n";
        std::cout <<"Iabc  Insert the characters abc at the cursor position" <<"\n";
        std::cout <<"F Moves the cursor forward one character " <<"\n";
        std::cout <<"B Moves the cursor backward one character " <<"\n";
        std::cout <<"D Deletes the character after the cursor " <<"\n";
        std::cout <<"J Jumps to the beginning of the buffer " <<"\n";
        std::cout <<"E Jumps to the end of the buffer" <<"\n";
        std::cout <<"H Prints this message " <<"\n";
        std::cout <<"Q Exits from the editor program" <<"\n";

    }