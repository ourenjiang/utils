file(GLOB_RECURSE SRC_SOURCES *.cpp)

add_library(utils ${SRC_SOURCES})
set_target_properties(utils PROPERTIES POSITION_INDEPENDENT_CODE ON) # -fPIC for static library
target_link_libraries(utils
    yaml-cpp.a
    log4cpp.a
    boost_program_options.a
    zmq.a
    boost_timer.a
)
