- What is the purpose of a forward declaration?
A forward declaration declares a nested subprogram but does not define it, we need to define it later. It's used to reduce the number of header inclusion while still being able to use the variables, functions, etc. of the called class;
We call it in the .h file in order to don't open this file by #include, this decrease the number of operating system calls.
Reduce the recompilation if the forward declared class is modified. 

- What are the differences between the stack and the heap?
The stack allocation and deallocation are automatically done by the compiler but in heap we need to do it by ourselves, manually.
Handling heap memory is more expensive than managing stack memory. 
Stack is more prone to memory problems whereas the main problem of heap memory is fragmentation. 
It's more easier to access the stack because it's a small region of memory and it's cache friendly, the heap is dispersed. 
Stack isn't flexible, memory size allocated cannot be changed but the heap is flexible, the allocated memory is modifiable. 

- What is the difference between a variable passsed by copy, by reference or by pointer?
If we pass by copy a variable, it's a copy of the variable and when we change it inside the function, that will don't affect the original. 
If we pass by reference, the function gets an alias to the original variable and the several changes affect the original.
When we pass by pointer the function will get the adress of the variable. We need to use "*" to modify or access it. The changes will affect the original too. 

- What is a pure virual class?
A virtual class (abstract class) will have at least one pure virtual function with no implementation (declared using = 0). 
We can't instantiate this class, we can inherite from it and the heirs must override the pure virtual function to be usable.

- What are the different phases of the compilation process?
We have preprocessing, compilation, assembly and linking. The first (preprocessing) handles the different #include, #define, #ifdef, #ifndef and macros, this prepare the source code for compilation. 
The second part, compilation, will convert the preprocessed code into assembly code and checks for syntax errors, if it encounters any issues, the program is stop and report them.
The third part, assembly, will translate the assembly code generate by compilation into an object file (.o/.obj).
The last, linking combines object files and libraries to produce the .exe.

- What is a smart-pointer? What problem do they solve? What problem do they bring?
A smart-pointer manage dynamically allocated memory automatically, it manages the lifetime of this.
They ensure proper deallocation by releasing the memory when the pointer goes out of scope. They prevent memory leaks. They reduce the manual new/delete errors.
They bring some problems like risk of cyclic references.

- What is the problem that multi-threading try to solve?
Multi-threading try to solve a problem of performance and responsiveness issues like they allow programs to run multiple tasks at the same time in different cores. 
The multi-threading helps us to run faster and more efficiently programs by doing work in parallel. 

- Give at least two synchronization types that are used by multi-threading programs? What are their purpose?
First, with have the mutex which ensures only one thread to access a shared data at a time and prevents race conditions. 
The second one is atomic variables wich ensure thread-safe operations without any locks.

- What is a Spin Lock?
It's a type of lock that causes a thread repeatedly checks until the lock becomes available.

- What is a Dead Lock?
A Dead lock it's a type of lock when two or more threads are waiting indefinitely for resources held by another threads.

- What does the following code display?
```cpp
int x = 10;
int* p = &x;
*p = 20;
std::cout << x << std::endl;
```
The following code display 20.

- What is the following code output?
```cpp
int* p = nullptr;
*p = 5;
std::cout << p << std::endl;
```
A crash.

- What does the following code display?
```cpp
class A {
public:
    virtual void f() { std::cout << "A"; }
};

class B : public A {
public:
    void f() override { std::cout << "B"; }
};

A* obj = new B();
obj->f();
``` 
The output is B.

- Does that code works?
```cpp
class A {
public:
    virtual void f() = 0
};

class B : public A {
public:
    void f() override { std::cout << "B"; }
};

A a;
a->f();

A* b = new B;
b->f();
``` 
"virtual void f() = 0" miss a ";" and we can't create A, it's abstract class.

- What is the number of loop that program will execute?
``` cpp
unsigned char nbHalfLoop = 200;
for (unsigned char id = 0; id < 2 * nbHalfLoop; id++)
{
cout << id;
}
```
Infinite loop.

- In the following code, which container should be used and why?
```cpp
CONTAINER<int> data;

for (int i = 0; i < 100000; i++) {
    data.Add(i);
}

bool exists(int value) {
    for (int x : data) {
        if (x == value) return true;
    }
    return false;
}
```
array

- In the following code, which container should be used and why?
```cpp
CONTAINER<int> data = { 1, 2, 3, 4, 5 };

// ...

data.Insert(data.begin(), 0);
```
We can use std::vector begiven that it stores elements contiguously in memory. The push_back is efficient and vector is cache-friendly with fast iteration.

- In the following code, which container should be used and why?
```cpp
CONTAINER<int> data;

void add(int x) {
    for (int v : data) {
        if (v == x) return;
    }
    data.Add(x);
}
```
unordered_set 