add_rules("mode.debug", "mode.release")

target("sudoku_stats")
    set_kind("binary")
    set_languages("c++20")
    add_files("src/*.cpp", "src/ui/*.cpp", "src/models/*.cpp")
    add_includedirs("src")
