#!/bin/sh

install_dir=paceic_ems_server

build_dir=server_build

compile_type=$1

if [ "$compile_type" = "arm" ]; then
    build_dir=server_aarch64_build
    # 构建
    cmake\
        -B ../$build_dir\
        -DENABLE_TEST=ON\
        -DCROSS_COMPILE=ON\
        ./
else 
    # 构建
    cmake\
        -B ../$build_dir\
        -DENABLE_TEST=ON\
        -DCROSS_COMPILE=OFF\
        ./
fi

# 编译&安装
cd ../$build_dir;
make -j4 && make install

echo "build success."
