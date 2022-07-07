cmake_minimum_required(VERSION 3.0.0)
project(proC++ VERSION 0.1.0)

INCLUDE_DIRECTORIES(
  c:/Users/ALL/vcpkg/installed/x64-windows/include/
)
LINK_DIRECTORIES(
  c:/Users/ALL/vcpkg/installed/x64-windows/lib/
)

include(CTest)
enable_testing()

add_executable(proC++ main.cpp)

TARGET_LINK_LIBRARIES(proC++
sqlite3 fmt
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
