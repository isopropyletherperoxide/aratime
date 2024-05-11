## Aratime 

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
(In the root directory of the repository)

```bash 
make && sudo make install
```

#### Kernel Module 
Optionally, there is a kernel module provided that makes the program unkillable even with ``sudo``. To compile it run ``make`` in the ``kernel`` folder (**Linux headers required!**). Load the module with ``insmod process.ko`` after launching ``aratime``. This has been tested to work on Kernel 6.6.21 only and I do not take any responsibility for anything that may happen.   




