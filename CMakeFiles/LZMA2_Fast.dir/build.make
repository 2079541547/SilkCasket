# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/yuwu/Documents/新建文件夹

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yuwu/Documents/新建文件夹

# Include any dependencies generated for this target.
include CMakeFiles/LZMA2_Fast.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/LZMA2_Fast.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/LZMA2_Fast.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LZMA2_Fast.dir/flags.make

CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/dict_buffer.c.o: CMakeFiles/LZMA2_Fast.dir/flags.make
CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/dict_buffer.c.o: lib/LZMA2-Fast/dict_buffer.c
CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/dict_buffer.c.o: CMakeFiles/LZMA2_Fast.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/yuwu/Documents/新建文件夹/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/dict_buffer.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/dict_buffer.c.o -MF CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/dict_buffer.c.o.d -o CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/dict_buffer.c.o -c /home/yuwu/Documents/新建文件夹/lib/LZMA2-Fast/dict_buffer.c

CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/dict_buffer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/dict_buffer.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yuwu/Documents/新建文件夹/lib/LZMA2-Fast/dict_buffer.c > CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/dict_buffer.c.i

CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/dict_buffer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/dict_buffer.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yuwu/Documents/新建文件夹/lib/LZMA2-Fast/dict_buffer.c -o CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/dict_buffer.c.s

CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_common.c.o: CMakeFiles/LZMA2_Fast.dir/flags.make
CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_common.c.o: lib/LZMA2-Fast/fl2_common.c
CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_common.c.o: CMakeFiles/LZMA2_Fast.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/yuwu/Documents/新建文件夹/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_common.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_common.c.o -MF CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_common.c.o.d -o CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_common.c.o -c /home/yuwu/Documents/新建文件夹/lib/LZMA2-Fast/fl2_common.c

CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_common.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_common.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yuwu/Documents/新建文件夹/lib/LZMA2-Fast/fl2_common.c > CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_common.c.i

CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_common.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_common.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yuwu/Documents/新建文件夹/lib/LZMA2-Fast/fl2_common.c -o CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_common.c.s

CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_compress.c.o: CMakeFiles/LZMA2_Fast.dir/flags.make
CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_compress.c.o: lib/LZMA2-Fast/fl2_compress.c
CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_compress.c.o: CMakeFiles/LZMA2_Fast.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/yuwu/Documents/新建文件夹/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_compress.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_compress.c.o -MF CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_compress.c.o.d -o CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_compress.c.o -c /home/yuwu/Documents/新建文件夹/lib/LZMA2-Fast/fl2_compress.c

CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_compress.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_compress.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yuwu/Documents/新建文件夹/lib/LZMA2-Fast/fl2_compress.c > CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_compress.c.i

CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_compress.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_compress.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yuwu/Documents/新建文件夹/lib/LZMA2-Fast/fl2_compress.c -o CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_compress.c.s

CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_decompress.c.o: CMakeFiles/LZMA2_Fast.dir/flags.make
CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_decompress.c.o: lib/LZMA2-Fast/fl2_decompress.c
CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_decompress.c.o: CMakeFiles/LZMA2_Fast.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/yuwu/Documents/新建文件夹/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_decompress.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_decompress.c.o -MF CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_decompress.c.o.d -o CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_decompress.c.o -c /home/yuwu/Documents/新建文件夹/lib/LZMA2-Fast/fl2_decompress.c

CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_decompress.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_decompress.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yuwu/Documents/新建文件夹/lib/LZMA2-Fast/fl2_decompress.c > CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_decompress.c.i

CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_decompress.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_decompress.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yuwu/Documents/新建文件夹/lib/LZMA2-Fast/fl2_decompress.c -o CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_decompress.c.s

CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_pool.c.o: CMakeFiles/LZMA2_Fast.dir/flags.make
CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_pool.c.o: lib/LZMA2-Fast/fl2_pool.c
CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_pool.c.o: CMakeFiles/LZMA2_Fast.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/yuwu/Documents/新建文件夹/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_pool.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_pool.c.o -MF CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_pool.c.o.d -o CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_pool.c.o -c /home/yuwu/Documents/新建文件夹/lib/LZMA2-Fast/fl2_pool.c

CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_pool.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_pool.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yuwu/Documents/新建文件夹/lib/LZMA2-Fast/fl2_pool.c > CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_pool.c.i

CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_pool.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_pool.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yuwu/Documents/新建文件夹/lib/LZMA2-Fast/fl2_pool.c -o CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_pool.c.s

CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_threading.c.o: CMakeFiles/LZMA2_Fast.dir/flags.make
CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_threading.c.o: lib/LZMA2-Fast/fl2_threading.c
CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_threading.c.o: CMakeFiles/LZMA2_Fast.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/yuwu/Documents/新建文件夹/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_threading.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_threading.c.o -MF CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_threading.c.o.d -o CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_threading.c.o -c /home/yuwu/Documents/新建文件夹/lib/LZMA2-Fast/fl2_threading.c

CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_threading.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_threading.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yuwu/Documents/新建文件夹/lib/LZMA2-Fast/fl2_threading.c > CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_threading.c.i

CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_threading.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_threading.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yuwu/Documents/新建文件夹/lib/LZMA2-Fast/fl2_threading.c -o CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_threading.c.s

CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/lzma2_dec.c.o: CMakeFiles/LZMA2_Fast.dir/flags.make
CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/lzma2_dec.c.o: lib/LZMA2-Fast/lzma2_dec.c
CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/lzma2_dec.c.o: CMakeFiles/LZMA2_Fast.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/yuwu/Documents/新建文件夹/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/lzma2_dec.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/lzma2_dec.c.o -MF CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/lzma2_dec.c.o.d -o CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/lzma2_dec.c.o -c /home/yuwu/Documents/新建文件夹/lib/LZMA2-Fast/lzma2_dec.c

CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/lzma2_dec.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/lzma2_dec.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yuwu/Documents/新建文件夹/lib/LZMA2-Fast/lzma2_dec.c > CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/lzma2_dec.c.i

CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/lzma2_dec.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/lzma2_dec.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yuwu/Documents/新建文件夹/lib/LZMA2-Fast/lzma2_dec.c -o CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/lzma2_dec.c.s

CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/lzma2_enc.c.o: CMakeFiles/LZMA2_Fast.dir/flags.make
CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/lzma2_enc.c.o: lib/LZMA2-Fast/lzma2_enc.c
CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/lzma2_enc.c.o: CMakeFiles/LZMA2_Fast.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/yuwu/Documents/新建文件夹/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/lzma2_enc.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/lzma2_enc.c.o -MF CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/lzma2_enc.c.o.d -o CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/lzma2_enc.c.o -c /home/yuwu/Documents/新建文件夹/lib/LZMA2-Fast/lzma2_enc.c

CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/lzma2_enc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/lzma2_enc.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yuwu/Documents/新建文件夹/lib/LZMA2-Fast/lzma2_enc.c > CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/lzma2_enc.c.i

CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/lzma2_enc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/lzma2_enc.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yuwu/Documents/新建文件夹/lib/LZMA2-Fast/lzma2_enc.c -o CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/lzma2_enc.c.s

CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/radix_bitpack.c.o: CMakeFiles/LZMA2_Fast.dir/flags.make
CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/radix_bitpack.c.o: lib/LZMA2-Fast/radix_bitpack.c
CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/radix_bitpack.c.o: CMakeFiles/LZMA2_Fast.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/yuwu/Documents/新建文件夹/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/radix_bitpack.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/radix_bitpack.c.o -MF CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/radix_bitpack.c.o.d -o CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/radix_bitpack.c.o -c /home/yuwu/Documents/新建文件夹/lib/LZMA2-Fast/radix_bitpack.c

CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/radix_bitpack.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/radix_bitpack.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yuwu/Documents/新建文件夹/lib/LZMA2-Fast/radix_bitpack.c > CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/radix_bitpack.c.i

CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/radix_bitpack.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/radix_bitpack.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yuwu/Documents/新建文件夹/lib/LZMA2-Fast/radix_bitpack.c -o CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/radix_bitpack.c.s

CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/radix_mf.c.o: CMakeFiles/LZMA2_Fast.dir/flags.make
CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/radix_mf.c.o: lib/LZMA2-Fast/radix_mf.c
CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/radix_mf.c.o: CMakeFiles/LZMA2_Fast.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/yuwu/Documents/新建文件夹/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/radix_mf.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/radix_mf.c.o -MF CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/radix_mf.c.o.d -o CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/radix_mf.c.o -c /home/yuwu/Documents/新建文件夹/lib/LZMA2-Fast/radix_mf.c

CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/radix_mf.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/radix_mf.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yuwu/Documents/新建文件夹/lib/LZMA2-Fast/radix_mf.c > CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/radix_mf.c.i

CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/radix_mf.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/radix_mf.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yuwu/Documents/新建文件夹/lib/LZMA2-Fast/radix_mf.c -o CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/radix_mf.c.s

CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/radix_struct.c.o: CMakeFiles/LZMA2_Fast.dir/flags.make
CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/radix_struct.c.o: lib/LZMA2-Fast/radix_struct.c
CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/radix_struct.c.o: CMakeFiles/LZMA2_Fast.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/yuwu/Documents/新建文件夹/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/radix_struct.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/radix_struct.c.o -MF CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/radix_struct.c.o.d -o CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/radix_struct.c.o -c /home/yuwu/Documents/新建文件夹/lib/LZMA2-Fast/radix_struct.c

CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/radix_struct.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/radix_struct.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yuwu/Documents/新建文件夹/lib/LZMA2-Fast/radix_struct.c > CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/radix_struct.c.i

CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/radix_struct.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/radix_struct.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yuwu/Documents/新建文件夹/lib/LZMA2-Fast/radix_struct.c -o CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/radix_struct.c.s

CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/range_enc.c.o: CMakeFiles/LZMA2_Fast.dir/flags.make
CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/range_enc.c.o: lib/LZMA2-Fast/range_enc.c
CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/range_enc.c.o: CMakeFiles/LZMA2_Fast.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/yuwu/Documents/新建文件夹/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/range_enc.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/range_enc.c.o -MF CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/range_enc.c.o.d -o CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/range_enc.c.o -c /home/yuwu/Documents/新建文件夹/lib/LZMA2-Fast/range_enc.c

CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/range_enc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/range_enc.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yuwu/Documents/新建文件夹/lib/LZMA2-Fast/range_enc.c > CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/range_enc.c.i

CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/range_enc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/range_enc.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yuwu/Documents/新建文件夹/lib/LZMA2-Fast/range_enc.c -o CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/range_enc.c.s

CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/util.c.o: CMakeFiles/LZMA2_Fast.dir/flags.make
CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/util.c.o: lib/LZMA2-Fast/util.c
CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/util.c.o: CMakeFiles/LZMA2_Fast.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/yuwu/Documents/新建文件夹/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/util.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/util.c.o -MF CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/util.c.o.d -o CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/util.c.o -c /home/yuwu/Documents/新建文件夹/lib/LZMA2-Fast/util.c

CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/util.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/util.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yuwu/Documents/新建文件夹/lib/LZMA2-Fast/util.c > CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/util.c.i

CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/util.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/util.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yuwu/Documents/新建文件夹/lib/LZMA2-Fast/util.c -o CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/util.c.s

CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/xxhash.c.o: CMakeFiles/LZMA2_Fast.dir/flags.make
CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/xxhash.c.o: lib/LZMA2-Fast/xxhash.c
CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/xxhash.c.o: CMakeFiles/LZMA2_Fast.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/yuwu/Documents/新建文件夹/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building C object CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/xxhash.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/xxhash.c.o -MF CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/xxhash.c.o.d -o CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/xxhash.c.o -c /home/yuwu/Documents/新建文件夹/lib/LZMA2-Fast/xxhash.c

CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/xxhash.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/xxhash.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/yuwu/Documents/新建文件夹/lib/LZMA2-Fast/xxhash.c > CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/xxhash.c.i

CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/xxhash.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/xxhash.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/yuwu/Documents/新建文件夹/lib/LZMA2-Fast/xxhash.c -o CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/xxhash.c.s

# Object files for target LZMA2_Fast
LZMA2_Fast_OBJECTS = \
"CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/dict_buffer.c.o" \
"CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_common.c.o" \
"CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_compress.c.o" \
"CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_decompress.c.o" \
"CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_pool.c.o" \
"CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_threading.c.o" \
"CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/lzma2_dec.c.o" \
"CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/lzma2_enc.c.o" \
"CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/radix_bitpack.c.o" \
"CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/radix_mf.c.o" \
"CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/radix_struct.c.o" \
"CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/range_enc.c.o" \
"CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/util.c.o" \
"CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/xxhash.c.o"

# External object files for target LZMA2_Fast
LZMA2_Fast_EXTERNAL_OBJECTS =

libLZMA2_Fast.a: CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/dict_buffer.c.o
libLZMA2_Fast.a: CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_common.c.o
libLZMA2_Fast.a: CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_compress.c.o
libLZMA2_Fast.a: CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_decompress.c.o
libLZMA2_Fast.a: CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_pool.c.o
libLZMA2_Fast.a: CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/fl2_threading.c.o
libLZMA2_Fast.a: CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/lzma2_dec.c.o
libLZMA2_Fast.a: CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/lzma2_enc.c.o
libLZMA2_Fast.a: CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/radix_bitpack.c.o
libLZMA2_Fast.a: CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/radix_mf.c.o
libLZMA2_Fast.a: CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/radix_struct.c.o
libLZMA2_Fast.a: CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/range_enc.c.o
libLZMA2_Fast.a: CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/util.c.o
libLZMA2_Fast.a: CMakeFiles/LZMA2_Fast.dir/lib/LZMA2-Fast/xxhash.c.o
libLZMA2_Fast.a: CMakeFiles/LZMA2_Fast.dir/build.make
libLZMA2_Fast.a: CMakeFiles/LZMA2_Fast.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/yuwu/Documents/新建文件夹/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Linking C static library libLZMA2_Fast.a"
	$(CMAKE_COMMAND) -P CMakeFiles/LZMA2_Fast.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LZMA2_Fast.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LZMA2_Fast.dir/build: libLZMA2_Fast.a
.PHONY : CMakeFiles/LZMA2_Fast.dir/build

CMakeFiles/LZMA2_Fast.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LZMA2_Fast.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LZMA2_Fast.dir/clean

CMakeFiles/LZMA2_Fast.dir/depend:
	cd /home/yuwu/Documents/新建文件夹 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yuwu/Documents/新建文件夹 /home/yuwu/Documents/新建文件夹 /home/yuwu/Documents/新建文件夹 /home/yuwu/Documents/新建文件夹 /home/yuwu/Documents/新建文件夹/CMakeFiles/LZMA2_Fast.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/LZMA2_Fast.dir/depend

