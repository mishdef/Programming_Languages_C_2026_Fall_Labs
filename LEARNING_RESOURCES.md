# C Learning Resources on GitHub (as of September 2025)

This page lists useful GitHub repositories for learning and practicing C programming.  
Each resource includes a description and a suggested difficulty level.

---

## Repository Table

| Repository                                                                                                              | Description                                                                                                               | Difficulty              |
| ----------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------- | ----------------------- |
| [CodeWithHarry / The-Ultimate-C-Programming-Course](https://github.com/CodeWithHarry/The-Ultimate-C-Programming-Course) | A structured course with chapters, practice sets, and project code. Good for beginners who want guided progression.       | Beginner                |
| [nCally / Project-Based-Tutorials-in-C](https://github.com/nCally/Project-Based-Tutorials-in-C)                         | A collection of tutorials building projects in C (from small programs to advanced topics like emulators and OS concepts). | Intermediate → Advanced |
| [sbccas / c-programming-tutorials](https://github.com/sbccas/c-programming-tutorials)                                   | Tutorials, assignments, and sample programs covering basics and intermediate C programming concepts.                      | Beginner → Intermediate |
| [h0mbre / Learning-C](https://github.com/h0mbre/Learning-C)                                                             | A repository of small programs and exercises created while learning C. Shows practical learning progress.                 | Beginner                |
| [mcinglis / c-style](https://github.com/mcinglis/c-style)                                                               | A C style guide with best practices for readability, maintainability, and consistent coding.                              | All Levels              |
| [ShravanDalavi / CProgrammingProjects](https://github.com/ShravanDalavi/CProgrammingProjects)                           | A set of projects and algorithmic exercises implemented in C. Useful for practice and inspiration.                        | Intermediate            |

---

## Suggested Learning Path

1. **Start Here (Beginner):**
    - [CodeWithHarry / The-Ultimate-C-Programming-Course](https://github.com/CodeWithHarry/The-Ultimate-C-Programming-Course)
    - [h0mbre / Learning-C](https://github.com/h0mbre/Learning-C)

2. **Next Steps (Beginner → Intermediate):**
    - [sbccas / c-programming-tutorials](https://github.com/sbccas/c-programming-tutorials)
    - Practice writing small programs and algorithms.

3. **Level Up (Intermediate → Advanced):**
    - [nCally / Project-Based-Tutorials-in-C](https://github.com/nCally/Project-Based-Tutorials-in-C)
    - [ShravanDalavi / CProgrammingProjects](https://github.com/ShravanDalavi/CProgrammingProjects)

4. **Always Useful:**
    - [mcinglis / c-style](https://github.com/mcinglis/c-style) – Follow this style guide throughout your learning.

---

💡 **Tip:** Don’t just read the code — clone the repositories, compile, run, and try modifying the programs yourself!

## 1. Basic Template & Command Line Arguments

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // argc - argument count (minimum 1 - the program name itself)
    // argv[0] - path to the program (e.g., ./program)
    // argv[1] - first passed argument (it's a string!)

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE; // or return 1;
    }

    // Converting an argument string to a number:
    int num = atoi(argv[1]);
    float fnum = atof(argv[2]);

    return EXIT_SUCCESS; // or return 0;
}
```

````

---

## 2. Input/Output (I/O) & Data Validation

### Format Specifiers (`printf` / `scanf`)

| Specifier | Data Type          | Example   | Notes                                       |
| --------- | ------------------ | --------- | ------------------------------------------- |
| `%d`      | `int`              | `42`      | Integer                                     |
| `%u`      | `unsigned int`     | `42`      | Unsigned integer                            |
| `%f`      | `float` / `double` | `3.14`    | Use `%lf` for `double` in `scanf`           |
| `%.2f`    | `float` / `double` | `3.14`    | Round to 2 decimal places (only for printf) |
| `%c`      | `char`             | `'A'`     | Single character                            |
| `%s`      | `char[]`           | `"Hello"` | String (stops at the first space)           |
| `%49s`    | `char[50]`         |           | Length limit (prevents buffer overflow)     |
| `%[^,]`   | `char[]`           | `"Alice"` | Read everything UNTIL a comma (Scanset)     |

### Safe Input (Reading from keyboard)

**Number validation:**

```c
int n;
printf("Enter a number: ");
if (scanf("%d", &n) != 1) {
    printf("Invalid input!\n");
    return 1; // Exit or handle error
}
```

**Clearing the input buffer (if `scanf` fails or before `fgets`):**

```c
int ch;
while ((ch = getchar()) != '\n' && ch != EOF) { }
```

**Safe string reading with spaces (`fgets`):**

```c
char line[256];
printf("Enter a string: ");
if (fgets(line, sizeof(line), stdin) != NULL) {
    // Remove the trailing '\n' added by fgets
    line[strcspn(line, "\n")] = '\0';
}
```

---

## 3. Arrays & Pointers

### Pass by Reference (Modifying variables inside a function)

```c
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
// Function call: swap(&x, &y);
```

### Standard Array Algorithms

```c
int array_sum(const int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) sum += arr[i];
    return sum;
}

int array_max(const int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}
```

---

## 4. Strings

A string in C is just an array of characters ending with a null-terminator `'\0'`.

### Manual String Handling (without `<string.h>`)

```c
// Find string length
int my_strlen(const char *str) {
    int len = 0;
    while (str[len] != '\0') len++;
    return len;
}

// Copy string from src to dest
void my_strcpy(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; // NEVER FORGET to add the null-terminator!
}
```

---

## 5. Structures (Structs)

```c
#define MAX_NAME 50

typedef struct Student {
    char name[MAX_NAME];
    int id;
    float gpa;
} Student;

// Zero-initialisation (crucial so unused bytes aren't garbage in binary files)
Student s1 = {0};
strcpy(s1.name, "Alice");
s1.id = 101;
s1.gpa = 3.5;

// Accessing fields via pointer
void print_student(const Student *s) {
    printf("Name: %s, ID: %d, GPA: %.2f\n", s->name, s->id, s->gpa);
}
```

---

## 6. Dynamic Memory (`malloc` / `free`)

Used when the array size is unknown at compile time (e.g., entered by the user).

```c
int n = 10;
// Allocate memory for an array of n elements
int *arr = malloc(n * sizeof(int));
// Or for structs: Student *students = malloc(n * sizeof(Student));

// ALWAYS check for NULL after allocation
if (arr == NULL) {
    printf("Memory allocation failed.\n");
    return 1;
}

// Use it like a normal array
arr[0] = 42;

// ALWAYS free the memory when done
free(arr);
```

---

## 7. File I/O

### Text Files (Writing) - Mode `"w"`

```c
FILE *fp = fopen("data.txt", "w");
if (fp == NULL) {
    perror("Error opening file");
    return 1;
}
fprintf(fp, "%s,%d,%.2f\n", "Bob", 123, 3.8);
fclose(fp);
```

### Text Files (Reading & Parsing CSV) - Mode `"r"`

The safest way is to read a whole line with `fgets`, then parse it with `sscanf`.

```c
FILE *fp = fopen("data.txt", "r");
if (fp == NULL) return 0; // File does not exist yet

char line[256];
Student s;

while (fgets(line, sizeof(line), fp) != NULL) {
    // Parse format "Name,ID,GPA". [^,] means read everything up to the comma.
    if (sscanf(line, "%49[^,],%d,%f", s.name, &s.id, &s.gpa) == 3) {
        printf("Loaded: %s, %d, %.2f\n", s.name, s.id, s.gpa);
    }
}
fclose(fp);
```

### Binary Files (Writing / Reading) - Modes `"wb"` / `"rb"`

Writes/reads the actual memory block (`struct`) directly to/from disk.

```c
// WRITING (wb)
FILE *fp = fopen("data.bin", "wb");
if (fp != NULL) {
    // Write 1 element of size sizeof(Student) from address &s
    fwrite(&s, sizeof(Student), 1, fp);
    fclose(fp);
}

// READING (rb)
FILE *fp2 = fopen("data.bin", "rb");
if (fp2 != NULL) {
    fread(&s, sizeof(Student), 1, fp2);
    fclose(fp2);
}
```

### Get File Size in Bytes

```c
long get_file_size(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) return -1;

    fseek(fp, 0, SEEK_END); // Jump to the end of the file
    long size = ftell(fp);  // Get current position (which equals the size)
    fclose(fp);

    return size;
}
```
````
