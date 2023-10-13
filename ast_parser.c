#include <stdio.h>
#include <stdlib.h>
#include <jansson.h>
#include <string.h>

int count_if_statements(json_t *node) {
    int count = 0;
    json_t *nodetype = json_object_get(node, "_nodetype");

    if (json_is_string(nodetype) && strcmp(json_string_value(nodetype), "If") == 0) {
        count++;
    }

    if (json_is_array(node)) {
        size_t size = json_array_size(node);
        for (size_t i = 0; i < size; i++) {
            count += count_if_statements(json_array_get(node, i));
        }
    }
    else if (json_is_object(node)) {
        const char *key;
        json_t *value;

        json_object_foreach(node, key, value) {
            count += count_if_statements(value);
        }
    }

    return count;
}

void parse_function(json_t *func) {
	json_t *nodetype = json_object_get(func, "_nodetype");
    json_t *name = json_object_get(func, "name");
	json_t *decl = json_object_get(func, "Decl");
    if(nodetype && json_is_string(nodetype) && strcmp(json_string_value(nodetype), "Decl") == 0 && name) {
        printf("Function Name: %s\n", json_string_value(name));
    }
	json_t *type = json_object_get(func, "type");
	json_t *return_type = json_object_get(type, "type");
	json_t *type_identifier = json_object_get(return_type, "type");
	json_t *names = json_object_get(type_identifier, "names");
	if(json_is_array(names)) {
		json_t *type_name = json_array_get(names, 0);
		if(json_is_string(type_name)) {
			printf("Return Type: %s\n", json_string_value(type_name));
		}
	}
	json_t *args = json_object_get(json_object_get(func, "type"), "args");
	json_t *params = json_object_get(args, "params");
	size_t num_params = json_array_size(params);
	for(size_t i = 0; i < num_params; i++) {
		json_t *param = json_array_get(params, i);
		const char *param_name = json_string_value(json_object_get(param, "name"));
		json_t *param_type = json_object_get(json_object_get(json_object_get(param, "type"), "type"), "names");
		const char *type_str = json_string_value(json_array_get(param_type, 0));
		printf("Parameter: %s, Type: %s\n", param_name, type_str);
	}

	printf("\n");
}
int main(int argc, char **argv) {
	json_error_t error;
    json_t *root = json_load_file(argv[1], 0, &error);
    json_t *functions = json_object_get(root, "ext");
    size_t num_functions = json_array_size(functions);
    printf("Number of functions: %zu\n\n", num_functions / 2);
	printf("Number of if statements: %d\n\n", count_if_statements(root));
    for(size_t i = 0; i < num_functions; i++) {
        json_t *func = json_array_get(functions, i);
        parse_function(func);
    }
    json_decref(root);
    return 0;
}

