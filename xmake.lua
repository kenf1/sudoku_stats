add_rules("mode.debug", "mode.release")

add_requires("libpqxx")

target("sudoku_stats")
    set_kind("binary")
    set_languages("c++20")
    add_files("src/*.cpp", "src/ui/*.cpp", "src/models/*.cpp", "src/db/*.cpp")
    add_includedirs("src")
    add_packages("libpqxx")
