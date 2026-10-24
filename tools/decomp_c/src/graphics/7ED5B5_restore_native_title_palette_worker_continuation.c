#include "som_c.h"

/* 7ED5B5 restore_native_title_palette_worker_continuation   [class A, 15 bytes, 12 instructions]
 * Source: src/boot/restore_native_title_palette_worker_continuation.s
 * Documented in docs/boot-native-title-palette-worker.md
 * Entry: M=8 bit X=16 bit DB=$7F D=$0400.  Callers read: ABXYCZNV.
 */
static void restore_native_title_palette_worker_continuation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x0400) { c->fail = 3; return; }
    SET_A8(r, 0x7F);
    r->z = 0;
    r->n = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0x7ED5B5, SOM_RTL, "gen", restore_native_title_palette_worker_continuation, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 5, 1, 0, 15, 12)
