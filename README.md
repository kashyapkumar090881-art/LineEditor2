# Simple Line Editor in C

## Project Description

A simple command-line line editor developed in C.

The editor allows users to create, view, modify, save, and load a small text document through terminal commands.

## Data Structure

The program uses a 2D character array:

```c
char document[MAX_LINES][MAX_LENGTH];
```

An array was chosen because the document is small and accessing lines by their number is simple. Insertion and deletion are implemented by shifting existing lines.

## Features Implemented

* Insert a line
* Delete a line
* Display the document
* Save document to a text file
* Load document from a text file
* Invalid input handling

## Technologies

* C
* GCC
* VS Code
* GitHub

## Team Members

1. KASHYAP KUMAR M GHATKE
2. KARTHIK K.S

## How to Compile

Open the terminal in the project folder and run:

```cmd
gcc main.c -o lineeditor
```

## How to Run

On Windows:

```cmd
.\lineeditor.exe
```

## Project Files

```text
LineEditor/
│
├── main.c
├── HELP.md
├── README.md
└── document.txt
```

## Example

```text
1. Insert Line
2. Delete Line
3. Display Document
4. Save Document
5. Load Document
6. Exit
```
