# starter-sdlcpp
A template for starting c++ project for linux/windows using CMake and libsdl.

# compiling for linux
```
mkdir build && cd build && cmake .. && make
```

# compiling for windows (on a linux machine, cross compilation)
```
mkdir build && cd build && cmake .. -DCMAKE_TOOLCHAIN_FILE=../i686-w64-mingw.cmake && make
```

## references
references used.
 - [libsdl](https://lazyfoo.net/tutorials/SDL/)
