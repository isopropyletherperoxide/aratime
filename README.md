### Aratime 

A simple, POSIX-compatible tool that provides a time limit for a running application.

### Usage 

```bash
aratime <time(in_minutes)> proc1 proc2 ... procn
```

#### Example:
Start killing Discord and Firefox after 10 minutes

```bash 
aratime 10 Discord firefox-bin
```

An ``aratime_wrapper`` script is provided, which automatically disowns the process from the shell that called it. 

### Installation 

```bash 
make && sudo make install
```


