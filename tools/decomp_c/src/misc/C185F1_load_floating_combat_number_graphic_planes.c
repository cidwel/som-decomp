#include "som_c.h"

/* C185F1 load_floating_combat_number_graphic_planes   [class A, 25 bytes, 10 instructions]
 * Source: src/rom/load_floating_combat_number_graphic_planes.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BYCV.
 */
static void load_floating_combat_number_graphic_planes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(0x0014, x);
    RAM16_SET(0x0008, 0x32);
    RAM16_SET(0x0000, 0x0800);
    r->a = 0xD1;
    r->y = 0xF100;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    { const uint16_t sp_call = r->sp; JSL(c, 0x8608, 0x01C599); GUARD_JSL(c, sp_call, 0x8608); } /* dispatch_object_graphics_plane_conversion */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC185F1, SOM_RTS, "gen", load_floating_combat_number_graphic_planes, 0, L_B | L_Y | L_C | L_V, 1, 1, 0, 25, 10)
