# **Project 7: Library Circulation and Hold Management System**

By: Kalysha Melendez Hernandez, Harman Kaur, Wren Root, Leonardo Navarro Mercado

## **Project Goal Statement**

Develop a library circulation system that manages materials, patrons, checkouts, returns, and requests for unavailable items.

## **How to Use**

build:
```bash
cmake -S . -B build
cmake --build build
```

run:
```bash
./build/Debug/app
```

test:
```bash
ctest --test-dir build -C Debug     # for all tests
./build/Debug/patron_tests          # for individual tests
```

## **How to View Milestone 3**

Milestone 3 is a working vertical slice of our project. We chose to implement the account creation/signin for our library system.

Commit: 5eac56a

In this commit, we set up a menu system for our app and account creation, which is pretty straightforwards. You can create either a librarian or a patron account, which will automatically sign you in upon creation. Then, you can see your account dashboard and the choices of actions we will implement in the future. For example, a librarian account will show "2) Add to Catalog", which will enable the librarian to add an item into the catalog. In the same session, you can sign out of your account and sign back in. The system will notify you if your email is already in use, or if your password is incorrect.

build:
```bash
cmake -S . -B build
cmake --build build
```

run:
```bash
./build/Debug/app
```
