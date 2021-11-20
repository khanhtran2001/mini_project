#include <stdio.h>
#include <iostream>
#include "check_input.cpp"
using namespace std;


int main(int argc, char** argv){
    //determine converting mode
    //converting mode is "" if no argument provided;
    string convert_mode;
    //if there are 3 or 4 parameters
    if (check_argument_number(argc)){
        if (argc == 3){
            convert_mode = handle_input(argc,argv[1],argv[2],"");
        }
        else {
            convert_mode = handle_input(argc,argv[1],argv[2],argv[3]);
        }
    }
    //others
    else {
        convert_mode = handle_input(argc,"","","");
    }
    //exit program if convert mode = "error"
    if (convert_mode == "error"){
        return -1;
    }
    return 0;
}