#include "som_c.h"

/* 7EB333 reserved_native_bank_7f_long_api   [class A, 15 bytes, 12 instructions]
 * Source: src/boot/reserved_native_bank_7f_long_api.s
 * Documented in docs/boot-native-task-access-wrappers.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void reserved_native_bank_7f_long_api(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    SET_A8(r, 0x7F);
    r->z = 0;
    r->n = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0x7EB333, SOM_RTL, "gen", reserved_native_bank_7f_long_api, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 5, 1, 0, 15, 12)
