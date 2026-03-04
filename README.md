# C String Library

A string library with several functions to use, manipulate and process strings.

## Usage example:
```c
#include <stdio.h>
#include "str.h"

int main(void) {
    // Create a new string
    str name = str_new("john");
    printf("name: %s\n", str_data(&name));

    // Create an empty string
    str empty = str_empty();
    printf("empty: %s\n", str_data(&empty));
    
    // Copy name into empty
    str_write(&empty, str_data(&name));
    printf("after copy, empty: %s\n", str_data(&empty));
    
    // Modify name
    str_write(&name, "alice");
    printf("name after write: %s\n", str_data(&name));

    // Clean up
    str_destroy(&name);
    str_destroy(&empty);

    return 0;
}
```

## Expected output:
    name: john
    empty: 
    after copy, empty: john
    name after write: alice

## compiling:
```bash
make
```