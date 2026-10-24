#include "som_c.h"

/* C2AA5C configure_map_screen_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/configure_map_screen_long.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=8 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void configure_map_screen_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 0, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0xAA5E, 0xC2AA60); /* configure_map_screen */
    r->mf = true;
    r->xf = true;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2AA5C, SOM_RTL, "hand", configure_map_screen_long, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 0, 1, 4, 2)
