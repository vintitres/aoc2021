%.out: %.cpp
	time clang++ -std=c++17 -O3 -mno-sse $< -o $@
