# RecursiveFileDeleter
Program search and delete files by substring.


# What does the program do?
The program searches for and deletes files by the specified 
substring in the root folder and subfolders.

Just place the application in the desired directory, launch it, enter the desired substring to search for, then the program will find and delete files with the found substring in the name.

For example, if you enter "_.txt" as a substring, and the folder will contain files:

- test.txt
- test_.txt
- another.txt

In this case the program will delete only the file:

- test_.txt

# Something else?
* Be careful - the program will delete all files that have a substring in their name.
* You need C++17 compiler to build this program. Well, or you can change std::filesystem to std::experemental::filesystem


# License?
The program is distributed under the ZLIB license.

# ....
I hope this program will help someone.
Good luck and have a good day.

