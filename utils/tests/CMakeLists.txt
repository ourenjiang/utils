add_executable(SyncSocketTest SyncSocketTest.cpp)
target_link_libraries(SyncSocketTest
PRIVATE utils
)

####################################################
add_executable(TcpServerTest TcpServerTest.cpp)
target_link_libraries(TcpServerTest
PRIVATE utils
)

####################################################
add_executable(dealerTest DealerTest.cpp)
target_link_libraries(dealerTest
PRIVATE utils
)

####################################################
add_executable(dealerTest2 DealerTest2.cpp)
target_link_libraries(dealerTest2
PRIVATE utils
)

####################################################
add_executable(boostTimerTest BoostTimerTest.cpp)
target_link_libraries(boostTimerTest
PRIVATE utils
)

####################################################
add_executable(syncRespondTest SyncRespondTest.cpp)
target_link_libraries(syncRespondTest
PRIVATE utils
)

####################################################
add_executable(backtraceTest BacktraceTest.cpp)
target_link_libraries(backtraceTest
PRIVATE utils
)