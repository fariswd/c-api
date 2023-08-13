#ifndef RESPONSE_HELPER_H
#define RESPONSE_HELPER_H

#include <microhttpd.h>

int success_response(struct MHD_Connection *connection, char *raw);
int error_response(struct MHD_Connection *connection, char *raw);

#endif