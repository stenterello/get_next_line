# Get Next Line

The "get_next_line" repository contains the C implementation of a function called `get_next_line`, which reads a file descriptor and returns a string up to the newline character. This project is part of the projects completed for the Common Core curriculum at 42School and has achieved a score of 125 out of 100. It focuses on the use of static variables, allowing the use of at most one static variable. Additionally, file reading is done using a predefined buffer size.

## Requirements

- Compatible C compiler (e.g., GCC)
- UNIX or Linux operating system

## Usage

1. Clone the repository to your local system:

   ```shell
   git clone https://github.com/stenterello/get_next_line.git

2. Navigate to the main directory of the repository:  

   ```shell
   cd get_next_line

3. Compile the program by running the command:  

   ```shell
   gcc -Wall -Wextra -Werror -D BUFFER_SIZE=<buffer_size> get_next_line.c get_next_line_utils.c -o gnl_test

   Make sure to replace <buffer_size> with the desired buffer size and <test_file.c> with the test file you want to use as main.

4. Run the generated program:  

   ```shell
   ./gnl_test <example_file>


## Description
The "get_next_line" project has been developed as part of the projects completed for the Common Core curriculum at 42School. It enables efficient reading of a file descriptor and extracting a string up to the newline character. The get_next_line function reads the file descriptor provided as a parameter and returns one line at a time until the file is fully read or the newline character is encountered.

The project is based on the use of a static variable to store the data read during subsequent calls to the get_next_line function. This allows the function to resume reading from where it left off previously.

You can use the get_next_line function on multiple file descriptors concurrently by using the bonus file get_next_line_bonus.c. This file provides an advanced version of the get_next_line function that correctly handles static variables for each opened file descriptor.
