# Minishell

First year individual project. A simple shell in C based on TCSH.

## Features

- Handle paths, setenv/unsetenv, builtin cd, and error messages
- Handle semicolons (‘;’), pipes (‘|’), and the four redirections (‘>’, ‘<’, ‘>>’, ‘<<’)
- Has a simple parser to handle operator priority (e.g. `echo hey | cat -e > test; cat test; ls -l`)

## Getting started

Run the project.
```
make && ./mysh
```

You can also send your command like this:
```
echo "command" | ./mysh
```