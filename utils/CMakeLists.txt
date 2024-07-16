set(utils_SRCS
ResourceInit.cpp
LogWrapper.cpp
CommandlineParams.cpp
EnvironmentVariables.cpp
Zeromq.cpp
Miscellaneous.cpp
HttpWrapper.cpp
cpphttplib_splitout/httplib.cc
SyncRequest.cpp
SyncRespond.cpp
BoostTimer.cpp
Datetime.cpp
Endian.cpp
Cgi.cpp
JsonWrapper.cpp
StreamWrapper.cpp
modbus/Crc16.cpp
modbus/ModbusRtu.cpp
)

add_library(utils ${utils_SRCS})
set_target_properties(utils PROPERTIES POSITION_INDEPENDENT_CODE ON) # -fPIC for static library
target_link_libraries(utils
yaml-cpp.a
log4cpp.a
boost_program_options.a
zmq.a
modbus.a
jsoncpp.a
boost_timer.a
)

add_subdirectory(tests)