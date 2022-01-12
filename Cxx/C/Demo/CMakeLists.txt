cmake_minimum_required(VERSION 3.5)
project(Demo)

#按照正则表达式搜索路径下的文件 file(<GLOB|GLOB_RECURSE> <variable> <pattern>)
#file(GLOB SRC_LIST "./src/*.cpp")
#搜索文件内所有的源文件 
#aux_source_directory("./src/" SRC_LIST)：

#添加编译目标
#add_library(dslib SHARED ${SRC_LIST})
add_executable(main main.c "./src/")

#添加头文件目录
#为该位置之后的target链接头文件目录（不推荐） 
#include_directories("./Includes/")
#为特定的目标链接头文件目录 target_include_directories(<target> <PUBLIC|INTERFACE|PRIVATE]> <items>)

#添加依赖库
#为该位置之后的target链接依赖库 link_libraries(<items>)
#为特定的目标链接依赖库 target_link_libraries(<target> <items>)

#添加子目录，子目录中要有CMakeLists.txt文件，否则会报错。 
add_subdirectories("./SubDemo"))

#包含其他cmake文件 include(./path/to/tool.cmake)或set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ./path/to)，随后include(tool)

#定义变量，其中CACHE会将变量定义在缓存文件CMakeCache.txt里，可以在下次编译的时候读取
#set(<variable> <value>... [PARENT_SCOPE])
#set(<variable> <value>... CACHE <type> <docstring> [FORCE])

#作用域 add_subdirectories(<dir>)

#选项 add_option(MY_OPTION <ON|OFF>)
#会定义一个选项。在使用cmake命令时，可以通过-D改变选项的值。比如cmake .. -D MY_OPTION=ON

#编译选项 add_compile_options(-std=c++11)
#如果想要指定具体的编译器的选项，可以使用make_cxx_flags()或cmake_c_flags()