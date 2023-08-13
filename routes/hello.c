#include <stdio.h>
#include <string.h>
#include <microhttpd.h>

#include "../helpers/response.h"
#include "../controllers/hello_controller.h"

int hello_route(struct MHD_Connection *connection, char *method)
{
  if (strcmp(method, "GET") == 0)
  {
    return get_hello(connection);
  }

  const char *not_found = "{\"message\": \"not found in hello\"}";
  return error_response(connection, not_found);
}