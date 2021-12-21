%.out: %.cpp
	time clang++ -O3 $< -o $@
