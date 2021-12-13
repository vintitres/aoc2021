%.out: %.cpp
	time clang++ $< -o $@
