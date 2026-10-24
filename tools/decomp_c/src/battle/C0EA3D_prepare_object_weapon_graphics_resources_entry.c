#include "som_c.h"

/* C0EA3D prepare_object_weapon_graphics_resources_entry   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/prepare_object_weapon_graphics_resources_entry.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void prepare_object_weapon_graphics_resources_entry(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    JSR(c, 0xEA3F, 0xC0EA41); /* prepare_object_weapon_graphics_resources */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC0EA3D, SOM_RTL, "gen", prepare_object_weapon_graphics_resources_entry, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 4, 2)
