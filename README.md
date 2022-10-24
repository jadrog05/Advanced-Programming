# Advanced-Programming
This is my solution to my advance programming module with the following brief:

Your task is to implement and critically evaluate a simplified take-away food ordering system in C++. 
The purpose of this assessment is to demonstrate your understanding of advanced programming techniques such as low-level memory management, 
input/output, and object- oriented design principles. Users will interact with your application via a command line interface (CLI), rather 
than a graphical interface. Once implemented, users should be able to use the system to view a menu, create orders, add/remove items from 
their order, and get a receipt for once they “checkout”. Your implementation will be marked based on the completeness of functionality 
(as per the brief), the overall program structure, and your demonstration of advanced object-oriented design principles. You are also asked 
to produce a short report detailing the functionality you’ve managed to implement (i.e., whether it deviates from the brief), the overall 
structure of your program, and the tests you’ve performed to verify its correctness.

You are provided with a skeleton program called Takeaway.cpp, and a file containing food and drink items for sale in menu.csv. You may edit 
the content of Takeaway.cpp, but the general structure should be left unchanged. Do NOT edit menu.csv. You may need to implement additional 
functions to those shown in order to produce a working implementation. The menu.csv file continues one row per item available for purchase, 
with the following columns:
Volume Alcohol by 
Type 
Name 
Price 
Calories 
Shareable 
2-4-1 
Volume(ml) 
Alcohol by volume (abv)

The program logic should be implemented in Takeaway.cpp, which should initialise a Menu object from menu.csv and an (initially empty) Order object. 
You should write code to accept input commands with the following syntax:

menu - display the menu to the user
add [INDEX] - add an item to the order by numeric index in the menu (starting at 1) 
remove [INDEX] - remove item from order by numeric index in the order (starting at 1) 
checkout - display the items in the user’s order, the price, and discount savings
help - display a help menu for the user with the available options
exit - terminate the program gracefully

Upon checkout, give the user the option to either complete their order (output their receipt and terminate gracefully) or go back and modify it. 
Additional marks may be awarded for the use of STL/contemporary C++ components in your solution, as well as attempts at the following bonus tasks:
- Allow users to add and remove multiple items at once, e.g., add 2 5 7
 
- Modify the calculateTotal function so that 2-4-1 discounts cause only the cheapest eligible item(s) to be free. You may add a row to menu.csv in order to test this behaviour, but do not modify the other data in the file.

- Add commands to sort the menu by item price in ascending/or descending order, using some combination of operator overloading/functional programming in your implementation.

Here is a sample execution:

1. User selects the menu option, producing output such as shown below: 
----------------Appetisers----------------
(1) Nachos: £4.99, 600 cal (shareable)
(2) Buffalo wings: £3.99, 450 cal (2-4-1)
(3) Garlic bread: £3.99, 500 cal (2-4-1) 
----------------Main dishes----------------
(4) Burger: £9.99, 950 cal
(5) Mac & cheese: £7.99, 850 cal
(6) Fish & chips: £8.99, 1000 cal
(7) Chicken tikka masala: £6.99, 700 cal 
----------------Beverages----------------
(8) Lager: £3.50, 200 cal (568ml, 4.5% abv)
(9) White wine: £4.00, 150 cal (175ml, 11.5% abv) (10) Red wine: £4.00, 170 cal (175ml, 12.5% abv) (11) Coke: £2.50, 140 cal (330ml)
(12) Water: £1.50, 0 cal (330ml)

2. User adds an appetiser, e.g., add 2
The corresponding pointer is retrieved from the Menu object The pointer is then added to the Order object
Output: Buffalo wings added to order!

3. User adds a second appetiser, e.g., add 3
The corresponding pointer is retrieved from the Menu object The pointer is then added to the Order object
Output: Garlic bread added to order!

4. User adds a main course, e.g., add 4
The corresponding pointer is retrieved from the Menu object The pointer is then added to the Order object
Output: Burger added to order!

5. User selects checkout, producing output like the following: ===== Checkout =====
(1) Buffalo wings: £3.99, 450 cal (2-4-1) (2) Garlic bread: £3.99, 500 cal (2-4-1) (3) Burger: £9.99, 950 cal
-------------
2-4-1 discount applied! Savings: £3.99 Total: £13.98
Do you want to place your order?
Type 'y' to confirm, or 'n' to go back and modify it.
 
6. User confirms their order (y), and the string shown above is written to a file called receipt.txt. 
This may overwrite any existing file that may be present.
