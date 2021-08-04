cmake_minimum_required(VERSION 3.10)
project("LinCulator"
        LANGUAGES CXX)
set(LIBRARY_NAME Classes)
#==================================================
#SET HEADERS
#==================================================

list(APPEND headers_path "${CMAKE_CURRENT_SOURCE_DIR}/include")
#==================================================
#SET SOURCES
#==================================================

set(sources_path ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(exec_source
    ${sources_path}/LinCulator.cpp)
set(srcs
    ${sources_path}/Fraction.cpp
    ${sources_path}/Matrix.cpp
    ${sources_path}/MyNamespace.cpp)


add_library(${LIBRARY_NAME} SHARED )
target_include_directories(
  ${LIBRARY_NAME}
  PRIVATE
    ${headers_path}
)
target_sources(
  ${LIBRARY_NAME}
  PRIVATE
    ${srcs}
)


add_executable(${PROJECT_NAME} ${exec_source})
target_include_directories(
  ${PROJECT_NAME}
  PRIVATE
    ${headers_path}
)
target_link_libraries(
  ${PROJECT_NAME}
  PRIVATE
    Classes
)
