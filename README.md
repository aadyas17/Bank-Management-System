# Bank Management System in C++

This is a simple console-based bank management project written in C++.

## Features

- Create a new bank account
- Display all saved accounts
- Search for an account by account number
- Deposit money into an account
- Withdraw money from an account

## How it works

The program stores account records in a text file named `bank.txt`.
Each time you create, search, deposit, or withdraw, the file is read and updated.

## How to run

### Using g++

```bash
g++ bankSystem.cpp -o bankSystem.exe
.\\bankSystem.exe
```

### Notes

- Make sure you run the program from the same folder as `bankSystem.cpp`.
- If `bank.txt` does not exist, the program will create it when you add an account.
- Account names with spaces are not fully supported because the program uses basic `cin` input.

## Author

Made for learning basic file handling and menu-driven programming in C++.