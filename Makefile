.PHONY: run fmt clean

run:
	xmake --root && ./build/*/*/release/sudoku_stats

fmt:
	find . -type f \( -iname "*.cpp" -o -iname "*.h" -o -iname "*.c" \) | xargs clang-format -i

clean:
	rm -rf .xmake build