# expense-tracker-app

1. Introduction
The Expense Tracker System is a console-based application developed in C++ designed
to help users manage their personal finances. It allows users to record incomes and
expenses, categorize them, and generate monthly financial reports. The project focuses
on clean code architecture and the practical application of Object-Oriented Programming
(OOP) principles.

3. System Architecture & OOP Principles
The project is built with a modular structure, separating the data model, business logic,
and storage mechanisms.
Key OOP Concepts Applied:
• Encapsulation: Data members in classes like Transaction are kept private, with
access provided through public getter methods.
• Abstraction: An interface IStorage is used to abstract the data persistence logic,
allowing the system to work with any storage type (Text, JSON, Database) without
changing the core logic.
• Inheritance & Polymorphism: TextFileStorage inherits from the IStorage interface.
The TransactionManager interacts with storage through a base class pointer,
demonstrating runtime polymorphism.
• Operator Overloading: The << operator is overloaded for the Transaction class to
provide a clean and formatted output to the console.

4. Class Breakdown
A. Transaction (The Data Model)
The core entity representing a single financial entry. It stores an ID, amount, date,
category, and type (Income/Expense).
• Serialization: Includes a serialize() method to convert object data into a comma-
separated string for file storage.
B. TransactionManager (The Logic Layer)
Acts as the controller of the system. It manages the collection of transactions, handles the
ID generation logic, and coordinates between the user interface and the storage layer.
C. IStorage & TextFileStorage (The Data Layer)
• IStorage: An abstract base class (interface) defining the contract for saving and
loading data.
• TextFileStorage: A concrete implementation that handles reading from and writing
to a .txt file using file streams (ifstream, ofstream).
D. InputValidator (Utility)
A static utility class that ensures the robustness of the application. It handles user input
errors, such as entering text when a number is expected, and validates date formats
(DD/MM/YYYY).

5. Key Features

1. Record Management: Users can add new income or expense entries and delete
specific records by their unique ID.

2. Advanced Filtering: Provides functionality to list all records or filter them by a
specific date or month.

3. Financial Reporting: Generates a monthly summary calculating total income, total
expenses, and the net balance:
Net Balance = Total Income - Total Expense

4. Data Persistence: All transactions are automatically saved to a text file,
ensuring data is not lost when the program closes.

5. Conclusion
This project demonstrates a professional approach to software development by utilizing
design patterns and clean code practices. The use of the Strategy Pattern for storage
makes the system highly maintainable; for instance, adding a Database storage option
would require no changes to the TransactionManager or Main logic.
