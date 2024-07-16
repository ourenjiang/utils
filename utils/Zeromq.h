#pragma once
#include "zmq.hpp"

namespace zeromq
{

/**
 * @brief 获取zmq::context_t的单例对象
 * @return zmq::context_t单例对象
 * @exception NoThrow
*/
zmq::context_t& contextSingleton();

/**
 * @brief 创建zeromq套接字
 * @param type 套接字类型
 * @return zmq::socket_t单例对象
 * @exception NoThrow
*/
zmq::socket_t socket(zmq::socket_type type);

}//namespace zeromq
