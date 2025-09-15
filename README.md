# Lab 2

## Team Members
- May Khan
- Shreya Nair

## Lab Question Answers

Answer for Question 1: 

1. What is argc and *argv[]?

    Argc is the number of arguments the main function takes in, whihc *argv[] is the pointer/refernce to the character array of arguments.
     */


2. What is a UNIX file descriptor and file descriptor table?
    A UNIX file descriptor is an number that represents an open file. Anytime a file opened, the OS assigned it the file descriptor. The program uses this number to read/write files.
    A file descriptor table is a data table that has a column of file descriptors and then a corresponding column to show what each FD points to, whether it is a regular file, a keybaord input, devices, or a socket. Every process has its own file descriptor table.

3. What is struct? What's the structure of sockaddr_in?
    In C, a struct is something the user/progammer can define as their own data type with its own varaibles.  In C, sockaddr_in is a struct that contains and address family for sockets, a port number, and an address.

4. What are the input parameters and return value of socket()
    The first parameter of socket() is  the domain number, which represents the version of IP family, whether its IPv4 or IPv6 addresses. In the code, AF_INET6 represents IPv6 addresses. The second parameter is the socket type and specfies the transportation of communication, whether its a byte dtream used by TCP or datagramps used by UDP. The third input is the specific protocol used. This value usually defaults to 0 for TCP and UDP. The return value of socket() is an integer that represents a new file descriptor for the socket. If this number is negative, there has been an error.

5. What are the input parameters of bind() and listen()?
    The parameters of bind() are the socket fd, a pointer the the struct sockaddr and the size of the sockaddr struct. The inputs of listen() are the socket fd and the bacllog, or number of maximum number of connections the socket can queue.
6.  Why use while(1)? Based on the code below, what problems might occur if there are multiple simultaneous connections to handle?
    We need while(1) becuase the program should continously run in order to continously receive and read inputs coming. If there are multiple simultaneous connections to handle, the while could get stuck in delays that will not allow for other connections to be handled or even an infinite loop.

7. Research how the command fork() works. How can it be applied here to better handle multiple connections?
The fork() command creates a new process that is a duplicate of the original process that can run independently from the original. We can apply it here to better handle multiple connections by creating a fork() to handle the clients that are being accepted in the code above. The original/parent function can listen and accept for clients while the child can process the clients.


8. This program makes several system calls such as 'bind', and 'listen.' What exactly is a system call?

    A system call is a function in the os that the user can request to call. The system calls allow programs made by users to access these function from the os kernel.



