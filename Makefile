.PHONY: fmt run clean

fmt:
	find . -type f \( -iname "*.cpp" -o -iname "*.h" -o -iname "*.c" \) | xargs clang-format -i

run: fmt
	xmake --root && ./build/*/*/release/sudoku_stats

clean:
	rm -rf .xmake build