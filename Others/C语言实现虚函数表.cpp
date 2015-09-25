#include <stdio.h>

typedef struct {
    void (*draw)(void*);
    void (*rotate)(void*);
} vtable;

typedef struct {
    vtable *vptr;
} Shape;

typedef struct {
    vtable *vptr;
    int x, y, w, h;
} Rect;

typedef struct {
    vtable *vptr;
    int x, y, r;
} Cycle;

void DrawRect(void *p) {
    Rect *me = (Rect *)p;
    printf("DrawRect\n");
}

void RotateRect(void *p) {
    Rect *me = (Rect *)p;
    printf("RotateRect\n");
}

void DrawCycle(void *p) {
    Cycle *me = (Cycle *)p;
    printf("DrawCycle\n");
}

void RotateCycle(void *p) {
    Cycle *me = (Cycle *)p;
    printf("RotateCycle\n");
}

vtable RectOpers = {&DrawRect, &RotateRect};
vtable CycleOpers = {&DrawCycle, &RotateCycle};


int main() {
    Rect rt1 = {&RectOpers, 0, 0, 10, 10};
    Cycle cy1 = {&CycleOpers, 10, 10, 20};
    Shape *sh = (Shape *)&rt1;
    sh->vptr->draw(sh);
    sh->vptr->rotate(sh);
    sh = (Shape *)&cy1;
    sh->vptr->draw(sh);
    sh->vptr->rotate(sh);
    return 0;
}



