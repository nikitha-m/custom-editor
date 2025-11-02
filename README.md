# Custom Editor

A custom text editor built with C++.

## Requirements

- CMake 3.16 or higher
- C++17 compatible compiler (GCC, Clang, or MSVC)

## Building

### Quick Build

```bash
mkdir build
cd build
cmake ..
make
```

### Build Options

- **Release build** (optimized):
  ```bash
  mkdir build
  cd build
  cmake -DCMAKE_BUILD_TYPE=Release ..
  make
  ```

- **Debug build** (with debug symbols):
  ```bash
  mkdir build
  cd build
  cmake -DCMAKE_BUILD_TYPE=Debug ..
  make
  ```

- **With tests**:
  ```bash
  mkdir build
  cd build
  cmake -DBUILD_TESTS=ON ..
  make
  ```

## Running

After building, the executable will be located at `build/bin/custom-editor`:

```bash
./build/bin/custom-editor
```

## Project Structure

```
custom-editor/
├── CMakeLists.txt          # Main CMake configuration
├── src/
│   ├── CMakeLists.txt      # Source CMake configuration
│   └── main.cpp            # Main application entry point
├── include/                # Header files
├── tests/                  # Test files (optional)
└── README.md              # This file
```

## Development

- Add new source files to `src/CMakeLists.txt`
- Add header files to the `include/` directory
- Use `include_directories(include)` in CMakeLists.txt to include headers
