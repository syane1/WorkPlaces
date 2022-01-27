project(DS_LIB)

# 设置指定的C++编译器版本是必须的，如果不设置，或者为OFF，则指定版本不可用时，会使用上一版本。
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
# 如果代码需要支持C++11，就直接加上这句
#set(CMAKE_CXX_STANDARD 11)

SET(LIBDS_SRC_DIR ${PROJECT_SOURCE_DIR}/src)
SET(LIBDS_INC_DIR ${PROJECT_SOURCE_DIR}/Include)

aux_source_directory(${LIBDS_SRC_DIR} LIBDS_SRC_FILES)

add_library(${PROJECT_NAME} STATIC ${LIBDS_SRC_FILES})
include_directories(${LIBDS_INC_DIR})

#链接编译好的库
#link_directories(${PROJECT_SOURCE_DIR}/../lib)
#target_link_libraries(${PROJECT_NAME} protobuf)