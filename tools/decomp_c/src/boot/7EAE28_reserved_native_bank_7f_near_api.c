#include "som_c.h"

/* 7EAE28 reserved_native_bank_7f_near_api   [class A, 15 bytes, 12 instructions]
 * Source: src/boot/reserved_native_bank_7f_near_api.s
 * Documented in docs/boot-native-task-access-wrappers.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void reserved_native_bank_7f_near_api(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    SET_A8(r, 0x7F);
    r->z = 1;
    r->n = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EAE28, SOM_RTS, "gen", reserved_native_bank_7f_near_api, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 5, 1, 0, 15, 12)
