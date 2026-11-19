# **Project 7: Library Circulation and Hold Management System**

By: Kalysha Melendez Hernandez, Harman Kaur, Wren Root, Leo Navarro Mercado

## **Main Classes and Responsibilities/Major Requirements**

### **main.cpp**

- creates Library  
- loop; allows user to: (1) create account, (2) sign in, (2) increment clock by n days

### **class Library**

- has a Catalog, map of Persons, a Clock  
- if successful signin, display actions; else go back to main

### **class Catalog**

- search thru books  
- checkout/return  
- add//remove from catalog  
- searches through all items via search title or item ID, outputting at most top 3 matches

### **class Item**

- list of Patrons who are in line for hold

  #### **class Book**

  #### **class Game**

  #### **class Audiobook**

- Each class inheriting Item:  
  - create\_item() ← blocking function that takes in user input to create item  
  - display\_item() ← string representing the item details  
  - display\_short\_name() ← short rep of item (first 15 letters of title or something)

### **class Person**

- creates user with unique id

#### 	**class Librarian**

- allow user to: (1) checkout book, (2) return book, (3) add/remove book to catalog, (4) add to hold list, (5) signout

#### 	**class Patron**

- displays account info:   
  - allow user to: (1) pay fines, (2) search for book, (3) signout

### **class Clock**

- creates a way to keep track of time (initializes to day 1, increments in Library)  
- can give deadline for checkout (+\~14 days)  
- can check if deadline has passed  
- way to increment time

## **UML Class Diagram**

Key: `+` public, `-` private, `#` protected. △ = inherits from (arrow points to the parent).

### Person hierarchy

```
┌─────────────────────────────────────────────┐
│ «abstract» Person                           │
├─────────────────────────────────────────────┤
│ - id : int                                  │
│ - userName : string                         │
│ - email : string                            │
│ - password : string                         │
│ - isSignedIn : bool                         │
├─────────────────────────────────────────────┤
│ + Person(personId, personName,              │
│     personEmail, personPassword)            │
│ + getId() : int                             │
│ + getUserName() : string                    │
│ + getEmail() : string                       │
│ + getPassword() : string                    │
│ + signIn(email : string, password : string) │
│     : bool                                  │
│ + signOut() : void                          │
│ + displayActions(lib : Library*)            │
│     : void  «pure virtual»                  │
└─────────────────────────────────────────────┘
                     △                                           △
                     │                                            │
┌─────────────────────────────────────────┐  ┌─────────────────────────────────────────┐
│ Patron                                  │  │ Librarian                               │
├─────────────────────────────────────────┤  ├─────────────────────────────────────────┤
│ - accountDebt : double                  │  │                                         │
│ - borrowedBooks                         │  ├─────────────────────────────────────────┤
│     : unordered_map<int, Item*>         │  │ + Librarian(personId, personName,       │
├─────────────────────────────────────────┤  │     personEmail, personPassword)        │
│ + Patron(personId, personName,          │  │ + checkoutBook() : void                 │
│     personEmail, personPassword)        │  │ + returnBook() : void                   │
│ + getAccountDebt() : double             │  │ + addBook() : void                      │
│ + payAccountDebt(amount : double)       │  │ + removeBook() : void                   │
│     : double                            │  │ + addToHoldList() : void                │
│ + getBorrowedBooks() : vector<string>   │  │ + removeFromHoldList() : void           │
│ + borrowBook(id : int, book : Item*)    │  │ + displayActions(lib : Library*) : void │
│     : void                              │  └─────────────────────────────────────────┘
│ + returnBook(id : int, book : Item*)    │
│     : void                              │
│ + displayActions(lib : Library*) : void │
└─────────────────────────────────────────┘
```

### Item hierarchy

```
┌────────────────────────────────────────┐
│ «abstract» Item                        │
├────────────────────────────────────────┤
│ # title : string                       │
│ # holdQueue : deque<Patron*>           │
├────────────────────────────────────────┤
│ + addHold(p : Patron*) : void          │
│ + nextHold() : Patron*                 │
│ + hasHolds() : bool                    │
│ + isNextHold(p : Patron*) : bool       │
│ + matchesSearch(term : string) : bool  │
│ + create_item() : void  «pure virtual» │
│ + display_item()                       │
│     : string  «pure virtual»           │
│ + display_short_name()                 │
│     : string  «virtual»                │
└────────────────────────────────────────┘
              △                             △                             △
              │                              │                              │
┌───────────────────────────┐  ┌───────────────────────────┐  ┌───────────────────────────┐
│ Book                      │  │ Audiobook                 │  │ Game                      │
├───────────────────────────┤  ├───────────────────────────┤  ├───────────────────────────┤
│ - author : string         │  │ - author : string         │  │ - rating : string         │
│ - pages : int             │  │ - narrator : string       │  ├───────────────────────────┤
├───────────────────────────┤  │ - duration : int          │  │ + create_item() : void    │
│ + create_item() : void    │  ├───────────────────────────┤  │ + display_item() : string │
│ + display_item() : string │  │ + create_item() : void    │  └───────────────────────────┘
└───────────────────────────┘  │ + display_item() : string │
                               └───────────────────────────┘
```

### Library

```
┌──────────────────────────────────────────┐
│ Library                                  │
├──────────────────────────────────────────┤
│ - users : unordered_map<string, Person*> │
│ - totalUsers : int                       │
│ + catalog : Catalog*                     │
│ + clock : Clock*                         │
├──────────────────────────────────────────┤
│ + Library()                              │
│ + patronExists(email : string) : bool    │
│ + getPatron(email : string) : Patron*    │
│ + createAccount(isLibrarian : bool)      │
│     : void                               │
│ + signin() : void                        │
│ + incrementClock() : void                │
└──────────────────────────────────────────┘
```

### Clock

```
┌────────────────────────────────┐
│ Clock                          │
├────────────────────────────────┤
│ - counter : int                │
│ - customer : Patron*           │
│ - customerItem : Catalog*      │
│ - checkedoutTime               │
│     : system_clock::time_point │
├────────────────────────────────┤
│ + Clock()                      │
│ + getDay() : int               │
│ + increment(num : int) : void  │
│ + isDay(num : int) : bool      │
│ + isPast(num : int) : bool     │
│ + customerCheckingOut(         │
│     currentPatron : Patron*,   │
│     item : Catalog*) : void    │
│ + clockStatus() : void         │
└────────────────────────────────┘
```

### Catalog

```
┌─────────────────────────────────────┐
│ Catalog                             │
├─────────────────────────────────────┤
│ - items : unordered_map<int, Item*> │
│ - nextIndex : int                   │
├─────────────────────────────────────┤
│ - searchForItem(input : string)     │
│     : vector<Item*>                 │
│ - displayEverything() : void        │
│ + Catalog()                         │
│ + isValidItemId(id : int) : bool    │
│ + getItem(id : int) : Item*         │
│ + search() : void                   │
│ + addItem() : void                  │
│ + removeItem() : void               │
└─────────────────────────────────────┘
```

### Relationships

```
Library   ◇──── 0..* Person     (users map)
Library   ────▶ 1    Catalog    (catalog)
Library   ────▶ 1    Clock      (clock)
Catalog   ◇──── 0..* Item       (items map)
Patron    ────▶ 0..* Item       (borrowedBooks)
Item      ────▶ 0..* Patron     (holdQueue)
Clock     ────▶ 0..1 Patron     (customer)
Clock     ────▶ 0..1 Catalog    (customerItem)
Person    ┄┄┄▶      Library    (displayActions parameter)
```


## **Important Design Decisions/Assumptions/Questions**

* Typed Menu where user chooses via int (1), (2), etc  
* primarily using blocking functions 

## **Planned Repository Structure**
```
CS410-Project/  
├── CMakeLists.txt  
├── .gitignore  
├── include/  
│   └── my\_project/  
│       ├── Audiobook.h  
│       ├── Book.h  
│       ├── Catalog.h  
│       ├── Clock.h  
│       ├── Game.h  
│       ├── Item.h  
│       ├── Library.h  
│       ├── Librarian.h  
│       ├── Patron.h  
│       ├── Person.h  
├── src/  
│   ├── Audiobook.cpp  
│   ├── Book.cpp  
│   ├── Catalog.cpp  
│   ├── Clock.cpp  
│   ├── Game.cpp  
│   ├── Item.cpp  
│   ├── Library.cpp  
│   ├── Librarian.cpp  
│   ├── Patron.cpp  
│   ├── Person.cpp  
│   └── main.cpp  
├── tests/  
│   ├── CMakeLists.txt  
│   └── test\_etc.cpp  
├── docs/  
│   └── architecture.md  
└── README.md  
```
