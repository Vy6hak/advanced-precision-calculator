# Advanced Precision Calculator (APC) 🧮

An arbitrary-precision arithmetic tool developed in C. This project performs calculations on integers of virtually infinite length by bypassing the 64-bit limitations of standard data types.

## 🧠 Technical Overview
The project is built using a **Doubly Linked List** data structure. Each node in the list stores a single digit of the number. 



### Why Doubly Linked Lists?
* **Bidirectional Traversal:** Essential for arithmetic; we traverse from **Tail to Head** (Right to Left) to handle carries and borrows, and from **Head to Tail** (Left to Right) to display the final result.
* **Dynamic Memory:** Uses `malloc` to allocate space only as needed, ensuring memory efficiency for massive calculations.

## 🚀 Features
* **Full Arithmetic Suite:** Supports Addition, Subtraction, Multiplication, and Division.
* **Sign Handling:** Correctly processes operations involving positive and negative integers.
* **Smart Parsing:** Removes leading zeros and validates command-line arguments for safety.

## 🛠️ How to Build and Run

1. **Compile the project:**
   Using the provided Makefile, simply run:
   ```bash
   make
