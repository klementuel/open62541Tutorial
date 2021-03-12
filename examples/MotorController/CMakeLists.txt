cmake_minimum_required(VERSION 3.10)

# set the project name
project(MotorSteuerung)

set(CMAKE_PREFIX_PATH "/home/parallels/install")
message("Cmake Prefix Path is \"${CMAKE_PREFIX_PATH}\"")
# open62541 must be installed.
# If in custom path, then use -DCMAKE_PREFIX_PATH=/home/user/install
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



