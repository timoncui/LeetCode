# Usage: Make CPP_FILE_NAME_WITHOUT_EXT
% : %.cpp
	g++ -g -o $* $<
	./$*