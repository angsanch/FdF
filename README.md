# FdF

Tridimensional representation of a grid of points using the isometric proyection.

Project for the main 42 cursus.

### Description

The goal of FdF is to create a simple 3D wireframe renderer from a 2D heightmap. The program reads a file containing numerical values, where each number represents an elevation point. These points are then projected into a 3D space and connected with lines to form a wireframe mesh.

## Getting Started

### Dependencies

- [Linux](https://linux.org/)
- [Make](https://www.gnu.org/software/make/)
- [GCC](https://gcc.gnu.org/)
- [Python](https://python.org)
- [MLX42](https://github.com/codam-coding-college/MLX42)

### Installation

* Download/Clone the repository and enter its directory
* Download the mlx and my lib with `git submodule update --init libft minilibx`
* Install the MLX dependencies, check their [documentation](https://github.com/codam-coding-college/MLX42/blob/master/README.md#installation-%EF%B8%8F)
* Compile the code typing `make`

## Usage

**Execution:**

Only the path to the file containing the map is necessary.

```bash
./fdf path/to/file.fdf
```

### Controls
- `Z` -> Zoom in
- `C` -> Zoom out
- Arrow keys -> Move the model
- Mouse scroll -> Change Z multiplier (altitude scaling)

### Arguments

- file path: A simple path to the file containing all the information.

### Examples

```bash
./fdf maps/pylone.fdf
```

### File format

FDF files store elevation data as a grid of numbers, where each value corresponds to the height (Z-coordinate) of a point in a 2D plane (X, Y)

#### Example pyramid

```fdf
0   0   0   0   0
0  10  10  10   0
0  10  20  10   0
0  10  10  10   0
0   0   0   0   0
```

#### Color support

Optionally, heights can include hex color codes (e.g., 0xRRGGBB) after a comma

```fdf
0,0xFF0000   0,0x00FF00   0,0x0000FF
10,0xFFFF00  20,0xFF00FF  10,0x00FFFF
```

## Innerworkings

### Parser

Simple parser that reads the file and builds the grid. The parser is only designed to create grids, but the other parts of the proyect are able to represent any set of points joined by any bond.

### FDF

This is the center of the program, it feeds the information gotten from the parser to the engine. The 3D magic happens here.

### Engine

This warps arround the MLX to make it easier to deal with. Draws everything on the screen.
Manages all the hooks providing an unified call, allowing you to have a single function triggered by different kinds of events.

## Acknowledgments

* [42Madrid](https://www.42madrid.com/)
* [Codam](https://github.com/codam-coding-college/)

## Authors

* **Daniel Sanchez** ([GitHub](https://github.com/angsanch) / [LinkedIn](https://www.linkedin.com/in/angeldanielsanchez/))

## License

This project is licensed under the GNU Public License version 3.0 - see the [LICENSE](LICENSE) file for details.
