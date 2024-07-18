#include "js_c.h"

duk_ret_t js_log_debug(duk_context *ctx) {
    const char *message = duk_to_string(ctx, 0); 

    printf("[DEBUG] %s\n", message);

    return 0; 
}

duk_ret_t js_log_info(duk_context *ctx) {
    const char *message = duk_to_string(ctx, 0);  

    printf("[INFO] %s\n", message);

    return 0; 
}

duk_ret_t js_log_error(duk_context *ctx) {
    const char *message = duk_to_string(ctx, 0);  

    fprintf(stderr, "[ERROR] %s\n", message);

    return 0;  
}

duk_ret_t js_sleep(duk_context *ctx) {
    unsigned int milliseconds = (unsigned int) duk_require_uint(ctx, 0);

    // Use platform-specific sleep function (POSIX or Windows)
    #ifdef _WIN32
        Sleep(milliseconds);  // Windows sleep in milliseconds
    #else
        usleep(milliseconds * 1000);  // POSIX usleep takes microseconds, so convert milliseconds to microseconds
    #endif

    return 0; 
}