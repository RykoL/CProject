# CProject
CProject creates your c++ development environment in one single line.

## Building
To build CProject you'll need
- Boost 1.60.0
- libpthread (For Unit Testing)
- libGtest (For Unit Testing)

### Linux
```` sh
cmake .
make install #might require root
````


## Usage
General Usage is:
```` sh
./CProject <Projectname> <options>
````

Command | Description
------- | -----------
--directories , -d  dir1 dir2 dir3 ...| Adds directories to the project structure 
--add-cmake | Creates a CMakeLists.txt in the base directory
--include-directories, -i dir1 dir2 dir3 ... | Adds the directories as include directories to the CMakeLists.txt 
--libs , -l lib1 lib2 lib3 ... | Adds the libraries to the CMakeLists.txt , to link them with the executable.
--flags, -f flag1 flag2 flag3 ... | Add compiler flags to the CMakeLists.txt


## Example

A very easy example that shows how to setup a C++ project with **CProject** is setting up an **SFML environment**.
Requirement is that you've got the SFML libraries and headers setup on your working machine. I will not show you
how to install SFML on your computer as there are enough tutorial on the web.

To set up a working environment type the following line in your terminal :
```` sh
CProject SFML_Tut -l sfml-window sfml-graphics sfml-system -i /usr/include/SFML -f std=c++1y g --add-cmake
````

You can now go into your project directory and invoke cmake.
```` sh
cd SFML_Tut/
cmake .
````

To test if everything is set up correctly copy the basic example from [SFML] (http://www.sfml-dev.org/tutorials/2.1/graphics-draw.php) and compile it with invoking make. The Project should now build correctly and you can test the SFML application.

