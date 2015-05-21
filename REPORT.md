##Learning Linux
###Basic Terminal Commands
1. **pwd**-pwd stands for "print working directory".The _pwd_ command will allow you to know in which directory you're located. 
2. **ls**-The _ls_ command shows ('_list_') the files in current directory.
3. **cd**-The _cd_ command allows to change directories.  
 * To navigate into the root directory, use "**cd /**"  
 * To navigate to your home directory, use "**cd**" or "**cd ~**"  
 * To navigate up one directory level, use "**cd ..**"  
 * To navigate to the previous directory (or back), use "**cd -**"   
4. **rm**-Removes or deletes a file in directory.
5. **rmdir**-The _rmdir_ command deletes an empty directory.  
           -To delete a directory and all of its contents recursively, use **rm -r** instead.
6. **mkdir**-The _mkdir_ command allows to create directories.  

###Compilation of C Programs
gcc is the "GNU" C Compiler.  
The standard way to compile the program is with the command    
 **gcc programsourcecode.c -o executablefilename -I.** 

###Command: make
Without a makefile, the typical approach to the test/modify/debug cycle is to use the up arrow in a terminal to go back to your last compile command so you don't have to type it each time, especially once you've added a few more .c files to the mix.Unfortunately, this approach to compilation has two downfalls.  
* First, if you lose the compile command or switch computers you have to retype it from scratch, which is inefficient at best.
* Second, if you are only making changes to one .c file, recompiling all of them every time is also time-consuming and inefficient.  

The purpose of the make utility is to determine automatically which pieces of a large program need to be recompiled, and issue the commands to recompile them.   
To prepare to use make, you must write a file called the makefile that describes the relationships among files in your program, and the states the commands for updating each file. In a program, typically the executable file is updated from object files, which are in turn made by compiling source files.

###Understanding Variables
 **Global Variables**-These are the variables which are declared outside all the functions. These variables can be used in all the functions.  
 
 **Local Variables**-These are the which are declared inside a function. These can only be used in the function itself.  
 **Static Variable**- These variables don't disappear when function is not active. When again function comes in action the variables retain their value which they had last time.  
 
 **Volatile Variable**-
 
 






          
