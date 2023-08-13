#ifndef HELLO_CONTROLLER_H
#define HELLO_CONTROLLER_H

#include <microhttpd.h>

int get_hello(struct MHD_Connection *connection);

#endif