# 0x16. C - Simple Shell

This is the 0x16. C - Simple Shell project for ALX, created by Hanafy Mouhcine and Yassine Mansouri.

## Table of Contents

- [Description](#description)
- [Features](#features)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Built-in Commands](#built-in-commands)
- [Project Structure](#project-structure)
- [Contributing](#contributing)
- [License](#license)

## Description

The 0x16. C - Simple Shell project is a small-scale implementation of a Unix-like shell. It reads user input, parses the input, and executes the requested commands.

## Features

- Basic command execution
- Built-in command support (e.g., `cd`, `exit`)
- Command history
- Environment variable handling
- Signal handling
- Error handling

## Getting Started

1. Clone this repository: `git clone <repository_url>`
2. Compile the shell: `make`
3. Run the shell: `./simple_shell`

## Usage

The shell provides a command-line interface where you can enter commands. It supports both built-in commands and external commands. You can use the `cd` command to change directories, and the `exit` command to exit the shell.

## Built-in Commands

The shell supports the following built-in commands:

- `cd [directory]`: Change the current directory.
- `exit [status]`: Exit the shell.

## Project Structure

The project is organized into the following files:

- `shell.h`: Header file containing function prototypes and structures.
- `main.c`: Entry point of the shell.
- `builtin.c`: Implementations of built-in commands.
- `parser.c`: Functions for parsing user input.
- `executor.c`: Functions for executing commands.
- `utils.c`: Utility functions (e.g., string manipulation).
- `history.c`: Functions for handling command history.
- `variables.c`: Handling environment variables and variables.
- `path.c`: Functions for handling the PATH environment variable.
- `signals.c`: Signal handling.
- `error_handling.c`: Error handling functions.
- `Makefile`: Build script for compiling the shell.
- `README.md`: Description and usage instructions.

## Contributing

Contributions to this project are welcome! Feel free to fork the repository, make changes, and submit a pull request.
