# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/lib/python3.10/dist-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /usr/local/lib/python3.10/dist-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/insa/lnguyen/Home_INSA/pld-comp/antlr.tmp/build/runtime/thirdparty/utfcpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/insa/lnguyen/Home_INSA/pld-comp/antlr.tmp/build/runtime/utfcpp-prefix/src/utfcpp-build

# Include any dependencies generated for this target.
include CMakeFiles/docsample.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/docsample.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/docsample.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/docsample.dir/flags.make

CMakeFiles/docsample.dir/samples/docsample.cpp.o: CMakeFiles/docsample.dir/flags.make
CMakeFiles/docsample.dir/samples/docsample.cpp.o: /mnt/insa/lnguyen/Home_INSA/pld-comp/antlr.tmp/build/runtime/thirdparty/utfcpp/samples/docsample.cpp
CMakeFiles/docsample.dir/samples/docsample.cpp.o: CMakeFiles/docsample.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/insa/lnguyen/Home_INSA/pld-comp/antlr.tmp/build/runtime/utfcpp-prefix/src/utfcpp-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/docsample.dir/samples/docsample.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/docsample.dir/samples/docsample.cpp.o -MF CMakeFiles/docsample.dir/samples/docsample.cpp.o.d -o CMakeFiles/docsample.dir/samples/docsample.cpp.o -c /mnt/insa/lnguyen/Home_INSA/pld-comp/antlr.tmp/build/runtime/thirdparty/utfcpp/samples/docsample.cpp

CMakeFiles/docsample.dir/samples/docsample.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/docsample.dir/samples/docsample.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/insa/lnguyen/Home_INSA/pld-comp/antlr.tmp/build/runtime/thirdparty/utfcpp/samples/docsample.cpp > CMakeFiles/docsample.dir/samples/docsample.cpp.i

CMakeFiles/docsample.dir/samples/docsample.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/docsample.dir/samples/docsample.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/insa/lnguyen/Home_INSA/pld-comp/antlr.tmp/build/runtime/thirdparty/utfcpp/samples/docsample.cpp -o CMakeFiles/docsample.dir/samples/docsample.cpp.s

# Object files for target docsample
docsample_OBJECTS = \
"CMakeFiles/docsample.dir/samples/docsample.cpp.o"

# External object files for target docsample
docsample_EXTERNAL_OBJECTS =

docsample: CMakeFiles/docsample.dir/samples/docsample.cpp.o
docsample: CMakeFiles/docsample.dir/build.make
docsample: CMakeFiles/docsample.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/mnt/insa/lnguyen/Home_INSA/pld-comp/antlr.tmp/build/runtime/utfcpp-prefix/src/utfcpp-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable docsample"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/docsample.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/docsample.dir/build: docsample
.PHONY : CMakeFiles/docsample.dir/build

CMakeFiles/docsample.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/docsample.dir/cmake_clean.cmake
.PHONY : CMakeFiles/docsample.dir/clean

CMakeFiles/docsample.dir/depend:
	cd /mnt/insa/lnguyen/Home_INSA/pld-comp/antlr.tmp/build/runtime/utfcpp-prefix/src/utfcpp-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/insa/lnguyen/Home_INSA/pld-comp/antlr.tmp/build/runtime/thirdparty/utfcpp /mnt/insa/lnguyen/Home_INSA/pld-comp/antlr.tmp/build/runtime/thirdparty/utfcpp /mnt/insa/lnguyen/Home_INSA/pld-comp/antlr.tmp/build/runtime/utfcpp-prefix/src/utfcpp-build /mnt/insa/lnguyen/Home_INSA/pld-comp/antlr.tmp/build/runtime/utfcpp-prefix/src/utfcpp-build /mnt/insa/lnguyen/Home_INSA/pld-comp/antlr.tmp/build/runtime/utfcpp-prefix/src/utfcpp-build/CMakeFiles/docsample.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/docsample.dir/depend

