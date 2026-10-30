cmake_minimum_required(VERSION 3.20)
project(cpp-oop LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall -Wextra -Wpedantic)

# Хелпер: один .cpp -> один исполняемый файл с тем же именем
function(add_example name path)
    add_executable(${name} ${path})
    set_target_properties(${name} PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
endfunction()

# --- lesson_00_intro. Введение в ООП ---
add_example(procedural_vs_object lesson_00_intro/procedural_vs_object.cpp)
add_example(class_and_object     lesson_00_intro/class_and_object.cpp)
add_example(four_principles      lesson_00_intro/four_principles.cpp)
add_example(counter              lesson_00_intro/counter.cpp)

# --- lesson_01_object. Объект ---
add_example(struct_vs_class  lesson_01_object/struct_vs_class.cpp)
add_example(encapsulation    lesson_01_object/encapsulation.cpp)
add_example(ctor_dtor        lesson_01_object/ctor_dtor.cpp)
add_example(passing          lesson_01_object/passing.cpp)
add_example(operators        lesson_01_object/operators.cpp)

# --- lesson_02_resources. Управление ресурсами ---
add_example(raii             lesson_02_resources/raii.cpp)
add_example(rule_of_five     lesson_02_resources/rule_of_five.cpp)
add_example(smart_pointers   lesson_02_resources/smart_pointers.cpp)
add_example(exceptions       lesson_02_resources/exceptions.cpp)

# --- lesson_03_hierarchy. Иерархии ---
add_example(inheritance      lesson_03_hierarchy/inheritance.cpp)
add_example(polymorphism     lesson_03_hierarchy/polymorphism.cpp)

# --- lesson_04_runtime_types. Типы в рантайме ---
add_example(casts_rtti       lesson_04_runtime_types/casts_rtti.cpp)

# --- lesson_05_project. Мини-проект «Библиотека» ---
# Здесь несколько .cpp -> одна цель, поэтому не хелпер add_example.
add_executable(library
        lesson_05_project/main.cpp
        lesson_05_project/book.cpp
        lesson_05_project/audiobook.cpp
        lesson_05_project/comic.cpp
        lesson_05_project/library.cpp
)
set_target_properties(library PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)