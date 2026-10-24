#include "som_c.h"

/* C03F28 refresh_controller_status_public_call   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/refresh_controller_status_public_call.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCZNV.
 */
static void refresh_controller_status_public_call(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    JSR(c, 0x3F2A, 0xC03F2C); /* refresh_controller_status_bits_from_party */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC03F28, SOM_RTL, "gen", refresh_controller_status_public_call, 0, L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 4, 2)
