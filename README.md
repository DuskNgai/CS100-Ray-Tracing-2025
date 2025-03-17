# Outline of Introduction to Programming (CS100)

This project is intended for recitation of Introduction to Programming (CS100) at Shanghaitech. To help students understand the basic concepts of programming, we will use C and C++ to implement a simple ray tracer. During the process, we will cover the topics and concepts of programming C and C++ that related to the course on that week. The project is based on the book [Ray Tracing in One Weekend](https://raytracing.github.io/).

## Weekly Schedule

### Week 1

1. Choosing the recitation class.

### Week 2

1. Introduction to C and C++.
2. Introduction to the project.
3. Introduction to git and github.
4. Compiling and running a program through Visual Studio/GCC/Clang.

### Week 3

1. Fixed width integer types.
2. Functions and function prototypes.
3. C standard library.

### Week 4

1. Pointers & arrays.
2. Dynamic memory allocation.

### Week 5

1. Preprocessor directives.
2. Multiple source files & header files.

## How to Run the Program

```bash
python script/run.py
```

## FAQs

> 1. [Windows, Powershell] In running the program, Powershell errors that "无法在本地运行脚本", "Execution Policy".

Run Powershell in Administrator mode, and type
```powershell
Set-ExecutionPolicy -Scope LocalMachine -ExecutionPolicy RemoteSigned
```
and then type `Y` for yes. Then run the program again.

> 2. [Python] `ModuleNotFoundError: No module named 'PIL'`.

Install the module `Pillow` by typing
```bash
pip install Pillow
```
and then run the program again.

## References

1. [Ray Tracing in One Weekend](https://raytracing.github.io/)
2. [cppreference](https://en.cppreference.com/w/)
