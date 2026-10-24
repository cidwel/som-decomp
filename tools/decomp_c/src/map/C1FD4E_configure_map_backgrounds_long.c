#include "som_c.h"

/* C1FD4E configure_map_backgrounds_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/configure_map_backgrounds_long.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void configure_map_backgrounds_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSR(c, 0xFD50, 0xC1FD52); GUARD_JSR(c, sp_call, 0xFD50); } /* configure_map_backgrounds */
    r->mf = true;
    r->xf = true;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC1FD4E, SOM_RTL, "hand", configure_map_backgrounds_long, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 1, 4, 2)
