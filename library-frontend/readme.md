# Library Management System - DSA Project

## Overview

This is a comprehensive Library Management System project developed for DSA (Data Structures and Algorithms) summer training using C++. The project demonstrates the practical application of various data structures and algorithms in a real-world scenario.

## Project Structure

```
library_project_final/
├── main.cpp                      # Core C++ implementation
├── library_system                # Compiled executable
├── README.md                     # This file
├── problem_statement.md          # Problem statement document
├── system_architecture.md        # System architecture document
├── dsa_techniques.md             # DSA techniques document
├── algorithms_pseudocode.md      # Algorithms and pseudocode document
├── test_dataset.md               # Dataset and evaluation metrics document
├── project_file.md               # Complete project documentation
├── todo.md                       # Project progress tracking
├── library-frontend/             # React frontend implementation
│   ├── src/
│   │   ├── App.jsx               # Main React component
│   │   └── ...                   # Other components and assets
│   ├── package.json              # Dependencies
│   └── ...                       # Configuration files
└── library_presentation/         # Presentation slides
    ├── title_slide.html
    ├── problem_statement.html
    ├── dsa_techniques.html
    ├── system_architecture.html
    ├── algorithms.html
    ├── frontend.html
    ├── evaluation.html
    ├── conclusion.html
    └── images/                   # Presentation images
```

## Features

### Core Functionality
- **Add Book**: Add new books with title, author, pages, price, and ISBN
- **Display Books**: View all books in the library
- **Search by Author**: Find all books by a specific author
- **Count Books**: Get the total number of books in the library
- **Delete Book**: Remove books by ISBN
- **Sort Books**: Sort books by title or author

### Frontend Features
- **Dashboard**: Overview with library statistics
- **Book Browser**: Search and filter functionality
- **Add Book Form**: User-friendly input interface
- **Analytics**: Visual representation of library data

## Technologies Used

- **C++**: Core backend implementation
- **React**: Frontend user interface
- **Tailwind CSS**: Styling framework
- **shadcn/ui**: UI component library
- **Chart.js**: Data visualization

## Data Structures and Algorithms

### Data Structures
- **Vector/Array**: Primary storage for book collection
- **Hash Map**: ISBN-based lookups for O(1) access time
- **Linked List**: Alternative for dynamic collections

### Algorithms
- **Linear Search**: Finding books by author or title
- **Binary Search**: For sorted collections
- **Sorting Algorithms**: std::sort (IntroSort) for organizing books
- **Hash-based Search**: Efficient lookups using hash tables

### Time Complexity
- Add Book: O(1)
- Display Books: O(n)
- Search by Author: O(n)
- Count Books: O(1)
- Delete Book: O(n)

## How to Run

### Backend (C++)

```bash
# Compile the C++ code
g++ main.cpp -o library_system

# Run the executable
./library_system
```

### Frontend (React)

```bash
# Navigate to the frontend directory
cd library-frontend

# Install dependencies (if not already installed)
pnpm install

# Start the development server
pnpm run dev --host
```

The frontend will be available at `http://localhost:5173/`

## Testing

The system has been thoroughly tested with:
- **Functional Testing**: All core operations verified
- **Performance Testing**: Response times measured
- **User Experience Testing**: Frontend usability confirmed
- **Data Integrity Testing**: Input validation and error handling

## Evaluation Results

- ✅ All core functionalities working correctly
- ✅ Performance meets expected benchmarks
- ✅ User interface is responsive and intuitive
- ✅ Code follows best practices and is well-documented

## Future Enhancements

1. **Database Integration**: Replace in-memory storage with persistent database
2. **User Authentication**: Add user accounts and permissions
3. **Borrowing System**: Implement book borrowing and return functionality
4. **Advanced Search**: Add more search criteria and filters
5. **Barcode Integration**: Support for scanning book barcodes
6. **Mobile App**: Native mobile application
7. **API Development**: RESTful API for third-party integrations

## Documentation

- **Problem Statement**: Detailed project requirements and objectives
- **System Architecture**: Component breakdown and design decisions
- **DSA Techniques**: Explanation of data structures and algorithms used
- **Algorithms & Pseudocode**: Detailed algorithm implementations
- **Dataset & Evaluation**: Test data and performance metrics
- **Presentation**: Complete slide deck for project showcase

## Author

This project was developed as part of the DSA summer training program, demonstrating practical application of data structures and algorithms in software development.

## License

This project is for educational purposes as part of the DSA summer training program.

