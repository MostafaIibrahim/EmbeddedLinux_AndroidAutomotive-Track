# Atomic Operation
- It's a syncronization mechanism used with premitive data types to prevent Data Race of multi_threading
- It makes a reentrent function
- Anything non preemtive like Vectors and arrays so we use Mutex

### Syntax
``` C++ 
std::atomic<T> Obj /*--> Atomic templete for Obj which is the shared resource between threads*/
```
- So it was int object and now it's atomic int object
- So it avoid data race by using atomic operation 

## Topics for reading
- What is Std::chrono library
