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


- What is a pure virual class?


- What are the different phases of the compilation process?


- What is a smart-pointer? What problem do they solve? What problem do they bring?


- What is the problem that multi-threading try to solve?


- Give at least two synchronization types that are used by multi-threading programs? What are their purpose?


- What is a Spin Lock?


- What is a Dead Lock?


- What does the following code display?
```cpp
int x = 10;
int* p = &x;
*p = 20;
std::cout << x << std::endl;
```


- What is the following code output?
```cpp
int* p = nullptr;
*p = 5;
std::cout << p << std::endl;
```


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


- What is the number of loop that program will execute?
``` cpp
unsigned char nbHalfLoop = 200;
for (unsigned char id = 0; id < 2 * nbHalfLoop; id++)
{
cout << id;
}
```


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


- In the following code, which container should be used and why?
```cpp
CONTAINER<int> data = { 1, 2, 3, 4, 5 };

// ...

data.Insert(data.begin(), 0);
```


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