#include <stdio.h>
#include "duktape.h"
#include "js_c.h"
#include "utils.h"

int main() {
     duk_context *ctx = duk_create_heap_default();  // Create a Duktape heap

    // Register the native function logDebug to the global object in Duktape
    duk_push_c_function(ctx, js_log_debug, 1 /* number of arguments */);
    duk_put_global_string(ctx, "logDebug");  // Register function as global 'logDebug'

    duk_push_c_function(ctx, js_log_info, 1 /* number of arguments */);
    duk_put_global_string(ctx, "logInfo");  // Register function as global 'logDebug'

    duk_push_c_function(ctx, js_log_error, 1 /* number of arguments */);
    duk_put_global_string(ctx, "logError");  // Register function as global 'logDebug'

    duk_push_c_function(ctx, js_sleep, 1 /* number of arguments */);
    duk_put_global_string(ctx, "sleep");  // Register function as global 'sleep'

    char *script = read_file_contents("main.js");
    if (!script) {
        return 1;
    }

    // Execute a JavaScript script that calls logDebug
   duk_eval_string(ctx, script);


    // if (duk_peval_string(ctx, script) != 0) {
    //     duk_destroy_heap(ctx);
    //     free(script);
    //     return 1;
    // }

    // printf("RUN completed");

    // // 获取并处理 JavaScript 返回的对象
    // if (duk_is_object(ctx, -1)) {
    //     printf("JavaScript returned an object:\n");

    //     // 遍历对象的属性
    //     duk_enum(ctx, -1, DUK_ENUM_OWN_PROPERTIES_ONLY);
    //     while (duk_next(ctx, -1, 1 /* get_value */)) {
    //         printf("%s: %s\n", duk_to_string(ctx, -2), duk_to_string(ctx, -1));
    //         duk_pop_2(ctx);  // 弹出 key 和 value
    //     }
    //     duk_pop(ctx);  // 弹出 enum

    // } else {
    //     printf("JavaScript returned a non-object value:\n%s\n", duk_safe_to_string(ctx, -1));
    // }


    free(script);

    duk_destroy_heap(ctx);  // Clean up Duktape heap

    return 0;
}