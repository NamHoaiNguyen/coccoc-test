cmake_minimum_required(VERSION 3.19.2)

project(convert)

include_directories(
/include/convert/number_to_text.h
/include/language/english/english.h
/include/language/vietnam/vietnamese.h
/include/language/language.h 
/include/factory/language_factory.h)

set(CMAKE_BUILD_TYPE RelWithDebInfo)

set (SOURCES src/main.cpp 
src/convert/number_to_text.cpp
src/language/english/english.cpp
src/language/vietnam/vietnamese.cpp
src/factory/language_factory.cpp
src/language/language.cpp)

add_executable(convert ${SOURCES})

