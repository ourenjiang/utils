file(GLOB_RECURSE SRC_SOURCES *.cpp *.c)

add_executable(checkForamt ${SRC_SOURCES})
target_link_libraries(checkForamt
  utils
)
