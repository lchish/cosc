#ifndef FLEXARRAY_H_
#define FLEXARRAY_H_

typedef struct flexarrayrec *flexarray;

extern flexarray flexarray_new();
extern void flexarray_append(flexarray,int);
extern void flexarray_print(flexarray);
extern void flexarray_sort(flexarray);
extern void flexarray_delete(flexarray);

#endif
