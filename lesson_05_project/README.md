# Мини-проект. Библиотека

Итоговая работа по курсу. Собирает всё сразу:

- иерархия классов и полиморфизм (урок 03);
- абстрактный класс как интерфейс (урок 03);
- `unique_ptr` для владения (урок 02);
- `dynamic_cast` / RTTI для фильтрации по типу (урок 04);
- разделение на `.h` / `.cpp` — как в настоящем проекте.

## Что нужно

Класс `Item` — абстрактный интерфейс:

- `title()`, `author()`, `year()`, `value()` — чисто виртуальные.

Три наследника:

- `Book` — книга: `pages`, `value() = pages * 0.1`.
- `AudioBook` — аудиокнига: `minutes`, `value() = minutes * 0.05`.
- `Comic` — комикс: `issues`, `value() = issues * 0.3`.

Класс `Library`:

- хранит `std::vector<std::unique_ptr<Item>>`;
- `add(std::unique_ptr<Item>)`;
- `printAll() const` — печатает `[тип] title — author (year)`;
- `totalValue() const` — сумма всех `value()`;
- `findByAuthor(const std::string&) const` — вектор `const Item*`;
- `countByType<T>() const` — через `dynamic_cast` считает элементы типа `T`.

## Структура

    lesson_05_project/
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

## Сборка и запуск

    cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
    cmake --build build
    ./build/bin/library

Цель `library` собирается из нескольких `.cpp` — в `CMakeLists.txt`
это отдельный `add_executable`, а не хелпер `add_example`.

## Что демонстрирует

- **Инкапсуляция** — поля наследников `private`, доступ через методы.
- **Абстракция** — `Item` описывает только интерфейс.
- **Наследование** — `Book`, `AudioBook`, `Comic` наследуют `Item`.
- **Полиморфизм** — `printAll`, `totalValue` работают с `Item*`,
  вызывают реализации наследников.
- **RAII** — `unique_ptr` в `Library` освобождает объекты сам.
- **RTTI** — `countByType<T>` и печать `typeid(*it).name()`.