#include <stdio.h>
#include <string.h>
#include <microhttpd.h>

int success_response(struct MHD_Connection *connection, char *page)
{
  struct MHD_Response *response;
  int ret;

  response = MHD_create_response_from_buffer(strlen(page),
                                             (void *)page, MHD_RESPMEM_PERSISTENT);
  MHD_add_response_header(response, MHD_HTTP_HEADER_CONTENT_TYPE, "application/json");

  ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
  MHD_destroy_response(response);

  return ret;
}

int error_response(struct MHD_Connection *connection, char *page)
{
  struct MHD_Response *response;
  int ret;

  response = MHD_create_response_from_buffer(strlen(page),
                                             (void *)page, MHD_RESPMEM_PERSISTENT);
  MHD_add_response_header(response, MHD_HTTP_HEADER_CONTENT_TYPE, "application/json");

  ret = MHD_queue_response(connection, MHD_HTTP_BAD_REQUEST, response);
  MHD_destroy_response(response);

  return ret;
}