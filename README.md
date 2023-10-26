# Convex Hull Algorithm
This program creates the convex hull from given set of points using [Graham Scan algorithm](https://en.wikipedia.org/wiki/Graham_scan). The algorithm works as on gif below:  
 ![](https://upload.wikimedia.org/wikipedia/commons/7/71/GrahamScanDemo.gif)  
By Shiyu Ji - Own work, CC BY-SA 4.0, https://commons.wikimedia.org/w/index.php?curid=54390512

## About code
The custom `Point` struct which is used to store points, is implemented using templetes. The `convex_hull::convexHull` function which uses `Points` (vector of `Point`) as an argument was also made generic usig templates. So all the code is in [include](include) directory in header files.  

The algorithm was implemented by mostly using iterators and functions from `<algorithm>` std library.

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
