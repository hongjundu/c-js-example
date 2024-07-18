#include <stdio.h>
#include <unistd.h>
#include "duktape.h"

duk_ret_t js_log_debug(duk_context *ctx);

duk_ret_t js_log_info(duk_context *ctx);

duk_ret_t js_log_error(duk_context *ctx);

duk_ret_t js_sleep(duk_context *ctx);