#!/usr/bin/env bash

LIB_PATH=$(pwd)/lib/libmicrohttpd
cc -o app app.c routes/hello.c controllers/hello_controller.c helpers/response.c -I$LIB_PATH/src/include -L$LIB_PATH/src/microhttpd/.libs -lmicrohttpd

exit 0;