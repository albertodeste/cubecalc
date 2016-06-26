#include "neo4j-client.h"
#include <errno.h>
#include <stdio.h>

char * neo4j_connection_string = "neo4j://neo4j:password@localhost:7687";

int run_query(char * query)
{
  int id = -1;
  neo4j_client_init();
  neo4j_connection_t *c = neo4j_connect(neo4j_connection_string, NULL, NEO4J_INSECURE);
  neo4j_session_t *s = neo4j_new_session(c);
  neo4j_result_stream_t *rs = neo4j_run(s, query, neo4j_null);
  neo4j_result_t *r = neo4j_fetch_next(rs);
  neo4j_value_t v = neo4j_result_field(r, 0);
  id = neo4j_int_value(v);
  neo4j_close_results(rs);
  neo4j_end_session(s);
  neo4j_close(c);
  neo4j_client_cleanup(); 
  return id;
}
