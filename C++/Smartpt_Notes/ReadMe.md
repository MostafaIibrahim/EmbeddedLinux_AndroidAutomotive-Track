# Rules of three in C++

### What are Smart Pointers?
Smart pointers are a type of C++ object that automatically manage memory for you. They are used to avoid memory leaks and dangling pointers.
### What are the different types of Smart Pointers?
There are three main types of smart pointers in C++:
1.  **Unique Pointer (`std::unique_ptr`)**: This type of smart pointer is used to manage ownership of a dynamically allocated object. It ensures that the object is deleted when it goes out of scope.
- Syntax:


2.  **Shared Pointer (`std::shared_ptr`)**: This type of smart pointer is used to manage shared ownership of a dynamically allocated object. It ensures that the object is deleted when the last shared pointer to it is destroyed

3. **Weak Pointer  (`std::weak_ptr`)**: This type of smart pointer is used to observe a dynamically allocated object that is owned by a shared pointer. It does not extend the lifetime of the object.
### How to use Smart Pointers?
Here is an example of how to use smart pointers in C++:

What are the differences between R-value and L-value
### What are R-value and L-value?
In C++, an lvalue (short for "left value") is an expression that refers to a
memory location and whose value can be modified. An rvalue (short for "right value") is
an expression that does not refer to a memory location and whose value cannot be
modified.
### How to determine if an expression is an L-value or R-value?
Here are some rules to determine if an expression is an L-value or R-value:
1.  **L-value**: An expression is an L-value if it can appear on the left

side of an assignment operator. For example, `x` is an L-value because it can
appear on the left side of an assignment operator: `x = 5;`

2.  **R-value**: An expression is an R-value if it cannot appear on the left
side of an assignment operator. For example, `5` is an R-value because it
cannot appear on the left side of an assignment operator: `5 = x;` is
invalid.
### What are the implications of L-value and R-value?
Here are some implications of L-value and R-value:
1.  **L-value**: L-values are used to initialize variables, and they can be
used as the left operand of an assignment operator.
2.  **R-value**: R-values are used as the right operand of an assignment
operator, and they cannot be used to initialize variables.


