#ifndef HELLO_ROUTE_H
#define HELLO_ROUTE_H

#include <microhttpd.h>

int hello_route(struct MHD_Connection *connection, char *method);

#endif