# CS121 Student Data — Part 1

## Progress
This week I designed three classes: `Address`, `Date`, and `Student`. I completed and tested the Address and Date implementations. I also implemented Student ahead of schedule using the supplied sample CSV record. Reading a CSV file from disk and creating a user interface are left for next week.

## Design
- **Address** stores street, city, state, and ZIP code as strings (ZIP codes may begin with zero).
- **Date** stores month, day, and year as integers. It accepts a date string and prints a readable date.
- **Student** will own one Address and two Date objects, plus first name, last name, and completed credit hours.
- The diagram is in `UML.md`.

## Algorithms / pseudocode

### Address.init(street, city, state, zip)
1. Assign each parameter to the corresponding private data member.

### Address.printAddress()
1. Print street followed by a newline.
2. Print city, space, state, comma, space, ZIP code, and newline.

### Date.init(dateText)
1. Create an input stream from the date string.
2. Read month, slash, day, slash, and year.
3. Reject missing values, extra characters, or incorrect separators.
4. Reject invalid months or years.
5. Determine the maximum number of days for the month, including leap-year February.
6. Reject invalid days.
7. Save month, day, and year to the object.

### Date.printDate()
1. Use the month number to find its name in a month-name array.
2. Print month name, space, day, comma, space, year, and newline.

### Student.init(csvLine)
1. Split the CSV line into its nine fields.
2. Store first and last name.
3. Initialize the Address object from street, city, state, ZIP.
4. Initialize the birth and graduation Date objects.
5. Convert completed credit hours to an integer.

### Student.printStudent()
1. Print first and last name.
2. Print the student's Address.
3. Print the birth date after `DOB: ` and graduation date after `Grad: `.
4. Print completed credit hours and a separator line.

### Student.getLastFirst()
1. Return last name, comma, space, first name.

## Build and test
Run `make` to compile and `make run` to execute. `make debug` opens GDB (if installed); `make valgrind` checks memory (if installed); `make clean` removes compiled files.

Expected output from the supplied sample test:
```
Hello!
January 27, 1997
123 W Main St
Muncie IN, 47303
Danielle Johnson
32181 Johnson Course Apt. 389
New Jamesside IN, 59379
DOB: February 17, 2004
Grad: May 15, 2027
Credits: 65
________________________________________

Johnson, Danielle
```

## Extra effort
The Date class checks invalid dates and leap years, rather than only splitting strings. For example, February 29 is accepted in 2024 but rejected in 2023. Invalid input throws `std::invalid_argument`.

## Next steps
Add reading multiple students from a CSV file and a user interface in the next part. The Student class, its test, and its Makefile object target are already implemented.
