![workflow status badge](https://github.com/Andyloris/free-physics-engine/actions/workflows/c-cpp.yml/badge.svg)
[![License: GPL v2](https://img.shields.io/badge/License-GPL_v2-blue.svg)](https://www.gnu.org/licenses/old-licenses/gpl-2.0.en.html)
# Free physics engine

Free physics engine (I should find a shorter name) is a lightweight, free and open-source physics engine written in pure C.

## Background

I wanted to write this physics engine when I realised I was missing the part maths played in programming. I was also bored of taking up small, easy projects.

## Objectives

- Keeping every thing as simple as possible while retaining as much functionality
- Keeping integration into other projects as easy as possible
- Keeping every thing organised...
- ...while keeping the code as fast as possible

## Todo

- [ ] Rotational dynamics
- [ ] Collision detecton
- [ ] Writing a simple API
- [ ] Documentation
- [ ] More shapes... (only spheres right now)

## Building

Just clone the project and run make in the directory

```sh
git clone https://github.com/Andyloris/free-physics-engine
cd free-physics-engine
make all
```

You can also run the output with
```sh
make run
```
