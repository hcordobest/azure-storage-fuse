#!/usr/bin/env bash
BLOBFS_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

## Use "export INCLUDE_TESTS=1" to enable building tests

<<<<<<< HEAD
cmake_args='(-DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DCMAKE_BUILD_TYPE=RelWithDebInfo ..'
if [ -n "${INCLUDE_TESTS}" ]; then
    cmake_args='-DCMAKE_BUILD_TYPE=RelWithDebInfo -DINCLUDE_TESTS=1 ..'
=======
if [ $1 = "debug" ]
then
	cmake_args='-DCMAKE_BUILD_TYPE=Debug ..'
	if [ -n "${INCLUDE_TESTS}" ]; then
		cmake_args='-DCMAKE_BUILD_TYPE=Debug -DINCLUDE_TESTS=1 ..'
	fi
else
	cmake_args='-DCMAKE_BUILD_TYPE=RelWithDebInfo ..'
	if [ -n "${INCLUDE_TESTS}" ]; then
		cmake_args='-DCMAKE_BUILD_TYPE=RelWithDebInfo -DINCLUDE_TESTS=1 ..'
	fi
fi

## Build the cpplite lib first
#echo "Building the cpplite lib"
if [ $1 = "debug" ]
then
rm -rf cpplite/build.release
rm -rf build/blobfuse
mkdir cpplite/build.release
cd cpplite/build.release
echo "Building cpplite in Debug mode"
cmake .. -DCMAKE_BUILD_TYPE=Debug -DBUILD_ADLS=ON -DUSE_OPENSSL=OFF
else
mkdir cpplite/build.release
cd cpplite/build.release
cmake .. -DCMAKE_BUILD_TYPE=Release -DBUILD_ADLS=ON -DUSE_OPENSSL=OFF
fi

cmake --build .
status=$?

if test $status -eq 0
then
	echo "************************ CPPLite build Successful ***************************** "
else
	echo "************************ CPPLite build Failed ***************************** "
	exit $status
>>>>>>> 8c4db0fdc03a29fc9c5e18711fa05fa0d4cdb04d
fi
cd -

## install pkg-config, cmake, libcurl and libfuse first
## For example, on ubuntu - sudo apt-get install pkg-config libfuse-dev cmake libcurl4-openssl-dev -y
mkdir build
cd build

# Copy the cpplite lib here
#cp ../cpplite/build.release/libazure*.a ./ 

## Use cmake3 if it's available.  If not, then fallback to the default "cmake".  Otherwise, fail.
cmake3 $cmake_args
if [ $? -ne 0 ]
then
    cmake $cmake_args
fi 
if [ $? -ne 0 ]
then
	ERRORCODE=$?
	echo "cmake failed.  Please ensure that cmake version 3.5 or greater is installed and available."
	exit $ERRORCODE
fi
make
make package

