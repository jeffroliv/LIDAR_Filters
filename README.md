#Brain Corporation Coding Challenge

Candidate: Jeffrey Liv

Date: 02/25/2019

Written and tested using Microsoft Visual Studio and g++

OS: Windows 10 Home 64-bit

Goal: 
	
	The goal of the assignment is to write filters to reduce noise in the data coming from a LIDAR sensor attached to a robot. 

Filters:
	
	(1) Range filter
		-The range filter crops all values that are below range_min (resp. above range_max), and replaces them with the range_min values (resp.range_max)
	
	(2) Temporal median filter
		-The temporal median filter returns the median of the current and the previous D scans

Functions/Methods:
	
	(1) update
		-The update function takes in an array of float values and returns a filtered output with values within the range of [0.03, 50.0]
	
	(2) median
		-The median function takes in an array of float values and returns the median of the array

	(3) println
		-The println function prints a line

	(4) main
		-The main function is used to test the update and median functions for their validaty
		-Further notes/comments can be found within the .cpp file

Prerequisites:
	
	(1) Computer with either g++ (5.1.0) or Microsft Visual Studio installed
	(2) Access to a command line (only when using g++)

Files:
	
	(1) range_test.txt
		-Contains the values that will be scanned in the program in order to test the range filter

	(2) med_test.txt
		-Contains the values that will be scanned in the program in order to test the temporal median filter

Running the program using g++:
	
	(1) Open a command line prompt (cmd.exe)
	(2) Open the folder containing the program
	(3) Navigate to the folder that contains the Filters.cpp file
		Example: ...\Liv-Jeffrey\LIDAR_Filters\LIDAR_Filters
	(4) Copy the path of the folder that contains Filters.cpp file
	(5) Use the path that has just been copied in conjunction with a cd command
		Example: cd <PATH>
	(6) Compile the program with the following command:
		g++ -o LIDAR_Filters Filters.cpp
	(7) Run the executable file with the following command:
		LIDAR_Filters.exe

Running the program using Microsoft Visual Studio:
	
	(1) Open the folder containing the program
	(2) Navigate to the folder that contains the LIDAR_Filters.vcxproj file
	(3) Double-click to open the project file
	(4) Press Ctrl + F5 to compile and run the program

Notes: 
	
	The pdf file containing the prompt for the coding challenge contains 2 mistakes in the output of the temporal median. 
	The correct output for the temporal median can be seen when running the program. 

