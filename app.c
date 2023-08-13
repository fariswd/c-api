#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <microhttpd.h>

#include "routes/hello.h"
#include "helpers/response.h"

int answer_to_connection(void *cls, struct MHD_Connection *connection,
                         const char *url,
                         const char *method, const char *version,
                         const char *upload_data,
                         size_t *upload_data_size, void **con_cls)
{

  if (strcmp(url, "/hello") == 0 || strcmp(url, "/hello/") == 0)
  {
    return hello_route(connection, method);
  }

  const char *not_found = "{\"message\": \"Hi\"}";
  return error_response(connection, not_found);
}

int main()
{
  struct MHD_Daemon *daemon;

  daemon = MHD_start_daemon(MHD_USE_INTERNAL_POLLING_THREAD, 8080, NULL, NULL,
                            &answer_to_connection, NULL, MHD_OPTION_END);
  if (NULL == daemon)
    return 1;

  printf("Server started at port 8080");
  getchar();

  MHD_stop_daemon(daemon);
  return 0;
}