# sf-raytracing

A simple raytracer written in C++. This is a personal project to learn and experiment with C++ and computer graphics.

The output is PPM format file in this project.

# build

Make sure you have installed the CMake build system, and execute the following commands in the root directory of this project to build the executable:

```powershell
cmake -B build -S .
cmake --build build
```

# run

To run the executable after building, execute the following command in the root directory of this project:

```powershell
./build/sf-raytracing > image.ppm
```

# 项目

这是一个简单的路径追踪项目，一个用于学习 C++ 和计算机图形学的个人项目

项目输出文件是 PPM 格式的图像文件

# 构建

确保安装了 CMake 构建系统，执行下列指令在项目根目录来构建

```powershell
cmake -B build -S .
cmake --build build
```

# 运行

执行下列指令在项目根目录来运行

```powershell
./build/sf-raytracing > image.ppm
```
