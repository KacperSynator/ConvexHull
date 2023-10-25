# pwr-racing-entry

### Build
To build the project use CMake:
```bash
mkdir build
cd build
cmake ..
make
```

### Run
The application takes one optional argument, the filepath to the data file. 
If the path is not given the program will ask for filepath. One data file is included in [data.txt](data/data.txt).
```bash
# in build folder
./convex_hull [path_to_data]
```

#### Examples:
```bash
# Filepath not given as argument
./convex_hull
Filepath not given, please enter filepath: ../data/data.txt
Convex hull points: [(4, -1), (5, 3), (2, 3), (-1, 2), (1, 0)]
```
```bash
# Filepath given as argument
./convex_hull ../data/data.txt
Convex hull points: [(4, -1), (5, 3), (2, 3), (-1, 2), (1, 0)]
```
