#include "som_c.h"

/* C0E9F4 refresh_actor_weapon_graphics_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/refresh_actor_weapon_graphics_long.s
 * Documented in docs/rom-combat.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void refresh_actor_weapon_graphics_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0xE9F6, 0xC0EA19); /* refresh_object_weapon_graphics_and_palette */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC0E9F4, SOM_RTL, "gen", refresh_actor_weapon_graphics_long, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 4, 2)
