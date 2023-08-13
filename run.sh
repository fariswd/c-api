#!/usr/bin/env bash

LIB_PATH=$(pwd)/lib/libmicrohttpd
LD_LIBRARY_PATH=$(pwd)/lib/
export LD_LIBRARY_PATH=$LIB_PATH:$LD_LIBRARY_PATH
export DYLD_LIBRARY_PATH=$LIB_PATH/src/microhttpd/.libs:$DYLD_LIBRARY_PATH
./app
exec tail -f /dev/null
