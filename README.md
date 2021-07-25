# Casino Demo
A simple game about about a casino, where you can insert, remove or spend credits to see cars in multiple colors

## Dependencies
* **[SDL2](https://www.libsdl.org/)** - A library for managing computer multimedia hardware components
* **[SDL_image](https://www.libsdl.org/projects/SDL_image/)** - An image file loading library
* **[SDL_mixer](https://www.libsdl.org/projects/SDL_mixer/)** - A sample multi-channel audio mixer library
* **[SDL_ttf](https://www.libsdl.org/projects/SDL_ttf/)** - A sample library to use TrueType fonts in SDL applications
## How to run

The executable can be found in the root of the project's directory.

First be sure to have all the dependencies installed. For example, in debian-based operating systems (like Ubuntu), you can do that with:

```bash
sudo apt install libsdl2-2.0-0 libsdl2-image-2.0-0 libsdl2-mixer-2.0-0 libsdl2-ttf-2.0-0
```

To run the executable of the game, this can be done in the root of the project's directory with the command:

```bash
./CasinoDemo
```

## How to compile

All the instructions describred in this section are related to debian-based operating systems (like Ubuntu). Other linux distributions use other package managers, instead of `apt`.

First, it is required to install the build tools and the compilers:

```bash
sudo apt install g++ make cmake
```

Install all the development dependencies:

```bash
sudo apt install libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev libsdl2-ttf-dev
```

Generate the `Makefile` using `cmake`:

```bash
cmake -B build
```

Compile the executable:

```bash
cmake --build build
```

And the executatble will be generated, in the root of the project, with the name `CasinoDemo`.

To simplify, you can run the following script to generate the `Makefile`, compile the game and run it:

```bash
bin/run
```