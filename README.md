# Agricultural Management System 🌾

A **C-based Agricultural Management System** designed to help manage farm information, agricultural products, users, and purchasing activities through a simple menu-driven interface.

The system allows authorized users to manage farm records, search and view farms, register new users, approve registrations, and purchase agricultural products. Farm data is stored persistently using file I/O.

---

## Project Overview

The Agricultural Management System is developed in **C** to provide a platform for managing information related to multiple farms.

The system provides functionality for:

* Adding new farm records
* Viewing farm information
* Searching for farms
* Deleting farms
* User authentication
* User registration
* Administrator approval
* Persistent farm-data storage
* Purchasing farm products
* Calculating purchase costs
* Role-based access control

The application uses a **menu-driven text interface** with a simple graphical/ASCII-style welcome screen.

---

## Objectives

The major objectives of the project are:

1. **Farm Data Management**
   Maintain information about farms, crops, livestock, production quantities, and sales.

2. **User Authentication and Authorization**
   Allow authorized users to log in according to their roles.

3. **User Registration and Approval**
   Allow new users to register while requiring administrator approval before access.

4. **Data Persistence**
   Store farm information in a file so that data remains available between program sessions.

5. **Search and Retrieval**
   Allow users to search for farms by name.

6. **Farm Deletion**
   Allow authorized administrators to remove farms.

7. **User-Friendly Interface**
   Provide a menu-driven interface with graphical elements.

8. **Approval Workflow**
   Require administrator approval for new user registrations.

9. **Data Presentation**
   Display farm information in a structured and readable format.

10. **System Extensibility**
    Provide a foundation that can be expanded with additional farms, users, and functionality.

---

## Features

### User Authentication

The system provides username/password authentication and distinguishes between administrators and regular users.

Each user record contains information such as:

* Username
* Password
* Admin status
* Approval status

---

### Role-Based Access

The system supports two primary roles:

#### Administrator

Administrators have additional privileges, including:

* Adding farms
* Viewing farm information
* Searching farms
* Deleting farms
* Managing user registration requests
* Approving or disapproving users

#### Regular User

Regular users can access permitted farm-management and purchasing functionality after successful authentication and approval.

---

### Farm Management

The system maintains detailed information about individual farms.

Farm records may contain:

* Farm name
* Farmer's name
* Phone number
* Crop types
* Production quantity
* Chicken breeds
* Cow breeds
* Fish types
* Milk quantity
* Eggs available

Users can:

* Add farms
* View farms
* Search farms
* Delete farms where authorized

The `farm` structure serves as the primary data structure for farm information.

---

### Farm Search

Users can search for a specific farm by providing its name.

If a matching farm is found, the system displays its detailed information. Otherwise, the system notifies the user that the farm could not be found.

---

### Farm Deletion

Authorized administrators can delete farms by providing the farm name.

The system:

1. Checks administrator privileges.
2. Locates the farm.
3. Removes the farm from the array.
4. Shifts the remaining array elements.
5. Updates the farm count.

---

### Purchase System

The system includes purchasing functionality for agricultural products.

Users can purchase products such as:

* Chickens
* Cows
* Fish
* Eggs
* Milk

The system calculates the total cost associated with a purchase and applies the purchase to the farm's sales logic.

---

### User Registration

New users can submit registration requests by providing:

* Username
* Password

A registration request is stored until an administrator reviews it.

Only users approved by an administrator can access the system.

---

### File Persistence

Farm information is stored in:

```text
farm_data.dat
```

When the program starts, existing farm information can be loaded from the file.

When farm information changes, the system can write the updated data back to the file.

This allows farm data to persist between program executions.

---

## Project Structure

The report describes the application around several core structures and functions.

A conceptual structure of the project is:

```text
Agricultural Management System
│
├── User
│   └── Authentication & authorization
│
├── UserRequest
│   └── New user registration
│
├── farm
│   └── Farm information
│
├── interface()
│   └── Welcome interface
│
├── addFarm()
│   └── Add new farm
│
├── viewFarms()
│   └── Display farms
│
├── searchFarm()
│   └── Search by farm name
│
├── deleteFarm()
│   └── Delete farm
│
├── writeFarmDataToFile()
│   └── Save farm data
│
├── readFarmDataFromFile()
│   └── Load farm data
│
├── userLogin()
│   └── Authenticate users
│
└── purchaseItems()
    └── Purchase farm products
```

---

## Main Structures

### `User`

The `User` structure is responsible for authentication and authorization.

It contains:

```c
username
password
isAdmin
```

The structure also supports approval-related information for controlling system access.

---

### `UserRequest`

The `UserRequest` structure handles registration requests for new users.

It contains:

```c
username
password
```

It is used specifically for users who are requesting registration.

---

### `farm`

The `farm` structure is the primary structure of the application.

It stores information related to individual farms, including agricultural production and livestock information.

Example information includes:

```text
Farm Name
Farmer Name
Phone Number
Crop Types
Production Quantity
Chicken Breeds
Cow Breeds
Fish Types
Milk Quantity
Egg Quantity
```

The project requirements explicitly identify these types of farm information.

---

## ⚙️ Main Functions

### `interface()`

Displays the introductory interface of the application.

It provides:

* A graphical/ASCII representation of a tractor
* Welcome message
* Contributor acknowledgment

It serves as the starting interface for the Agricultural Management System.

---

### `addFarm()`

```c
void addFarm(struct farm f[], int *numFarms, int maxSize);
```

Adds a new farm to the system.

The function collects information such as:

* Farm name
* Farmer name
* Phone number
* Crop types
* Production quantity
* Livestock breeds
* Other farm information

It also checks whether the farm array has reached its maximum capacity.

---

### `viewFarms()`

```c
void viewFarms(struct farm f[], int numFarms);
```

Displays detailed information for all existing farms.

---

### `searchFarm()`

```c
void searchFarm(
    struct farm f[],
    int numFarms,
    const char *name
);
```

Searches for a farm using its name.

If the farm exists, its information is displayed. If no matching farm is found, the user receives an appropriate notification.

---

### `deleteFarm()`

```c
void deleteFarm(
    struct farm f[],
    int *numFarms,
    const char *name
);
```

Deletes a farm from the system.

The function checks administrator privileges before performing the deletion.

---

### `writeFarmDataToFile()`

```c
void writeFarmDataToFile(
    struct farm f[],
    int numFarms
);
```

Writes farm information to:

```text
farm_data.dat
```

This provides persistent storage for farm records.

---

### `readFarmDataFromFile()`

```c
void readFarmDataFromFile(
    struct farm f[],
    int *numFarms,
    int maxSize
);
```

Reads previously stored farm information from:

```text
farm_data.dat
```

The information is then loaded into the farm array when the program starts.

---

### `userLogin()`

```c
int userLogin(
    struct User users[],
    int numUsers,
    char *username,
    char *password
);
```

Handles user authentication by checking the provided username and password against registered users.

---

### `purchaseItems()`

```c
void purchaseItems(struct farm *Farm);
```

Allows users/customers to purchase products from farms.

The function also calculates the total purchase cost.

---

## System Workflow

```text
                         ┌────────────────────┐
                         │ Start Application  │
                         └──────────┬─────────┘
                                    │
                                    ▼
                         ┌────────────────────┐
                         │ Welcome Interface  │
                         └──────────┬─────────┘
                                    │
                                    ▼
                         ┌────────────────────┐
                         │    Login / Menu    │
                         └──────────┬─────────┘
                                    │
                   ┌────────────────┼────────────────┐
                   │                │                │
                   ▼                ▼                ▼
              Admin Login      User Login       Registration
                   │                │                │
                   ▼                ▼                ▼
             Admin Access      User Access     Submit Request
                   │                │                │
          ┌────────┼────────┐       │                ▼
          │        │        │       │          Admin Approval
          ▼        ▼        ▼       │                │
        Add      Search   Delete    │                ▼
        Farm      Farm     Farm     │          Approved User
          │        │        │       │
          └────────┼────────┘       │
                   │                │
                   ▼                ▼
              Farm Data       Purchase Products
                   │                │
                   └───────┬────────┘
                           ▼
                    File Persistence
```

---

## Technologies Used

* **C**
* **Structures**
* **Arrays**
* **Functions**
* **File I/O**
* **String Manipulation**
* **Menu-driven Programming**
* **Role-based Access Control**

---

## Libraries Used

The project uses three standard C libraries.

| Library    | Purpose                                           |
| ---------- | ------------------------------------------------- |
| `stdio.h`  | Standard input/output operations                  |
| `stdlib.h` | Standard library and memory-related functionality |
| `string.h` | String and character-array manipulation           |

The project report specifically identifies these as the libraries used by the application.

---

## Authentication

The system provides username/password authentication with administrator and regular-user roles.

### Sample Accounts

The project report provides the following credentials for testing:

| Role          | Username | Password   |
| ------------- | -------- | ---------- |
| Administrator | `admin`  | `admin123` |
| User          | `user1`  | `user123`  |
| User          | `user2`  | `user456`  |

> **Security Note:** These credentials are included as academic/demo credentials from the project report. Do not use real passwords or sensitive credentials in a production environment.

---

## User Interface

The system uses a simple **text-based, menu-driven interface**.

The interface includes:

* Welcome message
* ASCII/graphical tractor representation
* Contributor acknowledgment
* Menu options
* Login and logout functionality
* Farm management operations
* Purchasing operations

The project report describes the interface as text-based while also including graphical elements in the welcome section.

---

## How to Run

### Prerequisites

Install a C compiler such as:

* GCC
* Clang
* MinGW
* Any standard C compiler

Check GCC:

```bash
gcc --version
```

---

### Clone the Repository

```bash
git clone https://github.com/your-username/your-repository-name.git
```

Navigate into the project:

```bash
cd your-repository-name
```

---

### Compile

If the source file is named `main.c`:

```bash
gcc main.c -o agricultural_management
```

---

### Run

#### Linux / macOS

```bash
./agricultural_management
```

#### Windows

```bash
agricultural_management.exe
```

> **Note:** The exact compilation command may need to be adjusted according to the source-file names and project structure in the repository.

---

## Data File

The application uses:

```text
farm_data.dat
```

to persist farm information.

A typical repository structure could look like:

```text
Agricultural-Management-System/
│
├── main.c
├── farm_data.dat
├── README.md
└── ...
```

If `farm_data.dat` is generated automatically by the application, it does not necessarily need to be committed to GitHub.

---

## Data Persistence

The application follows this general process:

```text
Program Starts
      │
      ▼
Read farm_data.dat
      │
      ▼
Load Farm Records
      │
      ▼
User Operations
      │
      ├── Add Farm
      ├── Search Farm
      ├── View Farms
      ├── Delete Farm
      └── Purchase Products
      │
      ▼
Update Farm Data
      │
      ▼
Write to farm_data.dat
```

This ensures that farm information can remain available between different program sessions.

---

## Error Handling

The project includes basic error handling for situations such as:

* Farm not found
* File operation problems
* Invalid input scenarios

The project report also records several issues encountered during development, including:

* String input errors
* Statement issues
* Search printing issues
* Purchasing malfunction

---

## Concepts Demonstrated

This project demonstrates several fundamental C programming concepts:

### Structures

Used to organize:

* User information
* Registration requests
* Farm information

### Functions

The system is divided into dedicated functions for individual operations such as adding, searching, deleting, reading, writing, logging in, and purchasing.

### Arrays

Farm and user records are managed using arrays.

### Pointers

Pointers are used in functions that need to modify values such as the number of farms.

Example:

```c
int *numFarms
```

### File I/O

Farm data is stored and retrieved using file operations.

### String Handling

The `string.h` library is used for working with usernames, farm names, and other character arrays.

### Conditional Logic

Role-based authorization and system decisions rely on conditional statements.

### Menu-Driven Programming

Users interact with the application by selecting options from menus.

---

## System Requirements

The system requirements described in the project include:

### User Authentication

* Different user roles
* User login
* Additional administrator privileges

### Farm Management

* Add farm information
* Search farms
* View farms
* Delete farms

### Purchase System

* Purchase chickens
* Purchase cows
* Purchase fish
* Purchase eggs
* Purchase milk
* Calculate purchase costs

### Registration

* Submit registration requests
* View registration requests
* Approve registrations

### File I/O

* Store farm data persistently
* Read stored farm data

### Interface

* User-friendly menu
* ASCII/visual elements
* Welcome interface

### Security

* Secure handling of credentials and sensitive information

### Session Control

* Logout
* Exit program

---

## Future Improvements

The project identifies several possible improvements.

### Increase Farm Capacity

The current farm capacity could be increased to support more farm records.

### Expand Product Catalog

Additional agricultural products could be made available for customers.

### Improve Purchasing System

The purchasing functionality could be further developed and refined.

### Add Reports / Reviews

A reporting or review system could be introduced for farms and/or purchases.

### Improve Security

The authentication and credential-handling mechanisms could be strengthened.

Potential future security improvements include password hashing.

###  Graphical User Interface

A dedicated GUI could replace or complement the current text-based interface.

### Bug Fixes

Existing issues related to input handling, searching, printing, and purchasing can be addressed in future versions.

---

## Screenshots

For screenshots of workflow check out the report pdf


## License

This project was developed for **academic and educational purposes**.

