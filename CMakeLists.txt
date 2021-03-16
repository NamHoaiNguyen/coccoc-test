cmake_minimum_required(VERSION 3.19.2)

project(convert)

include_directories(/include/language/number_to_text.h 
/include/language/english/number_to_text_english.h
/include/language/english/english.h
/include/language.h /include/language_factory.h)

set(CMAKE_BUILD_TYPE RelWithDebInfo)

set (SOURCES src/main.cpp src/language/number_to_text.cpp
src/language/english/number_to_text_english.cpp
src/language/english/english.cpp
src/language_factory.cpp
src/language.cpp)

add_executable(convert ${SOURCES})

