# **Project 7: Library Circulation and Hold Management System**

By: Kalysha Melendez Hernandez, Harman Kaur, Wren Root

### **Project Goal Statement**

Develop a library circulation system that manages materials, patrons, checkouts, returns, and requests for unavailable items.

### **Stakeholder list**

- Librarian, Patrons, City Officials, City Residents, City/State/Federal Government

### **At least 8 functional requirements**

(Note: These were just starter requirements for our system, but they are elaborated on down below in the user stories section. When adding issues to github, maybe only add unique user story requirements, since these will just be duplicates.)

1. Assign a unique IDs to a patron
2. Assign an ID to each item
3. Allow a librarian to checkout an available item for a patron, but reject if they have overdue items or exceeding pending fines
4. Allow patrons to return items
5. Allow patrons to place a hold on an unavailable item, but reject if they have overdue items, pending fines, or they are already on hold
6. Display item availability
7. Calculate total wait time for an item
8. Allow admin to add/remove items from catalog
9. Calculate the total fines for overdue items
10. Allow patrons to pay their fines

### **At least 3 nonfunctional requirements**

1. The system should be easy to use by librarians
2. The system should prevent invalid checkouts
3. The system should easy to use for all patrons : older, adults, and younger

### **At least 6 user stories (at least 3 w acceptance criteria)**

1. As a librarian or a patron, I want to be able to check the availability/wait time for a given book that's checked out, so I can decide whether to check it out.
    1. Requirements:
        1. The system shall accept a search title or item ID.
        2. The system shall examine all stored entries (the catalog).
        3. The system shall determine the top (3?) matches.
        4. The system shall report the estimated wait time for the top (3?) matches, depending on the number of copies and the hold list length.

    2. Acceptance Criteria:
        - [ ] Given an item ID or title not in the system, when a check is performed, the system rejects input.
        - [ ] Given an item ID or title with no wait time, when a check is performed, the wait time "Available" or "0 days" is returned.
        - [ ] Given an item ID or title with a wait time, when check is performed, the estimated wait time is returned.

2. As a librarian, I want to be able to check out a book for a patron so that they can borrow the book.
    1. Requirements:
        1. The system should be able to search by patron ID.
        2. The system shall accept an entry of a potential item to add.
        3. The system should report if the patron is able to check out the book.
        4. The system should either accept or reject the checkout

    2. Acceptance Criteria:
        - [ ] Given an item not in the system, the system will reject check out.
        - [ ] Given a patrons ID# and an item to checkout, if they currently have an overdue item or late fees, reject the checkout.
        - [ ] Given a patrons ID# and an item to checkout, if the book is on hold by another user, reject the checkout.
        - [ ] Given a patrons ID# and an item to checkout, if they do not have an overdue flag, late fees, and the book is not on hold by another user, check the book out of the system

3. As a librarian, I want to be able to automatically process overdue items so that patrons will incur repercussions for late items.
    1. Requirements:
        1. The system should examine all items that are overdue (checked out past the deadline).
        2. The patron should incur a flag on their account, preventing future checkouts.
        3. The system should increment daily fines onto the patron for each item overdue.

4. As a patron, I want to be able to return items so that I meet the return deadline or stop incurring fines.
    1. Requirements:
        1. The system should allow for the input of a patron’s ID# and an item’s ID#
        2. The system should reject return if either field is invalid, or patron didn’t check out item
        3. If this is the last overdue item on the patron’s account, take off the overdue flag preventing more check outs.
        4. The system should mark the item as either available or in hold.

    2. Acceptance Criteria
        - [ ] Given a patron’s ID# and an item to return, if either field is not found in the system, reject return.
        - [ ] Given a patron’s ID# and an item to return, if item is not checked out by this patron, also reject return.
        - [ ] Given a patron’s ID# and an item to return, if the item is on hold, mark it as on hold and remove from the patron’s list of checked outs. Notify the patron at the top of the hold list and set hold deadline of (maybe?) 7 days
        - [ ] Given a patron’s ID# and an item to return, if the item is not on hold, mark it as available and remove from the patron’s list of checked outs.
        - [ ] Given the patron’s ID#, check if patron still has overdue books - else remove flag if there. (maybe instead of a ‘flag’ we just check of overdues? idk, maybe this saves time)

5. As a patron, I want to be able to pay off the fines on my account so that I am not in debt to the library
    1. Requirements:
        1. The system should allow a patron to view their outstanding fines given their ID#.
        2. The system should allow a form of payment to be inputted
        3. The system should allow the patron to pay up to the fine amount.
        4. The system should update to reflect the new total fines on the account.

6. As a librarian, I want to be able to assign a unique ID to a patron so that I can track which items this specific patron checks out.
    1. Requirements:
        1. Record a patron’s full name and email.
        2. Check if the email has previously had a library ID or not. if yes find their account and give them their number, if not create a new id.
        3. Provide patrons a unique number id. (perhaps \~9 digits, so int32)

- (The librarian can print this id as a barcode on a card to give)

7. As a librarian, I want to be able to add items from the catalog so that the catalog is accurately portraying the real world.
    1. Requirements:
        1. The system provides an input item field, where librarians can type in information, such as the type of item, title, and number of copies.
            1. If an item ID is provided, the system updates the item count for that item and updates the hold list as well.

        2. The system provides a unique item id to the item. (perhaps \~9 digits, so int 32).

- (The librarian can print this id as a barcode sticker to scan the item.) 3. The system lists the item(s) as available in the catalog.

8. As a librarian, I want to put an item on hold for a patron so that they can be notified when it is next available
    1. Requirements:
        1. The system allows for an input of a patron ID# and an item ID#
        2. The system checks if item is available - if so, redirects to check out process.
        3. The system adds patron to bottom of hold list, given that patron is not already in the list.

9. As a librarian, I want to be able to automatically process holds so that patrons get the books they want most.
    1. Requirements:
        1. The system automatically notifies patron next in hold list if there is an open copy of the item they want (either item was returned or a new copy added via librarian, so this can be done in those two spots too)
        2. The system automatically skips patron in hold list if the hold deadline runs out (aka they don’t pick up the held item in time) and notifies the patron next in line.
        3. The system automatically lists the item as available if there are no holds.

### **Prioritized backlog: Must / Should / Could**

- \[label github issues]

### **At least 5 open questions or assumptions**

1. The system works separately for patrons and librarians
2. Librarians are able to see and change both patron and librarian information
3. Patron IDs are unique numbers of the same length (maybe: a “2” followed by 8 random digits?)
4. Items IDs are different from Patron IDs, but may be reused if multiple copies of it exist? (maybe: a “3” followed by 8 random digits?)
5. Once an item is returned, if it’s on hold, the next user in line will be notified, and given a deadline to come check it out. Else, it goes to the next user, etc, until it can go back to just being listed as available.
6. Wait times for an item are calculated using the number of copies of the item and the number of people on the hold list. (average # of days current readers have left + (\~21 days \* floor(# of people on hold/# of copies))) (or something, idk, future problem)

(feel free to adjust these btw, i just wanna make sure we’re on the same page)

| Patrons/Users                            | Both                           | Librarians/Admins               |
| ---------------------------------------- | ------------------------------ | ------------------------------- |
| can view checked out books and deadlines | can view item availability     | can checkout book for patron    |
| can view/pay fines                       | can view hold time for an item | can add patrons to hold         |
| can’t checkout books                     |                                | can add/remove from catalog     |
| can’t add to hold list                   |                                | can view a patron’s information |

Things to possibly adjust:

- [ ] add limit to how many items a patron can check out
- [ ] add limit to how many holds a patron can have
- [ ] add limit to how many fines you can have before it stops you from checking out
    - [ ] alternatively, get rid of fines (like most modern libraries) and just post book worth onto the patron’s account after \~45 days and report as lost book
- [ ] figure out a way that a book could have the same id as another book (easy lookup and knowing how many copies there are of it) but also know who returned the book without checking ids upon return. (like using a drop-box system)
- [ ] a log in system? could just use email and library card number for patrons, and dif for librarian account(s)
- [ ] only one admin account, or multiple librarian accounts?

Things to expand upon in future:

- child/parent IDs
- IT staff?
- more rentals outside of books (my library does video games, so that would be cool)
- restricted users - users who have accumulated fines or overdues
- adjusting limits - reliable patrons would be able to check out more books/holds
- smart hold times - calculate the hold times based on the average return time of specific item, or perhaps on average return time of the specific patrons ahead in waitlist
