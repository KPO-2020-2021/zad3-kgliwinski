# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/krzysztof/PO/zad3-kgliwinski/prj

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/krzysztof/PO/zad3-kgliwinski/prj/build

# Include any dependencies generated for this target.
include CMakeFiles/engine.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/engine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/engine.dir/flags.make

CMakeFiles/engine.dir/src/example.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/src/example.cpp.o: ../src/example.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/krzysztof/PO/zad3-kgliwinski/prj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/engine.dir/src/example.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/src/example.cpp.o -c /home/krzysztof/PO/zad3-kgliwinski/prj/src/example.cpp

CMakeFiles/engine.dir/src/example.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/src/example.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/krzysztof/PO/zad3-kgliwinski/prj/src/example.cpp > CMakeFiles/engine.dir/src/example.cpp.i

CMakeFiles/engine.dir/src/example.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/src/example.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/krzysztof/PO/zad3-kgliwinski/prj/src/example.cpp -o CMakeFiles/engine.dir/src/example.cpp.s

CMakeFiles/engine.dir/src/lacze_do_gnuplota.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/src/lacze_do_gnuplota.cpp.o: ../src/lacze_do_gnuplota.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/krzysztof/PO/zad3-kgliwinski/prj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/engine.dir/src/lacze_do_gnuplota.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/src/lacze_do_gnuplota.cpp.o -c /home/krzysztof/PO/zad3-kgliwinski/prj/src/lacze_do_gnuplota.cpp

CMakeFiles/engine.dir/src/lacze_do_gnuplota.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/src/lacze_do_gnuplota.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/krzysztof/PO/zad3-kgliwinski/prj/src/lacze_do_gnuplota.cpp > CMakeFiles/engine.dir/src/lacze_do_gnuplota.cpp.i

CMakeFiles/engine.dir/src/lacze_do_gnuplota.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/src/lacze_do_gnuplota.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/krzysztof/PO/zad3-kgliwinski/prj/src/lacze_do_gnuplota.cpp -o CMakeFiles/engine.dir/src/lacze_do_gnuplota.cpp.s

CMakeFiles/engine.dir/src/vector.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/src/vector.cpp.o: ../src/vector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/krzysztof/PO/zad3-kgliwinski/prj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/engine.dir/src/vector.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/src/vector.cpp.o -c /home/krzysztof/PO/zad3-kgliwinski/prj/src/vector.cpp

CMakeFiles/engine.dir/src/vector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/src/vector.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/krzysztof/PO/zad3-kgliwinski/prj/src/vector.cpp > CMakeFiles/engine.dir/src/vector.cpp.i

CMakeFiles/engine.dir/src/vector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/src/vector.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/krzysztof/PO/zad3-kgliwinski/prj/src/vector.cpp -o CMakeFiles/engine.dir/src/vector.cpp.s

CMakeFiles/engine.dir/src/matrix.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/src/matrix.cpp.o: ../src/matrix.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/krzysztof/PO/zad3-kgliwinski/prj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/engine.dir/src/matrix.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/src/matrix.cpp.o -c /home/krzysztof/PO/zad3-kgliwinski/prj/src/matrix.cpp

CMakeFiles/engine.dir/src/matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/src/matrix.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/krzysztof/PO/zad3-kgliwinski/prj/src/matrix.cpp > CMakeFiles/engine.dir/src/matrix.cpp.i

CMakeFiles/engine.dir/src/matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/src/matrix.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/krzysztof/PO/zad3-kgliwinski/prj/src/matrix.cpp -o CMakeFiles/engine.dir/src/matrix.cpp.s

CMakeFiles/engine.dir/src/rectangle.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/src/rectangle.cpp.o: ../src/rectangle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/krzysztof/PO/zad3-kgliwinski/prj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/engine.dir/src/rectangle.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/src/rectangle.cpp.o -c /home/krzysztof/PO/zad3-kgliwinski/prj/src/rectangle.cpp

CMakeFiles/engine.dir/src/rectangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/src/rectangle.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/krzysztof/PO/zad3-kgliwinski/prj/src/rectangle.cpp > CMakeFiles/engine.dir/src/rectangle.cpp.i

CMakeFiles/engine.dir/src/rectangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/src/rectangle.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/krzysztof/PO/zad3-kgliwinski/prj/src/rectangle.cpp -o CMakeFiles/engine.dir/src/rectangle.cpp.s

CMakeFiles/engine.dir/src/menu.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/src/menu.cpp.o: ../src/menu.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/krzysztof/PO/zad3-kgliwinski/prj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/engine.dir/src/menu.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/src/menu.cpp.o -c /home/krzysztof/PO/zad3-kgliwinski/prj/src/menu.cpp

CMakeFiles/engine.dir/src/menu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/src/menu.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/krzysztof/PO/zad3-kgliwinski/prj/src/menu.cpp > CMakeFiles/engine.dir/src/menu.cpp.i

CMakeFiles/engine.dir/src/menu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/src/menu.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/krzysztof/PO/zad3-kgliwinski/prj/src/menu.cpp -o CMakeFiles/engine.dir/src/menu.cpp.s

engine: CMakeFiles/engine.dir/src/example.cpp.o
engine: CMakeFiles/engine.dir/src/lacze_do_gnuplota.cpp.o
engine: CMakeFiles/engine.dir/src/vector.cpp.o
engine: CMakeFiles/engine.dir/src/matrix.cpp.o
engine: CMakeFiles/engine.dir/src/rectangle.cpp.o
engine: CMakeFiles/engine.dir/src/menu.cpp.o
engine: CMakeFiles/engine.dir/build.make

.PHONY : engine

# Rule to build all files generated by this target.
CMakeFiles/engine.dir/build: engine

.PHONY : CMakeFiles/engine.dir/build

CMakeFiles/engine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/engine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/engine.dir/clean

CMakeFiles/engine.dir/depend:
	cd /home/krzysztof/PO/zad3-kgliwinski/prj/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/krzysztof/PO/zad3-kgliwinski/prj /home/krzysztof/PO/zad3-kgliwinski/prj /home/krzysztof/PO/zad3-kgliwinski/prj/build /home/krzysztof/PO/zad3-kgliwinski/prj/build /home/krzysztof/PO/zad3-kgliwinski/prj/build/CMakeFiles/engine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/engine.dir/depend
