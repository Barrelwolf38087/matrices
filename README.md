# matrices
A little thing with matrices I'm working on for fun.

## Features
The goal of this project is to make using matrices in code intuitive and to check the validity of
operations at compile time wherever possible. For example, you cannot assign a `matrix<int, 2, 3>`
to a `matrix<int, 3, 3>`. I aim to extend this functionality to operations like multiplication.

Because the type of the data in a matrix is a template argument, it is also possible to create matrices of
custom types.

As you may have noticed, this way of dealing with matrices prevents them from having sizes determined at runtime.
At some point, I plan on adding a second type of matrix to address this problem.

## Installation
Add this repository as a git submodule to your project:
`$ git submodule add https://github.com/Barrelwolf38087/matrices.git`

Add the following two lines to your CMakeLists.txt:
```cmake
add_subdirectory(matrices)
target_link_libraries(${PROJECT_NAME} matrices)
```

## Usage
A basic example:

```c++
#include <iostream>
#include <matrix.hpp>

int main() {
    matrix<int, 3, 3> mat{};

    mat[0][1] = 2;

    mat.print();

    auto dmat = mat.as<double>();

    dmat[0][2] = 2.5555;

    dmat.print();

    std::cout << "left mid: " << dmat[0][1] << std::endl;
    std::cout << "left bottom: " << dmat[0][2] << std::endl;
    std::cout << "size: " << dmat.rows() << " x " << dmat.cols() << std::endl;

    return 0;
}
```
