#include "som_c.h"

/* C1E0D7 initialize_party_hud_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/initialize_party_hud_long.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void initialize_party_hud_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0xE0D9, 0xC1E104); /* initialize_party_hud */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC1E0D7, SOM_RTL, "gen", initialize_party_hud_long, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 4, 2)
