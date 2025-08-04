
What will be the size of this c struct? 

struct base {
int a;
char d[0];
}


Write a c program to simulate c++ inheritance.


struct base {
int a;
int b;
};

struct derived {
int c;
struct base b1;
};

Will the above code break inheritance?
If yes, why?

The scope of a global static variable is limited to the file?
How is this limit enforced?

What is the difference between kernel programming and userspace programming?

Why is segmentation fault caused?
What is the signal number associated with it?

What prevents user space process from accessing the entire address space?

There are two linked lists which form two numbers:
9 -> 1 -> 2 -> 0 -> 0 ->0
1 -> 4 -> 0 

Write a program to return sum of these two numbers (E.g return 912000 + 140)
https://www.geeksforgeeks.org/dsa/add-two-numbers-represented-by-linked-list/
