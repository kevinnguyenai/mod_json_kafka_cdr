 /*
 * FreeSWITCH Modular Media Switching Software Library / Soft-Switch Application
 * Copyright (C) 2005-2014, Anthony Minessale II <anthm@freeswitch.org>
 *
 * Version: MPL 1.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is FreeSWITCH Modular Media Switching Software Library / Soft-Switch Application
 *
 * The Initial Developer of the Original Code is
 * Anthony Minessale II <anthm@freeswitch.org>
 * Portions created by the Initial Developer are Copyright (C)
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *
 * Kevin Nguyen <kevin.nguyen.ai@gmail.com>
 *
 * mod_json_cdr.h -- JSON CDR Module to files or curl or kafka
 *
 */
#ifndef MOD_JSON_CDR_KAFKA_H
#define MOD_JSON_CDR_KAFKA_H

#include <switch.h>
#include "librdkafka/rdkafka.h"

#define MAX_URLS 20
#define MAX_ERR_DIRS 20
#define ENCODING_NONE 0
#define ENCODING_DEFAULT 1
#define ENCODING_BASE64 2

static struct {
  char *cred;
  char *urls[MAX_URLS];
  int url_count;
  int url_index;
  switch_thread_rwlock_t *log_path_lock;
  char *base_log_dir;
  char *base_err_log_dir[MAX_ERR_DIRS];
  char *log_dir;
  char *err_log_dir[MAX_ERR_DIRS];
  int err_dir_count;
  uint32_t delay;
  uint32_t retries;
  uint32_t shutdown;
  uint32_t enable_cacert_check;
  char *ssl_cert_file;
  char *ssl_key_file;
  char *ssl_key_password;
  char *ssl_version;
  char *ssl_cacert_file;
  uint32_t enable_ssl_verifyhost;
  int encode;
  int log_http_and_disk;
  switch_bool_t log_errors_to_disk;
  int log_b;
  int prefix_a;
  int disable100continue;
  int rotate;
  long auth_scheme;
  switch_memory_pool_t *pool;
  switch_event_node_t *node;
  int encode_values;
  switch_queue_t *queue;
  switch_thread_t *thread;
  char *bootstrap_servers;
  char *topic_prefix;
  int topic_dyn;
  int buffer_size; 
} globals;

typedef struct {
  char *json_text;
  char *json_text_escaped;
  char *logdir;
  char *uuid;
  char *filename;
} cdr_data_t;

SWITCH_MODULE_LOAD_FUNCTION(mod_json_cdr_load);
SWITCH_MODULE_SHUTDOWN_FUNCTION(mod_json_cdr_shutdown);
SWITCH_MODULE_DEFINITION(mod_json_cdr, mod_json_cdr_load, mod_json_cdr_shutdown, NULL);

#endif // MOD_JSON_CDR_KAFKA_H
