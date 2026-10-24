#include "som_c.h"

/* C1864D load_actor_secondary_graphics_and_palette_long   [class A, 7 bytes, 3 instructions]
 * Source: src/rom/load_actor_secondary_graphics_and_palette_long.s
 * Documented in docs/event-menu-effect-graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: XC.
 */
static void load_actor_secondary_graphics_and_palette_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0x864F, 0xC18634); /* load_actor_cast_secondary_graphics */
    r->mf = 1;
    r->xf = 0;
    JSR(c, 0x8652, 0xC185D8); /* load_object_weapon_palette_from_field_04f */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC1864D, SOM_RTL, "gen", load_actor_secondary_graphics_and_palette_long, 0, L_X | L_C, 1, 1, 0, 7, 3)
