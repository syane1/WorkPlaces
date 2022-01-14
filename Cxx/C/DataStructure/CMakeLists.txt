#指定最小cmake版本
cmake_minimum_required(VERSION 3.0.0)
project(DsMain VERSION 0.1.0 LANGUAGES C CXX)

# 设置指定的C++编译器版本是必须的，如果不设置，或者为OFF，则指定版本不可用时，会使用上一版本。
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
# 如果代码需要支持C++11，就直接加上这句
#set(CMAKE_CXX_STANDARD 11)

# 如果想要生成的可执行文件拥有符号表，可以gdb调试，就直接加上这句
#add_definitions("-Wall -g")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
set(DSLIB ${PROJECT_SOURCE_DIR}/DsLib)

add_subdirectory(${DSLIB})
include_directories(${DSLIB}/Include)

set(MAIN_PREFIX "main")

#生成的可执行文件
add_executable(${PROJECT_NAME} ${MAIN_PREFIX}.c )

#链接操作
target_link_libraries(${PROJECT_NAME}
    LIB_DS
)

install(TARGETS ${PROJECT_NAME} LIB_DS
    RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/bin           #可执行二进制安装到${PROJECT_SOURCE_DIR}/bin目录
    LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/lib           #动态库安装到${PROJECT_SOURCE_DIR}/lib目录
    ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/lib           #静态库也安装到${PROJECT_SOURCE_DIR}/lib目录
    PUBLIC_HEADER DESTINATION ${PROJECT_SOURCE_DIR}/Include #头文件
)

set_target_properties(${PROJECT_NAME} 
    #PROPERTIES PREFIX "EXE" SUFFIX ".out" #前缀为EXE 后缀为.out 例如EXEmain.out
    PROPERTIES OUTPUT_NAME ${MAIN_PREFIX}.out#直接改名为main.out
)