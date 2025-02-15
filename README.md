# Library Management in C

This project is a library management application implemented in C, using a hash table to efficiently store and manage books.

## Features
- Add a book to the library
- Delete a book
- Search for a book by its name
- Display all registered books
- Load and save books from a file

## Project Structure

```
|-- src/
|   |-- gestionlivre.c  # Function implementations
|   |-- gestionlivre.h  # Header file
|-- data/
|   |-- books.txt       # File containing books
|-- main.c              # Main program
|-- README.md           # Project documentation
|-- Makefile            # Project compilation
```

## Compilation and Execution
### Prerequisites
- A C compiler (GCC recommended)

### Compilation
Run the following command to compile the project:
```sh
make
```

### Execution
Once compiled, run the program with:
```sh
./gestion_bibliotheque <filename>
```
where `<filename>` is the file containing the books to load at program startup.

## Usage
1. **Add a book**: Enter the book's name, author, genre, and year.
2. **Search for a book**: Enter the book's name to check its availability.
3. **Delete a book**: Provide the book's name to remove it from the library.
4. **Save changes**: Books can be saved in a text file for future use.

## Contribution
Contributions are welcome! You can:
- Report a bug
- Suggest improvements
- Add new features

## License
This project is licensed under the MIT License. You are free to use it as long as you comply with the terms of the license.
