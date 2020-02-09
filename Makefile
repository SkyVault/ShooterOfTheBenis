# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dustin/Projects/Benis3D

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dustin/Projects/Benis3D

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/dustin/Projects/Benis3D/CMakeFiles /home/dustin/Projects/Benis3D/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/dustin/Projects/Benis3D/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named Harp.exe

# Build rule for target.
Harp.exe: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Harp.exe
.PHONY : Harp.exe

# fast build rule for target.
Harp.exe/fast:
	$(MAKE) -f CMakeFiles/Harp.exe.dir/build.make CMakeFiles/Harp.exe.dir/build
.PHONY : Harp.exe/fast

src/assets.o: src/assets.c.o

.PHONY : src/assets.o

# target to build an object file
src/assets.c.o:
	$(MAKE) -f CMakeFiles/Harp.exe.dir/build.make CMakeFiles/Harp.exe.dir/src/assets.c.o
.PHONY : src/assets.c.o

src/assets.i: src/assets.c.i

.PHONY : src/assets.i

# target to preprocess a source file
src/assets.c.i:
	$(MAKE) -f CMakeFiles/Harp.exe.dir/build.make CMakeFiles/Harp.exe.dir/src/assets.c.i
.PHONY : src/assets.c.i

src/assets.s: src/assets.c.s

.PHONY : src/assets.s

# target to generate assembly for a file
src/assets.c.s:
	$(MAKE) -f CMakeFiles/Harp.exe.dir/build.make CMakeFiles/Harp.exe.dir/src/assets.c.s
.PHONY : src/assets.c.s

src/components.o: src/components.c.o

.PHONY : src/components.o

# target to build an object file
src/components.c.o:
	$(MAKE) -f CMakeFiles/Harp.exe.dir/build.make CMakeFiles/Harp.exe.dir/src/components.c.o
.PHONY : src/components.c.o

src/components.i: src/components.c.i

.PHONY : src/components.i

# target to preprocess a source file
src/components.c.i:
	$(MAKE) -f CMakeFiles/Harp.exe.dir/build.make CMakeFiles/Harp.exe.dir/src/components.c.i
.PHONY : src/components.c.i

src/components.s: src/components.c.s

.PHONY : src/components.s

# target to generate assembly for a file
src/components.c.s:
	$(MAKE) -f CMakeFiles/Harp.exe.dir/build.make CMakeFiles/Harp.exe.dir/src/components.c.s
.PHONY : src/components.c.s

src/ecs.o: src/ecs.c.o

.PHONY : src/ecs.o

# target to build an object file
src/ecs.c.o:
	$(MAKE) -f CMakeFiles/Harp.exe.dir/build.make CMakeFiles/Harp.exe.dir/src/ecs.c.o
.PHONY : src/ecs.c.o

src/ecs.i: src/ecs.c.i

.PHONY : src/ecs.i

# target to preprocess a source file
src/ecs.c.i:
	$(MAKE) -f CMakeFiles/Harp.exe.dir/build.make CMakeFiles/Harp.exe.dir/src/ecs.c.i
.PHONY : src/ecs.c.i

src/ecs.s: src/ecs.c.s

.PHONY : src/ecs.s

# target to generate assembly for a file
src/ecs.c.s:
	$(MAKE) -f CMakeFiles/Harp.exe.dir/build.make CMakeFiles/Harp.exe.dir/src/ecs.c.s
.PHONY : src/ecs.c.s

src/game.o: src/game.c.o

.PHONY : src/game.o

# target to build an object file
src/game.c.o:
	$(MAKE) -f CMakeFiles/Harp.exe.dir/build.make CMakeFiles/Harp.exe.dir/src/game.c.o
.PHONY : src/game.c.o

src/game.i: src/game.c.i

.PHONY : src/game.i

# target to preprocess a source file
src/game.c.i:
	$(MAKE) -f CMakeFiles/Harp.exe.dir/build.make CMakeFiles/Harp.exe.dir/src/game.c.i
.PHONY : src/game.c.i

src/game.s: src/game.c.s

.PHONY : src/game.s

# target to generate assembly for a file
src/game.c.s:
	$(MAKE) -f CMakeFiles/Harp.exe.dir/build.make CMakeFiles/Harp.exe.dir/src/game.c.s
.PHONY : src/game.c.s

src/main.o: src/main.c.o

.PHONY : src/main.o

# target to build an object file
src/main.c.o:
	$(MAKE) -f CMakeFiles/Harp.exe.dir/build.make CMakeFiles/Harp.exe.dir/src/main.c.o
.PHONY : src/main.c.o

src/main.i: src/main.c.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.c.i:
	$(MAKE) -f CMakeFiles/Harp.exe.dir/build.make CMakeFiles/Harp.exe.dir/src/main.c.i
.PHONY : src/main.c.i

src/main.s: src/main.c.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.c.s:
	$(MAKE) -f CMakeFiles/Harp.exe.dir/build.make CMakeFiles/Harp.exe.dir/src/main.c.s
.PHONY : src/main.c.s

src/map.o: src/map.c.o

.PHONY : src/map.o

# target to build an object file
src/map.c.o:
	$(MAKE) -f CMakeFiles/Harp.exe.dir/build.make CMakeFiles/Harp.exe.dir/src/map.c.o
.PHONY : src/map.c.o

src/map.i: src/map.c.i

.PHONY : src/map.i

# target to preprocess a source file
src/map.c.i:
	$(MAKE) -f CMakeFiles/Harp.exe.dir/build.make CMakeFiles/Harp.exe.dir/src/map.c.i
.PHONY : src/map.c.i

src/map.s: src/map.c.s

.PHONY : src/map.s

# target to generate assembly for a file
src/map.c.s:
	$(MAKE) -f CMakeFiles/Harp.exe.dir/build.make CMakeFiles/Harp.exe.dir/src/map.c.s
.PHONY : src/map.c.s

src/maths.o: src/maths.c.o

.PHONY : src/maths.o

# target to build an object file
src/maths.c.o:
	$(MAKE) -f CMakeFiles/Harp.exe.dir/build.make CMakeFiles/Harp.exe.dir/src/maths.c.o
.PHONY : src/maths.c.o

src/maths.i: src/maths.c.i

.PHONY : src/maths.i

# target to preprocess a source file
src/maths.c.i:
	$(MAKE) -f CMakeFiles/Harp.exe.dir/build.make CMakeFiles/Harp.exe.dir/src/maths.c.i
.PHONY : src/maths.c.i

src/maths.s: src/maths.c.s

.PHONY : src/maths.s

# target to generate assembly for a file
src/maths.c.s:
	$(MAKE) -f CMakeFiles/Harp.exe.dir/build.make CMakeFiles/Harp.exe.dir/src/maths.c.s
.PHONY : src/maths.c.s

src/models.o: src/models.c.o

.PHONY : src/models.o

# target to build an object file
src/models.c.o:
	$(MAKE) -f CMakeFiles/Harp.exe.dir/build.make CMakeFiles/Harp.exe.dir/src/models.c.o
.PHONY : src/models.c.o

src/models.i: src/models.c.i

.PHONY : src/models.i

# target to preprocess a source file
src/models.c.i:
	$(MAKE) -f CMakeFiles/Harp.exe.dir/build.make CMakeFiles/Harp.exe.dir/src/models.c.i
.PHONY : src/models.c.i

src/models.s: src/models.c.s

.PHONY : src/models.s

# target to generate assembly for a file
src/models.c.s:
	$(MAKE) -f CMakeFiles/Harp.exe.dir/build.make CMakeFiles/Harp.exe.dir/src/models.c.s
.PHONY : src/models.c.s

src/physics.o: src/physics.c.o

.PHONY : src/physics.o

# target to build an object file
src/physics.c.o:
	$(MAKE) -f CMakeFiles/Harp.exe.dir/build.make CMakeFiles/Harp.exe.dir/src/physics.c.o
.PHONY : src/physics.c.o

src/physics.i: src/physics.c.i

.PHONY : src/physics.i

# target to preprocess a source file
src/physics.c.i:
	$(MAKE) -f CMakeFiles/Harp.exe.dir/build.make CMakeFiles/Harp.exe.dir/src/physics.c.i
.PHONY : src/physics.c.i

src/physics.s: src/physics.c.s

.PHONY : src/physics.s

# target to generate assembly for a file
src/physics.c.s:
	$(MAKE) -f CMakeFiles/Harp.exe.dir/build.make CMakeFiles/Harp.exe.dir/src/physics.c.s
.PHONY : src/physics.c.s

src/physics_type.o: src/physics_type.c.o

.PHONY : src/physics_type.o

# target to build an object file
src/physics_type.c.o:
	$(MAKE) -f CMakeFiles/Harp.exe.dir/build.make CMakeFiles/Harp.exe.dir/src/physics_type.c.o
.PHONY : src/physics_type.c.o

src/physics_type.i: src/physics_type.c.i

.PHONY : src/physics_type.i

# target to preprocess a source file
src/physics_type.c.i:
	$(MAKE) -f CMakeFiles/Harp.exe.dir/build.make CMakeFiles/Harp.exe.dir/src/physics_type.c.i
.PHONY : src/physics_type.c.i

src/physics_type.s: src/physics_type.c.s

.PHONY : src/physics_type.s

# target to generate assembly for a file
src/physics_type.c.s:
	$(MAKE) -f CMakeFiles/Harp.exe.dir/build.make CMakeFiles/Harp.exe.dir/src/physics_type.c.s
.PHONY : src/physics_type.c.s

src/player.o: src/player.c.o

.PHONY : src/player.o

# target to build an object file
src/player.c.o:
	$(MAKE) -f CMakeFiles/Harp.exe.dir/build.make CMakeFiles/Harp.exe.dir/src/player.c.o
.PHONY : src/player.c.o

src/player.i: src/player.c.i

.PHONY : src/player.i

# target to preprocess a source file
src/player.c.i:
	$(MAKE) -f CMakeFiles/Harp.exe.dir/build.make CMakeFiles/Harp.exe.dir/src/player.c.i
.PHONY : src/player.c.i

src/player.s: src/player.c.s

.PHONY : src/player.s

# target to generate assembly for a file
src/player.c.s:
	$(MAKE) -f CMakeFiles/Harp.exe.dir/build.make CMakeFiles/Harp.exe.dir/src/player.c.s
.PHONY : src/player.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... Harp.exe"
	@echo "... edit_cache"
	@echo "... src/assets.o"
	@echo "... src/assets.i"
	@echo "... src/assets.s"
	@echo "... src/components.o"
	@echo "... src/components.i"
	@echo "... src/components.s"
	@echo "... src/ecs.o"
	@echo "... src/ecs.i"
	@echo "... src/ecs.s"
	@echo "... src/game.o"
	@echo "... src/game.i"
	@echo "... src/game.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/map.o"
	@echo "... src/map.i"
	@echo "... src/map.s"
	@echo "... src/maths.o"
	@echo "... src/maths.i"
	@echo "... src/maths.s"
	@echo "... src/models.o"
	@echo "... src/models.i"
	@echo "... src/models.s"
	@echo "... src/physics.o"
	@echo "... src/physics.i"
	@echo "... src/physics.s"
	@echo "... src/physics_type.o"
	@echo "... src/physics_type.i"
	@echo "... src/physics_type.s"
	@echo "... src/player.o"
	@echo "... src/player.i"
	@echo "... src/player.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

