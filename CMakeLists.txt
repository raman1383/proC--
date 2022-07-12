cmake_minimum_required(VERSION 3.22.0)
project(proC++ VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
INCLUDE_DIRECTORIES(
  c:/Users/ALL/vcpkg/installed/x64-windows/include/
)
LINK_DIRECTORIES(
  c:/Users/ALL/vcpkg/installed/x64-windows/lib/
)

include(CTest)
enable_testing()

add_executable(proC++ main.cc)

TARGET_LINK_LIBRARIES(proC++
sqlite3 fmt
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
