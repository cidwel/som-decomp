#include "som_c.h"

/* 7ECE62 reserved_native_title_status_and_direct_page_api   [class A, 9 bytes, 7 instructions]
 * Source: src/boot/reserved_native_title_status_and_direct_page_api.s
 * Documented in docs/source-recovery-parallel-reserved-title-api.md
 * Entry: M=16 bit X=16 bit DB=$7F D=$0000.  Callers read: BXYCZNV.
 */
static void reserved_native_title_status_and_direct_page_api(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    r->z = 1;
    r->n = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7ECE62, SOM_RTS, "gen", reserved_native_title_status_and_direct_page_api, 0, L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 3, 0, 0, 9, 7)
