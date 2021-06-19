# Custom Cmake File

The repetitve build process and complex build dependencies can be managed with cmake.
Create a CMakeLists.txt in your source code folder (e.g. where your main.c is).

``` {.Bash language="Bash"}
nano CMakeLists.txt
```

and tailor the following example, taken from https://github.com/klementuel/open62541Tutorial/tree/opcua.rocks/examples/MotorController with kind permission, to your needs:

``` {.makefile language="make"}
make_minimum_required(VERSION 3.10)

# set the project name
project(MotorSteuerung)

set(CMAKE_PREFIX_PATH "/home/parallels/install")
message("Cmake Prefix Path is \"${CMAKE_PREFIX_PATH}\"")
# open62541 must be installed.
# If in custom path, then use -DCMAKE_PREFIX_PATH=/home/user/install
# Set with Required Components the Namespace like FullNamespace or ReducedNamespace
find_package(open62541 1.1 REQUIRED COMPONENTS FullNamespace)

#The following folder will be included
include_directories(${CMAKE_PREFIX_PATH}/include)
link_directories(${CMAKE_PREFIX_PATH}/lib)

# add the executable
add_executable(MotorSteuerung main.c MotorSteuerung.c)

#The following libraries will be linked
target_link_libraries(MotorSteuerung open62541 mbedtls mbedx509 mbedcrypto)

#Limit Parallel Linking Jobs with -DMY_LIMIT_FLAG=ON
option(MY_LIMIT_FLAG "If Build fail you can set this ON to Limit parralel Linking Jobs to One" OFF) #OFF by default
if(MY_LIMIT_FLAG)
set(MY_LIMIT_FLAG "-flto=1")
message("Set Parallel Linking Jobs to One")
endif(MY_LIMIT_FLAG)
unset(MY_LIMIT_FLAG CACHE) # <---- this is the important!!

#Set the the C Standart
set_property(TARGET MotorSteuerung PROPERTY C_STANDARD 99)
```

Prepare the build environment, cmake and build

``` {.Bash language="Bash"}
mkdir build && cd build
cmake .. -DCMAKE_PREFIX_PATH=/home/{user}/install -DMY_LIMIT_FLAG=ON
make
```

Include additional libraries and classes as follows:
(Note that the DCMAKE_PREFIX_PATH and DMY_LIMIT_FLAG are now part of CMakeLists.txt for better portability to other build environments)

``` {.makefile language="make"}
cmake_minimum_required(VERSION 3.10)

# set the project name
project(PaintingStationBelt)

#Set open62541 Path directly
set(CMAKE_PREFIX_PATH "/home/parallels/install")
message("Cmake Prefix Path is \"${CMAKE_PREFIX_PATH}\"")
# open62541 must be installed.
# If in custom path, then use -DCMAKE_PREFIX_PATH=/home/user/install
find_package(open62541 1.1 REQUIRED)
#find PythonLibs
find_package(PythonLibs REQUIRED)
message("Python Prefix Path is \"${PYTHON_INCLUDE_DIRS}\"")

#The following folder will be included
include_directories(${CMAKE_PREFIX_PATH}/include ${PYTHON_INCLUDE_DIRS} PyhtonScripts)
link_directories(${CMAKE_PREFIX_PATH}/lib)

# add the executable
add_executable(PaintingStationBelt main.c PaintingStationBelt.c Callbacks.c OpcUaHelper.c KpiCalculator.c)

#The following libraries will be linked
target_link_libraries(PaintingStationBelt open62541 mbedtls mbedx509 mbedcrypto pthread ${PYTHON_LIBRARIES})

#Limit Parallel Linking Jobs with -DMY_LIMIT_FLAG=ON
option(MY_LIMIT_FLAG "If Build fail you can set this ON to Limit parralel Linking Jobs to One" OFF) #OFF by default
if(MY_LIMIT_FLAG)
set(MY_LIMIT_FLAG "-flto=1")
message("Set Parallel Linking Jobs to One")
endif(MY_LIMIT_FLAG)
unset(MY_LIMIT_FLAG CACHE) # <---- this is the important!!

#Set the the C Standart
set_property(TARGET PaintingStationBelt PROPERTY C_STANDARD 99)
```

Finally build as usual (in your build folder)

``` {.Bash language="Bash"}
cmake ..
make
```

