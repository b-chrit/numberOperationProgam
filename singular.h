#ifndef SINGULAR_H
#define SINGULAR_H
enum filter_type{EQ,NEQ,GEQ,LEQ,LESS,GREATER};
void print(double arr[],size_t size);
void shift(double arr[],size_t size,double by);
size_t filter(double arr[],size_t count,enum filter_type t,double threshold);
#endif

