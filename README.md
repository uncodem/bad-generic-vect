# bad-generic-vect
This is a simple library that abuses the c processor to create template-like types    
this can be used as a dynamic array library.    
    
But keep in mind due to the macros, you can't actually use pointers with the `type*` syntax    
you have to typedef it to a typename like so `typedef int* int_ptr` to make sure that the compiler    
doesnt give errors

NOTE: This shouldn't be used for anything at all, even though it can be used. This is simply a learning expierience for me.
