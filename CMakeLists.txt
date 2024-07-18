cmake_minimum_required(VERSION 3.10)

# 项目名称
project(c-js-example C)

# 设置 C 标准
set(CMAKE_C_STANDARD 99)

# 设置编译选项
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

# 源文件列表
set(SRCS duktape.c js_c.c utils.c main.c)

# 输出目录
set(OUTPUT_DIR ${CMAKE_BINARY_DIR}/output)

# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR})

# 生成目标可执行文件
add_executable(c-js-example ${SRCS})

# 确保输出目录存在
add_custom_command(TARGET c-js-example PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E make_directory ${OUTPUT_DIR})
