#project 4 Account Manager
This project is a account manager for a bank and stores the information inside a text file called "accounts.txt"
compile the program with g++ main.cpp account.cpp

###Input/Output
[main.cpp lines 41-42](/main.cpp)
This is using cin to get the information from the user about what they want to do in the program and using the cout to provide messages to the user.
###Control Flow
[main.cpp lines 43-207](/main.cpp)
This asks the user what they want to do in the program and select what to do according to the users input using If , else if and else conditions
Also will use a switch for the next users input
###Iteration
[main.cpp lines 49-61](/main.cpp)[main.cpp lines 66-112](/main.cpp)
This will use a for loop to search through the account information vector to see if the users username exists and if the password is correct 
Also the Do while loop will repeat the whole thing till the user enters number 4.Quit and then it will end the loop 
[main.cpp lines 255-280](/main.cpp)
This while loop is to read information though the file and this will happen while the file is good and if we read all of the file it will end the loop 
###Data Structure
[main.cpp lines 21-22](/main.cpp)
Here There is a vector to keep the classes for each of the accounts so it is a vector of account classes and this vector will be expanded when the 
file is read and put those information on to the vector in function import()
###Functions
[main.cpp lines 217-297](/main.cpp)
[account.cpp lines 7-67](/account.cpp)
There are lots of functions in this program
In the main there is the Import() function which will have pass by reference for the accounts vector and 
this function will read the file and put the information into the vector and also will expand the vector when 
we put new information to it
in the account.cpp , there are multiple functions to get and set all the user information
###file I/O
[main.cpp lines 243-257](/main.cpp)
[main.cpp lines 165-176](/main.cpp)
This will open the accounts.txt and read from the file and put everything to the vector 
The second one will open the file and then put all the information from the vector back to the file
so that we can get it the next time we open the program
This will happend when the user quits the program
###Class
[account.h lines 6-34](/account.h)
This is a class which has all the user information like username , password , name ,secret question , secret answer
and these variables are private so that the outside cant change or access but there some public functions which can 
be called to change or view these provate variables which the main program will call
