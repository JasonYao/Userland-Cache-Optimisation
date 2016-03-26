# CSCI-UA-201: Computer Systems Organisation, Project 2: Cache Optimisation
By Jason Yao

## Description
A programme to show a deeper understanding of C optimisation in relation
to the underlying hardware specifications. Specifically, this means optimising 
programmes to minimise cache "cache misses", which can cause delays
when executing code, due to the processor then having to either go to a 
lower cache, or even to memory to retrieve the data it requires.

Date: Spring, 2015

Location: New York University

Professor: Dr. Mohamed Zahran

Language(s): C (On another note, if ever chatting with Dr.Zahran, ask him about his feelings on Java)

## Executing steps
### Compilation
```sh
gcc -g optimised.c -o optimised
```

## Execution with timing information from val/cachegrind
```sh
valgrind --tool=cachegrind  --D1=32768,4,64 --cachegrind-out-file=cache.trace ./optimised
cg_annotate cache.trace
```

## Project Outcomes
- Executed C programmes completely from the commandline

- Learned cache profiling with `valgrind` (specifically `cachegrind`)

- Learned C optimisation tweaks in order to maximise programme efficiency

- Learned about cache hierarchy and types of locality, including:
	- Spatial locality (data near your original data will be copied, up to a full bus-width)
	- Temporal locality (data recently referenced are going to be in cache)

## Final report & conclusions
Please see the [reports](report/report.md) section for the final analysis.
For a pdf version of this text, please click [here](report/report.pdf)

## License
This repo is licensed under the GNU GPL v3, a copy of which may be found [here](LICENSE)
