#include <iostream>
#include <stdlib.h>					// -- Importing Standard Library Class
#include <chrono>					// -- Importing Time Library Class
#include <thread>					// -- Importing Time Delay Class
#include <fstream>					// -- Importing File Storage Class
using namespace std;

// ---------- Creating user-defined functions ---------- //
void task()
{
	for(int i = 1; i <=5; i++)
	{
		// ---- task to be performed
		std::cout <<"Loading ... " <<std::endl;
		// ---- waiting for 2 seconds
		std::this_thread::sleep_for(std::chrono::seconds(2));
	}
}

void displayGradeFile()
{
	std::ifstream inputFile("GradeFile.txt");
	if(!inputFile)
	{
		std::cerr <<"Error Opening GradeFile.txt" <<std::endl;
		return;
	}
	
	std::cout <<"-------------------- Student Stored Data ----------------------" <<endl;
	std::string line;
	while(std::getline(inputFile, line))
	{
		std::cout << line <<std::endl;
	}
	
	inputFile.close();
	
}


int main() {
	// ------ variable declaration ------ //
	string Firstname;
	string Lastname;
	string Othername;
	string Subject;
	string Gender;
	string outputOne;
	string outputTwo;
	string assignGender;
	double Classmark;
	double Exammark;
	double Total;
	string Grade;
	string Operator;
	double Average;
	
	cout <<"---------------------------------------------------------------" <<endl;
	cout <<"                  Skyline International School                 " <<endl;
	cout <<"             Instructor's Data Portal Management System        " <<endl;
	cout <<"          ------------------------------------------------     " <<endl;
	cout <<"| Enter Instructor's Name \n = ";
	cin  >>Operator;
	cout <<"                                                               " <<endl;
	cout <<"---------------------------------------------------------------" <<endl; 
	
	// ---- Calling the task function in a separate thread
	std::thread taskThread(task);
	
	// ---- Waiting for 10 seconds(5 iterations * 2 seconds each)
	std::this_thread::sleep_for(std::chrono::seconds(10));
	
	// ---- Join the task thread
	taskThread.join();
	
	// ---- Clearing Console
	system("CLS");
	
	
	// --  If statment to Control the flow of the program
	string flow;
	cout <<"Type Record : To calculate & save student data  " <<endl;
	cout <<"Type View   : To view all  student save data    " <<endl;
	cout <<" == ";
	cin  >>flow;
	cout <<endl;
	
	if(flow == "Record" || flow == "record" || flow == "RECORD")
	{
		system("CLS");
		goto  Record;
	}
	else if(flow == "View" || flow =="view" || flow == "VIEW")
	{
		system("CLS");
		cout <<"Processing Request " <<endl;
		cout <<"Please wait ..."     <<endl;
		sleep(5);
		system("CLS");
				
		// -- calling two user - define functions
		std::thread taskThread(task);
				
		// -- waiting for 10 seconds(5 iterations * 2 seconds each)
		std::this_thread::sleep_for(std::chrono::seconds(10));
				
		// -- Join the task thread
		taskThread.join();
		system("CLS");
				
		//-- Calling second function
		displayGradeFile(); 
				
		return 0;
	}
	else
	{
		cout <<"Invalid input type ERROR !!!" <<endl;
		cout <<"Program will terminate "      <<endl;
		return 0; 	
	}
	
	// -- using goto keyword
	Record : 
	
	cout <<"|--------------------------------------------------------------|" <<endl;
	cout <<"| Welcome " <<Operator 										      <<endl;
	cout <<"|                    Student Data Entry System                 |" <<endl;
	cout <<"|--------------------------------------------------------------|" <<endl;
	
	// ------ Using Input & Output Function
	// ---- Using goto Function
Roach : 
	cout <<"Enter Student Name   :: Firstname : Lastname : Othername \n = ";
	cin  >>Firstname >>Lastname >>Othername;
	cout <<endl;
	
	cout <<"Enter Student Gender :: Male : Female \n = ";
	cin  >>Gender;
	cout <<endl; 
	
	// ------ If Statement to Assign Gender 
	if(Gender == "Male" || Gender =="male" || Gender == "MALE")
	{
		// -- Assigning Gender Male
		assignGender = "Mr";
	}
	else if(Gender == "Female" || Gender == "female" || Gender == "FEMALE")
	{
		// -- Assigning Gender Female
		assignGender = "Miss";
	}
	else
	{
		// -- Assigning Gender Unknown
		assignGender = "Unknown";
	}
	
	cout <<"Enter " <<assignGender <<" " <<Lastname <<" Subject \n = ";
	cin  >>Subject;
	cout <<endl;
	
	cout <<"Enter " <<assignGender <<" " <<Lastname <<" Class Score '0 - 30 \n = ";
	cin  >>Classmark;
	cout <<endl;
	
		// -- While Loop execution 
		int counter;
		int rollno = 4;
		
		while(Classmark > 30)
		{
			rollno --;
			
			cout <<"------------------ ERROR !!! ---------------------" <<endl;
			cout <<"Invalid Student Classmark Entered "                 <<endl;
			cout <<"You have " <<rollno <<" trail left"                 <<endl;
			cout <<"Re - enter " <<assignGender <<" " <<Lastname <<" Classmark 0 -30 \n = ";
			cin  >>Classmark;
			cout <<endl;
			
			// -- updating counter
			counter++;
			
			// -- If Statement
			if(counter == 3 && Classmark > 30)
			{
				// -- Terminating the program
				cout <<"3 Continuous Invalid Inputs " <<endl;
				cout <<"----- Program will terminate after 5 seconds -----" <<endl;
				
				// -- creating a delay class
				std::this_thread::sleep_for(std::chrono::seconds(5));
				return 0;
			}
			else
			{
				continue;
			}
		}
	
	cout <<"Enter " <<assignGender <<" " << Lastname <<" Exam Score  '0 - 70' \n = ";
	cin  >>Exammark;
	cout <<endl;
			// ----- while loop exeution
			// -- Resetting counter & rollno variable
			counter = 0;
			rollno  = 4;
			
			while(Exammark > 70)
			{
				rollno --;
				cout <<"------------------ ERROR !!! ---------------------" <<endl;
				cout <<"Invalid Student Exammark Entererd                 " <<endl;
				cout <<"You have " <<rollno <<" trail left                " <<endl;
				cout <<"Re-enter " <<assignGender <<" " <<Lastname <<" Exam score '0 - 70' \n = ";
				cin  >>Exammark;
				cout <<endl;
				
				// -- update counter
				counter++;
				
				// -- If Statement 
				if(counter == 3 && Exammark > 70)
				{
					// -- termating the program
					cout <<"3 continuous invalid inputs " <<endl;
					cout <<"Program will be terminated after 5 seconds " <<endl;
					std::this_thread::sleep_for(std::chrono::seconds(5));
					return 0;
				}
				else
				{
					continue;
				}
			}
			
			// ----- performing calculations
			Total   = Classmark + Exammark;						// -- calculating total mark
			Average = Total / 2;								// -- calculating average mark
			
			// -- Calculating Student Grade & Assigning Grade 
			if(Total >= 95 && Total <= 100){
				Grade = "A+";
			}
			else if(Total >= 90){
				Grade = "A";
			}
			else if(Total >= 85){
				Grade = "B";
			}
			else if(Total >= 80){
				Grade = "C";
			}
			else if(Total >= 75){
				Grade = "D";
			}
			else if(Total >= 70){
				Grade = "E";
			}
			else if(Total >= 65){
				Grade = "F";
			}
			else if(Total <= 64 && Total >= 0){
				Grade = "F+ Disappointed";
			}
			else{
				Grade = "Your Grade doesn't' Exist ";	
			}
			
			// ------ Open a text File for writing and appending
			std::ofstream outputFile("GradeFile.txt", std::ios::app);
			
			// -- if statement to check if file exist
			if(!outputFile){
				std:cerr <<"Error Opening GradeFile.txt" <<std::endl;
				
				// -- Return an error code
				return 1;
			}
			// -- Redirect cout to the output file
			std::streambuf *coutBuffer = std::cout.rdbuf();
			std::cout.rdbuf(outputFile.rdbuf());
			
			// ------ Output to cout will now go to the file "GradeFile.txt"
			std::cout <<"------------------------------------------------------- " <<std::endl;
			std::cout <<"                   Student Exam Data                    " <<std::endl;
			std::cout <<"--------------------------------------------------------" <<std::endl;
			std::cout 															   <<std::endl;
			std::cout <<"Operator's Name               : " <<Operator 			   <<std::endl;
			std::cout <<"Student Full Name             : " <<assignGender<< " " <<Firstname <<" " <<Lastname <<" " <<Othername <<std::endl;
			std::cout <<"Student Gender                : " <<Gender                <<std::endl;
			std::cout <<"Student Subject               : " <<Subject               <<std::endl;
			std::cout <<"Student Class Score           : " <<Classmark			   <<std::endl;
			std::cout <<"Student Exam Score            : " <<Exammark              <<std::endl;
			std::cout <<"Student Average Score         : " <<Average               <<std::endl;
			std::cout <<"Student Total Score           : " <<Total				   <<std::endl;
			std::cout <<"Student Grade                 : " <<Grade                 <<std::endl;
			std::cout <<"--------------------------------------------------------" <<std::endl;
			std::cout <<"                         Data Ended                     " <<std::endl;
			std::cout <<"--------------------------------------------------------" <<std::endl;
			std::cout <<std::endl;
			
			// ------ Restore cout back to the standard output
			std::cout.rdbuf(coutBuffer); 
			
			std::cout <<"------------------------------------------------------- " <<std::endl;
			std::cout <<"                   Student Exam Data                    " <<std::endl;
			std::cout <<"--------------------------------------------------------" <<std::endl;
			std::cout 															   <<std::endl;
			std::cout <<"Operator's Name               : " <<Operator 			   <<std::endl;
			std::cout <<"Student Full Name             : " <<assignGender<< " " <<Firstname <<" " <<Lastname <<" " <<Othername <<std::endl;
			std::cout <<"Student Gender                : " <<Gender                <<std::endl;
			std::cout <<"Student Subject               : " <<Subject               <<std::endl;
			std::cout <<"Student Class Score           : " <<Classmark			   <<std::endl;
			std::cout <<"Student Exam Score            : " <<Exammark              <<std::endl;
			std::cout <<"Student Average Score         : " <<Average               <<std::endl;
			std::cout <<"Student Total Score           : " <<Total				   <<std::endl;
			std::cout <<"Student Grade                 : " <<Grade                 <<std::endl;
			std::cout <<"--------------------------------------------------------" <<std::endl;
			std::cout <<"                         Data Ended                     " <<std::endl;
			std::cout <<"--------------------------------------------------------" <<std::endl;
			std::cout <<std::endl;
			std::cout <<std::endl;
			
			// ------ If Else If Statement
			string choice;
			cout <<"Type Yes  : Enter another Record      " <<endl;
			cout <<"Type No   : End The Program           " <<endl;
			cout <<"Type Data : To View All Stored Records" <<endl;
			cout <<" == ";
			cin  >>choice;
			
			// ------ Condition
			if(choice == "Yes" || choice == "yes" || choice == "YES")
			{
				system("CLS");
				goto Roach;
			}
			else if(choice == "No" || choice == "no" || choice == "NO")
			{
				cout <<"----------------------          -------------------- " <<endl;
				cout <<"                 Terminating Program                 " <<endl;
				cout <<"----------------------          ---------------------" <<endl;
				
				// -- delaying console for 5 seconds
				sleep(5);
			}
			else if(choice == "Data" || choice == "data" || choice == "DATA")
			// --- using goto keyword
				
			{
				cout <<"Processing Request " <<endl;
				cout <<"Please wait ..."     <<endl;
				sleep(5);
				system("CLS");
				
				// -- calling two user - define functions
				std::thread taskThread(task);
				
				// -- waiting for 10 seconds(5 iterations * 2 seconds each)
				std::this_thread::sleep_for(std::chrono::seconds(10));
				
				// -- Join the task thread
				taskThread.join();
				system("CLS");
				
				//-- Calling second function
				displayGradeFile(); 
			}
			else
			{
				cout <<"Invalid Input !!! ERROR "            <<endl;
				cout <<"Program will terminate in 5 seconds" <<endl;
				
				return 0;
			}
	return 0;
}