# Учебный курс по ООП в C++

От устройства объекта — к управлению ресурсами — к иерархиям — к типам в рантайме.

---

## Логика курса

Курс линеен. Пять уроков, каждый продолжает предыдущий,
и мини-проект в конце, собирающий всё вместе.

| № | Папка | Урок | Вопрос |
|---|-------|------|--------|
| 00 | `lesson_00_intro` | **Введение в ООП** | Что такое ООП, класс, объект, четыре принципа? |
| 01 | `lesson_01_object` | **Объект** | Из чего состоит класс, как создаётся и уничтожается? |
| 02 | `lesson_02_resources` | **Управление ресурсами** | Как не течь, кто владеет памятью и файлами? |
| 03 | `lesson_03_hierarchy` | **Иерархии** | Как переиспользовать код и работать через интерфейс? |
| 04 | `lesson_04_runtime_types` | **Типы в рантайме** | Как безопасно приводить типы в иерархии? |
| — | `lesson_05_project` | **Мини-проект** | Иерархия + полиморфизм + `unique_ptr` + RTTI в одном проекте |

Каждый урок завершается заданиями для самопроверки (`tasks.md`).

---

## Содержание

### lesson_00_intro. Введение в ООП
- 0.1. Что такое ООП и зачем оно
- 0.2. Класс и объект
- 0.3. Четыре принципа ООП
- 0.4. Словарь терминов
- 0.5. Как ООП выглядит в C++

### lesson_01_object. Объект
- 1.1. `struct` и `class`
- 1.2. Инкапсуляция
- 1.3. Конструктор и деструктор
- 1.4. Передача по ссылке и копирование
- 1.5. Перегрузка операторов

### lesson_02_resources. Управление ресурсами
- 2.1. RAII
- 2.2. Правило трёх / пяти
- 2.3. Умные указатели
- 2.4. Исключения

### lesson_03_hierarchy. Иерархии
- 3.1. Наследование
- 3.2. Полиморфизм
- 3.3. Абстрактные классы

### lesson_04_runtime_types. Типы в рантайме
- 4.1. Приведение типов
- 4.2. RTTI

### lesson_05_project. Мини-проект «Библиотека»
- Иерархия `Item` → `Book` / `AudioBook` / `Comic`
- `Library` на `std::vector<std::unique_ptr<Item>>`
- Полиморфизм, `dynamic_cast` / RTTI
- Разбивка на `.h` / `.cpp`

---

## Структура репозитория

    cpp-oop/
    ├── CMakeLists.txt
    ├── README.md
    ├── .gitignore
    ├── lesson_00_intro/              # Введение в ООП
    │   ├── README.md
    │   ├── procedural_vs_object.cpp
    │   ├── class_and_object.cpp
    │   ├── four_principles.cpp
    │   ├── counter.cpp
    │   └── tasks.md
    ├── lesson_01_object/             # Объект
    │   ├── README.md
    │   ├── struct_vs_class.cpp
    │   ├── encapsulation.cpp
    │   ├── ctor_dtor.cpp
    │   ├── passing.cpp
    │   ├── operators.cpp
    │   └── tasks.md
    ├── lesson_02_resources/          # Управление ресурсами
    │   ├── README.md
    │   ├── raii.cpp
    │   ├── rule_of_five.cpp
    │   ├── smart_pointers.cpp
    │   ├── exceptions.cpp
    │   └── tasks.md
    ├── lesson_03_hierarchy/          # Иерархии
    │   ├── README.md
    │   ├── inheritance.cpp
    │   ├── polymorphism.cpp
    │   └── tasks.md
    ├── lesson_04_runtime_types/      # Типы в рантайме
    │   ├── README.md
    │   ├── casts_rtti.cpp
    │   └── tasks.md
    └── lesson_05_project/            # Мини-проект «Библиотека»
        ├── README.md
        ├── tasks.md
        ├── main.cpp
        ├── item.h
        ├── book.h
        ├── book.cpp
        ├── audiobook.h
        ├── audiobook.cpp
        ├── comic.h
        ├── comic.cpp
        ├── library.h
        └── library.cpp

Каждая папка урока — самостоятельный мини-урок:

| Файл | Что содержит |
|------|--------------|
| `README.md` | теория урока: определения, код, пояснения |
| `*.cpp` | рабочий исполняемый пример под каждую подтему |
| `tasks.md` | задания для самопроверки по теме урока |

`lesson_05_project` отличается: это не один `.cpp` на тему, а маленький
проект с разделением на заголовки (`.h`) и реализации (`.cpp`).

---

## Сборка и запуск

    cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
    cmake --build build
    ./build/bin/counter
    ./build/bin/library

Учебные примеры (уроки 00–04): каждый `.cpp` — отдельный исполняемый
файл с тем же именем. Мини-проект (`library`) собирается из нескольких
`.cpp`. Список всех целей:

    cmake --build build --target help

---

## Как читать курс

1. Иди по номерам уроков: `lesson_00_intro` → `lesson_01_object` →
   `lesson_02_resources` → `lesson_03_hierarchy` → `lesson_04_runtime_types`.
   Сложность растёт.
2. Внутри урока темы связаны: каждый следующий пункт использует
   понятия предыдущего.
3. По каждой теме: прочитай `README.md` урока → запусти примеры →
   выполни задания из `tasks.md`.
4. В конце — `lesson_05_project`: собери всё, что выучил, в одном проекте.

---

## Требования

- CMake ≥ 3.20
- Компилятор с поддержкой C++20 (GCC ≥ 10, Clang ≥ 12, MSVC ≥ 19.29)
- Флаги: `-Wall -Wextra -Wpedantic`
