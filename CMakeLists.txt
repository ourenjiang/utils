cmake_minimum_required(VERSION 3.7)
project(utils)

#编译类型
set(CMAKE_BUILD_TYPE Debug)
# set(CMAKE_BUILD_TYPE Release)

# CPP标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 全局参数
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 编译器参数
add_compile_options(-Wfatal-errors)    # 减少模板代码错误导致的错误信息冗杂的问题
add_compile_options(-Wunused)
add_compile_options(-funwind-tables -ffunction-sections -rdynamic)

#安装路径
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/install)
#添加运行库路径(注意：多个路径之间以分号隔开)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib;")

# 安装项目配置文件
install(DIRECTORY etc DESTINATION ${CMAKE_INSTALL_PREFIX} USE_SOURCE_PERMISSIONS)

#全局头文件路径
include_directories(${PROJECT_SOURCE_DIR})
#全局库文件路径
link_directories(${CMAKE_BINARY_DIR}/lib)

# ==============================================================================
# 第三方依赖路径：与项目路径同级
# set(THIRD_PARTY_PATH ../third_party)

# jsoncpp-1.9.5
set(JSONCPP_PATH ${THIRD_PARTY_PATH}/jsoncpp-1.9.5)
include_directories(${JSONCPP_PATH}/include)
link_directories(${JSONCPP_PATH}/lib)

# libmodbus-3.1.10
set(LIB_MODBUS_PATH ${THIRD_PARTY_PATH}/libmodbus-3.1.10)
include_directories(${LIB_MODBUS_PATH}/include)
link_directories(${LIB_MODBUS_PATH}/lib)

# hiredis-1.2.0
set(HIREDIS_PATH ${THIRD_PARTY_PATH}/hiredis-1.2.0)
include_directories(${HIREDIS_PATH}/include)
link_directories(${HIREDIS_PATH}/lib)

# 注意，此版本在通过cmake间接链接hiredis时，无法自动关联它的运行时路径，暂时还找不到解决办法
# 一种临时手段时，使用它的静态库。即执行target_link_library时，使用redis++.a
# redis-plus-plus-1.3.11
set(REDIS_PLUS_PLUS_PATH ${THIRD_PARTY_PATH}/redis-plus-plus-1.3.11)
include_directories(${REDIS_PLUS_PLUS_PATH}/include)
link_directories(${REDIS_PLUS_PLUS_PATH}/lib)

# libzmq-4.3.5
set(LIBZMQ_PATH ${THIRD_PARTY_PATH}/libzmq-4.3.5)
include_directories(${LIBZMQ_PATH}/include)
link_directories(${LIBZMQ_PATH}/lib)

# cppzmq-4.10.0
set(CPPZMQ_PATH ${THIRD_PARTY_PATH}/cppzmq-4.10.0)
include_directories(${CPPZMQ_PATH}/include)

# msgpack-c-cpp-6.1.0
set(MSGPACK_PATH ${THIRD_PARTY_PATH}/msgpack-c-cpp-6.1.0)
include_directories(${MSGPACK_PATH}/include)

# sqlite-3.39.4
set(SQLITE_PATH ${THIRD_PARTY_PATH}/sqlite-3.39.4)
include_directories(${SQLITE_PATH}/include)
link_directories(${SQLITE_PATH}/lib)

# sqlite_modern_cpp-3.2
set(SQLITE_MODERN_CPP_PATH ${THIRD_PARTY_PATH}/sqlite_modern_cpp-3.2)
include_directories(${SQLITE_MODERN_CPP_PATH}/include)

# boost-1.84.0
set(BOOST_PATH ${THIRD_PARTY_PATH}/boost-1.84.0)
include_directories(${BOOST_PATH}/include)
link_directories(${BOOST_PATH}/lib)

# log4cpp-1.1.3
set(LOG4CPP_PATH ${THIRD_PARTY_PATH}/log4cpp-1.1.3)
include_directories(${LOG4CPP_PATH}/include)
link_directories(${LOG4CPP_PATH}/lib)

# yaml-cpp-0.8.0
set(YAMLCPP_PATH ${THIRD_PARTY_PATH}/yaml-cpp-0.8.0)
include_directories(${YAMLCPP_PATH}/include)
link_directories(${YAMLCPP_PATH}/lib)

add_subdirectory(utils)

install(TARGETS utils
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib)
