#ifndef TEMPL_H_
#define TEMPL_H_

#define CAT(a, b) a##_##b
#define TEMPL(x, y) CAT(x,y)
#define t_(type, name) TEMPL(type, name)

// #define TP(type) typedef type##* type##_ptr

#endif
