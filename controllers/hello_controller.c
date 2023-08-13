#include <stdio.h>
#include <microhttpd.h>
#include "../helpers/response.h"

int get_hello(struct MHD_Connection *connection)
{
  const char *res = "{\"message\": \"hi from get hello\"}";
  return success_response(connection, res);
}