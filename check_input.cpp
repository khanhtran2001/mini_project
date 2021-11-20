#pragma once
#include <iostream>
#include <filesystem>
#include <fstream>
#include <cstdlib>
#include "Error.cpp"
using namespace std;

//check the number of argument, return true if is 2,3 else return false 
bool check_argument_number(int n){
    if (n == 3 || n== 4){
        return true;
    }
    else {

        return false;
    }
}
//check the command , return true if it receive accpeted command
bool check_command(string command){
    if (command == "-t" || command == "-c" || command == "-h" || command == "-m" || command == ""){
        return true;
    }
    else {
        return false;
    }
}
// check if can open input file or not, return true if it can
bool check_open_file(string file_name){
    ifstream input_stream;    
    input_stream.open(file_name.c_str(), ios::in);
    if(!input_stream)
    {
        return false;
    } 
    input_stream.close();
    return true;
}

bool check_txt_file(string file_name){
    int n = file_name.length();
    if (n >= 5){
        //check .txt at the end of the string 
        string end_text;
        end_text = file_name.substr(n-4,n);
        if (end_text == ".txt"){
            return true;
        }    
    }
    return false;
}


//check output file exist or not and overwrite it
string overwrite_output_file(string output_file_name){
    ifstream tempInputFile;
    string overwrite;
    tempInputFile.open(output_file_name.c_str(), ios::in);
    string new_output_file_name;
    //if we can open file  - ask user to overwrite it 
    if ( tempInputFile ){
        cout << "This file already exists. Would you like to overwrite?  (Y/N):";
        cin >> overwrite;
        cout << endl ;
        //if user dont want to overwrite, exit the program
        if (overwrite == "N" || overwrite == "n" )
        {
            tempInputFile.close();
            return "no overwrite";
        }
        //overwrite the file
        else if (overwrite == "Y" || overwrite == "y"){
            //erasing all content in that file
            tempInputFile.close(); 
            //empty previous output file
            std::ofstream ofs;
            ofs.open(output_file_name, std::ofstream::out | std::ofstream::trunc);
            ofs.close();
            return "overwrite file";
        }
        else {
            tempInputFile.close();
            return "wrong command";
        }
    }
    //if we cannot open a file - file does not exist - creat new file
    else{
        std::ofstream { output_file_name };
        return "new output file";
    }
}


//function to check and process input
//return string "error" if error happend
//return mode to convert when no error happened

string handle_input(int n,string input_file_name,string output_file_name, string command ){
    
    //if number of argument not right or unknown command print error and exit
    if ((not check_argument_number(n))) {
        cout << "Error01: Unknown command, type \"morse -h\" for help." << endl;
        return "error";
        
    }
    //if the program can not open input file print error
    if (not check_open_file(input_file_name)){
        cout << "Error02: " << input_file_name << " cannot be opened, type \"morse -h\" for help." << endl;
        return "error";
    }
    // if input file and outpfile is not txt file print error
    if ((not check_txt_file(input_file_name)) || (not check_txt_file(output_file_name))){
        cout << "Error03: input file or output file is not txt file, type \"morse -h\" for help." << endl;
        return "error";
    }
    //check output file exist or not and overwrite it
    string overwrite_result = overwrite_output_file(output_file_name);
    if (overwrite_result == "no overwrite" ){
        cout << "Exit program."<< endl;
        return "error";
    }
    else if (overwrite_result == "wrong command"){
        cout << "Error03: Wrong command on overwriting output file, type \"morse -h\" for help." << endl;
        return "error";
    }
    else {
        cout << "Success input command, start converting" << endl;
        return command;
    }

}


